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
        /* que->head->result = atof(number); */
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
  /* printf("last %s\n", que_out->tail->data); */

  print_Q(que_out);

  printf("\nque end\n");
  calculate_value(que_out);

  /* print_Q(que_ut); */


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
      stack->data->result = atof(stack->data->data);
      continue;
    }else if (tmp_q->prio == 2){
      node_q* func = pop_s(&stack);
      node_q* res_q = create_node_q("func calc", 0);
      if (*tmp_q->data == 115)
        res_q->result = sin(func->result);
      else if (*tmp_q->data == 99)
        res_q->result = cos(func->result);
      else if (*tmp_q->data == 116)
        res_q->result = tan(func->result);
      else if (*tmp_q->data == 83)
        res_q->result = asin(func->result);
      else if (*tmp_q->data == 67)
        res_q->result = acos(func->result);
      else if (*tmp_q->data == 84)
        res_q->result = atan(func->result);
      else if (*tmp_q->data == 76)
        res_q->result = log10(func->result);
      else if (*tmp_q->data == 108)
        res_q->result = log(func->result);
      else if (*tmp_q->data == 82)
        res_q->result = sqrt(func->result);
      func->prio = 0;
      push_s(&stack, res_q);
    }
    else if (tmp_q->prio > 2){
        node_q* upper = pop_s(&stack);
        node_q* lowwer = pop_s(&stack);
        node_q* res = create_node_q("pass", 0);
        if (tmp_q->prio == 3)
          res->result = pow(lowwer->result, upper->result);
        else if (tmp_q->prio == 4){
          if (*tmp_q->data == 42)
            res->result = upper->result * lowwer->result;
          else
            res->result = lowwer->result / upper->result;
        } else if (tmp_q->prio = 5){
          if (*tmp_q->data == 45)
            res->result = upper->result - lowwer->result;
          else
            res->result = upper->result + lowwer->result;
        }
        res->prio = 0;
        push_s(&stack, res);
      }
    }
    printf("res = %lf\n", stack->data->result);
return 0;
}



int main(){
  
  /* char* in = "15-sin(12.34+(15*3*cos(24/12)))+13^2"; */
  
  char *in = "(123+15)^2*76^5-cos(85^3+(25161*13+(12*468)))-sin(32)+(15*3/2)";

  double res = 0.0;
  calc(in, &res);

  return 0;
}
