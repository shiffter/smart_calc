#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* typedef struct { */
/*   char symbol; */
/*   int prio; */
/* } token; */


typedef struct stack {
  char data;
  struct stack* next_node;
} node;



/* Stack functions */
int push(node** top, char x);
char peek(node* top);
int pop(node** top);
int is_empty(node** top);
void print_stack(node** top);


/* Deikstra algorithm functions */
int rpn(char* input, char* output);
int get_prio(char* value, int);
int check_stack_prio(node* stack, int prio_stack);



