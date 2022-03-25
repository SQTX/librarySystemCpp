cmake_minimum_required(VERSION 3.20)
project(librarySystem)

set(CMAKE_CXX_STANDARD 14)
set(standardPath src/pl/sqtx/liblary)

#add_executable(librarySystem src/pl/sqtx/liblary/app/main.cpp src/pl/sqtx/liblary/model/book.cpp)
add_executable(librarySystem
#        app
        ${standardPath}/app/main.cpp
        ${standardPath}/app/libraryControl.cpp
#        exception
        ${standardPath}/exception/noSuchOptionException.cpp
        ${standardPath}/exception/dataImportException.cpp
        ${standardPath}/exception/dataExportException.cpp
#        io
        ${standardPath}/io/dataReader.cpp
        ${standardPath}/io/consolePrinter.cpp
    #        file
            ${standardPath}/io/file/serializableFileManager.cpp
#                typesOfData
                ${standardPath}/io/file/typesOfData/publicationsData.cpp
                ${standardPath}/io/file/typesOfData/usersData.cpp
#        model
        ${standardPath}/model/library.cpp
        ${standardPath}/model/libraryUser.cpp
#            publications
            ${standardPath}/model/publications/publication.cpp
            ${standardPath}/model/publications/book.cpp
            ${standardPath}/model/publications/magazine.cpp
#            users
            ${standardPath}/model/users/user.cpp
#           sortData
            ${standardPath}/model/sortData/sortByTitle.cpp
            ${standardPath}/model/sortData/sortByDate.cpp
        )
