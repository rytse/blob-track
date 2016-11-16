cmake_minimum_required(VERSION 3.5)
project(blob-track)

# Version number
set(blob-track_VERSION_MAJOR 1)
set(blob-track_VERSION_MINOR 0)

# Include headers
#configure_file(
#        "${PROJECT_SOURCE_DIR}/main.h.in"
#        "${PROJECT_SOURCE_DIR}/main.h"
#)

file(GLOB_RECURSE blob-track_SOURCES "src/*.cpp")
file(GLOB_RECURSE blob-track_HEADERS "include/*.h")

set (blob-track_INCLUDE_DIRS "")
foreach (_headerFile ${blob-track_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND blob-track_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES blob-track_INCLUDE_DIRS)

# Include binary tree
include_directories(${blob-track_INCLUDE_DIRS})
#include_directories("${PROJECT_SOURCE_DIR}/src")

# Add executable
add_executable(blob-track ${blob-track_SOURCES} src/hsvfilter.cpp include/hsvfilter.h)

# Get dependencies
find_package(OpenCV REQUIRED)
target_link_libraries(blob-track ${OpenCV_LIBS})
