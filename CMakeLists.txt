cmake_minimum_required(VERSION 3.20)
project(librarySystem)

set(CMAKE_CXX_STANDARD 14)
set(standardPath src/pl/sqtx/liblary)

#add_executable(librarySystem src/pl/sqtx/liblary/app/main.cpp src/pl/sqtx/liblary/model/book.cpp)
add_executable(librarySystem
#        app file
        ${standardPath}/app/main.cpp
        ${standardPath}/app/libraryControl.cpp
        ${standardPath}/app/option.cpp
#        io
        ${standardPath}/io/dataReader.cpp
#        model
        ${standardPath}/model/book.cpp
        ${standardPath}/model/magazine.cpp
        ${standardPath}/model/publication.cpp
        ${standardPath}/model/library.cpp
        )
