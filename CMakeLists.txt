cmake_minimum_required(VERSION 3.0)

project (bmi-ueb-cxx CXX)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(BMICXX REQUIRED IMPORTED_TARGET bmicxx)
message("--   bmicxx include - ${BMICXX_INCLUDE_DIRS}")
include_directories(${BMICXX_INCLUDE_DIRS})

#Tell cmake we are using UEBlib
add_library(UEBmilib "")
#tell cmake where to find the UEBlib build info
add_subdirectory(extern)

add_subdirectory (src)
#add_subdirectory (testing)

target_link_libraries(UEBmilib PUBLIC bmiuebcxx)

include (CTest)
