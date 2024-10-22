cmake_minimum_required( VERSION 3.22 )

project( mdnorm CXX)

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Set a default build type if none was specified
# https://blog.kitware.com/cmake-and-the-default-build-type/
set (default_build_type "Release")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message (STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set (CMAKE_BUILD_TYPE "${default_build_type}" CACHE
       STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property (CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
else ()
  message (STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
endif ()

set(HIGHFIVE_GIT_REPOSITORY https://github.com/BlueBrain/HighFive.git)
set(HIGHFIVE_GIT_TAG v3.0.0-beta1)
set(HIGHFIVE_UNIT_TESTS OFF)
set(HIGHFIVE_USE_BOOST OFF)
set(HIGHFIVE_USE_EIGEN ON)

include(FetchContent)
FetchContent_Declare(HighFive
  GIT_REPOSITORY ${HIGHFIVE_GIT_REPOSITORY}
  GIT_TAG ${HIGHFIVE_GIT_TAG}
)
FetchContent_MakeAvailable(HighFive)

find_package(Eigen3 REQUIRED)

add_executable(read read.cpp)
target_link_libraries(read Eigen3::Eigen HighFive)

add_executable(read_raw read_raw.cpp)
target_link_libraries(read_raw Eigen3::Eigen HighFive)

