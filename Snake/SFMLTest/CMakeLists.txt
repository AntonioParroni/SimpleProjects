cmake_minimum_required(VERSION 3.17)
project(SFMLTest)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFMLTest main.cpp)
target_link_libraries(SFMLTest sfml-graphics sfml-audio)