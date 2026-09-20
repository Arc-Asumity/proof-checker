cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)

project(ProofChecker C CXX)

set(PROJECT_VERSION 0.1.0)

set(PROJECT_RELEASE 1)
set(PROJECT_DESCRIPTION "A Mathematics proof checker")

include(cmake/Deps.cmake)

add_subdirectory(src)
