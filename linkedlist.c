#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    Typedefining Técnico
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Struct do nó gerado para cada time 

struct nodeTecnico {
  char *nome;
  struct nodeTecnico * next;
};

// Struct da lista gerada para os times

struct listTecnicos {
  NodeTecnico * nodeTecnico;
};

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      Typedefining Jogador
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Struct do nó gerado para cada jogador 

struct nodeJogador {
  char *nome, *posicao, *cidade; // Cada jogador deve ter ao menos os seguintes dados: nome, posição, idade, número da camisa.
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
  char *nome, *estadio, *cidade; // Cada time deve ter ao menos os seguintes dados: nome, estádio, cidade
  struct listJogadores *jogadores;
  struct nodeTime * next;
};

// Struct da lista gerada para os times

struct listTimes {
  NodeTime * nodeTime;
};

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      Funções de Tecnico
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Criar Lista de Tecnicos

ListTecnicos * makeListTecnicos() {
  ListTecnicos * listTecnicos = malloc(sizeof(ListTecnicos));

  if (!listTecnicos) {
    return NULL;
  }

  listTecnicos->nodeTecnico = NULL;

  return listTecnicos;
}

// Criar Nó de Tecnico

NodeTime * createNodeTecnico(char * nome){
  NodeTecnico * newNodeTecnico = malloc(sizeof(NodeTecnico));

  if (!newNodeTecnico) {
    return NULL;
  }

  newNodeTecnico->nome = nome;
  
  newNodeTecnico->next = NULL;
  
  return newNodeTecnico;
}

// Adicionar informações de novo Tecnico

void addTecnicoInfo(ListTecnicos * listTecnicos, char * nome){
  NodeTecnico * current = NULL;

  if(listTecnicos->nodeTecnico == NULL) {
    listTecnicos->nodeTecnico = createNodeTecnico(nome);
  } else {
    current = listTecnicos->nodeTecnico; 

    while (current->next!=NULL){
      current = current->next;
    }

    current->next = createNodeTecnico(nome);
  }
}

// Exibir informações dos Tecnicos

void displayTecnicosInfo(ListTecnicos * listTecnicos) {
  NodeTecnico * current = listTecnicos->nodeTecnico;

  if(listTecnicos->nodeTecnico == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    printf("%s\n", current->nome);
  }
}

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                        Funções de Time
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Criar Lista de Times

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

// Criar Lista de Jogadores

ListJogadores * makeListJogadores() {
  ListJogadores * listJogadores = malloc(sizeof(ListJogadores));

  if (!listJogadores) {
    return NULL;
  }

  listJogadores->nodeJogador = NULL;

  return listJogadores;
}

// Criar Nó de Tecnico

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

// Adicionar informações de novo Tecnico

void addJogadorInfo(ListJogadores * listJogadores, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa){
  NodeJogador * current = NULL;

  if(listJogadores->nodeJogador == NULL) {
    listJogadores->nodeJogador = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
  } else {
    current = listJogadores->nodeJogador; 

    while (current->next!=NULL){
      current = current->next;
    }

    current->next = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
  }
}

// Exibir informações dos Tecnicos

void displayJogadoresInfo(ListJogadores * listJogadores) {
  NodeJogador * current = listJogadores->nodeJogador;

  if(listJogadores->nodeJogador == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    printf("%s\n", current->nome);
    printf("%s\n", current->posicao);
    printf("%s\n", current->cidade);
    printf("%d\n", current->idade);
    printf("%d\n", current->numeroCamisa);
  }
}

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    Funções de Jogador Relacionado
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Contar quantos jogadores relacionados há no Nó

int countNodes(struct nodeJogador * jogador) {
  int count = 0;

  while(jogador != NULL){
      jogador = jogador->next;
      count++;
  }

  return count;
}

// Criar Nó de Jogador Relacionado

NodeJogador * createNodeJogadorRelacionado(char * nome, char * posicao, char * cidade, int idade, int numeroCamisa){
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

// Adicionar informações de novo Jogador Relacionado

void addJogadorRelacionadoInfo(ListTimes * listTimes, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa){
  NodeJogador * current = NULL;

  if(listTimes->nodeTime->jogadores == NULL) {
    listTimes->nodeTime->jogadores = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
  } else {
    current = listTimes->nodeTime->jogadores; 
  
    if(countNodes(current) > 25) {
      printf("Time cheio!"); // Um time não pode ter mais de 25 jogadores relacionados
    } else {
      while (current->next!=NULL){
        current = current->next;
      }

      current->next = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
    }
  }
}

// Exibir informações dos Jogadores Relacionados

void displayJogadoresRelacionadosInfo(ListTimes * listTimes) {
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
