add_executable(curves_app main.cpp)
target_link_libraries(curves_app PRIVATE curves)
target_include_directories(curves_app PRIVATE ${CMAKE_SOURCE_DIR}/include)