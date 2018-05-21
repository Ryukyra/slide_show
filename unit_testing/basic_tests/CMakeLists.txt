include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})
add_executable(unit_testing Test.cpp)
target_link_libraries(unit_testing gtest gtest_main)