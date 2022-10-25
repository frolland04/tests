PROJECT(HelloWorld)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_CXX_STANDARD 11)
INCLUDE(CMakePrintHelpers)

# Get package info for Boost
FIND_PACKAGE(Boost 1.70 COMPONENTS locale system filesystem REQUIRED)

# Get package info for Cppzmq and Libzmq
FIND_PACKAGE(cppzmq REQUIRED)

# Get package info for Libnmea
FIND_PACKAGE(libnmea REQUIRED)
SET(LIBNMEA_LIBRARIES /usr/local/lib/libnmea.a)

# Get package info for Spdlog
FIND_PACKAGE(spdlog REQUIRED)

# Set the target info
ADD_EXECUTABLE(hello_world main.cpp)
TARGET_LINK_LIBRARIES(hello_world cppzmq spdlog::spdlog ${LIBNMEA_LIBRARIES} ${Boost_LIBRARIES})


