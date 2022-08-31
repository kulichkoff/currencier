#include <iostream>
#include "src/http_client.h"
#include "src/currency_parser.h"

#include <curlpp/Options.hpp> // for exceptions

int main() {
  try {
    HttpClient http;

    std::string raw_json = http.Get("https://www.cbr-xml-daily.ru/daily_json.js");
    CurrencyParser parser(raw_json.c_str());

    Currency *usd = parser.GetUsd();
    std::cout << usd->value << std::endl;

    Currency *eur = parser.GetEur();
    std::cout << eur->value << std::endl;

  } catch (curlpp::RuntimeError &e) {
    std::cerr << e.what() << std::endl;
  } catch (curlpp::LogicError &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
