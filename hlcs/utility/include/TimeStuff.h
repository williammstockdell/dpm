#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

std::chrono::system_clock::time_point
time_from_string(const std::string& value)
{
    std::tm tm{};

    std::istringstream is(value);
    is >> std::get_time(&tm, "%Y-%b-%d %H:%M:%S");

    if (is.fail()) {
        throw std::invalid_argument("Invalid time: " + value);
    }

    // Let mktime determine DST for the supplied local time.
    tm.tm_isdst = -1;

    const std::time_t t = std::mktime(&tm);
    if (t == static_cast<std::time_t>(-1)) {
        throw std::invalid_argument("Invalid time: " + value);
    }

    return std::chrono::system_clock::from_time_t(t);
}

std::string time_to_string(
    const std::chrono::system_clock::time_point& tp)
{
    const std::time_t t =
        std::chrono::system_clock::to_time_t(tp);

    std::tm tm{};
    localtime_r(&t, &tm);

    std::ostringstream os;
    os << std::put_time(&tm, "%Y-%b-%d %H:%M:%S");
    return os.str();
}
