//
// Created by kulichkoff on 31.08.22.
//

#include "currency_parser.h"

CurrencyParser::CurrencyParser(const char *raw_json) {
  json global_json = json::parse(raw_json);
  currency_data_ = global_json["Valute"];
}

CurrencyParser::~CurrencyParser() {
  delete usd_;
  delete eur_;
}

Currency *CurrencyParser::GetUsd() {
  json usd_json = currency_data_["USD"];
  if (!usd_) {
    usd_ = new Currency{
      usd_json["Name"],
      usd_json["CharCode"],
      usd_json["Value"],
      usd_json["Previous"],
    };
  }
  return usd_;
}

Currency *CurrencyParser::GetEur() {
  json eur_json = currency_data_["EUR"];
  if (!eur_) {
    eur_ = new Currency{
      eur_json["Name"],
      eur_json["CharCode"],
      eur_json["Value"],
      eur_json["Previous"],
    };
  }
  return eur_;
}
