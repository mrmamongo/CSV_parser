cmake_minimum_required(VERSION 3.12)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_DOCS "Build documentation" OFF)
option(BUILD_COVERAGE "Build code coverage" OFF)

set(
        HUNTER_CACHE_SERVERS
        "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
        CACHE STRING "Default cache server"
)

include("cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.278.tar.gz"
        SHA1 "35fa55bc1dfcf9f4d7264f8bb26cd1759ce1ae07"
)


project(Producer_Consumer)

find_package(Threads)

include_directories(third-party/PicoSHA2)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json)

hunter_add_package(Boost COMPONENTS log thread system filesystem program_options)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
hunter_add_package(Boost)

find_package(Boost COMPONENTS log log_setup thread system filesystem program_options)

#===================== QUEUE ==========================
add_library( sync_queue INTERFACE)

target_include_directories(sync_queue INTERFACE include/queue)

add_library(Producer_Consumer::sync_queue ALIAS sync_queue)
#=====================================================


#===================== HASHER ==========================
add_library( hasher INTERFACE)
target_include_directories(hasher INTERFACE include/hasher)
target_link_libraries(hasher INTERFACE nlohmann_json::nlohmann_json pthread ${Boost_LIBRARIES} Boost::boost)
add_library(Producer_Consumer::hasher ALIAS hasher)
#======================================================

#===================== CONSOLE ==========================
add_library( console STATIC soruces/console.cpp)

target_include_directories(console PUBLIC include/console)
target_link_libraries(console  Boost::log Boost::log_setup Boost::thread Boost::system Boost::filesystem Boost::program_options pthread Boost::boost Producer_Consumer::hasher Producer_Consumer::sync_queue)
add_library(Producer_Consumer::console ALIAS console )
#======================================================

add_executable(Producer_Consumer soruces/main.cpp)
target_link_libraries(Producer_Consumer pthread Producer_Consumer::console)
