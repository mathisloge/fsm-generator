#include <tinyxml2.h>
#include "xml/fsm_element.h"

int main()
{
    tinyxml2::XMLDocument doc;
	doc.LoadFile( "/media/mathis/ubuntu/fsm-generator/test.xml" );


    FsmElement fsm_el(doc.RootElement());

    fsm_el.process();
    
}