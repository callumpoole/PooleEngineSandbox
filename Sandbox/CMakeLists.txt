add_executable("${PROJECT_NAME}" 
	sandbox.cpp
	sandbox.h
	font_testing.h
	font_testing.cpp
	renderer_testing.h
	renderer_testing.cpp
	collider_testing.h
	collider_testing.cpp)

target_link_libraries("${PROJECT_NAME}" PRIVATE PooleEngine)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set_target_properties(${PROJECT_NAME} PooleEngine
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/${OUTPUTCONFIG}"
		LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/${OUTPUTCONFIG}"
		RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/${OUTPUTCONFIG}"
	)
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
