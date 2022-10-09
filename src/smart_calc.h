#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* typedef struct { */
/*   char symbol; */
/*   int prio; */
/* } token; */


#define INIT_S  (node) {0, NULL}
#define INIT_SS (struct_str) {NULL, 0}


typedef struct available_func {
  char *s, *c, *t, *S, *C, *T, *R, *l, *L, *M, *P;
  char *numbers;
} func;


typedef struct Qnode {
  char* data;
  int prio;
  double result; 
  struct Qnode* next;
} node_q;


typedef struct stack {
  node_q* data;
  struct stack* next_node;
} node_s;


typedef struct Queue {
  node_q *head, *tail;
} queue;


typedef struct string {
  char* output;
  int len;
} struct_str;



/* Stack functions */
int push_s(node_s** top, node_q*);
void peek_s(node_s* top);
node_q* pop_s(node_s** top);
int is_empty_s(node_s** top);
void print_stack(node_s* top);



/* Queue functions */
void push_q(queue*, char*, int);
queue* create_q();
node_q* create_node_q(char*, int);
node_q* pop_q(queue* Q);
void free_node_q(node_q* node);
void print_Q(queue* Q);




/* Deikstra algorithm functions */
int rpn(queue*, queue*);
int get_prio(char* value, int);
int check_stack_prio(node_s* stack, int prio_stack);
int math_keys(char*, func, char*);
func init_functions(func functions);
int check_unary(char* input, int iter_count);


/* main */
int calc(char* input, double* res);
int calculate_value(queue* rpn_q);




