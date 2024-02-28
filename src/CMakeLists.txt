cmake_minimum_required(VERSION 3.8.0)

add_executable(33_2_fishing main.cpp ${MY_INCLUDE_DIR}/game.h game.cpp)

target_include_directories(33_2_fishing PUBLIC ${MY_INCLUDE_DIR})