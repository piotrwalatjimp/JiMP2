project(xorcypherbreaker)

set(HEDEAR_FILES XorCypherBreaker.h)
set(SOURCE_FILES main.cpp XorCypherBreaker.cpp )

add_library(libxorcypherbreaker STATIC ${SOURCE_FILES} main.cpp XorCypherBreaker.cpp XorCypherBreaker.h)
target_include_directories(libxorcypherbreaker PUBLIC .)

add_executable(xorcypherbreaker ${SOURCE_FILES} main.cpp )

target_link_libraries(xorcypherbreaker libxorcypherbreaker)