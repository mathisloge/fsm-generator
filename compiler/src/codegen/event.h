#pragma once
#include <ostream>
#include "../xml/event_element.h"

namespace event {
    void generateEvent(std::ostream& input, const EventElement& event_el);
}