add_library(ProofCheckerUi UiCore.cpp)
target_include_directories(ProofCheckerUi PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProofCheckerUi PUBLIC imgui)
