#include "../smart_calc.h"



int calc(char* input, double* res){
  int out = 0;
  func avail_func = init_functions(avail_func);
  queue* que = create_q();
  for (int i = 0; *input; i++, input++) {
    /* printf("input = %c\n", *input); */
    int prio = get_prio(input, prio);
    if (*input == 120){
      char* x = calloc(2, sizeof(char));
      *x = *input;
      push_q(que, x, prio);
      free(x);
      continue;
    } else if (*input > 47 && *input < 58) {
        size_t len_num = strspn(input, avail_func.numbers);
        /* printf("%ld\n", len_num); */
        char* number = calloc(len_num + 1, sizeof(char));
        strncpy(number, input, len_num);
        /* printf("len num %ld\t\t len %s\n", len_num, number); */
        if (len_num > 1)
          input += len_num-1;
        push_q(que, number, 0);            // thierd param can be get from get_prio
        free(number);
        /* printf("after! %
  print_Q(Q);c\n", *input); */
        continue;
    } else if (prio > 2 || prio == 1) {
      char* operator = calloc(2, sizeof(char));
      *operator = *input;
      push_q(que, operator, prio);
      free(operator);
      continue;
    } else if (prio == 2){
      char* functions = calloc(2, sizeof(char)); 
      int shift = math_keys(input, avail_func, functions);
      input += shift;
      push_q(que, functions, prio);
      free(functions);
      continue;
    }
  }

  /* print_Q(que); */

  queue* que_out = create_q();

  rpn(que, que_out);

  print_Q(que_out);

  printf("\n\n");
  calculate_value(que_out);



  /* queue is ready */






/*   node_q* tmp; */
/*   while(tmp = pop_q(que)) */
/*     free_node_q(tmp); */
/*   free(que); */
  



  /* printf(":op elem %s\t\t%p\n", que->tail->data, que->tail->data); */

  return 0;
}


int calculate_value(queue* rpn_q){
  node_s* stack = NULL;
  node_q* tmp_q = NULL;
  double result = 0.0;
  while(tmp_q = pop_q(rpn_q)){
    if(tmp_q->prio == 0){
      push_s(&stack, tmp_q);
      continue;
    } else if (tmp_q->prio == 3){
      if (*tmp_q->data == 94){
        printf("catch a bitch\n");
        node_q* tmp_s1 = pop_s(&stack);
        node_q* tmp_s2 = pop_s(&stack);
        node_q* res = create_node_q("8", 0);


        /* node_q res = {, 0, 0.0, NULL}; */
        double degree = atof(tmp_s1->data);
        double main = atof(tmp_s2->data);
        printf("degree %lf, main %lf", degree, main);
        printf("stack\n");
        print_stack(stack);

        res->result = pow(main, degree);
        res->prio = 0;
        push_s(&stack, res);
        printf("top stack %0.2lf\n", stack->data->result);
      }
      printf("top stack %0.2lf\n", stack->data->result);
    }
      
    }
  printf("stack\n");
  print_stack(stack);
  printf("%0.2lf", stack->data->result);

return 0;
}



int main(){
  
  /* char* in = "15-sin(12.34+(15*3*cos(24/12)))+13^2"; */
  
  char *in = "(2^3)^4";
  double res = 0.0;
  calc(in, &res);

  return 0;
}
