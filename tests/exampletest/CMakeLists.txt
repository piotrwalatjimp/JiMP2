include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(GTEST_LIBS gtest gtest_main gmock gmock_main)

set(EXAMPLELIBRARY_SRC ExampleLibraryTest.cpp ../../lab3/minimaltimedifference/MinimalTimeDifference.cpp ../../lab3/minimaltimedifference/MinimalTimeDifference.h ../../lab3/minimaltimedifference/main.cpp)

add_executable(example_examplelibrary_tests ${EXAMPLELIBRARY_SRC})

target_link_libraries(example_examplelibrary_tests ${GTEST_LIBS})
target_link_libraries(example_examplelibrary_tests libexamplelibrary)