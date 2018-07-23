cmake_minimum_required( VERSION 2.8.4 )

set( PROJECT toy_robot )

set( SOURCE_CODE_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE PATH "src" )

set( THIRD_PARTY_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/3rd" CACHE PATH "Third party root directory" )

#setting this for gcc legacy build system
if( NOT CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.7 )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
endif()

option( BUILD_UNIT_TEST "unit tests?" ON )

if( EXISTS ${THIRD_PARTY_ROOT}/boost )
    add_definitions( -DBOOST_CB_DISABLE_DEBUG )
    set( CMAKE_PREFIX_PATH ${THIRD_PARTY_ROOT}/boost )
    set( Boost_DEBUG 1 )
    set( BOOST_ROOT
        ${THIRD_PARTY_ROOT}/boost
        CACHE PATH "Boost Root Directory" )
    set( BOOST_INCLUDEDIR
        ${THIRD_PARTY_ROOT}/boost/include
        CACHE PATH "Boost Include Directory" )
    set( BOOST_LIBRARYDIR
        ${THIRD_PARTY_ROOT}/boost/lib
        CACHE PATH "Boost Library Directory" )
    set( Boost_NO_SYSTEM_PATHS ON )
    set( Boost_USE_STATIC_LIBS ON
        CACHE BOOL "Link against Static Boost libraries" )
    set( Boost_USE_STATIC_RUNTIME OFF
        CACHE BOOL "Use static runtime library" )
    set( Boost_USE_MULTITHREADED ON
        CACHE BOOL "Link against multithreaded Boost Libraries" )
    set( Boost_ADDITIONAL_VERSIONS "1.50.0;1.50;1.61.0;1.61"
        CACHE STRING "List of boost versions not yet searched for by cmake" )
    find_package( Boost REQUIRED unit_test_framework )
    include_directories( ${Boost_INCLUDE_DIRS} )
    message( STATUS "Boost_LIBRARY_DIRS=${Boost_LIBRARY_DIRS}")
    LINK_DIRECTORIES( ${Boost_LIBRARY_DIRS} )
else()
    #conan install generates its own Findboost.cmake, however it is incapable of static linking
    find_package( Boost )
    # lower case through conan's Findboost.cmake
    include_directories( ${boost_INCLUDE_DIRS} )
    #can't link statically - commenting out and turnung off build for unit tests
    #message( STATUS "Boost_LIBRARY_DIRS=${boost_LIB_DIRS}")
    #LINK_DIRECTORIES( ${boost_LIB_DIRS} )
    set( BUILD_UNIT_TEST OFF )
endif()

add_subdirectory( ${SOURCE_CODE_BASE_DIR} )
include_directories( ${SOURCE_CODE_BASE_DIR} )
link_directories( ${SOURCE_CODE_BASE_DIR} )

if( ${BUILD_UNIT_TEST} )
    add_subdirectory( test )
endif()

set( TARGET toy_robot )

add_executable( ${TARGET}
    main.cpp
)

target_link_libraries( ${TARGET}
    LIB_ROBOT
)
