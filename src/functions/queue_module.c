#include "../smart_calc.h"


node_q* create_node_q(char* data, int prio){
  node_q* tmp = calloc(1, sizeof(node_q));
  if (strlen(data) > 0)
    tmp->data = calloc(strlen(data) + 1, sizeof(char));
  strncpy(tmp->data, data, strlen(data));
  tmp->prio = prio;
  tmp->result = 0.0;
  tmp->next = NULL;
  return tmp;
}


queue* create_q(){
  queue* q = calloc(1, sizeof(queue));
  if (q) q->head = q->tail = NULL;
  return q;
}


void push_q(queue* Q, char* data, int prio){
  node_q* tmp = create_node_q(data, prio);
  if (Q->tail == NULL){
    Q->head = Q->tail = tmp;
    return;
  }
  Q->tail->next = tmp;
  Q->tail = tmp;
}


node_q* pop_q(queue* Q){
  if (Q->head == NULL) return NULL;
    
  node_q* tmp = Q->head;
  Q->head = Q->head->next;

  if (Q->head == NULL){
    Q->tail = NULL;
  }
  return tmp;
}


void print_Q(queue* Q){
  node_q* tmp = Q->head;
  while(tmp){
    /* printf("node = %s\t%d\n", tmp->data, tmp->prio); */
    /* printf("data %s\t\t%p len = %ld\n", tmp->data, tmp->data, strlen(tmp->data)); */
    printf("%s ", tmp->data);

    tmp = tmp->next;
  }
}


void free_node_q(node_q* node){
  if (node->data)
    free(node->data);
  free(node);
}
