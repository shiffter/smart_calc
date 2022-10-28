#include "../smart_calc.h"


double common_calc(char* in){

  double res = 0;
  if (in){
    char* normalize_str = calloc(strlen(in)+1, sizeof(char));
    char* rpn_s = calloc(strlen(normalize_str)+1, sizeof(char));
  if (normalize_str && rpn){
    get_short_func(in, normalize_str);
    find_unary(normalize_str);
    if (!check_expr(normalize_str)) {
      rpn(normalize_str, rpn_s);
      calc(rpn_s, &res);
    } else printf("syntax_err");
    }
  free(normalize_str);
  free(rpn_s);
  }
  return res;
}
