# Create a library 
set(useful_headers_for_IDE ./common.h
)

add_library (utils benchmark.cpp 
logger.cpp 
result.cpp
test_analyser.cpp
${useful_headers_for_IDE}
)

# Make sure the compiler can find include files for our utils library
# when other libraries or executables link to bitscan
target_include_directories (utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


option(utils_build_tests "Build utils tests." OFF)
if (utils_build_tests)

# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (test_utils ./tests/gtest_main.cc
./tests/test_batch.cpp
./tests/test_benchmark.cpp
./tests/test_common.cpp
./tests/test_file.cpp
./tests/test_logger.cpp
#FIXME ./tests/test_result.cpp
#./tests/test_stress_timer.cpp
./tests/test_tanal.cpp
#./tests/test_thread.cpp
#./test_analyser.cpp
)

target_include_directories (test_utils PUBLIC ../googletest/include/)
# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (test_utils LINK_PUBLIC utils gtest)

endif()

install(TARGETS utils DESTINATION lib)
