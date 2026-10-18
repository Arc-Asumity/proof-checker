add_library(ProofChecker_UI_Widget Rectangle.cpp)
add_library(ProofChecker::UI::Widget ALIAS ProofChecker_UI_Widget)
target_include_directories(ProofChecker_UI_Widget PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProofChecker_UI_Widget PUBLIC ProofChecker::UI)
