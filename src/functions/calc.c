#include "../smart_calc.h"

int calc(char *input, double *res) {
  int out = 0;
  func avail_func = init_functions(avail_func);
  queue *que = create_q();
  for (int i = 0; *input; i++, input++) {
    if (*input == 32) {
      i--;
      continue;
    }
    int prio = get_prio(input, prio);
    if (*input == 120) {
      char *x = calloc(2, sizeof(char));
      *x = *input;
      push_q(que, x, prio);
      /* free(x); */
      continue;
    } else if (*input > 47 && *input < 58) {
      size_t len_num = strspn(input, avail_func.numbers);
      char *number = calloc(len_num + 1, sizeof(char));
      strncpy(number, input, len_num);
      if (len_num > 1)
        input += len_num - 1;
      push_q(que, number, 0); // thierd param can be get from get_prio
      /* free(number); */
      continue;
    } else if (prio == 2 || *input == 109) {
      char *functions = calloc(2, sizeof(char));
      int shift = math_keys(input, avail_func, functions);
      if (*input == 109)
        prio = 4;
      input += shift;
      push_q(que, functions, prio);
      /* free(functions); */
      continue;
    } else if (prio > 2 || prio == 1) {
      char *operator= calloc(2, sizeof(char));
      *operator= * input;
      push_q(que, operator, prio);
      /* free(operator); */
      continue;
    }
  }

    find_unary(que);
    queue *que_out = create_q();
    rpn(que, que_out);
    /* print_Q(que); */
    free_Q(que);
    /* print_Q(que_out); */
    /* calculate_value(que_out, res); */
    free_Q(que_out);
    return 0;
  }

  int calculate_value(queue * rpn_q, double* res) {
    node_s *stack = NULL;
    node_q *tmp_q = NULL;
    double result = 0.0;
    while (tmp_q = pop_q(rpn_q)) {
      if (tmp_q->prio == 0) {
        push_s(&stack, tmp_q);
        stack->data->result = atof(stack->data->data);
        continue;
      } else if (tmp_q->prio == 2) {
        node_q *func = pop_s(&stack);
        node_q *res_q = create_node_q("func calc", 0);
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
        else if (*tmp_q->data == 80) {
          res_q->result = func->result;
        } else if (*tmp_q->data == 77) {
          res_q->result = func->result * (-1.0);
        }
        func->prio = 0;
        push_s(&stack, res_q);
        free_node_q(func);
        
      } else if (tmp_q->prio > 2) {
        node_q *upper = pop_s(&stack);
        node_q *lowwer = pop_s(&stack);
        node_q *res = create_node_q("pass", 0);
        if (tmp_q->prio == 3)
          res->result = pow(lowwer->result, upper->result);
        else if (tmp_q->prio == 4) {
          if (*tmp_q->data == 109)
            res->result = fmod(lowwer->result, upper->result);
          else if (*tmp_q->data == 42)
            res->result = upper->result * lowwer->result;
          else
            res->result = lowwer->result / upper->result;
        } else if (tmp_q->prio = 5) {
          if (*tmp_q->data == 45)
            res->result = lowwer->result - upper->result;
          else
            res->result = upper->result + lowwer->result;
        }
        res->prio = 0;
        push_s(&stack, res);
        free_node_q(upper);
        free_node_q(lowwer);
      }
    free_node_q(tmp_q);
    }
      *res = stack->data->result;

      free(stack->data->data);
      free(stack->data);
      free(stack);

      /* free_node_s(stack); */

    return 0;
  }

  int check_unary(char *input, int iter_count) {
    int out = 0, prio = 69;
    while (*input++ == 32)
    if (iter_count == 0 && (*input == 43 || *input == 45))
      out = 1;
    prio = get_prio(++input, prio);
    if (prio == 1 || prio == 2)
      out = 1;
    return out;
  }

  void find_unary(queue * que) {
    node_q *prev_node = que->head;
    node_q *actualy = prev_node->next;
    int count = 0;
    while (actualy) {
      if (count == 0 && prev_node->prio == 5) {
        prev_node->prio = 2;
        if (*prev_node->data == 43)
          *prev_node->data = 80;
        else if (*prev_node->data == 45)
          *prev_node->data = 77;
      } else if (actualy->prio == 5) {
        if (prev_node->prio == 2 || *prev_node->data == 40){
          actualy->prio = 2;
        if (*actualy->data == 43)
          *actualy->data = 80;
        else if (*actualy->data == 45)    
          *actualy->data = 77;
        }
        /* if (actualy->next && actualy->next->prio == 2){ */
        /* actualy->prio = 2; */
        /* if (*actualy->data == 43) */
        /*   *actualy->data = 80; */
        /* else if (*actualy->data == 45) */    
        /*   *actualy->data = 77; */
        /* } */


      }
      node_q *tmp = actualy;
      actualy = actualy->next;
      prev_node = tmp;
      count++;
    }
  }

  int main() {

    /* char* in = "15-sin(12.34+(15*3*cos(24/12)))+13^2"; */
    char* in = "35";
    /* char *in ="(123+15)^2*76^5-cos(85^3+(25161*13+(12*468)))-sin(32)+(15*3/2)"; */
    /* char* in = "123+cos(15)-sin(23)^5"; */
    /* char *in = "10/(-1)*(-2)"; */
    /* char* in = "4 mod 3 + (1 * 2)"; */
     /* char* in = "2.4474/8.0162/3.2142+tan(0.6211+sin(tan(7.5952 +5.3702)) - 4.7121^sin(1.9427-2.8496))/cos(0.2688^0.5391+cos(tan(cos(cos(5.6221)))/sin(2.3295)-tan(cos(tan(cos(9.2239))))))"; */
     
    double res = 0.0;
    calc(in, &res);
    printf("%0.3lf\nlen %ld", res, strlen(in));
    return 0;
  }
