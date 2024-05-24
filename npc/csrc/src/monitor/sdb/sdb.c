#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
word_t vaddr_read(vaddr_t addr, int len);
word_t paddr_read(paddr_t addr, int len);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets(){
    static char *line_read = NULL;

    if(line_read){
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");

    if(line_read && *line_read){
        add_history(line_read);
    }

    return line_read;
}

static int cmd_c(char *args){
    cpu_exec(-1);
    return 0;
}

static int cmd_q(char *args){
    npc_state.state = NEMU_QUIT;
    return -1;
}

static int cmd_si(char *args){
    char *arg = strtok(args, " ");
    if(arg == NULL)
        return 1;
    int num = atoi(arg);
    cpu_exec(num);
    return 0;
}

static int cmd_info(char *args){
	char *arg = strtok(args," ");
	if(arg == NULL)
					printf("No args.\n");
	else if(strcmp(args,"r")==0)
					isa_reg_display();
	else if(strcmp(args,"w")==0)
					print_wp();
	return 0;
}
static int cmd_p(char *args){
		bool success = true;
		if (args == NULL){
			Log(ANSI_FG_RED"Loss parameter EXPR"ANSI_NONE);
			return 0;
		}
		word_t ans = expr(args, &success);
		if(success){
				Log(ANSI_FG_GREEN"Successfully evaluate the EXPR!"ANSI_NONE);
				Log(ANSI_FG_GREEN"EXPR: %s"ANSI_NONE, args);
				Log(ANSI_FG_GREEN"ANSWER:\n[Dec] unsigned: %u signed: %d\n[Hex]"FMT_WORD ANSI_NONE, ans, ans, ans);
		}
		else
				Log(ANSI_FG_RED"EXPR is illegal!"ANSI_NONE);
		return 0;
}
static int cmd_w(char *args){
		if(args==NULL)
						printf("No args!\n");
		WP* wp=new_wp(args);
		printf(ANSI_FG_GREEN"Set watchpoint %d:%s succefully!\n"ANSI_NONE,wp->NO,wp->exp);
		return 0;
}
static int cmd_d(char *args){
		if(args==NULL)
						printf("No args!\n");
		int pos;
		sscanf(args,"%d",&pos);
		bool f=true;
		WP* wp=delete_wp(pos,&f);
		if(f==false){
			printf(ANSI_FG_RED"Can`t find the Watchpoint!\n"ANSI_NONE);
			return 0;
		}
		free_wp(wp);
		printf(ANSI_FG_GREEN"Succefully delete!\n"ANSI_NONE);
		return 0;
}

static int cmd_help(char *args);

static int cmd_x(char* args) {
  char* N = strtok(NULL, " ");
  char* EXPR = strtok(NULL, " ");
  int num;
  bool success = true;
  vaddr_t addr;
  if (N == NULL || EXPR == NULL) {
      Log("Need two parameters N and EXPR");
      return 0;
  }
  sscanf(N, "%d", &num);
  // sscanf(EXPR, "%x", &addr);
  addr = expr(EXPR, &success);
  if(success) {
    for (int i = 0; i < num; i++) {
        word_t data = vaddr_read(addr + i * 4, 4);
        printf("addr: " FMT_PADDR, addr + i * 4);
        printf("\tdata: " FMT_WORD, data);
        printf("\n");
    }
  }
  else
    Log(ANSI_FG_RED"EXPR is illegal!"ANSI_NONE);
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },

  /* TODO: Add more commands */
	{ "si","单步执行", cmd_si },
	{"info","打印寄存器状态",cmd_info},
	{"x","扫描内存",cmd_x},
	{"p","单步执行",cmd_p},
	{"w","设置监视点",cmd_w},
	{"d","删除监视点",cmd_d}

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args){
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if(arg == NULL){
        /* no argument given*/
        for(i = 0; i < NR_CMD; i++){
            if(strcmp(arg, cmd_table[i].name) == 0){
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

void sdb_set_batch_mode(){
    is_batch_mode = true;
}

void sdb_mainloop(){
    if(is_batch_mode){
        cmd_c(NULL);
        return;
    }

    for(char *str; (str = rl_gets()) != NULL; ){
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if(cmd == NULL) {continue; }

        /* treat the remaining string as the argument,
         * which may need further parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if(args >= str_end){
            args = NULL;
        }
#ifdef CONFIG_DEVICE
        extern void sdl_clear_event_queue();
        sdl_clear_event_queue();
#endif /* ifdef CONFIG_DEVICE */

        int i;
        for(i = 0; i < NR_CMD; i++){
            if(strcmp(cmd, cmd_table[i].name) == 0){
                if(cmd_table[i].handler(args) < 0) {return; }
                break;
            }
        }

        if(i == NR_CMD) {printf("Unknown command '%s'\n", cmd);}
    }
}

void init_sdb(){
    /* Complie the regular expressions. */
    init_regex();

    /* Initialize the watchpoint pool. */
    init_wp_pool();
}
