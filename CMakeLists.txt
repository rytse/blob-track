cmake_minimum_required( VERSION 3.6 )
project( blob-track )
find_package( OpenCV REQUIRED )
#add_executable(blob-track main.cpp filters.cpp filters.h)
target_link_libraries(blob-track ${OpenCV_LIBS} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp)
add_executable(blob-track ${SOURCE_FILES} src/main.cpp include/main.h)