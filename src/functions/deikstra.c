#include "../smart_calc.h"


int rpn(char* input, char* out){
  int res = 0, in_prio = 10, st_prio = 10;
  node_s* stack = NULL;
  char* start = out;
  for(; *input; input++){
    printf("ss %s\n %s", start, input);
    sleep(1);
    in_prio = get_prio(input, in_prio); 
    if (in_prio == 0 || *input == 'x'){
      if(*input == 'x') { *out = *input; out++; }
      else { copy_number(&input, out); }
    }
    else if (in_prio == 1){
      if (*input == '(')
        push_s(&stack, *input, 0);
      else {
        char tmp = pop_s(&stack);
        while (tmp != ')'){
          *out = tmp;
          tmp = pop_s(&stack);
          out++;
        }
      }
    } else {
        if (is_empty(&stack)) push_s(&stack, *input, 0);

        else {
          st_prio = get_prio(&(stack->data), st_prio);
          if(st_prio <= in_prio ){
            while(st_prio <= in_prio && !is_empty(&stack)) {
              char tmp = pop_s(&stack);
              *out = tmp;
              out++;
              st_prio = get_prio(&(stack->data), st_prio);
            }
          push_s(&stack, *input, 0);
          } else if (st_prio > in_prio){
            push_s(&stack, *input, 0);
          }
      }

    }
  }
  while(!is_empty(&stack)){
    *out = pop_s(&stack);
    out++;
  }
  printf("out = %s\n", out);
return res; 
}



/* int get_prio(char *value, int prio) { */
/*   if (value != NULL) { */

/*     if (*value >= '0' && *value <= '9') */
/*       prio = 0; */
/*     else if (*value == ')' || *value == '(') */
/*       prio = 1; */
/*     else if (*value >= 'a' && *value <= 'z') { */
/*       if (*value == 'm' && *++value == '0') prio = 4; */
/*       else prio = 2; */
/*     } else if (*value == '^') */
/*       prio = 3; */
/*     else if (*value == '/' || *value == '*') */
/*       prio = 4; */
/*     else if (*value == '+' || *value == '-') */
/*       prio = 5; */
/*   } else { */
/*     prio = -1; */
/*   } */
/*   return prio; */
/* } */

