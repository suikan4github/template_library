#----------------------------------------------------------------------------
# Do not edit lines below

# Test executable and library name
set(TEST_EXECUTABLE_NAME test_${PROJECT_NAME})

# List all source file in this directory
file(GLOB TEST_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Add the executable for the testcase which is using googletest
add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SRC})

# Add the library under test.
target_link_libraries(${TEST_EXECUTABLE_NAME}  
                        "gtest_main"
                        ${TEST_LIBRARY_NAME}
                         )
# Add the include directory for test executable.
target_include_directories(${TEST_EXECUTABLE_NAME}
                            PUBLIC
                            "${PROJECT_SOURCE_DIR}/src"
                            )

# Find and integrate the Google Test package

# Load the FetchContent module
# New in CMake 3.11
include("FetchContent")

# Declaration of googletest as content
FetchContent_Declare(
  	"googletest"
  	GIT_REPOSITORY "https://github.com/google/googletest.git"
  	GIT_TAG "release-1.11.0"
)

# Fetch the googletest
FetchContent_MakeAvailable("googletest")

# Include the GoogleTest
include("GoogleTest")

# Search test cases and link 
# New in CMake 3.10
gtest_discover_tests(${TEST_EXECUTABLE_NAME})