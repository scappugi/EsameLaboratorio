//
// Created by simon on 08/01/2023.
//
#include <gtest/gtest.h>
#include"../CollezioneNote.h"
using namespace std;

TEST(TestCollezione, TestInserimento){
    CollezioneNote c("test");
    string nomeTest="nomeTest";
    Nota notaTest(nomeTest);
    c.AddNoteToList(&notaTest);
    ASSERT_EQ(&notaTest, c.getNota(nomeTest));
}


TEST(TestCollezione, TestRemoveNote){
    CollezioneNote c("test");
    string nomeTest="nomeTest";
    Nota notaTest(nomeTest);
    c.AddNoteToList(&notaTest);

    //blocco nota per fare test
    c.bloccaNota(&notaTest);
    ASSERT_EQ(false, c.removeToList(&notaTest));

    c.sbloccaNota(&notaTest);

    ASSERT_TRUE(c.removeToList(&notaTest));

    EXPECT_FALSE(c.removeToList(&notaTest)); //una volta fatto il remove non si dovrebbe più poter rimuovere
}


TEST(TestCollezione, TestRenameNote){
    CollezioneNote c("test");
    string OldNomeTest="OldNomeTest";
    Nota notaTest(OldNomeTest);
    c.AddNoteToList(&notaTest);

    string NewNomeTest="NewNomeTest";

    ASSERT_EQ(&notaTest, c.getNota(OldNomeTest));

    c.modificaNota(&notaTest, NewNomeTest);

    ASSERT_FALSE(c.getNota(OldNomeTest));

    ASSERT_EQ(&notaTest,c.getNota(NewNomeTest));

}
