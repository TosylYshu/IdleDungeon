cmake_minimum_required(VERSION 3.14)
project(ch13)

set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} SHARED
src/campsite.cpp
src/explorer.cpp
src/lead_room.cpp
src/monster.cpp
src/monster_leader.cpp
src/normal_room.cpp
src/role.cpp
src/trap_room.cpp
src/weapon.cpp
src/weapon_room.cpp
)

add_executable(run demo/run.cpp)
target_link_libraries(run ${PROJECT_NAME})
