//
// Created by simon on 08/01/2023.
//
#include <gtest/gtest.h>
#include"../CollezioneNote.h"
#include "../PaginaHome.h"

using namespace std;

TEST(TestPaginaHome, TestInsertCollection){
    PaginaHome ph;
    string test="Test";
    CollezioneNote c(test);
    ph.addCollezione(&c);
    ASSERT_TRUE(ph.contieneCollezioni(test));
    ASSERT_FALSE(ph.contieneCollezioni("test"));
}

TEST(TestPaginaHome, TestCreateNewCollection){
    PaginaHome ph;
    string test="test";
    ph.creaNuovaCollezione(test); //crea nuova collezione con nome test
    string test2="test2";
    ph.creaNuovaCollezione(test2);
    ASSERT_TRUE(ph.contieneCollezioni(test));
    ASSERT_TRUE(ph.contieneCollezioni(test2));
}

TEST(TestPaginaHome, TestAddNoteToCollection){
    PaginaHome ph;
    string test="test";
    CollezioneNote c(test);
    ph.addCollezione(&c);
    Nota nota("notaTest");
    ph.aggiungiNotaACollezioneBase(&nota,test);
    ASSERT_EQ(&nota,c.getNota("notaTest"));
}
