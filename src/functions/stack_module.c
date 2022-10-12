#include "../smart_calc.h"


int push_s(node_s **top, node_q *data) {
  int out = 0;
  node_s *new_node = NULL;
  new_node = (node_s *)malloc(sizeof(node_s));
  if (new_node != NULL) {

    new_node->data = calloc(1, sizeof(node_q));
    if (new_node->data){
      new_node->data->data = calloc(strlen(data->data)+1,sizeof(char));
      strncpy(new_node->data->data, data->data, strlen(data->data));
    }
    new_node->next_node = *top;
    *top = new_node;
    free(data->data);
    free(data);
  } else {
    out = -1;
  }
  return out;
}

void peek_s(node_s *top) {
  if (top->data)
    printf("%s", top->data->data);
}

node_q *pop_s(node_s **top) {
  if (*top == NULL)
    return NULL;
  node_q *val = (*top)->data;
  node_s *tmp = *top;
  *top = (*top)->next_node;
  /* if (tmp->data->data) */
  /*   free(tmp->data->data); */
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
    printf("%s\n", tmp->data->data);
    tmp = tmp->next_node;
  }
}


void free_node_s(node_s* node){
  if(node && node->data){
    free_node_q(node->data);
  }
}
