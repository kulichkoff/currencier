#include <iostream>
#include <stdlib.h>

#include "src/http_client.h"
#include "src/currency_parser.h"

#include <curlpp/Options.hpp> // for exceptions

int main(int argc, char **argv) {
  try {
    HttpClient http;

    std::string raw_json = http.Get(
      "https://www.cbr-xml-daily.ru/daily_json.js");
    CurrencyParser parser(raw_json.c_str());


    Currency *usd = parser.GetUsd();
    Currency *eur = parser.GetEur();

    if (argc == 1) {
      std::cout << "USD: " << usd->value << std::endl;
      std::cout << "EUR: " << eur->value << std::endl;
    } else if (argc == 3) {
      std::string currency_flag = argv[1];
      double value = strtod(argv[2], nullptr);
      std::string currency;
      double result = 0;

      if (currency_flag == "--usd") {
        currency = "USD";
        result = usd->value * value;
      } else if (currency_flag == "--eur") {
        currency = "EUR";
        result = eur->value * value;
      } else {
        std::cerr << "Unknown currency code\n";
        return -1;
      }

      std::cout << "[" << currency << "] " << value << " = [RUB] " << result
                << std::endl;
    } else {
      std::cerr << "Usage: currencier OR currencier --[eur|usd] [value]\n";
      return -1;
    }

  } catch (curlpp::RuntimeError &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  } catch (curlpp::LogicError &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }

  return 0;
}
