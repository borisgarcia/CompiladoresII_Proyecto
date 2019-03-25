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
    strlitMap[str] = name;
    return name;
}

std::string IdentsHandler::genStrNames()
{
    std::cout << "\n; String Literals\n\n";
    for(const auto & s : strLitMap)
        if(s.first.find("\"") == std::string::npos)
            std::cout << s.second << " db \'" << s.first << "\', 0\n";
        else
            std::cout << s.second << " db \'" << s.first << "\', 0\n";
    return "";
}

std::string IdentsHandler::genVarNames() {
    std::cout << "; Variables\n";
    for (const auto& s : varNames) {
        std::cout << s.first << " dd " << (s.second == -1 ? 0 : s.second) << "\n";
    }
    std::cout << "; Temp variables\n";
    for (const auto& s : tmpNames) {
        std::cout << s << ": dd 0\n";
    }
    return "";
}

bool IdentsHandler::isGlobalVar(std::string name){
    if(varNames.find(name) == varNames.end())
        return false;
    return true;
}