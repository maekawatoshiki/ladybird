cmake_minimum_required(VERSION 3.21)

add_executable(LibJSSample LibJSSample.cpp)

target_link_libraries(LibJSSample
    PRIVATE
        AK
        LibCore
        LibUnicode
        LibJS
        LibGC
)
