#include "../smart_calc.h"


double common_calc(char* in, x_x* x_info){

  double res = 0;
  if (in){
    char* normalize_str = calloc(strlen(in)+1, sizeof(char));
    char* rpn_s = calloc(strlen(normalize_str)+1, sizeof(char));
  if (normalize_str && rpn_s){
    get_short_func(in, normalize_str);
    find_unary(normalize_str);
    if (!check_expr(normalize_str)) {
      rpn(normalize_str, rpn_s);

      calc(rpn_s, &res, x_info);
    } else printf("syntax_errO");
    }
  free(normalize_str);
  free(rpn_s);
  }
  return res;
}


//int calculate_graph(graph plot, char* input){
//    char* rpn_str = calloc(strlen(input)+1, sizeof(char));
//    rpn(input, rpn_str);

//    for(int i = plot.start, j = 0; i <= plot.stop; i+=plot.step, j++){
//        double y = 0;
//        plot.x_val[j] = i;
//        plot.y_val[j] = common_calc(input);
//    }

//    return 0;
//}
