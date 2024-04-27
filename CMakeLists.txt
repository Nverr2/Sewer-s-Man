cmake_minimum_required(VERSION 3.27)
project(Culvert_s_Man)

set(CMAKE_CXX_STANDARD 17)

add_executable(Culvert_s_Man main.cpp
        src/menu.cpp
        src/Player.cpp
        headers/Arma.h
        src/Arma.cpp
)

include_directories(headers /usr/include c:/SFML/include)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Culvert_s_Man ${SFML_LIBRARIES})
endif ()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
