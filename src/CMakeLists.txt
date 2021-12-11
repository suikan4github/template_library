# Project Parameters.
# File name of main()
set(MAIN_FILE_PATTERN ".*/main.cpp$")

#----------------------------------------------------------------------------
# Do not edit the lines below 

# Project Parameters.
# Library name
include("parameters.cmake")

# Executable name
set(EXECUTABLE_NAME "dev_${MY_LIBRARY_NAME}")

# List up all source files including main.cpp
file(GLOB ALL_SRCS "*.cpp")

# Executable if needed
add_executable(${EXECUTABLE_NAME} 
    ${ALL_SRCS})

# Add pthread library to support std::thread
# In the case of MSVC, this is not required.
if (NOT(MSVC))
    target_link_libraries(${EXECUTABLE_NAME} "pthread")
endif(NOT(MSVC))


# Remove the "main file" from list to create a library for test
set( LIB_SRCS ${ALL_SRCS})                                  # create a new list as copy
list(FILTER LIB_SRCS EXCLUDE REGEX ${MAIN_FILE_PATTERN})    # Filter out the main file

# Library to develop ( without main file)
add_library(${MY_LIBRARY_NAME} STATIC
    ${LIB_SRCS})


