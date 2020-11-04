cmake_minimum_required(VERSION 2.6)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# and the GTest and pthread library
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
add_executable(runTests unit_test.cpp ../JSON.cpp ../Character.cpp ../Hero.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
