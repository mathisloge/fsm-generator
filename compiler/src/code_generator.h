#pragma once
#include "xml/fsm_element.h"
#include <filesystem>
class CodeGenerator
{
public:
    explicit CodeGenerator(const FsmElement &main_fsm);
    void generateCode(std::filesystem::path output_path);
    ~CodeGenerator();

private:
    const FsmElement &main_fsm_;
};