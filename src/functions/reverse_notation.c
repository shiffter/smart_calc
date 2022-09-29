#include "../smart_calc.h"

int rpn(char *input, char *output) {
  node *stack = NULL;
  const char *stat_in = input;
  const char *stat_out = output;
  int len = strlen(input); // return value without '\0'

  if (len > 0) {
    int i = 0;
    for (i = 0; *input; i++, input++) {
            /* printf("IN   p1 %p, p2 %p\n", input, output); */
      /* printf("STAT p1 %p, p2 %p\n\n", stat_in, stat_out); */
            printf("%d) input %c  output %s\n", i, *input, stat_out);
            printf("\nnext iter\n");
          if (!is_empty(&stack)){
            printf("stack\n");
            print_stack(&stack);
 
          }
 
      int prio = get_prio(input, prio);
      if (prio == 0) {
        *output = *input;
        output++;
        continue;
      } else {

        int stack_prio = get_prio(&(stack->data), stack_prio);

        switch ((*input == 41) || (*input == 40)) {
        case 1:
          if (*input == 40){
             push(&stack, *input);
          }
           else {
            char tmp_sym = pop(&stack);
            while (tmp_sym != 40) {
              *output = tmp_sym;
              tmp_sym = pop(&stack);
              output++;
            }
          }
          break;
        case 0:
          if (is_empty(&stack) || (peek(stack) == 40)) {
            push(&stack, *input);
            continue;
          }


          if (stack_prio < prio) { // need while
            while (stack_prio < prio && !is_empty(&stack)) {
              *output = pop(&stack);
              output++;
              stack_prio = get_prio(&(stack->data), stack_prio);
            }
          }
          
          /* if (is_empty(&stack)){ */
          /*   push(&stack, *input); */
          /*   continue; */
          /* } */
            /* printf("prio after pop %d", stack_prio); */

          if (stack_prio == prio) {
            *output = pop(&stack);
            push(&stack, *input);
            output++;
            continue;
          }

          if (stack_prio > prio || stack_prio == -1) {
            push(&stack, *input);
          } break;
        }
      }
    }





    if (!is_empty(&stack)) {
      while (!is_empty(&stack)) {
        *output = pop(&stack);
        output++;
      }
      /* peek(stack); */
    }
  }
  return 0;
}

int get_prio(char *value, int prio) {
  if (value != NULL) {
    if (*value > 96 && *value < 123)
      prio = 0;
    else if (*value == 40 || *value == 41)
      prio = 1;
    else if (*value == 94)
      prio = 2;
    else if (*value == 42 || *value == 47)
      prio = 3;
    else if (*value == 43 || *value == 45)
      prio = 4;
  } else {
    prio = -1;
  }

  return prio;
}

int main(int argc, char *argv[]) {

  /* node* stack = NULL; */
  /* push(&stack, 107); */
  /* push(&stack, 108); */
  /* push(&stack, 109); */
  /* pop(&stack); */
  /* print_stack(&stack); */

  /* printf("%s\n", argv[1]); */
  char *input = "(a+b)*c+s/b^e";
  char *out = (char *)calloc(50, sizeof(char));
  rpn(input, out);

  printf("%s\n", out);
  free(out);

  return 0;
}

/* if(*input > 96 && *input < 123){ */
/*         *output = *input; */
/*         output++; */
/*         continue; */
/*       } */
/*       int prio_val = -1, stack_prio = -1; */
/*       switch(*input){ */
/*         case 40: */
/*           push(&stack, *input); */
/*           break; */
/*         case (43 || 45): */
/*           push(&stack, *input); */
/*           break; */
/*         case 41: */
/*           while (peek(stack) != 40){ */
/*             *output = pop(&stack); */
/*             printf("pop stack = %c\n", *output); */
/*             output++; */
/*           } */
/*           printf("last = %c\n", pop(&stack)); */
/*           break; */

/* token sym_and_prio[len]; */
/* int i = 0; */
/* for(i = 0; *input; input++, i++){         //input and output have the same
 * size */
/*   token* tmp = NULL; */
/*   tmp = (token*)malloc(sizeof(token)); */
/*   tmp->symbol = -1; */
/*   tmp->prio = -1; */
/*   get_prio(input, tmp); */
/*   /1* printf("sym %c, prio = %d\n", tmp->symbol, tmp->prio); *1/ */
/*   sym_and_prio[i] = *tmp; */
/*   free(tmp); */
/* } */
/*   for(int j = 0; j < i; j++){ */
/*     if (sym_and_prio[j].prio == 0) { */
/*       *output = sym_and_prio[j].symbol; */
/*       output++; */
/*       continue; */
/*     } else { */
/*       int prio_stack = -1; */

/*     } */

/*   } */

/* int check_stack_prio(node* stack, int prio_stack){ */
/*   if (stack != NULL) */
/*     prio_stack = stack->data.prio; */
/*   return prio_stack; */
/* } */

/* int compare_token(char string, char stack){ */

/* } */




/* debug string */
      /* printf("IN   p1 %p, p2 %p\n", input, output); */
      /* printf("STAT p1 %p, p2 %p\n\n", stat_in, stat_out); */
      /*       printf("%d) input %c  output %s\n", i, *input, stat_out); */
      /*       if (!is_empty(&stack)){ */
      /*         printf("\nstack: \n"); */
      /*         print_stack(&stack); */
      /*       } */
      /*       printf("\nnext iter\n"); */

