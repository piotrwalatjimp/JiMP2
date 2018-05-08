include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(GTEST_LIBS gtest gtest_main gmock gmock_main)

set(EXAMPLELIBRARY_SRC ExampleLibraryTest.cpp ../../lab3/minimaltimedifference/MinimalTimeDifference.cpp ../../lab3/minimaltimedifference/MinimalTimeDifference.h ../../lab3/minimaltimedifference/main.cpp ../../lab3/smarttree/SmartTree.cpp ../../lab3/smarttree/main.cpp ../../lab3/smarttree/SmartTree.h ../../lab3/ccounter/CCounter.cpp ../../lab3/ccounter/main.cpp ../../lab3/ccounter/CCounter.h ../../lab3/tinyurl/TinyUrl.cpp ../../lab3/tinyurl/TinyUrl.h ../../lab3/tinyurl/main.cpp ../../lab4/simplejson/SimpleJson.cpp ../../lab4/simplejson/SimpleJson.h ../../lab4/simplejson/main.cpp ../../lab4/simpletemplateengine/SimpleTemplateEngine.cpp ../../lab4/simpletemplateengine/SimpleTemplateEngine.h ../../lab4/simpletemplateengine/main.cpp ../../lab5/matrix/Matrix.cpp ../../lab5/matrix/Matrix.h ../../lab5/matrix/main.cpp ../../lab5/textpool/TextPool.cpp ../../lab5/textpool/TextPool.h ../../lab5/textpool/main.cpp ../../lab6/point/Point.cpp ../../lab6/point/Point.h ../../lab6/zipper/Zipper.cpp ../../lab6/zipper/main.cpp ../../lab6/zipper/Zipper.h ../../lab7/arrayfill/ArrayFill.cpp ../../lab7/arrayfill/ArrayFill.h ../../lab8/pesel/Pesel.cpp ../../lab8/pesel/Pesel.h ../../lab8/pesel/main.cpp ../../lab7/arrayfill/main.cpp)

add_executable(example_examplelibrary_tests ${EXAMPLELIBRARY_SRC})

target_link_libraries(example_examplelibrary_tests ${GTEST_LIBS})
target_link_libraries(example_examplelibrary_tests libexamplelibrary)