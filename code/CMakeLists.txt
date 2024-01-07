cmake_minimum_required(VERSION 3.10)
project(trial VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Warning flags
SET(WARNING_FLAG OFF)     # On for showing the warning
if(WARNING_FLAG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat-security")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-conversion")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wduplicated-cond")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wlogical-not-parentheses")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnull-dereference")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wdouble-promotion")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pie")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIE")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--exclude-libs,ALL")
endif()

find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/basic_processing")
include_directories("${PROJECT_SOURCE_DIR}/Edge_detector")
include_directories("${PROJECT_SOURCE_DIR}/Contouring")

add_subdirectory(basic_processing)
add_subdirectory(Edge_detector)
add_subdirectory(Contouring)

####### GTests ########
SET(GTEST OFF)     # On for build the unitest, off for not
if(GTEST)
  add_subdirectory(unitTests/lib/googletest)
  add_subdirectory(unitTests)
endif()

add_executable(TRIAL
  main.cpp
)

target_link_libraries(TRIAL
  ${OpenCV_LIBS} 
  ${CMAKE_THREAD_LIBS_INIT}
  trial_basic_processing
  trial_Edge_detector
  trial_Contouring
)

# Set the path to the directory where all project artifacts should be installed, based on config option from cmake
if(NOT DEFINED VAL_INSTALL_DIR)
	set(VAL_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/trial)
endif()

add_compile_definitions(VAL_INSTALL_DIR="${VAL_INSTALL_DIR}")

# Install targets
install(TARGETS TRIAL
  RUNTIME DESTINATION ${VAL_INSTALL_DIR}
)
