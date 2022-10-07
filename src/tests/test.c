#include "test.h"

int main() {
  int no_failed1 = 0, no_failed2 = 0 /*, no_failed3 = 0, no_failed4 = 0,
     no_failed5 = 0, no_failed6 = 0, no_failed7 = 0, no_failed8 = 0,
     no_failed9 = 0, no_failed10 = 0, no_failed11 = 0*/
      ;

  Suite *s1, *s2 /*, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11*/
      ;

  SRunner *runner1,
      *runner2 /*, *runner3, *runner4, *runner5, *runner6,
                **runner7, runner8, *runner9, *runner10, *runner11*/
      ;

  s1 = push_in_test();
  runner1 = srunner_create(s1);
  srunner_set_fork_status(runner1, CK_NOFORK);
  srunner_run_all(runner1, CK_NORMAL);
  no_failed1 = srunner_ntests_failed(runner1);
  srunner_free(runner1);

  s2 = rpn_test();
  runner2 = srunner_create(s2);
  srunner_set_fork_status(runner2, CK_NOFORK);
  srunner_run_all(runner2, CK_NORMAL);
  no_failed2 = srunner_ntests_failed(runner2);
  srunner_free(runner2);

  int failures = (!no_failed1 && !no_failed2 /*&& !no_failed3 && !no_failed4 &&
                  !no_failed5 && !no_failed6 && !no_failed7 && !no_failed8 &&
                  !no_failed9 && !no_failed10 && !no_failed11*/
  );

  return (failures == 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
