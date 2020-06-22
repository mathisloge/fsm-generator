#pragma once
#include <map>
#include <string>
#include <ostream>
#include "../xml/event_element.h"
#include "../xml/state_element.h"

namespace state
{
    void generateState(std::ostream &input,
                       const std::shared_ptr<StateElement> &state_el,
                       const std::map<std::string, std::shared_ptr<EventElement>> &events);
} // namespace state