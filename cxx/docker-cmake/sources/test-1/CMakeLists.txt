PROJECT(HelloWorld)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_CXX_STANDARD 17)
INCLUDE(CMakePrintHelpers)

# Get package info for Boost
FIND_PACKAGE(Boost 1.70 COMPONENTS locale system filesystem random thread timer chrono log program_options REQUIRED)

# Get package info for Cppzmq and Libzmq
FIND_PACKAGE(cppzmq REQUIRED)

# Get package info for Libnmea
FIND_PACKAGE(libnmea REQUIRED)
SET(LIBNMEA_LIBRARIES /usr/local/lib/libnmea.a)

# Get package info for Spdlog
FIND_PACKAGE(spdlog REQUIRED)

# Get package info for Nlohmann JSON
FIND_PACKAGE(nlohmann_json 3.2.0 REQUIRED)

# Get package info for Libcpr
FIND_LIBRARY(cpr NAMES cpr REQUIRED)

# Get package info for SDBus-c++
FIND_PACKAGE(sdbus-c++ REQUIRED)

# Get package info for Libblepp
FIND_LIBRARY(ble++ NAMES ble++ REQUIRED)

# Get package info for Tiny BLE
FIND_LIBRARY(tinyb NAMES tinyb REQUIRED)

# Get package info for Websocket++
FIND_PACKAGE(websocketpp REQUIRED)

# Get package info for CppLinuxSerial
FIND_LIBRARY(CppLinuxSerial NAME CppLinuxSerial REQUIRED)

# Get the package info for OpenCV
FIND_PACKAGE(OpenCV REQUIRED)

# Get the package info for Poco
FIND_PACKAGE(Poco REQUIRED Zip JSON Util Net XML)

# Get package info for LMDB++
FIND_LIBRARY(lmdb NAME lmdb REQUIRED)

# Set the target info
ADD_EXECUTABLE(hello_world main.cpp)
TARGET_LINK_LIBRARIES(hello_world PRIVATE ${Poco_LIBRARIES} ${OpenCV_LIBRARIES} CppLinuxSerial tinyb ble++ SDBusCpp::sdbus-c++ cpr nlohmann_json::nlohmann_json spdlog::spdlog ${LIBNMEA_LIBRARIES} cppzmq ${Boost_LIBRARIES} lmdb)


