cmake_minimum_required(VERSION 3.20)

project(polevoi-d-v-23-00)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO bin.relwithdbg)

option(BUILD_WITH_CODEFORCES "Build prj.codeforces targets" off)

if (BUILD_WITH_CODEFORCES)
  add_subdirectory(prj.codeforces)
endif()

add_subdirectory(prj.lab)
add_subdirectory(prj.test)

set(CMAKE_CXX_STANDARD 20)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "D:/.dima/2023-misis-check/misis2023f-23-00-polevoi-d-v/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "D:/.dima/2023-misis-check/misis2023f-23-00-polevoi-d-v/bin.dbg")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "D:/.dima/2023-misis-check/misis2023f-23-00-polevoi-d-v/bin.check")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "D:/.dima/2023-misis-check/misis2023f-23-00-polevoi-d-v/bin.relwithdbg")
add_subdirectory(prj.check)