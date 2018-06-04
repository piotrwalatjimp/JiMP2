
project(sequentialgenerator)

set(HEDEAR_FILES SequentialGenerator.h)
set(SOURCE_FILES SequentialGenerator.cpp)

add_library(libsequentialgenerator STATIC ${SOURCE_FILES} ../timerecorder/main.cpp ../timerecorder/TimeRecorder.cpp ../timerecorder/TimeRecorder.h ../tree/main.cpp ../tree/Tree.h ../tree/Tree.cpp ../treeiterators/TreeIterators.cpp ../treeiterators/TreeIterators.h ../treeiterators/main.cpp)
target_include_directories(libsequentialgenerator PUBLIC .)

add_executable(sequentialgenerator ${SOURCE_FILES} main.cpp)

target_link_libraries(sequentialgenerator libsequentialgenerator)