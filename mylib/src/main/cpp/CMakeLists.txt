cmake_minimum_required(VERSION 3.18.1)

project("mylib")

find_library(log-lib log)

get_filename_component(PROJECT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../../.. ABSOLUTE)

add_library(externalLib SHARED IMPORTED GLOBAL)
set_target_properties(externalLib PROPERTIES IMPORTED_LOCATION
    ${PROJECT_FOLDER}/externalDependency/lib/${ANDROID_ABI}/libexternalLibrary.so
)

add_library(internalLib SHARED
    myInternalLibrary/src/internalLibrary.cpp)

add_library(mylib SHARED mylib.cpp )
target_link_libraries(mylib
    android
    ${log-lib}
    internalLib
    externalLib
)
target_include_directories(mylib PRIVATE
    ${PROJECT_FOLDER}/externalDependency/include
    myInternalLibrary/include
)
