#include "../smart_calc.h"

/* int main() { */
/*   /1* char* in = "sin (13.68*cos(23.56 ^4))+cos(5 mod(22))*tan(35 * (12+13))"; *1/ */

/*   /1* char* in = "-12 + (-15) * 14^(-3) + cos(-23) + sqrt(168)+ */
/*    * (12-cos(32*4^(-3)))"; *1/ */
/*   /1* char* in = "sin(20.32)*12.36^4 +(cos(tan(35.4)))+(-sqrt(153.3)) * 2^45 + */
/*    * 2^3"; *1/ */
/*   /1* char *in = "2^3^(-4+2^3)"; *1/ */
/*   char* in = "2+3+4"; */
/*   char *out = calloc(strlen(in) + 1, sizeof(char)); */
/*   char *out1 = calloc(100, sizeof(char)); */
/*   get_short_func(in, out); */
/*   find_unary(out); */

/*   printf("out %s|\n", out); */
/*   rpn(out, out1); */

/*   printf("out1 %s|\n", out1); */
/*   double res = 0; */
/*   calc(out1, &res); */
/*   free(out); */
/*   free(out1); */
/*   return 0; */
/* } */

double calc(char *input, double *res, x_x* x_info) {
  node_s *stack = NULL;
  int in_prio = 10, st_prio = 10;
  char *numbers = "0123456789.";
  /* printf("%s\n", input); */
  
  /* for (int i = 0; *input; input++, i++) printf("%c", *input); */

  for (int i = 0; *input; input++, i++) {
    /* printf("input for start %c\n", *input); */

  /* printf("in %c\n", *input); */
  /* printf("in %p\n", input); */
    if (*input == ' ')
      continue;
    in_prio = get_prio(input, in_prio);
    /* printf("input %c prio %d \n",*input, in_prio); */
    if (in_prio == 0) {
      if(*input == 'x'){
          push_s(&stack, 'Z', x_info->start);
      } else {
      size_t len = strspn(input, numbers);
      char *tmp_num = calloc(len, sizeof(char));
      /* printf("len number %ld\n", len); */
      strncat(tmp_num, input, len);
      push_s(&stack, 'Z', atof(tmp_num));
      input += len;
      /* printf("input at end %c\n", *input); */
      free(tmp_num);
      }
    } else if (in_prio == 6) {
      if (*input == 'P' || *input == 'M') {
        double tmp = stack->prio;
        pop_s(&stack);
        if (*input == 'P')
          push_s(&stack, 'Z', tmp);
        else
          push_s(&stack, 'Z', (-tmp));
      } else {
        double tmp_1 = stack->prio;
        pop_s(&stack);
        double tmp_2 = stack->prio;
        pop_s(&stack);
        double tmp_res = 0;
        if (*input == '+')
          tmp_res = tmp_1 + tmp_2;
        else
          tmp_res = tmp_2 - tmp_1;
        push_s(&stack, 'X', tmp_res);
      }
    } else if (in_prio == 5 || in_prio == 4) {
      double tmp_1 = stack->prio;
      pop_s(&stack);
      double tmp_2 = stack->prio;
      pop_s(&stack);
      if (*input == 'm')
        push_s(&stack, 'Z', fmod(tmp_2, tmp_1));
      else if (*input == '*')
        push_s(&stack, 'Z', tmp_1 * tmp_2);
      else if (*input == '/')
        push_s(&stack, 'Z', tmp_2 / tmp_1);
      else if (*input == '^')
        push_s(&stack, 'Z', pow(tmp_2, tmp_1));
    } else if (in_prio == 3) {
      double tmp = stack->prio;
      pop_s(&stack);
      if (*input == 's')
        push_s(&stack, 'Z', sin(tmp));
      else if (*input == 'S')
        push_s(&stack, 'Z', asin(tmp));
      else if (*input == 'c')
        push_s(&stack, 'Z', cos(tmp));
      else if (*input == 'C')
        push_s(&stack, 'Z', acos(tmp));
      else if (*input == 't')
        push_s(&stack, 'Z', tan(tmp));
      else if (*input == 'T')
        push_s(&stack, 'Z', atan(tmp));
      else if (*input == 'l')
        push_s(&stack, 'Z', log(tmp));
      else if (*input == 'L')
        push_s(&stack, 'Z', log10(tmp));
      else if (*input == 'R') {
        if (tmp < 0) {
          printf("try get root from negative number");
          break;
        } else
          push_s(&stack, 'Z', sqrt(tmp));
      }
    }
  }
  *res = stack->prio;
  /* printf("res =%lf\n", *res); */
  return *res;
}

int valid_str(char *input) {
  int out = 0;
  out = pair_paren(input);
  return out;
}

int pair_paren(char *input) {
  int out = 0, paren = 1;
  char *start_str = input;
  while (*input) {
    /* printf("%c prio %d \n", *input, get_prio(input, 0)); */
    if (*input == '(')
      paren++;
    else if (*input == ')')
      paren--;
    input++;
  }
  if (paren != 1) {
    printf("Watch a pair parentheses\n");
    out = -1;
  }
  return out;
}

void find_unary(char *input) {
  char *next = ++input;
  --input;
  int count = 0;
  for (; *next; input++, next++) {
    if (count == 0 && (get_prio(input, 0) == 6))
      *input = (*input == 'M') ? 'M' : 'P';
    else if (*next == '+' || *next == '-')
      if (get_prio(input, 0) > 1 || *input == '(')
        *next = (*next == '+') ? 'P' : 'M';
    count++;
  }
}


int check_expr(char* input){
  int res = 0;
  res = valid_str(input);
  for(int i = 0; input[i] && !res; i++){
    if (i == 0 && get_prio(input, 0) > 3){
      if (*input == 'M' || *input == 'P' || *input == 'm')
        continue;
      else
        res = 1;
    }
    else if (input[i] == '.'){
      if (i == 0) res = 1;
      else if (input[i-1] == '.' || input[i+1] == '.') res = 1;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
      if (input[i] == 'M' || input[i] == 'P') continue;
      if (input[i+1] != '(') res = 1;
    } else if (get_prio(input+i, 0) > 1){
      if ((input+i+1) != NULL){
        if (get_prio(input+i+1, 0) > 3) res = 1;
      } 
    } 

   }
  return res;
}



int get_short_func(char *input, char *out) {
  int res = 0;
  char ch = *input;
  const void *find_ch = input;
  if (!input || !out)
    res = 1;
  func avail_func = init_functions(avail_func);
  for (; *input && find_ch && !res; input++, out++) {
    if (*input == ' ') {
      out--;
      continue;
    }
    find_ch = strchr(avail_func.all_sym, *input);
    if (find_ch == NULL) {
      printf("syntax error\n");
      res = 1;
      break;
    }
    if (*input >= 'a' && *input <= 'z' && *input != 'x') {
      math_keys(&input, avail_func, out);
    } else if (*input >= 0 && *input <= 9) {
      copy_number(&input, &out);
    } else {
      *out = *input;
    }
  }
  return res;
}

int copy_number(char **input, char **out) {
  int res = 0;
  char *numbers = "0123456789.";
  size_t len_num = strspn(*input, numbers);
  char check_number[40] = {0};
  /* char *number = calloc(len_num + 1, sizeof(char)); */
  if (len_num > 0) {
    strncat(*out, *input, len_num);
    if (len_num > 1) {
      *input += len_num - 1;
    }
    *out += len_num;
  }
  /* free(number)k */
  return res;
}

int math_keys(char **input, func functions, char *out) {

  if (**input == 's') {
    if (!strncmp(*input, functions.s, 3)) {
      *out = 's';
      *input += 2;
    } else if (!strncmp(*input, functions.R, 4)) {
      *out = 'R';
      *input += 3;
    }
  } else if (**input == 'a') {
    if (!strncmp(*input, functions.S, 4))
      *out = 'S';
    else if (!strncmp(*input, functions.C, 4))
      *out = 'C';
    else if (!strncmp(*input, functions.T, 4))
      *out = 'T';
    *input += 3;
  } else if (**input == 'c' && !strncmp(*input, functions.c, 3)) {
    *out = 'c';
    *input += 2;
  } else if (**input == 't' && !strncmp(*input, functions.t, 3)) {
    *out = 't';
    *input += 2;
  } else if (**input == 'l') {
    if (!strncmp(*input, functions.l, 2)) {
      *out = 'l';
      *input += 1;
    }
    if (!strncmp(*input, functions.L, 3)) {
      *out = 'L';
      *input += 2;
    }
  } else if (**input == 'm') {
    if (!strncmp(*input, functions.m, 3)) {
      *out = 'm';
      *input += 2;
    }
  }
  return 0;
}

int get_prio(char *value, int prio) {
  if (value != NULL) {
    if (*value == 'x' || *value >= '0' && *value <= '9')
      prio = 0;
    else if (*value == '(' || *value == ')')
      prio = 1;

    else if ((*value >= 'a' && *value <= 'z') ||
             (*value >= 'A' && *value <= 'Z')) {
      if (*value == 'm')
        prio = 5;
      else if (*value == 'M' || *value == 'P')
        prio = 6;
      else
        prio = 3;

    } else if (*value == '^')
      prio = 4;
    else if (*value == '/' || *value == '*')
      prio = 5;
    else if (*value == '+' || *value == '-')
      prio = 6;
  } else {
    prio = -1;
  }
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
