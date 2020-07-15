cmake_minimum_required(VERSION 3.17)

cmake_policy(SET CMP0048 NEW)

project(
	PooleEngineSandbox 
	VERSION 0.0.0 
	LANGUAGES CXX
)

if (MSVC)
    # add_compile_options(/W4 /WX)
    add_compile_options(/W4)
else()
    # add_compile_options(-W -Wall -Werror)
    add_compile_options(-W -Wall)
endif()

# It is always easier to navigate in an IDE when projects are organized in folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(PooleEngine)   #IMPORTANT Note: Add Library First
add_subdirectory(Sandbox) 	#                Then exe after for dependancies

# Setup our project as the startup project for Visual so that people don't need to do it manually
set_directory_properties(PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")