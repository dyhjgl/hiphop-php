set(CXX_SOURCES)
auto_sources(files "*.cpp" "")
list(APPEND CXX_SOURCES ${files})

add_definitions(-DHPHPI_PATH="hphpi/hphpi")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test_base_suite.inc ${CMAKE_CURRENT_SOURCE_DIR}/test_suite.inc COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test_base_fast.inc ${CMAKE_CURRENT_SOURCE_DIR}/test_fast.inc COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dummy_mysql_info.inc ${CMAKE_CURRENT_SOURCE_DIR}/test_mysql_info.inc COPYONLY)

add_custom_target(
  locale ALL
  COMMAND ln -sf ${CMAKE_CURRENT_SOURCE_DIR}/locale ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(test ${CXX_SOURCES})

target_link_libraries(test hphp_analysis hphp_runtime_static)
