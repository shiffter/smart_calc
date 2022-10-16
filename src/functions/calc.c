#include "../smart_calc.h"


int main(){
  char* in = "asin(x)*cos(x^2)";
  char out[100] = {0};
  get_short_func(in, out);
  printf("%s", out);
  return 0;
}


double calc(char* input, double* res){
     
  return *res;
}


int valid_str(char* input){
  int out = 0;
  out = pair_paren(input);
  return out;
}


int pair_paren(char* input){
  int out = 0, paren = 0;
  char* start_str = input;
  while(*input){
    if(*input == '(') paren++;
    else if (*input == ')') paren--;
    input++;
  }
  if (!paren){
    printf("Watch a pair parentheses\n");
    out = -1;
  }
  return out;
}


int get_short_func(char* input, char* out){
  int res = 0;
  char ch = *input;
  const void* find_ch = input;
  

  if (!input || !out) res = 1;

  func avail_func = init_functions(avail_func);

  for(; *input && find_ch; input++, out++){
    find_ch = strchr(avail_func.all_sym, *input);
    if (find_ch == NULL) { printf("syntax error\n"); break; }
    if(*input >= 'a' && *input <= 'z' && *input != 'x'){ math_keys(&input, avail_func, out); }
    else if (*input >= 0 && *input <= 9) { copy_number(&input, out); }
    else { *out = *input; }
  }
  return res;
}


int copy_number(char** input, char* out){
  int res = 0;
  char* numbers = "0123456789.";
  size_t len_num = strspn(*input, numbers);
  /* char *number = calloc(len_num + 1, sizeof(char)); */
  if (len_num > 0){
    strncat(out, *input, len_num);
    if (len_num > 1) *input += len_num - 1; 
  }
  /* free(number)k */


}


int math_keys(char** start, func functions, char *out) {

  if (**start == 's') {
    if      (!strncmp(*start, functions.s, 3)) { *out = 's'; *start += 2; }
    else if (!strncmp(*start, functions.R, 4)) { *out = 'R'; *start += 3; }
  } else if (**start == 'a') {
    if (!strncmp(*start, functions.S, 4)) *out = 'S'; 
    else if (!strncmp(*start, functions.C, 4)) *out = 'C'; 
    else if (!strncmp(*start, functions.T, 4)) *out = 'T'; 
    *start += 3;
  } else if (**start == 'c' && !strncmp(*start, functions.c, 3)) { *out = 'c'; *start += 2; }
    else if (**start == 't' && !strncmp(*start, functions.t, 3)) { *out = 't'; *start += 2; }
    else if (**start == 'l') {
      if (!strncmp(*start, functions.l, 2)) { *out = 'l'; *start += 1; }
      if (!strncmp(*start, functions.L, 3)) { *out = 'L'; *start += 2; }
  } else if (**start == 'm') {
    if (!strncmp(*start, functions.m, 3)) { *out = 'm'; *start += 2; }
  /* } else if (*start == 43) { *out = 80; *start += 0; } else if (*start == 45) { *out = 77; return 0;  } */
  }
  return 0;
}



int get_prio(char *value, int prio) {
  if (value != NULL) {
    if      (*value >= '0' && *value <= '9')  prio = 0;
    else if (*value == '(' || *value == ')')  prio = 1;
    else if (*value >= 'a' && *value <= 'z') {
      if (*value == 'm' && *++value == 'o')   prio = 4;
      else                                    prio = 2;
    } else if (*value == '^')                 prio = 3;
    else if (*value == '/' || *value == '*')    prio = 4;
    else if (*value == '+' || *value == '-')    prio = 5;
  } else { prio = -1; }
  return prio;
}





func init_functions(func functions) {
  functions.s = "sin";
  functions.S = "asin";
  functions.c = "cos";
  functions.C = "acos";
  functions.t = "tan";
  functions.T = "atan";
  functions.l = "ln";
  functions.L = "log";
  functions.R = "sqrt";
  functions.numbers = "1234567890.";
  functions.m = "mod";
  functions.M = "-";
  functions.P = "+";
  functions.all_sym = "1234567890+-*/.^()asScCtTlLRmMPx";
  functions.first_chars = "sactlm";
  return functions;
}
