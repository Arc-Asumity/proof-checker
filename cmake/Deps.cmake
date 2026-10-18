
include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG v2.0.8
        GIT_SHALLOW TRUE
        SOURCE_SUBDIR cmake
)
FetchContent_MakeAvailable(glad)

glad_add_library(
        ProofChecker_GLAD
        STATIC
        REPRODUCIBLE
        API gl:core=4.6
)
add_library(ProofChecker::GLAD ALIAS ProofChecker_GLAD)

find_package(OpenGL REQUIRED)

add_library(ProofChecker_OpenGL INTERFACE)
target_link_libraries(
        ProofChecker_OpenGL
        INTERFACE
        glfw
        OpenGL::GL
        ProofChecker::GLAD
)
add_library(ProofChecker::OpenGL ALIAS ProofChecker_OpenGL)
