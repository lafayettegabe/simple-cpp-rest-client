#ifndef API_HPP
#define API_HPP

#include <string>
#include <cpprest/http_client.h>
#include <nlohmann/json.hpp>

using t_json = nlohmann::json;

class API {
public:
    API(const utility::string_t& apiUrl);

    t_json get();
    void post(const t_json& data);

private:
    utility::string_t apiUrl;
};

#endif
