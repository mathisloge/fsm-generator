#include <filesystem>
#include <tinyxml2.h>
#include "xml/fsm_element.h"
#include "code_generator.h"

int main()
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile("/media/mathis/ubuntu/fsm-generator/test.xml");

    FsmElement fsm_el{doc.RootElement()};

    fsm_el.process();

    CodeGenerator code_gen{fsm_el};

    code_gen.generateCode(std::filesystem::path("/media/mathis/ubuntu/fsm-generator/example/src/gen"));
}