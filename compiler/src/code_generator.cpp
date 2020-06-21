#include "code_generator.h"


namespace fs = std::filesystem;
CodeGenerator::CodeGenerator(const FsmElement &main_fsm)
    : main_fsm_(main_fsm)
{
}

void CodeGenerator::generateCode(fs::path output_path)
{
    if(!fs::is_directory(output_path)) {
        throw std::runtime_error("the output path needs to be an directory");
    }

    
}

CodeGenerator::~CodeGenerator()
{
}