project(slide_show)
cmake_minimum_required(VERSION 3.7)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include( "${wxWidgets_USE_FILE}")


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

add_executable(${PROJECT_NAME} Slideshow.h Slideshow.cpp Launch.cpp Launch.h Constants.h)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

add_subdirectory(unit_testing)
