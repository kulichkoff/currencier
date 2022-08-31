#include <iostream>
#include <curlpp/Options.hpp> // for exceptions

#include "src/http_client.h"

int main() {
  try {
    HttpClient http;

    auto currency_json = http.Get("https://www.cbr-xml-daily.ru/daily_json.js");

    std::cout << currency_json << std::endl;

  } catch (curlpp::RuntimeError &e) {
    std::cerr << e.what() << std::endl;
  } catch (curlpp::LogicError &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
