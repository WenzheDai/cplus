cmake_minimum_required(VERSION 3.28)

project(Opencv)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: 	${OpenCV_VERSION}")
message(STATUS "    headers: 	${OpenCV_INCLUDE_DIRS}")
message(STATUS "    libraries: 	${OpenCV_LIBS}")

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Opencv t1.cpp)
target_link_libraries(Opencv ${OpenCV_LIBS})