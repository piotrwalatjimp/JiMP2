project(pesel)

set(HEDEAR_FILES Pesel.h)
set(SOURCE_FILES Pesel.cpp)

add_library(libpesel STATIC ${SOURCE_FILES} ../moviesubtitles/MovieSubtitles.cpp ../moviesubtitles/MovieSubtitles.h ../moviesubtitles/main.cpp ../moviesubtitles/main.cpp ../moviesubtitles/MovieSubtitles.cpp ../moviesubtitles/MovieSubtitles.h)
target_include_directories(libpesel PUBLIC .)

add_executable(pesel ${SOURCE_FILES} main.cpp)

target_link_libraries(pesel libpesel)
