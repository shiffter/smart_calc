#include "../smart_calc.h"

int rpn(char* input, struct_str* str_str) {
  int out = 0;

  if (input != NULL) {

    node *stack = NULL;
    int len = strlen(input); // return value without '\0'
    str_str->output = calloc(100, sizeof(char));
    str_str->len = len;
    if (str_str->output != NULL) {
      int i = 0;
      for (i = 0; *input; i++, input++) {

        /* printf("IN   p1 %p, p2 %p\n", input, str_str->output); */
        /* printf("\nnext iter\n"); */
        /* printf("%d) input %c str_str->output %s\n", i, *input, stat_out); */
        /* if (!is_empty(&stack)) { */
        /*   printf("stack\n"); */
        /*   print_stack(&stack); */
        /* } */

        int prio = get_prio(input, prio);
        /* printf("in prio %d\n", prio); */
        if (prio == 0) {
          *str_str->output = *input;
          str_str->output++;
          continue;
        } else {

          int stack_prio = get_prio(&(stack->data), stack_prio);
          /* printf("stack prio %d\n", stack_prio); */

          switch ((*input == 41) || (*input == 40)) {
          case 1:
            str_str->len--;
            if (*input == 40) {
              push(&stack, *input);
            } else {
              char tmp_sym = pop(&stack);
              while (tmp_sym != 40) {
                *str_str->output = tmp_sym;
                tmp_sym = pop(&stack);
                str_str->output++;
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
                *str_str->output = pop(&stack);
                str_str->output++;
                stack_prio = get_prio(&(stack->data), stack_prio);
              }
            }

            /* if (is_empty(&stack)){ */
            /*   push(&stack, *input); */
            /*   continue; */
            /* } */
            /* printf("prio after pop %d", stack_prio); */

            if (stack_prio == prio) {
              *str_str->output = pop(&stack);
              push(&stack, *input);
              str_str->output++;
              continue;
            }

            if (stack_prio > prio || stack_prio == -1) {
              push(&stack, *input);
              continue;
            }
          }
        }

        /* printf("end iter\n"); */
        /* if (!is_empty(&stack)) */
        /* print_stack(&stack); */

      } /*   printf("LST %c\n", pop(&stack)); */

      if (!is_empty(&stack)) {
        while (!is_empty(&stack)) {
          *str_str->output = pop(&stack);
          str_str->output++;
        }
        /* peek(stack); */
      }
    }
  
  str_str->output -= str_str->len;
  } else {
      out = 1;
    }
    return out;
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

/* int main(int argc, char *argv[]) { */

/*   /1* node* stack = NULL; *1/ */
/*   /1* push(&stack, 107); *1/ */
/*   /1* push(&stack, 108); *1/ */
/*   /1* push(&stack, 109); *1/ */
/*   /1* pop(&stack); *1/ */
/*   /1* print_stack(&stack); *1/ */

/*   /1* printf("%s\n", argv[1]); *1/ */
/*   char* input = "(a+b*(s-d)^x)/(z-x)+w*x"; */
/*   char* result = "absd-x^*+zx-/wx*+"; */
/*   struct_str* out; */
/*   /1* char* out = NULL; *1/ */
/*   /1* char *out = (char *)calloc(50, sizeof(char)); *1/ */
/*   out = calloc(1 ,sizeof(struct_str)); */
/*   /1* printf("before %p \n", out); *1/ */
/*   rpn(input, out); */
/*   /1* printf("after %p \n", out); *1/ */
  
/*   printf("%s\n", input); */
/*   printf("my    %s\n%d\n", out->output, out->len); */
/*   printf("right %s\n", result); */
/*   if(out->output != NULL) */
/*     free(out->output); */
/*   free(out); */
/*   return 0; */
/* } */

/* if(*input > 96 && *input < 123){ */
/*         *str_str->output = *input; */
/*         str_str->output++; */
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
/*             *str_str->output = pop(&stack); */
/*             printf("pop stack = %c\n", *str_str->output); */
/*             str_str->output++; */
/*           } */
/*           printf("last = %c\n", pop(&stack)); */
/*           break; */

/* token sym_and_prio[len]; */
/* int i = 0; */
/* for(i = 0; *input; input++, i++){         //input and str_str->output have the same
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
/*       *str_str->output = sym_and_prio[j].symbol; */
/*       str_str->output++; */
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
/* printf("IN   p1 %p, p2 %p\n", input, str_str->output); */
/* printf("STAT p1 %p, p2 %p\n\n", stat_in, stat_out); */
/*       printf("%d) input %c  str_str->output %s\n", i, *input, stat_out); */
/*       if (!is_empty(&stack)){ */
/*         printf("\nstack: \n"); */
/*         print_stack(&stack); */
/*       } */
/*       printf("\nnext iter\n"); */
