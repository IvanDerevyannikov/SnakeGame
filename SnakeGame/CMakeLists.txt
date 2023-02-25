# CMakeList.txt: проект CMake для CMakevcpkgSfmlProject; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (SnakeGame "SnakeGame.cpp" "SnakeGame.h" "AllClasses.h" "AllClasses.cpp")

target_link_libraries(SnakeGame PRIVATE sfml-system sfml-network sfml-graphics sfml-window)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SnakeGame PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
