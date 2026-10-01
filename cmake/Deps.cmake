include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

add_library(ProofChecker_OpenGL INTERFACE)
target_link_libraries(ProofChecker_OpenGL INTERFACE glfw OpenGL::GL)
add_library(ProofChecker::OpenGL ALIAS ProofChecker_OpenGL)
