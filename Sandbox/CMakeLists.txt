add_executable("${PROJECT_NAME}" sandbox.cpp)

target_link_libraries("${PROJECT_NAME}" PRIVATE PooleEngine)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

add_custom_command(
    TARGET "${PROJECT_NAME}"
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
	$<TARGET_FILE:PooleEngine>
        $<TARGET_FILE_DIR:PooleEngineSandbox>/$<TARGET_FILE_NAME:PooleEngine>
)