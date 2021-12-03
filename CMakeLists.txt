cmake_minimum_required(VERSION 3.20)
project(librarySystem)

set(CMAKE_CXX_STANDARD 14)
set(standardPath src/pl/sqtx/liblary)

#add_executable(librarySystem src/pl/sqtx/liblary/app/main.cpp src/pl/sqtx/liblary/model/book.cpp)
add_executable(librarySystem ${standardPath}/app/main.cpp ${standardPath}/model/book.cpp)
