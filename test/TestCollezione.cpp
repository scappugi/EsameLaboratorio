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


TEST(TestCollezione, TestLockNote){
    CollezioneNote c("test");
    string nomeTest="NomeTest";
    Nota notaTest(nomeTest);
    c.AddNoteToList(&notaTest);
    bool preBlocco=c.getNota(nomeTest)->getBlocco();
    c.bloccaNota(&notaTest);
    bool afterBlocco=c.getNota(nomeTest)->getBlocco();
    ASSERT_NE(preBlocco,afterBlocco);
}

TEST(TestCollezione, TestLockAllNote){
    CollezioneNote c("test");
    string nomeTest="NomeTest";
    Nota notaTest(nomeTest);
    string nomeTest2="NomeTest2";
    Nota notaTest2(nomeTest2);
    c.AddNoteToList(&notaTest);
    c.AddNoteToList(&notaTest2);
    c.bloccaTutteLeNote();
    ASSERT_EQ(notaTest.getBlocco(), true);
    ASSERT_TRUE(notaTest2.getBlocco());
}

