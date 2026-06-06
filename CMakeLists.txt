cmake_minimum_required(VERSION 3.14)
project(Tetris)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# Set standar C++ ke C++17 atau C++20 (Wajib untuk SFML 3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Beritahu CMake lokasi file konfigurasi SFML di dalam folder sfml-lib
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sfml-lib/lib/cmake/SFML")

# Cari library SFML yang diinstall vcpkg
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

# Tentukan file cpp kamu
add_executable(${PROJECT_NAME} src/main.cpp 
src/Engine.cpp include/Engine.hpp 
src/Render.cpp include/Render.hpp 
src/SceneManager.cpp include/SceneManager.hpp 
include/structData.hpp)

# Otomatis copy DLL SFML ke folder output executable
# add_custom_command(TARGET Tetris POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         "$<TARGET_FILE_DIR:SFML::Graphics>/*.dll" # Mengambil semua dll dari target SFML
#         "$<TARGET_FILE_DIR:Tetris>"               # Dipindahin ke folder Tetris.exe
#     COMMAND_EXPAND_LISTS
# )

# Hubungkan project dengan SFML
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Window SFML::System)