# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)

project ("tasks_week_3_Asher_Mentzer")

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()
# TODO: Add tests and install targets if needed.
# Add source to this project's executable.
add_executable (ex02 "" )


# Include sub-projects.
# add_subdirectory ("tasks_week_3_Asher_Mentzer")
add_subdirectory (include)
add_subdirectory (src)

