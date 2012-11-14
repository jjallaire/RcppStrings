
// [[Rcpp::interfaces(r, cpp)]]

#include <Rcpp.h>

#include <boost/function.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace Rcpp;
using namespace boost;

namespace {

// Generic character vector transformation logic
CharacterVector stringTransform(CharacterVector input, 
                                boost::function<void(std::string&)> transform){
  
  CharacterVector output(input.size());
  for (int i = 0; i<input.size(); i++) {
    std::string str(input[i]);
    transform(str);
    output[i] = str;
  }
  return output;   
}

// some helpers to trap boost string algorithms (wouldn't typically be 
// necessary for boost::function but they are template functions so 
// wierd casts would be necessary to use them directly)
inline void stringTrimAll(std::string& str) { algorithm::trim(str); }
inline void stringTrimLeft(std::string& str) { algorithm::trim_left(str); }
inline void stringTrimRight(std::string& str) { algorithm::trim_right(str); }  

} // anonymous namespace


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
  return stringTransform(input, stringTrimAll);
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
  return stringTransform(input, stringTrimLeft); 
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
  return stringTransform(input, stringTrimRight);
}
