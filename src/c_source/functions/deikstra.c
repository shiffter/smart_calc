#include "../smart_calc.h"

int rpn(char *input, char *out) {
  int res = 0, in_prio = 10, st_prio = 10;
  node_s *stack = NULL;
  char *start = out;
  for (; *input; input++) {
    if (*input == ' ')
      continue;
    in_prio = get_prio(input, in_prio);
    /* printf("input %c ptio %d \n", *input, in_prio); */
    if (in_prio == 0 || *input == 'x') {
      if (*input == 'x') {
        *out = *input;
        out++;
      }
      else {
        copy_number(&input, &out);
        *out++ = ' ';
      }
    }
    else if (in_prio == 1) {
      if (*input == '(')
        push_s(&stack, *input, 0);
      else {
        char tmp = pop_s(&stack);
        while (tmp != '(') {
          *out++ = tmp;
          *out++ = ' ';
          tmp = pop_s(&stack);
        }
      }
    } else {
      if (!is_empty(&stack) && (stack->data == '('))
        push_s(&stack, *input, 0);
      else if (!is_empty(&stack) && stack->data == '^' && *input == '^')
        push_s(&stack, *input, 0);
      else if (is_empty(&stack))
        push_s(&stack, *input, 0);
      else {
        st_prio = get_prio(&(stack->data), st_prio);
        if (st_prio <= in_prio) {
          while (st_prio <= in_prio && !is_empty(&stack)) {
            if (stack->data == '(')
              break;
            char tmp = pop_s(&stack);
            *out++ = tmp;
            *out++ = ' ';
            st_prio = get_prio(&(stack->data), st_prio);
          }
          push_s(&stack, *input, 0);
        } else if (st_prio > in_prio) {
          push_s(&stack, *input, 0);
        }
      }
    }
  }
  while (!is_empty(&stack)) {
    *out++ = pop_s(&stack);
    *out++ = ' ';
  }
  return res;
}
