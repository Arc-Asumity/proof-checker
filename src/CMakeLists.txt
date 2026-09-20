add_executable(ProofChecker Main.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    if (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
        set_target_properties(ProtocolLab PROPERTIES WIN32_EXECUTABLE TRUE)
    endif ()
endif ()

target_include_directories(ProofChecker PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProofChecker PRIVATE ProofCheckerUi)

add_subdirectory(ui)
