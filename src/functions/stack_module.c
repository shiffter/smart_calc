#include "../smart_calc.h"

/* node_s *top = NULL; */

int push_s(node_s **top, node_q* data) {
  int out = 0;
  node_s *new_node = NULL;
  new_node = (node_s*)malloc(sizeof(node_s));
  if (new_node != NULL) {
    new_node->data = data;
    new_node->next_node = *top;
    *top = new_node;
  } else {
    out = -1;
  }
  return out;
}

void peek_s(node_s *top) {
  if(top->data)
    printf("%s", top->data->data);
}

node_q* pop_s(node_s **top) {
  if (*top == NULL)
    return NULL;
  node_q* val = (*top)->data;
  node_s *tmp = *top;
  *top = (*top)->next_node;
  free(tmp);
  return val;
}

int is_empty_s(node_s **top) {
  int out = 0;
  if (*top == NULL)
    out = 1;
  return out;
}

void print_stack(node_s *top) {
  node_s *top_for_print = top;
  node_s *tmp = top_for_print;
  while (tmp) {
    printf("%0.2lf\n", tmp->data->result);
    tmp = tmp->next_node;
  }
}

/* int main(){ */
/*   node_s* top = NULL; */
/*   push(&top, 108); */
/*   push(&top, 45); */
/*   push(&top, 108); */
/*   push(&top, 45); */
/*   push(&top, 42); */
/*   printf("peek %c\n", peek(top)); */
/*   print_stack(top); */
/*   printf("peek %c\n", peek(top)); */

/*   /1* push(&top, 109); *1/ */
/*   /1* push(&top, 45); *1/ */
/*   /1* push(&top, 47); *1/ */

/*   /1* peek(top); *1/ */
/*   printf("is empty %d\n", is_empty(&top)); */
/*   /1* print_stack(&top); *1/ */

/*   /1* while(top) *1/ */
/*   /1*   printf("stack element = %c\n", pop(&top)); *1/ */

/*   /1* node_s* top1 = NULL; *1/ */
/*   /1* push(&top1, 109); *1/ */
/*   /1* push(&top1, 108); *1/ */
/*   /1* push(&top1, 107); *1/ */

/*   /1* while(top1) *1/ */
/*   /1*   printf("stack element = %         printf("iter %d\n", i); *1/ */
/* /1* printf("stack_val = %c, stack_prio %d\n", stack->data, stack_prio); *1/
 */
/* /1* printf("input val = %c, prio %d\n", *input, prio); *1/ */

/* /1* c\n", pop(&top1)); *2/ *1/ */

/*  return 0; */
/* } */
