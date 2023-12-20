add_library(part_one)
target_sources(part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)

add_executable(aoc aoc.cc)
target_link_libraries(aoc part_one)

add_custom_command(
  TARGET aoc POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_SOURCE_DIR}/puzzle_day1.txt 
    $<TARGET_FILE_DIR:aoc>)