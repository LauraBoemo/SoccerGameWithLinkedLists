#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Estrutura dos Nós
struct node {
  int data;
  struct node * next;
};

// Estrutura da Lista Geral
struct list {
  // char *nome, *estadio, *cidade;
  Node * head; 
};

// Estrutura da Lista Time
struct listTime {
  char *nome, *estadio, *cidade;
  Node * head; 
};

Node * createnode(int data) {
  Node * newNode = malloc(sizeof(Node));

  if (!newNode) {
    return NULL;
  }
  
  newNode->data = data;
  newNode->next = NULL;
  
  return newNode;
}

ListTime * makeListTime(char * nome, char * estadio, char * cidade) {
  ListTime * listTime = malloc(sizeof(ListTime));

  if (!listTime) {
    return NULL;
  }

  listTime->head = NULL;
  listTime->nome = nome;
  listTime->estadio = estadio;
  listTime->cidade = cidade;

  return listTime;
}

List * makeList() {
  List * list = malloc(sizeof(List));

  if (!list) {
    return NULL;
  }

  list->head = NULL;

  return list;
}

void display(ListTime * listTime) {
  Node * current = listTime->head;
 
  printf("%s\n", listTime->nome);
  printf("%s\n", listTime->estadio);
  printf("%s\n", listTime->cidade);
  
  if(listTime->head == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    printf("%d\n", current->data);
  }
}

void add(int data, List * list){
  Node * current = NULL;
  
  if(list->head == NULL){
    list->head = createnode(data);
  } else {
    current = list->head; 
    
    while (current->next!=NULL){
      current = current->next;
    }
    
    current->next = createnode(data);
  }
}

void delete(int data, List * list){
  Node * current = list->head;            
  Node * previous = current;           
  
  while(current != NULL){           
    if(current->data == data){      
      previous->next = current->next;
      
      if(current == list->head)
        list->head = current->next;
      
      free(current);
      
      return;
    }  

    previous = current;             
    current = current->next;        
  }                                 
}

void destroy(ListTime * listTime){
  Node * current = listTime->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(listTime);
}
