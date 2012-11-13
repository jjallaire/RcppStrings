// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

CharacterVector trimAll(CharacterVector input);
CharacterVector trimLeft(CharacterVector input);
CharacterVector trimRight(CharacterVector input);

static bool validateExported(const std::string& sig) {
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("CharacterVector(*trimAll)(CharacterVector)");
        signatures.insert("CharacterVector(*trimLeft)(CharacterVector)");
        signatures.insert("CharacterVector(*trimRight)(CharacterVector)");
    }
    return signatures.find(sig) != signatures.end();
}

RCPP_MODULE(RcppStrings_RcppExports) {
    Rcpp::function("trimAll", &trimAll, Rcpp::List::create(Rcpp::Named("input")));
    Rcpp::function("trimLeft", &trimLeft, Rcpp::List::create(Rcpp::Named("input")));
    Rcpp::function("trimRight", &trimRight, Rcpp::List::create(Rcpp::Named("input")));
    Rcpp::function("RcppExports_validateExported", &validateExported);
}