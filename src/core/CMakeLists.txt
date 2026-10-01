add_library(ProofChecker_Core Application.cpp Document.cpp)
add_library(ProofChecker::Core ALIAS ProofChecker_Core)
target_include_directories(ProofChecker_Core PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProofChecker_Core PUBLIC ProofChecker_UI)
