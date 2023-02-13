//
// Created by simon on 08/01/2023.
//
#include <gtest/gtest.h>
#include"../CollezioneNote.h"
#include "../PaginaHome.h"
using namespace std;

TEST(TestPaginaHome, TestInsertCollection){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio TestInsertCollection "<<endl;
    cout<<endl;
    PaginaHome ph;
    string test="Test";
    CollezioneNote c(test);
    ph.addCollezione(&c);
    ASSERT_TRUE(ph.contieneCollezioni(test));
    ASSERT_FALSE(ph.contieneCollezioni("test"));
    cout<<"----------------------------------------------------"<<endl;
}

TEST(TestPaginaHome, TestCreateNewCollection){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio TestCreateNewCollection "<<endl;
    cout<<endl;
    PaginaHome ph;
    string test="test";
    ph.creaNuovaCollezione(test); //crea nuova collezione con nome test
    string test2="test2";
    ph.creaNuovaCollezione(test2);
    ASSERT_TRUE(ph.contieneCollezioni(test));
    ASSERT_TRUE(ph.contieneCollezioni(test2));
    cout<<"----------------------------------------------------"<<endl;
}



TEST(TestPaginaHome, TestAddNoteToCollection){//aggiunto il caso in cui si prova ad aggiungere una nota ad una lista non esistente.
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio TestAddNoteToCollection "<<endl;
    cout<<endl;
    PaginaHome ph;
    string test="test";
    CollezioneNote c(test);
    ph.addCollezione(&c);
    string test1="test1";
    CollezioneNote c1(test1);
    Nota nota("notaTest");
    ph.aggiungiNotaACollezioneBase(nota,test);
    ASSERT_FALSE(ph.aggiungiNotaACollezioneBase(nota,test1));
    ASSERT_TRUE(c.cercaNote(nota));
    ASSERT_FALSE(c1.cercaNote(nota));
    cout<<"----------------------------------------------------"<<endl;
}

TEST(TestPaginaHome, TestRemoveNoteFromCollection){ //aggiunto il caso in cui utente prova a togliere nota da una collezione non inserita nella pagina home
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio TestRemoveNoteFromCollection "<<endl;
    cout<<endl;
    PaginaHome ph;
    string test="test";
    CollezioneNote c(test);
    ph.addCollezione(&c);
    string nomeNota="notaTest";
    Nota nota(nomeNota);
    c.AddNoteToList(nota);
    string nomeNota2="notaTest2";
    Nota nota2(nomeNota2);
    string nomeNota3="notaTest3";
    Nota nota3(nomeNota3);
    c.AddNoteToList(nota2);
    string  test1="test1";
    CollezioneNote c1(test1);
    c.AddNoteToList(nota3);
    ASSERT_TRUE(ph.eliminaNota(test,nota2));
    ASSERT_TRUE(ph.eliminaNota(test,nota3));
    ASSERT_FALSE(ph.eliminaNota(test,nota3)); //una volta eliminato non si deve poter rieliminare
    ASSERT_FALSE(ph.eliminaNota(test1, nota3));


    cout<<"----------------------------------------------------"<<endl;
}

TEST(TestPaginaHome, TestRemoveCollection){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio TestRemoveNoteFromCollection "<<endl;
    cout<<endl;
    PaginaHome ph;
    string test="test";
    CollezioneNote c(test);
    ph.addCollezione(&c);
    string test1="test1";
    CollezioneNote c1(test1);
    ph.addCollezione(&c1);
    ASSERT_TRUE(ph.eliminaCollezione(test1));
    ASSERT_FALSE(ph.contieneCollezioni(test1)); //non deve essere presente la collezione eliminata
    cout<<"----------------------------------------------------"<<endl;
}

TEST(TestPaginaHome, TestMoveNote){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------ Inizio TestMoveNote "<<endl;
    cout<<endl;
    PaginaHome ph;
    string test="test";
    CollezioneNote c(test);
    ph.addCollezione(&c);
    string test1="test1";
    CollezioneNote c1(test1);
    ph.addCollezione(&c1);
    Nota notaTest("nomeTest");
    c.AddNoteToList(notaTest);
    ASSERT_TRUE(ph.contieneNote(notaTest,test));
    ph.spostaNota(notaTest,test,test1);
    ASSERT_FALSE(ph.contieneNote(notaTest,test));
    ASSERT_TRUE(ph.contieneNote(notaTest,test1));
    cout<<"----------------------------------------------------"<<endl;
}