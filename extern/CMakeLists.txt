#From https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/#:~:text=%23%20NOTE%3A%20This%20helper,target%7D%20%24%7B_srcList%7D)%0Aendfunction()
#as a nice backwards compatible setup for target_sources
# NOTE: This helper function assumes no generator expressions are used
#       for the source files
function(target_sources_local target)
  if(POLICY CMP0076)
    # New behavior is available, so just forward to it by ensuring
    # that we have the policy set to request the new behavior, but
    # don't change the policy setting for the calling scope
    cmake_policy(PUSH)
    cmake_policy(SET CMP0076 NEW)
    target_sources(${target} ${ARGN})
    cmake_policy(POP)
    return()
  endif()

  # Must be using CMake 3.12 or earlier, so simulate the new behavior
  unset(_srcList)
  get_target_property(_targetSourceDir ${target} SOURCE_DIR)

  foreach(src ${ARGN})
    if(NOT src STREQUAL "PRIVATE" AND
       NOT src STREQUAL "PUBLIC" AND
       NOT src STREQUAL "INTERFACE" AND
       NOT IS_ABSOLUTE "${src}")
      # Relative path to source, prepend relative to where target was defined
      file(RELATIVE_PATH src "${_targetSourceDir}" "${CMAKE_CURRENT_LIST_DIR}/${src}")
    endif()
    list(APPEND _srcList ${src})
  endforeach()
  target_sources(${target} ${_srcList})
endfunction()

#Here is where you list the UEB sources needed
target_sources_local(UEBmilib
    PRIVATE
        UEB/canopy.cpp
        UEB/matrixnvector.cpp
        #UEB/ncfunctions_mswin.cpp TODO is this needed, or only in windows builds?
        UEB/ncfunctions.cpp
        UEB/snowdgtv.cpp
        UEB/snowdv.cpp
        UEB/snowxv.cpp
        UEB/uebdecls.cpp
        UEB/uebinputs.cpp
        UEB/uebpgdecls.h
)

#To set complier directives
#target_compile_definitions(UEBlib PUBLIC USE_X)
#Set the include search path
target_include_directories(UEBmilib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/UEB)