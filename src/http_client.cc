//
// Created by kulichkoff on 31.08.22.
//

#include <sstream>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include "http_client.h"

HttpClient::HttpClient() = default;

std::string HttpClient::Get(const char *url) {
  curlpp::Easy request;

  std::ostringstream os;

  request.setOpt(
    new curlpp::options::Url(url));
  request.setOpt(new curlpp::options::WriteStream(&os));

  request.perform();

  std::string currency_json = os.str();

  return currency_json;
}
