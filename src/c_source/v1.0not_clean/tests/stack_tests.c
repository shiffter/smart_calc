#include "test.h"

START_TEST(push_in) {
  node *stack = NULL;
  int out = -1;
  for (int i = 0; i < stack_size; i++) {
    mass[i] = rand() % (MAX_CHAR + 1 - MIN_CHAR) + MIN_CHAR;
    out = push(&stack, mass[i]);
    if (out == 0)
      ck_assert_int_eq(mass[i], stack->data);
    if (out == -1)
      ck_assert_ptr_eq(stack, NULL);
  }
}
END_TEST

START_TEST(pop_out) {
  node *stack = NULL;
  int out = -1, i = 0;
  for (i = stack_size - 1; i >= 0; i--) {
    out = pop(&stack);
    if (out != -1)
      ck_assert_int_eq(mass[i], out);
    else
      ck_assert_ptr_eq(stack, NULL);
  }
}
END_TEST

Suite *push_in_test() {
  Suite *s;

  s = suite_create("Push and pop");

  TCase *tc1_push = tcase_create("Push a-z symbols in stack");
  TCase *tc2_pop_out = tcase_create("Pop a-z symbols from stack");

  tcase_add_test(tc1_push, push_in);
  tcase_add_test(tc2_pop_out, pop_out);

  suite_add_tcase(s, tc1_push);
  suite_add_tcase(s, tc2_pop_out);

  return s;
}
