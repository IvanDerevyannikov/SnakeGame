
# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

set (CMAKE_TOOLCHAIN_FILE "C:/DEV/vcpkg/scripts/buildsystems/vcpkg.cmake")

project ("SnakeGame")

# Включите подпроекты.
add_subdirectory ("SnakeGame")