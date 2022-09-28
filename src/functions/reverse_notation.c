#include "s21_calc.h"


int alg(char* input, char* output){
  node* stack = NULL;
  /* char sym = 43; */

  /* push(&stack, sym); */
  int len = strlen(input);          //return value without '\0'
  if (len > 0){
    int i = 0;
    for(i = 0; *input; i++, input++){
      int prio = get_prio(input, prio);
      if (prio == 0){
        *output = *input;
        output++;
        continue;
      } else {
        if (is_empty(&stack) && i != len){
          push(&stack, *input);
          continue;
        }
        if(!is_empty(&stack))
          print_stack(&stack); 
        int stack_prio = get_prio(&(stack->data), stack_prio);
        /* printf("iter %d\n", i); */
        /* printf("stack_val = %c, stack_prio %d\n", stack->data, stack_prio); */
        /* printf("input val = %c, prio %d\n", *input, prio); */

        /* printf("stack_ prio %d\n", stack_prio); */
        if (stack_prio == prio){
          *output = pop(&stack);
          push(&stack, *input);
          output++;
          continue;
        }

        if (stack_prio > prio){
          push(&stack, *input);
          continue;
        }

        if (stack_prio < prio){           //need while
          *output = pop(&stack);
          push(&stack, *input);
          output++;
          continue;
        }
           
          
      }
      if (i == len && !is_empty(&stack))
        while (!is_empty(&stack))
          *output++ = pop(&stack);
        

    } 
      }
  return 0;
}



int get_prio(char* value, int prio){
  if (value != NULL){
    if (*value > 96 && *value < 123)
      prio = 0;
    else if (*value == 40 || *value == 41)
      prio = 1;
    else if (*value == 94)
      prio = 2;
    else if (*value == 42 || *value == 92)
      prio = 3;
    else if (*value == 43 || *value == 45)
      prio = 4;
  } else {  prio = -1; }

  return prio ;
}




int main(int argc, char* argv[]) {

  node* stack = NULL;
  push(&stack, 107);
  push(&stack, 108);
  push(&stack, 109);
  printf("pointer before %p\n", &stack);
  print_stack(&stack);
  printf("pointer after %p\n", &stack);

  /* printf("%s\n", argv[1]); */
  /* char out[50] = {'\0'}; */
  /* alg(argv[1], out); */
  /* printf("%s\n", out); */
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
    /* for(i = 0; *input; input++, i++){         //input and output have the same size */
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


