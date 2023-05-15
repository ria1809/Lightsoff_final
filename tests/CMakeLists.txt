add_executable(test_box test_box.cpp test_toggle.cpp)
add_test(NAME test_box  COMMAND test_box )
target_link_libraries(test_box PRIVATE gamelib Catch2::Catch2)

add_executable(test_toggle test_toggle.cpp )
add_test(NAME test_toggle  COMMAND test_toggle )
target_link_libraries(test_toggle PRIVATE gamelib Catch2::Catch2)
