
// [[Rcpp::interfaces(r, cpp)]]

#include <Rcpp.h>

#include <boost/function.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace Rcpp;
using namespace boost;

namespace {

// Generic character vector transformation logic
typedef void (*Transformer)(std::string& str, const std::locale&);
CharacterVector stringTransform(CharacterVector input, Transformer transform) {
  
  const std::locale& locale = std::locale();
  CharacterVector output(input.size());
  for (int i = 0; i<input.size(); i++) {
    std::string str(input[i]);
    transform(str, locale);
    output[i] = str;
  }
  return output;   
}

} // anonymous namespace

//' Trim whitespace from start and end of string
//' 
//' @usage trimAll(input)
//' @param input input character vector
//' @param side side on which whitespace is removed (left, right, or both)
//' @return character vector with leading and trailing whitespace removed
//' @examples 
//' \dontrun{
//' trimString("\n\nString with trailing and leading white space \t")
//' }
// [[Rcpp::export]]
CharacterVector stringTrim(CharacterVector input, std::string side="both") {
  
  // select correct transformation
  Transformer transform = NULL;
  if (side == "both")
    transform = algorithm::trim<std::string>;
  else if (side == "left")
    transform = algorithm::trim_left<std::string>;
  else if (side == "right")
    transform = algorithm::trim_right<std::string>;
  else {
    // we need to fix a bug in Rcpp modules to allow throwing exceptions
    // from module functions. for now we just warn and return the input
    Rf_warning("Unrecognized side argument '%s'", side.c_str());
    return input;
  }
    
  // perform the transformation
  return stringTransform(input, transform);
}
