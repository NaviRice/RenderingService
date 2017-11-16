cmake_minimum_required(VERSION 3.8)
project(rendering)

set(CMAKE_CXX_STANDARD 11)

set(SERVICE_SOURCE_FILES RenderingService.cpp RenderingService.hpp ../common/Service.cpp ../common/Service.hpp ../common/Socket.cpp ../common/Socket.hpp)
set(CLIENT_SOURCE_FILES Client.cpp Client.hpp ../common/Socket.cpp ../common/Socket.hpp)

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
#set(LIBRARIES /usr/local/lib/libprotobuf.15.dylib)
#target_link_libraries(rendering ${LIBRARIES})