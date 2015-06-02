#
# Top level CMakeLists.txt
#

cmake_minimum_required( VERSION 3.2 )
 
project( simorbit )

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14")

# The ordering seems important here, OGRE mucks with Boost's library list
find_package( OGRE REQUIRED )
find_package( OIS REQUIRED )
find_package( Boost 1.44 REQUIRED COMPONENTS program_options )

include_directories( ${INCLUDE_DIRECTORIES}
    ${Boost_INCLUDE_DIRS}
#    ${OIS_INCLUDE_DIRS}
#    ${OGRE_INCLUDE_DIRS}
#    ${OGRE_Overlay_INCLUDE_DIRS}
)
link_directories( ${LINK_DIRECTORIES}
    ${Boost_LIBRARY_DIRS}
#    ${OIS_LIBRARY_DIRS}
#    ${OGRE_LIBRARY_DIRS}
#    ${OGRE_Overlay_LIBRARY_DIRS}
)

add_subdirectory( src )

# vim et sw=4 ts=4
