#include <iostream>
#include <sstream>
#include "ident_handler.h"

std::string IdentsHandler::newTemp() {
    if (currFD == nullptr) {
        return "";
    } else {
        int offset = currFD->newVarOffset();
        return "ebp - " + std::to_string(-offset);
    }
}

std::string IdentsHandler::registerStrLiteral(const std::string& str) {
    auto it = strlitMap.find(str);

    if (it != strlitMap.end()) {
        return it->second;
    }    
    std::ostringstream ss;

    ss << "strl" << slitCount++;

    std::string name = ss.str();
    strlitMap.emplace(str, name);

    return name;
}

void IdentsHandler::genConstNames() {
    std::cout << "; Numeric constants\n";
    for (const auto& c : constMap) {
        std::cout << c.second << " dd " << c.first << "\n";
    }
    std::cout << "; String literals\n";
    for (const auto& s : strlitMap) {
        std::cout << s.second << " db \"" << s.first << "\", 0\n";
    }
}

void IdentsHandler::genVarNames() {
    std::cout << "; Variables\n";
    for (const auto& s : varNames) {
        std::cout << s << ": dd 0\n";
    }
    std::cout << "; Temp variables\n";
    for (const auto& s : tmpNames) {
        std::cout << s << ": dd 0\n";
    }
}
    
