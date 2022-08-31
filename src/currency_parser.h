//
// Created by kulichkoff on 31.08.22.
//

#ifndef CURRENCIER_CURRENCY_PARSER_H_
#define CURRENCIER_CURRENCY_PARSER_H_

#include <nlohmann/json.hpp>

using nlohmann::json;

struct Currency {
  std::string name;
  std::string code;
  float value;
  float previousValue;
};

class CurrencyParser {
public:
  explicit CurrencyParser(const char *raw_json);

  ~CurrencyParser();

  Currency *GetUsd();

  Currency *GetEur();

private:
  Currency *usd_{};
  Currency *eur_{};

  json currency_data_;
};


#endif //CURRENCIER_CURRENCY_PARSER_H_
