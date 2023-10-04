#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      Typedefining Jogador
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Struct do nó gerado para cada jogador 

struct nodeJogador {
  char *nome, *posicao, *cidade;
  int idade, numeroCamisa;
  struct nodeJogador * next;
};

// Struct da lista gerada para os jogadores

struct listJogadores {
  NodeJogador * nodeJogador;
};

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                        Typedefining Time
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Struct do nó gerado para cada time 

struct nodeTime {
  char *nome, *estadio, *cidade;
  struct listJogadores *jogadores;
  struct nodeTime * next;
};

// Struct da lista gerada para os times

struct listTimes {
  NodeTime * nodeTime;
};

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                        Funções de Time
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Criar Lista de Times (e, consequentemente, de Jogadores)

ListTimes * makeListTimes() {
  ListTimes * listTimes = malloc(sizeof(ListTimes));

  if (!listTimes) {
    return NULL;
  }

  listTimes->nodeTime = NULL;

  return listTimes;
}

// Criar Nó de Time

NodeTime * createNodeTime(char * nome, char * estadio, char * cidade){
  NodeTime * newNodeTime = malloc(sizeof(NodeTime));

  if (!newNodeTime) {
    return NULL;
  }

  newNodeTime->nome = nome;
  newNodeTime->estadio = estadio;
  newNodeTime->cidade = cidade;
  
  newNodeTime->next = NULL;
  
  return newNodeTime;
}

// Adicionar informações de novo Time

void addTimeInfo(ListTimes * listTimes, char * nome, char * estadio, char * cidade){
  NodeTime * current = NULL;

  if(listTimes->nodeTime == NULL) {
    listTimes->nodeTime = createNodeTime(nome, estadio, cidade);
  } else {
    current = listTimes->nodeTime; 

    while (current->next!=NULL){
      current = current->next;
    }

    current->next = createNodeTime(nome, estadio, cidade);
  }
}

// Exibir informações dos Times

void displayTimesInfo(ListTimes * listTimes) {
  NodeTime * current = listTimes->nodeTime;

  if(listTimes->nodeTime == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    printf("%s\n", current->nome);
    printf("%s\n", current->estadio);
    printf("%s\n", current->cidade);
  }
}

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                        Funções de Jogador
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Criar Nó de Jogador

NodeJogador * createNodeJogador(char * nome, char * posicao, char * cidade, int idade, int numeroCamisa){
  NodeJogador * newNodeJogador = malloc(sizeof(NodeJogador));

  if (!newNodeJogador) {
    return NULL;
  }

  newNodeJogador->nome = nome;
  newNodeJogador->posicao = posicao;
  newNodeJogador->cidade = cidade;
  newNodeJogador->idade = idade;
  newNodeJogador->numeroCamisa = numeroCamisa;

  newNodeJogador->next = NULL;
  
  return newNodeJogador;
}

// Adicionar informações de novo Jogador

void addJogadorInfo(ListTimes * listTimes, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa){
  NodeJogador * current = NULL;

  if(listTimes->nodeTime->jogadores == NULL) {
    listTimes->nodeTime->jogadores = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
  } else {
    current = listTimes->nodeTime->jogadores; 
  
    while (current->next!=NULL){
      current = current->next;
    }

    current->next = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
  }
}

// Exibir informações dos Jogadores

void displayJogadoresInfo(ListTimes * listTimes) {
  NodeJogador * current = listTimes->nodeTime->jogadores;

  if(listTimes->nodeTime->jogadores == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    printf("%s\n", current->nome);
    printf("%s\n", current->posicao);
    printf("%s\n", current->cidade);
    printf("%d\n", current->idade);
    printf("%d\n", current->numeroCamisa);
  }
}
