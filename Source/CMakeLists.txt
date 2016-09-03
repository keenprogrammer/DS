cmake_minimum_required (VERSION 2.6)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wwrite-strings")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/../Header/
)

add_executable(MyDs.exe main.c DL.c Main.cpp)

SET(BINS MyDs.exe)
 
INSTALL(TARGETS ${BINS} DESTINATION bin)
