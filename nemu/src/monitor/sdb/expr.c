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

enum {
  TK_NOTYPE = 256, TK_EQ = 255, TK_NEQ = 254, TK_NUM = 253, TK_HEXNUM = 252

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
	{"[0-9]+",TK_NUM},						//num
	{"0x[0-9,a-f]+",TK_HEXNUM},		//hexnum
	{"\\(",'('},							//left parenthesis
	{"\\)",')'},							//right parenthesis
	{"\\*",'*'},							//multiply
	{"\\/",'/'},							//divice
	{"\\-",'-'}								//minus
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

        switch (rules[i].token_type) {
								case 256:break;
								case 43:					//ascii num of +
													tokens[nr_token].type=43;break;
								case 255:
													tokens[nr_token].type=255;break;
								case 254:
													tokens[nr_token].type=254;break;
								case 253:
													tokens[nr_token].type=253;
													strncpy(tokens[nr_token].str,substr_start,substr_len);		//用strncpy函数将数字复制到tokens数组中
													break;
								case 252:					
													tokens[nr_token].type=252;
													strncpy(tokens[nr_token].str,substr_start,substr_len);
								case 45:			//ascii num of -
													tokens[nr_token].type=45;
								case 42:			//ascii num of *
													tokens[nr_token].type=42;
								case 47:			//ascii num of /
													tokens[nr_token].type=47;
								case 40:			//ascii num of (
													tokens[nr_token].type=40;
								case 41:			//ascii num of )
													tokens[nr_token].type=41;
          default: break;
        }
        break;
      }
				if(rules[i].token_type != 256)
								nr_token++;
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  TODO();

  return 0;
}
