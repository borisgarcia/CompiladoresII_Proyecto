#ifndef _TEMP_HANDLER_H_
#define _TEMP_HANDLER_H_

#include <string>
#include <list>
#include <sstream>
#include <memory>
#include <unordered_set>
#include <unordered_map>

class FuncDef {
public:
    FuncDef(const std::string& name, const std::string& type): name(name), type(type),paramOffset(4), varOffset(0) {}

    bool registerParam(const std::string& pname) 
    {
        if (params.find(pname) != params.end()) {
            return false;
        }
        paramOffset += 4;
        params.emplace(pname, paramOffset);
        
        return true;
    }

    bool registerVar(const std::string& vname) 
    {
        if (vars.find(vname) != vars.end()) {
            return false;
        }
        varOffset -= 4;
        vars.emplace(vname, varOffset);

        return true;
    }

    int getVarOffset(const std::string& vname) 
    {
        auto it = vars.find(vname); 
        if (it == vars.end()) {
            return 0;
        }
        return it->second; 
    }

    std::string getType()
    {
        return type;
    }

    int getParamOffset(const std::string& pname) 
    {
        auto it = params.find(pname); 
        if (it == params.end()) {
            return 0;
        }
        return it->second; 
    }

    int newVarOffset() {
        varOffset -= 4;
        return varOffset;
    }

    std::string getEpilogLabel() { return "__lbl_" + name + "_epilog"; }
    std::string getName() { return name; }
    int getParamCount() { return params.size(); }
    int getParamSize() { return (paramOffset - 8 + 4); }
    int getVarSize() { return (varOffset * -1); }

private:
    std::string name;
    std::unordered_map<std::string, int> params;
    std::unordered_map<std::string, int> vars;
    int paramOffset;
    int varOffset;
    std::string type;
};

using UPFuncDef = std::unique_ptr<FuncDef>;

class IdentsHandler {
public:
    IdentsHandler(): varCount(0), slitCount(0), lblCount(0) {}
    ~IdentsHandler() {}

    bool isGlobalVar(std::string name);
    void genPrintLiterals();

    std::string newTemp();
    std::string registerStrLiteral(const std::string& str);
    std::string genVarNames();
    std::string genConstNames();

    std::string genNewLabel() 
    {
        std::ostringstream ss;
        ss << "lbl" << lblCount++;
        return ss.str();
    }

    bool findFunc(const std::string& name) 
    {
        return (funcDefMap.find(name) != funcDefMap.end());
    }

    void setCurrentFuncDef(const std::string& funcName) 
    {
        auto it = funcDefMap.find(funcName);

        if (it == funcDefMap.end()) {
            currFD = nullptr;
        } else {
            currFD = it->second.get();
        }
    }

    void registerVar(const std::string& vname, int val) 
    {
        if (varNames.find(vname) == varNames.end()) {
            varNames[vname] = val;
        }
    }

    bool registerFuncDef(UPFuncDef&& funcDef) 
    {
        funcDefMap.insert( std::make_pair(funcDef->getName(), std::move(funcDef)) );
        return true;
    }

    bool registerLocalVar(const std::string& vname) 
    {
        if (currFD == nullptr) {
            return false;
        }
        currFD->registerVar(vname);
        return true;
    }

    int getVarOffset(const std::string& name) 
    {
        if (currFD == nullptr) {
            return 0;
        }
        int offset = currFD->getParamOffset(name);
        if (offset == 0) {
            offset = currFD->getVarOffset(name);
        }
        return offset;
    }

    FuncDef *getFuncDef(const std::string& fname) 
    {
        auto it = funcDefMap.find(fname);

        if (it == funcDefMap.end()) {
            return nullptr;
        } else {
            return it->second.get();
        }
    }

    FuncDef *getCurrentFuncDef() 
    { 
        return currFD; 
    }
   
private:
    std::unordered_map<std::string, std::string> strlitMap;
    std::unordered_map<std::string,int> varNames;
    std::unordered_map<std::string, UPFuncDef> funcDefMap;
    std::list<std::string> tmpNames;
    FuncDef *currFD;
    int varCount;
    int slitCount;
    int lblCount;
};

#endif
