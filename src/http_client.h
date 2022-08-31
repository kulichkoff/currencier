//
// Created by kulichkoff on 31.08.22.
//

#ifndef CURRENCIER_HTTP_CLIENT_H_
#define CURRENCIER_HTTP_CLIENT_H_


#include <string>

class HttpClient {
public:
  HttpClient();
  std::string Get(const char *url);
};


#endif //CURRENCIER_HTTP_CLIENT_H_
