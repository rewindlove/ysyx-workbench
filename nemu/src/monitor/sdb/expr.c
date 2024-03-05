/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <stdlib.h>

enum {
  TK_NOTYPE = 256, TK_EQ = 255, TK_NEQ = 254, TK_NUM = 253, TK_HEXNUM = 252,TK_MINUS=251

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    		// spaces
  {"\\+", '+'},         		// plus
  {"==", TK_EQ},        				// equal
	{"!=",TK_NEQ},										//not equal
	{"\\b[0-9]+\\b",TK_NUM},						//num
	{"0x[0-9,a-f]+",TK_HEXNUM},		//hexnum
	{"\\(",'('},							//left parenthesis
	{"\\)",')'},							//right parenthesis
	{"\\*",'*'},							//multiply
	{"\\/",'/'},							//divice
	{"\\-",'-'},							//minus
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
				Token tmp_token;
        switch (rules[i].token_type) {
								case 256:break;
								case '+': 
													tmp_token.type ='+';				 
													tokens[nr_token++]=tmp_token
													;break;
								case 255:
													tokens[nr_token].type=255;
													strcpy(tokens[nr_token].str, "==");
													nr_token++;
													break;
								case 254:
													tokens[nr_token].type=254;
													strcpy(tokens[nr_token].str, "!=");
													nr_token++;
													break;
								case 253:
													tokens[nr_token].type=253;
													strncpy(tokens[nr_token].str,&e[position - substr_len],substr_len);		//用strncpy函数将数字复制到tokens数组中
													nr_token++;
													break;
								case 252:					
													tokens[nr_token].type=252;
													strncpy(tokens[nr_token].str,&e[position - substr_len],substr_len);		//用strncpy函数将数字复制到tokens数组中
													nr_token++;
													break;
								case '-':			
													tmp_token.type ='-';				 
													tokens[nr_token++]=tmp_token;
													break;
								case '*':			//ascii num of *
													tmp_token.type ='*';				 
													tokens[nr_token++]=tmp_token;
													break;
								case '/':
													tmp_token.type ='/';				 
													tokens[nr_token++]=tmp_token;
													break;
								case '(':
													tmp_token.type ='(';				 
													tokens[nr_token++]=tmp_token;
													break;
								case ')':
													tmp_token.type =')';				 
													tokens[nr_token++]=tmp_token;
													break;
          default:
													printf("No rules!\n");
													break;
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

	static bool check_parentheses(int p,int q){
		int i,cnt=0;
		if(tokens[p].type!='('||tokens[q].type!=')')		//首尾没有括号
						return false;
		for(i=p;i<=q;i++){
			if(tokens[i].type=='(')
							cnt++;
			else if(tokens[i].type==')')
							cnt--;
			if(cnt==0&&i<q)		//左右括号数相等，括号匹配
							return true;
		}
		if(cnt<0)
						return false;
		return true;
	}
	int dominant_operator(int p,int q){
			int i;
			int pos=1;
			int pri=0;
			int pare=0;
			for(i=q;i>=1;i--){
					if(tokens[i].type == ')') pare++;
					if(tokens[i].type == '(') pare--;
					if(pare!=0) continue;
					switch(tokens[i].type){
									case'+':{
														if(pri<4){
																pos=i;
																pri=4;
														}
														break;
													}
									case'-':{
														if(pri<4){
																pos=i;
																pri=4;
														}
														break;
													}
									case'*':{
														if(pri<3){
																pos=i;
																pri=3;
														}
														break;
													}
									case'/':{
														if(pri<3){
																pos=i;
																pri=3;
														}
														break;
													}
									case TK_EQ:{
														if(pri<7){
																pos=i;
																pri=7;
														}
														break;
													}
									case TK_NEQ:{
														if(pri<2){
																pos=i;
																pri=2;
														}
														break;
													}
									case TK_MINUS:{
														if(pri<2){
																pos=i;
																pri=2;
														}
														break;
													}
									default:break;
					}

			}
			if(pri==0) return 0;
			if(pri==2){
					pri=0;
					for(i=p;i<=q;i++){
						if(tokens[i].type == ')') pare++;
						if(tokens[i].type == '(') pare--;
						if(pare!=0) continue;
						switch(tokens[i].type){
									case TK_MINUS:{
														if(pri<4){
																pos=i;
																pri=2;
														}
														break;
													}
					}
			}
	}
			return pos;
}
  /* TODO: Insert codes to evaluate the expression. */
  uint32_t eval(int p,int q){
					if(p>q){
						assert(0);
						return -1;
					}
					else if(p==q){
									uint32_t num;
										num=atoi(tokens[p].str);
						return num;
					}
					else if(check_parentheses(p,q)==true){
						return eval(p+1,q-1);
					}
					else{
						int op=-1;
						op=dominant_operator(p,q);
						int op_type=tokens[op].type;
						if(p==op||tokens[op].type==TK_MINUS){
								uint32_t ans1=eval(op+1,q);
								switch(tokens[op].type)
										case TK_MINUS:return -ans1;
						}
						uint32_t val1,val2;
						val1=eval(p,op-1);
						val2=eval(op+1,q);
						switch(op_type){
										case '+':return val1+val2;
										case '-':return val1-val2;
										case '*':return val1*val2;
										case '/':{
																	if(val2==0){
														 			printf("除数不能为0\n");
																	assert(0);
														 		}
																	else return val1/val2;
														 }
										default:printf("no op type!\n");
														assert(0);
													}
					}
	}

uint32_t expr(char *e, bool *success) {
  if (!make_token(e)){
    *success = false;
    return 0;
  }
	int i,brack = 0;
	for(i=0;i<nr_token;i++){
			if(tokens[i].type == '(') brack++;
			if(tokens[i].type == ')') brack--;
			if(brack<0){
				*success = false;
				return 0;
			}
			if(tokens[i].type == '-'&&(i == 0||(tokens[i-1].type!=')'&&tokens[i-1].type!=TK_NUM&&tokens[i-1].type!=TK_HEXNUM)))
							tokens[i].type = TK_MINUS;
	}
	if(brack!=0){
		*success = false;
		return 0;
	}
	*success=true;
	uint32_t sum1=0;
	sum1=eval(0,nr_token-1);
	return sum1;
}
