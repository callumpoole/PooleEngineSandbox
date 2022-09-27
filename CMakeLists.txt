cmake_minimum_required(VERSION 3.17)

cmake_policy(SET CMP0048 NEW)

project(
	PooleEngineSudoku 
	VERSION 0.0.0 
	LANGUAGES CXX
)

if (MSVC)
    # add_compile_options(/W4 /WX)
    add_compile_options(/W4 /wd4505 /wd4201)
else()
    # add_compile_options(-W -Wall -Werror)
    add_compile_options(-W -Wall)
endif()

# It is always easier to navigate in an IDE when projects are organized in folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(poole_engine)
add_subdirectory(sudoku)

# Setup our project as the startup project for Visual so that people don't need to do it manually
set_directory_properties(PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")