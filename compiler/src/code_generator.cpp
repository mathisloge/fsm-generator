#include "code_generator.h"
#include <ostream>
#include <fstream>
#include "codegen/event.h"
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
    output_path.append(main_fsm_.name() + ".h");
    std::ofstream ofs(output_path);
    
    for(const auto& event_el : main_fsm_.events())
    {
        event::generateEvent(ofs, *event_el.second);
    }
}

CodeGenerator::~CodeGenerator()
{
}