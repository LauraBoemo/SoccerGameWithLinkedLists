#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct list {
  Node * head; 
};

struct nodeJogador {
  char *nome, *posicao, *cidade;
  int idade, numeroCamisa;
  struct node * next;
};

struct nodeTime {
  char *nome, *estadio, *cidade;
  struct listJogadores *jogadores;
  struct nodeTime * next;
};

struct listJogadores {
  Node * head; 
};

struct listTime {
  Node * head; 
  NodeTime * nodeTime;
};

NodeTime * createNodeTime(char * nome, char * estadio, char * cidade);

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

void addTimeInfo(ListTime * listTime, char * nome, char * estadio, char * cidade){
  NodeTime * current = NULL;

  if(listTime->head == NULL) {
    listTime->head = createNodeTime(nome, estadio, cidade);
  } else {
    current = listTime->head; 

    while (current->next!=NULL){
      current = current->next;
    }

    current->next = createNodeTime(nome, estadio, cidade);
  }
}

// NodeJogador * createNodeJogador(char * nome, char * posicao, char * cidade, int idade, int numeroCamisa) {
//   NodeJogador * newNodeJogador = malloc(sizeof(NodeJogador));

//   if (!newNodeJogador) {
//     return NULL;
//   }
  
//   newNodeJogador->nome = nome;
//   newNodeJogador->posicao = posicao;
//   newNodeJogador->cidade = cidade;
//   newNodeJogador->idade = idade;
//   newNodeJogador->numeroCamisa = numeroCamisa;

//   newNodeJogador->next = NULL;
  
//   return newNodeJogador;
// }

ListTime * makeListTime() {
  ListTime * listTime = malloc(sizeof(ListTime));

  if (!listTime) {
    return NULL;
  }

  listTime->head = NULL;

  return listTime;
}

// void addTimeInfo(ListTime * listTime, char * nome, char * estadio, char * cidade){
//   Node * current = NULL;

//   if(listTime->head == NULL){
//     listTime->head = createNode(nome, estadio, cidade);
//   } else {
//     current = listTime->head; 
//     while (current->next!=NULL){
//       current = current->next;
//     }
//     current->next = createNode(data);
//   }
// }

void display(ListTime * listTime) {
  NodeTime * current = listTime->head;

  if(listTime->head == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    printf("%s\n", current->nome);
    printf("%s\n", current->estadio);
    printf("%s\n", current->cidade);
  }
}

// void addJogador(ListTime * list, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa) {
//   Node * current = NULL;
  
//   if(list->head == NULL){
//     list->head = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
//   } else {
//     current = list->head; 
    
//     while (current->next!=NULL) {
//       current = current->next;
//     }
    
//     current->next = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
//   }
// }

// void delete(int data, List * list){
//   Node * current = list->head;            
//   Node * previous = current;           
  
//   while(current != NULL){           
//     if(current->data == data){      
//       previous->next = current->next;
      
//       if(current == list->head)
//         list->head = current->next;
      
//       free(current);
      
//       return;
//     }  

//     previous = current;             
//     current = current->next;        
//   }                                 
// }

void destroy(ListTime * listTime){
  NodeTime * current = listTime->head;
  NodeTime * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(listTime);
}
