cmake_minimum_required(VERSION 3.19)
project(EsameLaboratorio)
set(CMAKE_CXX_STANDARD 14)

#aggiunge test a cmake
add_subdirectory(test)

set(SOURCE_FILES CollezioneNote.cpp CollezioneNoteImportanti.cpp
        CollezioneNoteImportanti.h Nota.cpp Nota.h Observer.h
        Subject.h PaginaHome.cpp PaginaHome.h)
add_executable(EsameLaboratorio main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(EsameLaboratorio core)