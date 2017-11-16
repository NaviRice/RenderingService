cmake_minimum_required(VERSION 3.8)
project(rendering)

set(CMAKE_CXX_STANDARD 11)

# Common libraries
set(PROTOCOL
        ../common/build/control.payload.pb.h
        ../common/build/control.payload.pb.cc
        ../common/build/data.header.payload.pb.h
        ../common/build/data.header.payload.pb.cc
        ../common/build/header.message.pb.h
        ../common/build/header.message.pb.cc
        ../common/build/location.model.pb.h
        ../common/build/location.model.pb.cc)

set(SERVICE ../common/Socket.cpp ../common/Socket.hpp ../common/Service.cpp ../common/Service.hpp)
set(COMMON ${PROTOCOL} ${SERVICE})

# Set source files
set(SERVICE_SOURCE_FILES RenderingService.cpp RenderingService.hpp ${COMMON})
set(CLIENT_SOURCE_FILES Client.cpp Client.hpp ${COMMON})

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set header search path
set(HEADERS /usr/local/include)

include_directories(${HEADERS})


add_executable(server ${SERVICE_SOURCE_FILES})
add_executable(client ${CLIENT_SOURCE_FILES})

# Set library search path
set(LIBRARIES /usr/local/lib/libprotobuf.15.dylib)

target_link_libraries(server ${LIBRARIES})
target_link_libraries(client ${LIBRARIES})