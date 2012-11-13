
// [[Rcpp::interfaces(r, cpp)]]

#include <Rcpp.h>

#include <boost/algorithm/string/trim.hpp>

using namespace Rcpp;
using namespace boost;

//' Trim whitespace from start and end of string
//' 
//' @usage trimAll(input)
//' @param input input character vector
//' @return character vector with leading and trailing whitespace removed
//' @examples 
//' \dontrun{
//' trimAll("\n\nString with trailing and leading white space \t")
//' }
// [[Rcpp::export]]
CharacterVector trimAll(CharacterVector input) {
  
  CharacterVector output(input.size());
  for (int i = 0; i<input.size(); i++) {
    std::string str(input[i]);
    algorithm::trim(str);
    output[i] = str;
  }
  return output;   
}

//' Trim whitespace from start of string
//' 
//' @usage trimLeft(input)
//' @param input input character vector
//' @return character vector with leading whitespace removed
//' @examples 
//' \dontrun{
//' trimLeft("\n\nString with leading white space")
//' }
// [[Rcpp::export]]
CharacterVector trimLeft(CharacterVector input) {
  
  CharacterVector output(input.size());
  for (int i = 0; i<input.size(); i++) {
    std::string str(input[i]);
    algorithm::trim_left(str);
    output[i] = str;
  }
  return output;      
}

//' Trim whitespace from end of string
//' 
//' @usage trimRight(input)
//' @param input input character vector
//' @return character vector with trailing whitespace removed
//' @examples 
//' \dontrun{
//' trimRight("\n\nString with trailing white space")
//' }
// [[Rcpp::export]]
CharacterVector trimRight(CharacterVector input) {
  
  CharacterVector output(input.size());
  for (int i = 0; i<input.size(); i++) {
    std::string str(input[i]);
    algorithm::trim_right(str);
    output[i] = str;
  }
  return output;   
}
