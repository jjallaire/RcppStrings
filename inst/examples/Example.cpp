
// [[Rcpp::depends(RcppStrings)]]

#include <RcppStrings.h>

// [[Rcpp::export]]
Rcpp::CharacterVector testTrim(Rcpp::CharacterVector str) {
  return RcppStrings::stringTrim(str, "both");
}