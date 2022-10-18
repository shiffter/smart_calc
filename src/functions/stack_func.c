#include "../smart_calc.h"
void peek_s(node_s *top) {
  if (top->data)
    printf("%c\n", top->data);
}


void print_ss(node_s* top){
  node_s* tmp = top;
  while(tmp){
    peek_s(tmp);
    tmp = tmp->next_node;
  }
}


char pop_s(node_s** top){
  char out = 0; 
  if (*top){
    out = (*top)->data;
    node_s* tmp = *top;
    *top = (*top)->next_node;
    free(tmp);
  } else { printf("Stack is empty!\n"); }
  return out; 
}



int push_s(node_s** top, char data, int prio) {
  int out = 0;
  node_s* new_n = calloc(1, sizeof(node_s));
  if (new_n){
    new_n->next_node = *top;
    new_n->data = data;
    *top = new_n;
  } else { printf("Allocate memory error!\n"); out = 1; }
  return out;
}


int is_empty(node_s** top){
  int out = 0;
  if (*top == NULL) out = 1;
  return out;
}
