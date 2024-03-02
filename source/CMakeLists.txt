set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/source)

# requires C++11 or higher features
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
endif()

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR})

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(SinglyLinkedList ${PROJECT_SOURCE_DIR}/SinglyLinkedList.cpp)

if(MSVC)
    add_compile_options("/Zc:__cplusplus")
endif()

add_test(NAME Test1 COMMAND $<TARGET_FILE:SinglyLinkedList>)