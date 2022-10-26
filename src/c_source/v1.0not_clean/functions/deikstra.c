#include "../smart_calc.h"


int rpn(char* input, char* out){
  int res = 0, in_prio = 10, st_prio = 10;
  node_s* stack = NULL;
  char* start = out;
  for(; *input; input++){
    if (*input == ' ') continue;
    /* sleep(0.5); */
    /* print_ss(stack); */
    /* printf("%s\n", start); */
    in_prio = get_prio(input, in_prio);
    printf("input %c ptio %d \n",*input, in_prio);
    /* *out++ = '|'; */
    /* printf("input %c, %d \n", *input, in_prio); */
    if (in_prio == 0 || *input == 'x'){
      if(*input == 'x') { *out = *input; out++; }
      /* else if(*input == 'P') push_s(&stack, 'P', 0); */
      else { copy_number(&input, &out); *out++ = ' ';}
      
    }
    /* else if (in_prio == 1) *out++ = 'M'; */
      /* push_s(&stack, 'M', 0); */
    else if (in_prio == 1){
      printf("stack_bracket\n");
      print_ss(stack);
      if (*input == '(')
        push_s(&stack, *input, 0);
      else {
        char tmp = pop_s(&stack);
        while (tmp != '('){
          /* printf("loop ing\n"); */
          /* sleep(1); */
          *out++ = tmp;
          *out++ = ' ';
          tmp = pop_s(&stack);
          /* out++; */
        }
      }
    } else {
        printf("stack2\n");
        print_ss(stack);
        /* printf("case 3\n"); */
        if (!is_empty(&stack) && (stack->data == '(')) push_s(&stack, *input, 0);
        else if(!is_empty(&stack) && stack->data == '^' && *input == '^') push_s(&stack, *input, 0);
        else if (is_empty(&stack)) push_s(&stack, *input, 0);
        else {
          st_prio = get_prio(&(stack->data), st_prio);
          if(st_prio <= in_prio ){
            while(st_prio <= in_prio && !is_empty(&stack)) {
              if (stack->data == '(') break;
              char tmp = pop_s(&stack);
              *out++ = tmp;
              *out++ = ' ';
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
    *out++ = pop_s(&stack);
    *out++ = ' '; 
  }
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

