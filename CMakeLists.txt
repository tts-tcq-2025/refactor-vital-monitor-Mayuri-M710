cmake_minimum_required(VERSION 3.14)
project(bms-monitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Collect source files from subdirectories
file(GLOB_RECURSE CORE_SOURCES "src/core/*.cpp")
file(GLOB_RECURSE CHECKER_SOURCES "src/checkers/*.cpp")
file(GLOB_RECURSE LANGUAGE_SOURCES "src/language/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Combine all source files
set(ALL_SOURCES ${CORE_SOURCES} ${CHECKER_SOURCES} ${LANGUAGE_SOURCES} ${TEST_SOURCES})

add_executable(test-monitor ${ALL_SOURCES})

target_link_libraries(
  test-monitor
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(test-monitor)
