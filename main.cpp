#include <iostream>
#include <nlohmann/json.hpp>
#include "api/api.hpp"
#include "datetime/datetime.hpp"

using t_json = nlohmann::json;

int main() {
    utility::string_t apiUrl = U("https://simple-firebase-rest-api.vercel.app/api/documents");
    try {
        API api(apiUrl);

        std::string formattedDateTime = getCurrentDateTimeFormatted();
        t_json jsonData = {
            {"data", {
                {"name", "gabe"},
                {"age", 24},
                {"createdAt", formattedDateTime}
            }}
        };

        api.post(jsonData);

        t_json updatedData = api.get();
        std::cout << "Updated Response JSON:\n" << updatedData.dump(4) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
