#include <common.h>
#include <elf.h>
#include <device/map.h>

#define MAX_SIZE 16		//环形缓冲区最大空间

/*iringbuf*/
typedef struct {
	word_t pc;
	uint32_t inst;
	}Instbuf;

int func_num = 0;

Instbuf iringbuf[MAX_SIZE];
int cur_inst = 0;
bool full = false;

void trace_inst(word_t pc, uint32_t inst){
	iringbuf[cur_inst].pc = pc;
	iringbuf[cur_inst].inst = inst;
	cur_inst = (cur_inst + 1) % MAX_SIZE;		//更新缓冲区位置
	full = full || cur_inst == 0;
	} 

void display_inst(){
	if(!full && !cur_inst)	return;

	int end = cur_inst;
	int i = full ? cur_inst : 0;

	IFDEF(CONFIG_ITRACE, void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte));
	char buf[128];
	char *p;
	//Statement("The most recently excuted instructions");
	do{
		p = buf;
		p += sprintf(buf, "%s" FMT_WORD ": %08x ", (i+1)%MAX_SIZE==end?" --> ":"     ", iringbuf[i].pc, iringbuf[i].inst);
		IFDEF(CONFIG_ITRACE, disassemble(p, buf + sizeof(buf) - p, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, 4));

		if ((i+1)%MAX_SIZE==end) printf(ANSI_FG_RED);	
		puts(buf);
		i = (i+ 1) % MAX_SIZE;
		}while(i != end);
		puts(ANSI_NONE);
	}


/*mtrace*/
void display_mread(paddr_t addr, int len){
	printf("memory read at" FMT_PADDR "len = %d\n", addr, len);
	}

void display_mwrite(paddr_t addr, int len, word_t data){
	printf("memory write at" FMT_PADDR "len = %d, data = " FMT_PADDR "\n", addr, len, data);
	}


// /*ftrace*/
//
// typedef struct{
// 	char name[32];
// 	paddr_t addr;
// 	Elf32_Xword size;
// 	}Symbol;
//
// Symbol *symbol = NULL;
//
// void parse_elf(const char *elf_file){
// 	if(elf_file == NULL)	return;
//
// 	FILE *fp;
// 	fp = fopen(elf_file, "rb");
//
// 	if(fp == NULL){
// 		printf("failed to open the elf file\n");
// 		exit(0);
// 		}
//
// 	Elf32_Ehdr ehdr;
//
// 	//读取elf文件头
// 	if(fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) <= 0){
// 		printf("failed to read the elf file\n");
// 		exit(0);
// 		}
//
// 	if(ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' || ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F'){	//e_ident数组前四位固定魔数，前四位分别相等则表明是一个ELF文件
// 		printf("this file is not a elf file\n");
// 		exit(0);
// 		}
//
// 	fseek(fp, ehdr.e_shoff, SEEK_SET);		//e_shoff用来指明节头表在文件内的偏移量
//
//
// 	Elf32_Shdr shdr;
// 	char *string_table = NULL;
//
// 	for(int i = 0; i < ehdr.e_shnum; i++){
// 		if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0){
// 			printf("fail to read the shdr!\n");
// 			exit(0);
// 			}
//
// 		if(shdr.sh_type == SHT_STRTAB){
// 			//获取字符串表
// 			string_table = malloc(shdr.sh_size);
// 			fseek(fp, shdr.sh_offset, SEEK_SET);
// 			if(fread(string_table, shdr.sh_size, 1, fp) <= 0){
// 				printf("fail to read the strtab\n");
// 				}
// 			}
// 		}
//
// 		//寻找符号表
// 		fseek(fp, ehdr.e_shoff, SEEK_SET);
//
// 		for(int i = 0; i < ehdr.e_shnum; i++){
// 			if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0){
// 				printf("fail to read the shdr\n");
// 				exit(0);
// 				}
//
// 			if(shdr.sh_type == SHT_SYMTAB){
// 				fseek(fp, shdr.sh_offset, SEEK_SET);
//
// 				Elf32_Sym sym;
//
// 				size_t sym_count = shdr.sh_size / shdr.sh_entsize;
// 				symbol = malloc(sizeof(Symbol) * sym_count);
//
// 				for(size_t j = 0; j < sym_count; j++){
// 					if(fread(&sym, sizeof(Elf32_Sym), 1, fp) <= 0){
// 						printf("fail to read the symtab\n");
// 						exit(0);
// 						}
//
// 					if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC){
// 						const char *name = string_table + sym.st_name;
// 						strncpy(symbol[func_num].name, name, sizeof(symbol[func_num].name) - 1);
// 						symbol[func_num].addr = sym.st_value;
// 						symbol[func_num].size = sym.st_size;
// 						func_num++;
// 						}
// 					}
// 				}
// 			}
// 	fclose(fp);
// 	free(string_table);
//
// 	}
//
// int rec_depth = 1;
// void display_call_func(word_t pc, word_t func_addr){
// 	int i = 0;
// 	for(; i < func_num; i++){
// 		if(func_addr >= symbol[i].addr && func_addr < (symbol[i].addr + symbol[i].size))
// 			break;
// 		}
//
// 	printf("0x%08x:",pc);
//
// 	rec_depth++;
//
// 	printf("call [%s@0x%08x]\n", symbol[i].name, func_addr);
// 	}
//
// void display_ret_func(word_t pc){
// 	int i = 0;
// 	for(; i < func_num; i++){
// 		if(pc >= symbol[i].addr && pc < (symbol[i].addr + symbol[i].size))
// 			break;
// 		}
//
// 	printf("0x%08x",pc);
//
// 	rec_depth--;
//
// 	for(int k = 0; k < rec_depth; k++)
// 		printf(" ");
// 	printf("ret [%s]\n", symbol[i].name);
// 	}
//
typedef struct
{
    char name[64];
    Elf32_Addr addr;
    Elf32_Word size;
    unsigned char info;
} Symbol_table;

Symbol_table *symbol_table = NULL;

size_t symbol_tables_size; // 全局变量

void parse_elf(const char *elf_file)
{
    if (elf_file == NULL)
    {
        return;
    }
    // 打开elf文件
    FILE *fp = fopen(elf_file, "rb");
    Assert(fp, "Can not open '%s'", elf_file);

    // 读取ELF header
    Elf32_Ehdr elf_header;
    if (fread(&elf_header, sizeof(Elf32_Ehdr), 1, fp) <= 0)
    {
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 检查文件是否为ELF文件
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
    {
        fprintf(stderr, "Not an ELF file\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 移动到Section header table,寻找字符表节
    fseek(fp, elf_header.e_shoff, SEEK_SET);
    Elf32_Shdr strtab_header;
    while (1)
    {
        if (fread(&strtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        if (strtab_header.sh_type == SHT_STRTAB)
        {
            break;
        }
    }

    // 读取字符串表内容
    char *string_table = malloc(strtab_header.sh_size);
    fseek(fp, strtab_header.sh_offset, SEEK_SET);
    if (fread(string_table, strtab_header.sh_size, 1, fp) <= 0)
    {
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 寻找符号表节
    Elf32_Shdr symtab_header;
    fseek(fp, elf_header.e_shoff, SEEK_SET);
    while (1)
    {
        if (fread(&symtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        if (symtab_header.sh_type == SHT_SYMTAB)  //SHT_SYMTAB代表此节包含一个符号表
        {
            break;
        }
    }

    /* 读取符号表中的每个符号项 */

    fseek(fp, symtab_header.sh_offset, SEEK_SET);
    Elf32_Sym symbol;
    // 确定符号表的条数
    size_t num_symbols = symtab_header.sh_size / symtab_header.sh_entsize;
    // 分配内存用于存储符号表
    symbol_table = (Symbol_table *)malloc(num_symbols * sizeof(Symbol_table));

    for (size_t i = 0; i < num_symbols; ++i)
    {
        if (fread(&symbol, sizeof(Elf32_Sym), 1, fp) <= 0)
        {
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        // 判断符号是否为函数，并且函数的大小不为零
        if (ELF64_ST_TYPE(symbol.st_info) == STT_FUNC && symbol.st_size != 0)
        {
            // 从字符串表中获取符号名称
            const char *name = string_table + symbol.st_name;
            // 存储符号信息到 symbol_table 结构体数组
            strncpy(symbol_table[i].name, name, sizeof(symbol_table[i].name) - 1);
            symbol_table[i].addr = symbol.st_value;
            symbol_table[i].info = symbol.st_info;
            symbol_table[i].size = symbol.st_size;
        }
        symbol_tables_size = num_symbols;
    }

    // 关闭文件并释放内存
    fclose(fp);
    free(string_table);
}

int rec_depth = 1;

void display_call_func(word_t pc, word_t func_addr)
{
    int i = 0;
    for (; i < symbol_tables_size; i++)
    {
        if (func_addr >= symbol_table[i].addr && func_addr < (symbol_table[i].addr + symbol_table[i].size))
        {
            break;
        }
    }
    printf("[FTRACE] 0x%08x:", pc);

    for (int k = 0; k < rec_depth; k++)
    {
        printf("  ");
    }

    rec_depth++;

    printf("call [%s @0x%08x]\n", symbol_table[i].name, func_addr);
}

void display_ret_func(word_t pc)
{
    int i = 0;
    for (; i < symbol_tables_size; i++)
    {
        if (pc >= symbol_table[i].addr && pc < (symbol_table[i].addr + symbol_table[i].size))
        {
            break;
        }
    }

    printf("[FTRACE] 0x%08x:", pc);

    rec_depth--;

    for (int k = 0; k < rec_depth; k++)
        printf("  ");

    printf("ret  [%s]\n", symbol_table[i].name);
}


/*dtrace*/
void display_dread(paddr_t addr, int len, IOMap *map){
    printf("device %10s read at addr = " FMT_PADDR " ,%d\n", map->name, addr, len);
}

void display_dwrite(paddr_t addr, int len, word_t data, IOMap *map){
    printf("device %10s write at addr = " FMT_PADDR " ,%d, data = " FMT_WORD "\n", map->name, addr, len, data);
}
