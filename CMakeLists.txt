cmake_minimum_required(VERSION 3.19)
project(EsameLaboratorio)

set(CMAKE_CXX_STANDARD 14)

add_executable(EsameLaboratorio main.cpp CollezioneNote.cpp CollezioneNoteImportanti.cpp CollezioneNoteImportanti.h Nota.cpp Nota.h Observer.cpp Observer.h Subject.cpp Subject.h)