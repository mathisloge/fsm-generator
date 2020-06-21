cmake_minimum_required(VERSION 3.17)
project(fsmcompiler)


find_package(tinyxml2 CONFIG REQUIRED)
add_executable(fsmcompiler 
    src/main.cpp
    src/xml/base_element.cpp
    src/xml/fsm_element.cpp
    src/xml/state_element.cpp
    src/xml/event_element.cpp
    src/xml/guard_element.cpp
    src/xml/transition_element.cpp
)
set_property(TARGET fsmcompiler PROPERTY CXX_STANDARD 20)

target_link_libraries(fsmcompiler PRIVATE tinyxml2::tinyxml2)