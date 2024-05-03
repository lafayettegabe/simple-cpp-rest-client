#include "api.hpp"

using namespace web::http;
using namespace web::http::client;

API::API(const utility::string_t& apiUrl) : apiUrl(apiUrl) {}

t_json API::get() {
    http_client client(apiUrl);
    return client.request(methods::GET).then([](http_response response) {
        if (response.status_code() == status_codes::OK) {
            return response.extract_string();
        } else {
            throw std::runtime_error("HTTP request failed with status code " + std::to_string(response.status_code()));
        }
    }).then([](std::string responseBody) {
        return t_json::parse(responseBody);
    }).get();
}

void API::post(const t_json& data) {
    http_client client(apiUrl);
    http_request request(methods::POST);
    request.headers().set_content_type(U("application/json"));
    request.set_body(data.dump());

    client.request(request).then([](http_response response) {
        if (response.status_code() != status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code " + std::to_string(response.status_code()));
        }
    }).wait();
}

