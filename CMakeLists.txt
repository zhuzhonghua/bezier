cmake_minimum_required (VERSION 3.5)

project(bezier)

aux_source_directory(. SRC)

SET(TOP ${PROJECT_SOURCE_DIR})

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(.)
set(SDL2_INCLUDE_DIRS "-I/usr/include/SDL2 -D_REENTRANT")
set(SDL2_LIBRARIES "-L/usr/lib/x86_64-linux-gnu -lSDL2 -lfreetype -lSDL2_gfx -lSDL2_ttf -lSDL2_mixer -lSDL2_image")

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}  ${SDL2_INCLUDE_DIRS})

ADD_DEFINITIONS(-DHAVE_CONFIG_H -DPCRE_STATIC -DSUPPORT_UTF -DSUPPORT_UTF8)

add_executable(bezier ${SRC})
target_link_libraries(bezier ${SDL2_LIBRARIES})
