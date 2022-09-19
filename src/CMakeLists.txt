cmake_minimum_required(VERSION 3.0)

set (UEB_VERSION 0.1)
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/uebcxx.pc.cmake
                ${CMAKE_BINARY_DIR}/uebcxx.pc)

set(bmi_ueb_lib_SRCS bmi/ControlFile.cxx)
if(WIN32)
  add_library(bmiuebcxx ${bmi_ueb_lib_SRCS})
else()
  add_library(bmiuebcxx SHARED ${bmi_ueb_lib_SRCS})
endif()

add_executable(run_bmiuebcxx bmi/bmi_main.cxx bmi/ControlFile.cxx)

install(
  TARGETS run_bmiuebcxx
  RUNTIME DESTINATION bin
)
install(
  TARGETS bmiuebcxx
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)
install(
  FILES bmi/ControlFile.hxx
  DESTINATION include
)
install(
  FILES ${CMAKE_BINARY_DIR}/uebcxx.pc
  DESTINATION lib/pkgconfig
)
