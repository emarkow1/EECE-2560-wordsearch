cmake_minimum_required(VERSION 3.10.0)
project(wordsearch VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(wordsearch 
    src/dictionary.cpp
    src/grid.cpp
    src/main.cpp
    )

target_include_directories(wordsearch PRIVATE src)


add_custom_command(TARGET wordsearch POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/Dictionary.txt
        $<TARGET_FILE_DIR:wordsearch>/Dictionary.txt
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/dict_sort_test.txt
        $<TARGET_FILE_DIR:wordsearch>/dict_sort_test.txt)

    
        

# cmake_minimum_required(VERSION 3.10)

# project(wordsearch VERSION 0.1.0 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# add_executable(wordsearch
#     src/dictionary.cpp
#     src/grid.cpp
#     src/main.cpp
# )

# target_include_directories(wordsearch PRIVATE src)

# set(WORDSEARCH_INPUT_FILES
#     Dictionary.txt
#     15x15s.txt
#     30x30s.txt
#     50x50s.txt
# )

# foreach(INPUT_FILE IN LISTS WORDSEARCH_INPUT_FILES)
#     add_custom_command(
#         TARGET wordsearch
#         POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_if_different
#             "${CMAKE_SOURCE_DIR}/${INPUT_FILE}"
#             "$<TARGET_FILE_DIR:wordsearch>/${INPUT_FILE}"
#         VERBATIM
#     )
# endforeach()