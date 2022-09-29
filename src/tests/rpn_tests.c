#include "test.h"

START_TEST(without_bracket) {
  char* case1 = "a+b*c";
  char* res_1 = "abc*+";
  
}
END_TEST

START_TEST(pop_out) {

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
