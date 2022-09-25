# CMakeList.txt : CMake project for SolarSystem, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Pong")

# Add source to this project's executable.
add_executable (Pong "Pong.cpp" "Pong.h" "Player.cpp" "Player.h" "Enemy.cpp" "Enemy.h" "Ball.cpp" "Ball.h")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Pong PRIVATE sfml-system sfml-window sfml-graphics)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
