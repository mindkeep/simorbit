#
# Top level CMakeLists.txt
#

cmake_minimum_required( VERSION 3.2 )
 
project( simorbit )

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14")

find_package( Boost 1.32 REQUIRED COMPONENTS program_options )
include_directories( ${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS} )
link_directories( ${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS} )

add_subdirectory( src )
