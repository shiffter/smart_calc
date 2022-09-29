#include "../smart_calc.h"

/* node *top = NULL; */

int push(node **top, char x) {
  int out = 0;
  node *new_node = NULL;
  new_node = (node *)malloc(sizeof(node));
  if (new_node != NULL) {
    new_node->data = x;
    new_node->next_node = *top;
    *top = new_node;
  } else {
    out = -1;
  }
  return out;
}

char peek(node *top) {
  char out = top->data;
  return out;
}

int pop(node **top) {
  if (*top == NULL)
    return -1;
  char val = (*top)->data;
  node *tmp = *top;
  *top = (*top)->next_node;
  free(tmp);
  return val;
}

int is_empty(node **top) {
  int out = 0;
  if (*top == NULL)
    out = 1;
  return out;
}

void print_stack(node **top) {
  node **top_for_print = top;
  node *tmp = *top_for_print;
  while (tmp->next_node) {
    printf("ch = %c\n", tmp->data);
    *top_for_print = tmp;
    tmp = (*top_for_print)->next_node;
  }
  printf("ch = %c\n", tmp->data);
}
/* int main(){ */
/*   node* top = NULL; */
/*   push(&top, 107); */
/*   push(&top, 108); */
/*   push(&top, 109); */
/*   peek(top); */

/*   while(top) */
/*     printf("stack element = %c\n", pop(&top)); */

/*   node* top1 = NULL; */
/*   push(&top1, 109); */
/*   push(&top1, 108); */
/*   push(&top1, 107); */

/*   while(top1) */
/*     printf("stack element = %        /* printf("iter %d\n", i); */
/* printf("stack_val = %c, stack_prio %d\n", stack->data, stack_prio); */
/* printf("input val = %c, prio %d\n", *input, prio); */

/* c\n", pop(&top1)); *1/ */

/*  return 0; */
/* } */

/* node* ins_node = NULL; */
/* ins_node = (node*)malloc(sizeof(node)); */
/* ins_node->data = x; */
/* ins_node->next_node = top; */
/* top = ins_node; */
