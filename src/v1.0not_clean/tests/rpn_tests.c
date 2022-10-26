#include "test.h"

START_TEST(without_brackets) {
  /* char *case1 = "a+b*c"; */
  /* char *res_1 = "abc*+"; */
  /* struct_str *out = calloc(1, sizeof(struct_str)); */
  /* ck_assert_int_eq(0, rpn(case1, out)); */
  /* ck_assert_str_eq(res_1, out->output); */
  /* free(out->output); */
  /* free(out); */

  /* char *case2 = "a+b+s*t+d/r*p^s*a-e-s*y^x"; */
  /* char *res_2 = "ab+st*+dr/ps^*a*+e-syx^*-"; */
  /* out = calloc(1, sizeof(struct_str)); */
  /* ck_assert_int_eq(0, rpn(case2, out)); */
  /* ck_assert_str_eq(res_2, out->output); */
  /* free(out->output); */
  /* free(out); */

  /* char *case3 = "+s-z*t/r*w"; */
  /* char *res_3 = "s+zt*r/w*-"; */
  /* out = calloc(1, sizeof(struct_str)); */
  /* ck_assert_int_eq(0, rpn(case3, out)); */
  /* ck_assert_str_eq(res_3, out->output); */
  /* free(out->output); */
  /* free(out); */
}
END_TEST

START_TEST(with_brackets) {

  /* char *case1 = "(a+b*(s-d)^x)/(z-x)+w*x"; */
  /* char *res_1 = "absd-x^*+zx-/wx*+"; */
  struct_str *out = calloc(1, sizeof(struct_str));
  /* ck_assert_int_eq(0, rpn(case1, out)); */
  /* ck_assert_str_eq(res_1, out->output); */
  /* free(out->output); */
  /* free(out); */

  char *case2 = "(a^b+c*e)^s*x-a+(z-s)";
  char *res_2 = "ab^ce*+s^x*a-zs-+";

  /* char* case2 = "a*b+(c--z)"; */
  /* char* res_2 = "ab*cz-+"; */

  /* out = calloc(1, sizeof(struct_str)); */
  ck_assert_int_eq(0, rpn(case2, out));
  ck_assert_str_eq(res_2, out->output);
  if (out->output)
    free(out->output);
  free(out);

  /* char* case3 = "(a^b+c*e)^s*x-a+(z-s)"; */
  /* char* res_3 = "a^ce*+s^x*a-zs-+"; */
  /* out = calloc(1, sizeof(struct_str)); */
  /* ck_assert_int_eq(0, rpn(case1, out)); */
  /* ck_assert_str_eq(res_1, out->output); */
  /* free(out->output); */
  /* free(out); */
}
END_TEST

Suite *rpn_test() {
  Suite *s;

  s = suite_create("Reverse polish notation tests");

  TCase *tc1_without_brackets = tcase_create("Without brackets cases");
  TCase *tc2_with_brackets = tcase_create("With brackets");

  tcase_add_test(tc1_without_brackets, without_brackets);
  tcase_add_test(tc2_with_brackets, with_brackets);

  suite_add_tcase(s, tc1_without_brackets);
  suite_add_tcase(s, tc2_with_brackets);

  return s;
}
