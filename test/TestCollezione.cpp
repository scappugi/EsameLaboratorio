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
    c.AddNoteToList(notaTest);
    ASSERT_TRUE(c.cercaNote(notaTest));
}


TEST(TestCollezione, TestRemoveNote){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio TestRemoveNote "<<endl;
    cout<<endl;
    CollezioneNote c("test");
    string nomeTest="nomeTest";
    Nota notaTest(nomeTest);
    c.AddNoteToList(notaTest);
    //blocco nota per fare test
    c.bloccaNota(notaTest);
    ASSERT_EQ(false, c.removeToList(notaTest));
    c.sbloccaNota(notaTest);
    ASSERT_TRUE(c.removeToList(notaTest));
    EXPECT_FALSE(c.removeToList(notaTest)); //una volta fatto il remove non si dovrebbe più poter rimuovere
    cout<<"----------------------------------------------------"<<endl;
}


TEST(TestCollezione, TestRenameNote){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio  TestRenameNote "<<endl;
    cout<<endl;
    CollezioneNote c("test");
    string OldNomeTest="OldNomeTest";
    Nota notaTest(OldNomeTest);
    c.AddNoteToList(notaTest);
    string NewNomeTest="NewNomeTest";
    ASSERT_TRUE(c.cercaNote(notaTest) );
    c.modificaNota(notaTest, NewNomeTest);
    Nota nota1(OldNomeTest);
    ASSERT_FALSE(c.cercaNote(nota1));
    Nota nota2(NewNomeTest);
    ASSERT_TRUE(c.cercaNote(nota2));

    cout<<"----------------------------------------------------"<<endl;

}


TEST(TestCollezione, TestLockNote){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio  TestLockNote "<<endl;
    cout<<endl;
    CollezioneNote c("test");
    string nomeTest="NomeTest";
    Nota notaTest(nomeTest);
    c.AddNoteToList(notaTest);
    bool preBlocco=c.getNota(nomeTest).getBlocco();
    c.bloccaNota(notaTest);
    bool afterBlocco=c.getNota(nomeTest).getBlocco();
    ASSERT_NE(preBlocco,afterBlocco);
    cout<<"----------------------------------------------------"<<endl;
}

TEST(TestCollezione, TestLockAllNote){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio  TestLockAllNote "<<endl;
    cout<<endl;
    CollezioneNote c("test");
    string nomeTest="NomeTest";
    Nota notaTest(nomeTest);
    string nomeTest2="NomeTest2";
    Nota notaTest2(nomeTest2);
    c.AddNoteToList(notaTest);
    c.AddNoteToList(notaTest2);
    c.bloccaTutteLeNote();
    ASSERT_EQ(c.getNota(nomeTest).getBlocco(), true);
    ASSERT_TRUE(c.getNota(nomeTest2).getBlocco());
    cout<<"----------------------------------------------------"<<endl;
}

