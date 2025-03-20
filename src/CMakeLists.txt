add_library(graph STATIC fifo.c graph.c traversal.c utils.c)
target_include_directories(graph PUBLIC ${CMAKE_SOURCE_DIR}/include)
