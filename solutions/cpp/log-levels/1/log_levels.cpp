#include <string>

namespace log_line {
std::string message(std::string line) {
    auto initialPosition = line.find(":") + 2;
    return line.substr(initialPosition);
}

std::string log_level(std::string line) { 
    if(line.find("ERROR") != std::string::npos)
    {
        std::string registrationLevel = "ERROR";
        auto initialPosition = line.find("ERROR");
        auto finalPosition = initialPosition + registrationLevel.length() - 1;
        return line.substr(initialPosition,finalPosition);
    }
    if(line.find("WARNING") != std::string::npos)
    {
        std::string registrationLevel = "WARNING";
        auto initialPosition = line.find("WARNING");
        auto finalPosition = initialPosition + registrationLevel.length() - 1;
        return line.substr(initialPosition,finalPosition);
    }
    if(line.find("INFO") != std::string::npos)
    {
        std::string registrationLevel = "INFO";
        auto initialPosition = line.find("INFO");
        auto finalPosition = initialPosition + registrationLevel.length() - 1;
        return line.substr(initialPosition,finalPosition);
    }
    return "";
}

std::string reformat(std::string line) {
    if(line.find("ERROR") != std::string::npos)
    {
        std::string registrationLevel = "[ERROR]:";
        auto initialPosition = line.find("[ERROR]:");
        line.erase(initialPosition,registrationLevel.length() + 1);
        return line + " (ERROR)";
    }
    if(line.find("WARNING") != std::string::npos)
    {
        std::string registrationLevel = "[WARNING]:";
        auto initialPosition = line.find("[WARNING]:");
        line.erase(initialPosition,registrationLevel.length() + 1);
        return line + " (WARNING)";
    }
    if(line.find("INFO") != std::string::npos)
    {
        std::string registrationLevel = "[INFO]:";
        auto initialPosition = line.find("[INFO]:");
        line.erase(initialPosition,registrationLevel.length() + 1);
        return line + " (INFO)";
    }
    return "";
}
}  // namespace log_line
