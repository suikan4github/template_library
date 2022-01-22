# Search for Doxygen package. The result is stored to DOXYGEN_FOUND variable 
find_package(Doxygen)

# Is Doxygen found? 
if(${DOXYGEN_FOUND})

    # Declaration of doxygen command execution
    add_custom_target(documents ALL
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile 
        )

else(${DOXYGEN_FOUND}) 
    # Not found
    message(WARNING "Doxygen package is not found.")
endif(${DOXYGEN_FOUND})