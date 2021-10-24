include(ExternalProject)
cmake_minimum_required(VERSION 3.12)

project(pmu2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -g -std=c++14 -Wextra -pthread")
set(STAGING_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")

###################### Libraries ###################
ExternalProject_Add(spdlog
    PREFIX spdlog
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/ext/spdlog
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
    -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
    -DCMAKE_INSTALL_PREFIX=${STAGING_DIR}
    -DSPDLOG_BUILD_SHARED=OFF
)

find_package(cppzmq REQUIRED)

set(SRC_FILES
    src/Log.cpp  
    src/PmuDataGenerator.cpp 
    src/ZmqStreamer.cpp
)

add_library(${PROJECT_NAME} ${SRC_FILES})

add_subdirectory(ext/gtest)

###################### Executable ###################
target_include_directories(${PROJECT_NAME}
    PUBLIC ext/sdplog/include/
    PUBLIC ${STAGING_DIR}/include/
    PUBLIC ext/gtest/googletest/include
)

add_dependencies(${PROJECT_NAME} spdlog)

add_executable(${PROJECT_NAME}_sandbox src/sandboxApp.cpp)

target_link_libraries(${PROJECT_NAME}_sandbox 
    ${PROJECT_NAME}
    cppzmq    
)
