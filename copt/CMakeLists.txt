# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
set(useful_headers_for_IDE ./clique/clique_types.h
./clique/clique_enum.h
./clique/clique.h
)

add_library (copt ./batch/benchmark_clique.cpp
${useful_headers_for_IDE}
)

# Make sure the compiler can find include files for our bitscan library
# when other libraries or executables link to bitscan
#target_include_directories (copt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (copt PUBLIC ${CMAKE_SOURCE_DIR})


#### SCRIPT to add LEDA to graph library(only Win32)#####
if(LEDA_ON)
#set root depending on installation
set(LEDA_ROOT C:/Leda63/)

#external libraries
include_directories(${LEDA_ROOT}/incl)
link_directories(${LEDA_ROOT})

endif()
###END LEDA ##########


add_executable (greedy_bb ./examples/published_alg.cpp)
IF (UNIX)
        #find_package (Threads)
        target_link_libraries (published_alg ${CMAKE_THREAD_LIBS_INIT})
ENDIF ()
target_link_libraries (greedy_bb LINK_PUBLIC copt graph bitscan utils)
target_include_directories(greedy_bb PUBLIC ../tclap/include)


install(TARGETS copt DESTINATION lib)

#For VSTUDIO found nothing better than to set it globally for all targets
#IF (WIN32)
#find_package(OpenMP)
#IF (OPENMP_FOUND)
#    SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#ENDIF()
#ENDIF (WIN32)

