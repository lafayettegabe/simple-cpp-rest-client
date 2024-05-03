#include "datetime.hpp"
#include <iomanip>
#include <sstream>
#include <ctime>

std::string getCurrentDateTimeFormatted() {
    std::time_t now = std::time(nullptr);
    std::tm localTime = *std::localtime(&now);

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << localTime.tm_mday << "/"
        << std::setw(2) << (localTime.tm_mon + 1) << "/" << (localTime.tm_year + 1900) % 100 << " "
        << std::setw(2) << localTime.tm_hour << ":" << std::setw(2) << localTime.tm_min;

    return oss.str();
}
