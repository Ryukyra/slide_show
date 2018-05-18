project(slide_show)

cmake_minimum_required(VERSION 3.7)

find_package(wxWidgets COMPONENTS core base REQUIRED)

include( "${wxWidgets_USE_FILE}")

set(SOURCE_FILES)

add_executable(${PROJECT_NAME} slide.h slide.cpp main.cpp main.h)

target_link_libraries(
        ${PROJECT_NAME}
        ${wxWidgets_LIBRARIES}
)