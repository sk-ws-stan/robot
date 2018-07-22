cmake_minimum_required( VERSION 2.8.4 )

option( BUILD_UNIT_TEST "unit tests?" OFF )

set( SOURCE_CODE_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE PATH "src" )

add_subdirectory( ${SOURCE_CODE_BASE_DIR} )
include_directories( ${SOURCE_CODE_BASE_DIR} )
link_directories( ${SOURCE_CODE_BASE_DIR} )

set( THIRD_PARTY_ROOT "set_third_party_root_yourself" CACHE PATH "Third party root directory" )

if( ${BUILD_UNIT_TEST} )
    if( EXISTS ${THIRD_PARTY_ROOT}/boost)
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
        set( Boost_ADDITIONAL_VERSIONS "1.50.0;1.50"
             CACHE STRING "List of boost versions not yet searched for by cmake" )
        find_package( Boost 1.50 REQUIRED
            test_exec_monitor
            unit_test_framework )
        INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
        message( STATUS "Boost_LIBRARY_DIRS=${Boost_LIBRARY_DIRS}")
        LINK_DIRECTORIES( ${Boost_LIBRARY_DIRS} )
    else()
        message( FATAL_ERROR "Boost directory does not exist in THIRD_PARTY_ROOT: ${THIRD_PARTY_ROOT}/boost" )
    endif()

    add_subdirectory( test )
endif()

set( TARGET toy_robot )

add_executable( ${TARGET}
    main.cpp
)

target_link_libraries( ${TARGET}
    LIB_ROBOT
)
