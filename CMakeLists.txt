cmake_minimum_required(VERSION 3.18)

project("cryptos")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
find_package(jsoncpp REQUIRED)
pkg_check_modules(CRYPTOPP libcrypto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_EXE_LINKER_FLAGS "-lstdc++ -lpthread")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE) # these are to use the prefered -pthread flag
set(THREADS_PREFER_PTHREAD_FLAG TRUE) # over the -lpthread option

file(GLOB sources ${CMAKE_SOURCE_DIR} src/*.cpp)
file(GLOB source_H ${CMAKE_SOURCE_DIR} src/*.hpp src/*.h)

add_executable("cryptos" ${sources} ${source_H})
target_compile_options("cryptos" PRIVATE -w)
target_link_libraries("cryptos" jsoncpp ${CRYPTOPP})
