#include "../smart_calc.h"

int rpn(queue *que_in, queue *que_out) {
  node_s *stack = NULL;
  node_q *que_node = NULL;
  while (que_node = pop_q(que_in)) {
    printf("que->node at begin %s\n", que_node->data);
    if (que_node->prio == 0) {
      push_q(que_out, que_node->data, 0);
      free(que_node);
      continue;
    } else {
      switch (que_node->prio == 1) {
      case 1:
        printf("case1\n");
        if (*que_node->data == 40)
          push_s(&stack, que_node);
        else {
          node_q *tmp_q = pop_s(&stack);
          while (*tmp_q->data != 40) {
            push_q(que_out, tmp_q->data, tmp_q->prio);
            /* free(tmp_q->data); */
            free(tmp_q);
            tmp_q = pop_s(&stack);
          }
          /* free(tmp_q->data); */
          free(tmp_q);

        }
        /* printf("que->node %s\n", que_node->data); */
        /* free(que_node->data); */
        free(que_node);
        continue;
      case 0:
        if (!is_empty_s(&stack) && *stack->data->data == 40) {
          push_s(&stack, que_node);
          /* free(que_node->data); //??? */
          free(que_node);
          continue;
        }
        if (!is_empty_s(&stack) && stack->data->prio <= que_node->prio) {
          while (!is_empty_s(&stack) && stack->data->prio <= que_node->prio) {
            if (stack->data->prio == 1) {
              break;
            } else {
              node_q *tmp_s = pop_s(&stack);
              push_q(que_out, tmp_s->data, tmp_s->prio);
              /* free(tmp_s->data); */
              free(tmp_s);
            }
          }
          push_s(&stack, que_node);
          free(que_node);
          continue;
        }
        if (is_empty_s(&stack)) {
          push_s(&stack, que_node);
          free(que_node);
          continue;
        }
        if (stack->data->prio == que_node->prio) {
          node_q *tmp_sy = pop_s(&stack);
          push_q(que_out, tmp_sy->data, tmp_sy->prio);
          /* free(tmp_sy->data); */
          free(tmp_sy);
          push_s(&stack, que_node);
          free(que_node);
          continue;
        }
        if (stack->data->prio > que_node->prio) {
          push_s(&stack, que_node);
          free(que_node);
          continue;
        }
      }
    } 
  }
  if (!is_empty_s(&stack)) {
    while (!is_empty_s(&stack)) {
      node_q *s = pop_s(&stack);
      push_q(que_out, s->data, s->prio);
      /* free(s->data); */
      free(s);
    }
  }
  free(stack);
  printf("%p \n", stack);
  return 0;
}

int get_prio(char *value, int prio) {
  if (value != NULL) {

    if (*value > 47 && *value < 58)
      prio = 0;
    else if (*value == 40 || *value == 41)
      prio = 1;
    else if (*value > 96 && *value < 123) {
      if (*value == 109 && *++value == 111)
        prio = 4;
      else
        prio = 2;
    } else if (*value == 94)
      prio = 3;
    else if (*value == 42 || *value == 47)
      prio = 4;
    else if (*value == 43 || *value == 45)
      prio = 5;
  } else {
    prio = -1;
  }
  return prio;
}

int math_keys(char *start, func functions, char *out) {

  if (*start == 115) {;

    if (!strncmp(start, functions.s, 3)) {
      *out = 115; // 115= s
      return 2;
    } else if (!strncmp(start, functions.R, 4)) {
      *out = 82;
      return 3;
    }
  } else if (*start == 97) {
    if (!strncmp(start, functions.S, 4))
      *out = 83; // 83 = S
    else if (!strncmp(start, functions.C, 4))
      *out = 67; // 67 = C
    else if (!strncmp(start, functions.T, 4))
      *out = 84; // 84 = T
    return 3;
  } else if (*start == 99 && !strncmp(start, functions.c, 3)) {
    *out = 99;
    return 2;
  } else if (*start == 116 && !strncmp(start, functions.t, 3)) {
    *out = 116;
    return 2;
  } else if (*start == 108) {
    if (!strncmp(start, functions.l, 2)) {
      *out = 108;
      return 1;
    }
    if (!strncmp(start, functions.L, 3)) {
      *out = 76;
      return 2;
    }
  } else if (*start == 109) {
    if (!strncmp(start, functions.m, 3)) {
      *out = 109;
      return 2;
    }
  } else if (*start == 43) {
    *out = 80;
    return 0;
  } else if (*start == 45) {
    *out = 77;
    return 0;
  }
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
  return functions;
}