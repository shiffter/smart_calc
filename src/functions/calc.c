#include "../smart_calc.h"


int main(){
  /* char* in = "sin (13.68*cos(23.56 ^4))+cos(mod(22))*tan(35 * (12+13))"; */
  
  /* char* in = "-12 + (-15) * 14^(-3) + cos(-23) + sqrt(168)+ (12-cos(32*4^(-3)))"; */
  char* in = "3+5-6+21.35";
  char* out = calloc(strlen(in)+1, sizeof(char));
  char* out1 = calloc(100, sizeof(char));
  get_short_func(in, out);
  rpn(out, out1);
  printf("out %s|\n", out1);
  double res = 0;
  calc(out1, &res);
  free(out);
  free(out1);
  return 0;
}


double calc(char* input, double* res){
  node_s* stack = NULL;
  int in_prio = 10, st_prio = 10;
  char* numbers = "0123456789.";
  for (; *input; input++){
    if(*input == ' ') continue;
    in_prio = get_prio(input, in_prio);
    printf("in %c, prio = %d\n", *input, in_prio);
    if (in_prio == 0){
      size_t len = strspn(input, numbers);
      char* tmp_num = calloc(len, sizeof(char));
      strncat(tmp_num, input, len);
      /* double num = atof(tmp_num); */
      push_s(&stack, 'Z', atof(tmp_num));
      input += len;
      free(tmp_num);
    } else if (in_prio == 5){
      double tmp_1 = stack->prio;
      pop_s(&stack);
      double tmp_2 = stack->prio;
      pop_s(&stack);
      double res = 0;
      if (*input == '+') res = tmp_1 + tmp_2;
      else res = tmp_2 - tmp_1;
      printf("res %lf\n", res);
      push_s(&stack, 'X', res);
    }
  }

  printf("res = %lf\n", stack->prio);
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

  for(; *input && find_ch && !res; input++, out++){
    if (*input == ' ') { out--; continue; }
    /* printf("char %c\n", (*input)); */
    find_ch = strchr(avail_func.all_sym, *input);
    if (find_ch == NULL) { printf("syntax error\n"); res = 1; break; }
    if(*input >= 'a' && *input <= 'z' && *input != 'x'){ math_keys(&input, avail_func, out); }
    else if (*input >= 0 && *input <= 9) { copy_number(&input, &out); }
    else { *out = *input; }
  }
  return res;
}


int copy_number(char** input, char** out){
  int res = 0;
  char* numbers = "0123456789.";
  size_t len_num = strspn(*input, numbers);
  /* char *number = calloc(len_num + 1, sizeof(char)); */
  if (len_num > 0){
    strncat(*out, *input, len_num);
    if (len_num > 1) {
      *input += len_num - 1;
    }
    *out += len_num;

  }
  /* free(number)k */


}


int math_keys(char** input, func functions, char *out) {

  if (**input == 's') {
    if      (!strncmp(*input, functions.s, 3)) { *out = 's'; *input += 2; }
    else if (!strncmp(*input, functions.R, 4)) { *out = 'R'; *input += 3; }
  } else if (**input == 'a') {
    if (!strncmp(*input, functions.S, 4)) *out = 'S'; 
    else if (!strncmp(*input, functions.C, 4)) *out = 'C'; 
    else if (!strncmp(*input, functions.T, 4)) *out = 'T'; 
    *input += 3;
  } else if (**input == 'c' && !strncmp(*input, functions.c, 3)) { *out = 'c'; *input += 2; }
    else if (**input == 't' && !strncmp(*input, functions.t, 3)) { *out = 't'; *input += 2; }
    else if (**input == 'l') {
      if (!strncmp(*input, functions.l, 2)) { *out = 'l'; *input += 1; }
      if (!strncmp(*input, functions.L, 3)) { *out = 'L'; *input += 2; }
  } else if (**input == 'm') {
    if (!strncmp(*input, functions.m, 3)) { *out = 'm'; *input += 2; }
  /* } else if (*input == 43) { *out = 80; *input += 0; } else if (*input == 45) { *out = 77; return 0;  } */
  }
  return 0;
}



int get_prio(char *value, int prio) {
  if (value != NULL) {
    if      (*value >= '0' && *value <= '9' || *value == 'x')  prio = 0;
    else if (*value == '(' || *value == ')')  prio = 1;
    else if ((*value >= 'a' && *value <= 'z') || (*value >= 'A' && *value <= 'Z')) {
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
  functions.all_sym = "1234567890+-*/.^()asScCtTlLRmMPx ";
  functions.first_chars = "sactlm";
  return functions;
}
