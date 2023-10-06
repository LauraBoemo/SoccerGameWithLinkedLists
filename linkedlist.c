// Notes
// -- Nao pode ser possivel cadastrar um jogador que ja existe
// -- Nao pode ser possivel cadastrar um time que ja existe
// -- Nao pode ser possivel cadastrar um tecnico que ja existe
// -- Nao pode ser possivel deletar um jogador que nao existe
// -- Nao pode ser possivel deletar um time que nao existe
// -- Nao pode ser possivel deletar um tecnico que nao existe

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
  char *nome, *posicao, *cidade, *timeRelacionado; // Cada jogador deve ter ao menos os seguintes dados: nome, posição, idade, número da camisa.
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
  struct nodeJogador * jogadores;
  struct nodeTime * next;
};

// Struct da lista gerada para os times

struct listTimes {
  NodeTime * nodeTime;
};

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      Typedefining Jogo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Struct do nó gerado para cada jogo 

struct nodeJogo {
  struct nodeTime * timeA, * timeB;
  struct nodeJogador * escalacaoA, * escalacaoB;
  struct nodeJogo * next;
};

// Struct da lista gerada para os jogo

struct listJogos {
  NodeJogo * nodeJogo;
};

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      Typedefining Lance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Struct do nó gerado para cada lance 

struct nodeLance {
  char * lance;
  struct nodeTime * time;
  struct nodeJogador * jogador;
  struct nodeLance * next;
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
  if(listTecnicos->nodeTecnico == NULL) {
    printf("0 tecnicos cadastrados!");
  } else {
    NodeTecnico * current = listTecnicos->nodeTecnico;

    for(; current != NULL; current = current->next) {
      printf("%s\n", current->nome);
    }
  }
}

// Pesquisar informacao de um Tecnico

void searchTecnicoInfo(ListTecnicos * listTecnicos, char * nome) {
  NodeTecnico * current = listTecnicos->nodeTecnico;

  if(listTecnicos->nodeTecnico == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
      printf("%s\n", current->nome);
    }
  }
}

// Deletar um Tecnico

void deleteTecnico(ListTecnicos * listTecnicos, char * nome){
  NodeTecnico * current = listTecnicos->nodeTecnico;            
  NodeTecnico * previous = current;      

  while(current != NULL){           
    if(current->nome == nome){      
      previous->next = current->next;

      if(current == listTecnicos->nodeTecnico)
        listTecnicos->nodeTecnico = current->next;
      
      free(current);
      return;
    }                  

    previous = current;             
    current = current->next;        
  }                                 
}         

// Deletar todos os Tecnicos

void destroyTecnicos(ListTecnicos * listTecnicos) {
  NodeTecnico * current = listTecnicos->nodeTecnico;
  NodeTecnico * next = current;

  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  
  free(listTecnicos);
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

// Criar Nó de Jogador relacionado ao Time

NodeJogador * createNodeJogadorRelacionadoAoTime(ListJogadores * listJogadores, char * nome) {
  if(listJogadores->nodeJogador == NULL) {
    printf("Não existem jogadores cadastrados!");
    return NULL;
  }
  
  NodeJogador * newNodeJogador = malloc(sizeof(NodeJogador));
  NodeJogador * currentJogador = listJogadores->nodeJogador;

  if(!newNodeJogador) {
    printf("Não foi possível relacionar novo jogador ao time.");
    return NULL;
  }

  for(; currentJogador != NULL; currentJogador = currentJogador->next) {
    if(currentJogador->nome == nome) {
      newNodeJogador->nome = currentJogador->nome;
      newNodeJogador->posicao = currentJogador->posicao;
      newNodeJogador->cidade = currentJogador->cidade;
      newNodeJogador->idade = currentJogador->idade;
      newNodeJogador->numeroCamisa = currentJogador->numeroCamisa;

      newNodeJogador->next = NULL;
      
      return newNodeJogador;
    }
  }
}

// Adicionar informações de novo Jogador relacionado ao Time

void addTimeJogadorRelacionadoInfo(ListTimes * listTimes, ListJogadores * listJogadores, char * nomeTime, char * nomeJogador) {
  NodeTime * currentTime = listTimes->nodeTime;

  if(listTimes->nodeTime == NULL) {
    printf("Não existem times cadastrados para relacionar a um jogador.");
    return;
  }
  
  for(; currentTime != NULL; currentTime = currentTime->next) {
    if(currentTime->nome == nomeTime) {
      if(listTimes->nodeTime->jogadores == NULL) {
        listTimes->nodeTime->jogadores = createNodeJogadorRelacionadoAoTime(listJogadores, nomeJogador);
        return;
      } else {
        NodeJogador * currentJogador = listTimes->nodeTime->jogadores;

        while (currentJogador->next!=NULL){
          currentJogador = currentJogador->next;
        }

        currentJogador->next = createNodeJogadorRelacionadoAoTime(listJogadores, nomeJogador);
        return;
      }
    }
  }

  printf("O time desejado não foi encontrado.");
}

// Exibir informações dos Times

void displayTimesInfo(ListTimes * listTimes) {
  if(listTimes->nodeTime == NULL) {
    printf("0 times cadastrados!");
  } else {
    NodeTime * current = listTimes->nodeTime;

    for(; current != NULL; current = current->next) {
      printf("%s\n", current->nome);
      printf("%s\n", current->estadio);
      printf("%s\n", current->cidade);
    }
  }
}

// Exibir informações dos Jogadores relacionados ao Time

void displayJogadoresRelaciondosAoTimeInfo(ListTimes * listTimes, char * nomeTime) {
  NodeTime * currentTime = listTimes->nodeTime;

  if(listTimes->nodeTime == NULL)  {
    printf("Não há times cadastrados");
    return;
  }
  
  for(; currentTime != NULL; currentTime = currentTime->next) {
    if(currentTime->nome == nomeTime) {
      NodeJogador * currentJogador = currentTime->jogadores;

      for(; currentJogador != NULL; currentJogador = currentJogador->next) {
        printf("%s\n", currentJogador->nome);
        printf("%s\n", currentJogador->posicao);
        printf("%s\n", currentJogador->cidade);
        printf("%d\n", currentJogador->idade);  
        printf("%d\n", currentJogador->numeroCamisa);  
      }
    }
  }
}

// Pesquisar informacao de um Time

void searchTimeInfo(ListTimes * listTimes, char * nome) {
  NodeTime * current = listTimes->nodeTime;

  if(listTimes->nodeTime == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
      printf("%s\n", current->nome);
      printf("%s\n", current->estadio);
      printf("%s\n", current->cidade);  
    }
  }
}

// Deletar um Time

void deleteTime(ListTimes * listTimes, char * nome){
  NodeTime * current = listTimes->nodeTime;            
  NodeTime * previous = current;      

  while(current != NULL){           
    if(current->nome == nome){      
      previous->next = current->next;

      if(current == listTimes->nodeTime)
        listTimes->nodeTime = current->next;
      
      free(current);
      return;
    }                  

    previous = current;             
    current = current->next;        
  }                                 
}     

// Deletar todos os Times

void destroyTimes(ListTimes * listTimes) {
  NodeTime * current = listTimes->nodeTime;
  NodeTime * next = current;

  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  
  free(listTimes);
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

void addJogadorInfo(ListJogadores * listJogadores, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa) {
  NodeJogador * currentJogador = NULL;

  if(listJogadores->nodeJogador == NULL) {
    listJogadores->nodeJogador = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
  } else {
    currentJogador = listJogadores->nodeJogador;
    while (currentJogador->next!=NULL) {
      currentJogador = currentJogador->next;
    }

    currentJogador->next = createNodeJogador(nome, posicao, cidade, idade, numeroCamisa);
  }
}

// Exibir informações dos Jogadores

void displayJogadoresInfo(ListJogadores * listJogadores) {
  if(listJogadores->nodeJogador == NULL) {
    printf("\n0 jogadores cadastrados!\n");
  } else {
    NodeJogador * current = listJogadores->nodeJogador;

    for(; current != NULL; current = current->next) {
      printf("%s\n", current->nome);
      printf("%s\n", current->posicao);
      printf("%s\n", current->cidade);
      printf("%d\n", current->idade);
      printf("%d\n", current->numeroCamisa);
    }
  }
}

// Pesquisar informacao de um Jogador

void searchJogadorInfo(ListJogadores * listJogadores, char * nome) {
  NodeJogador * current = listJogadores->nodeJogador;

  if(listJogadores->nodeJogador == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
      printf("%s\n", current->nome);
      printf("%s\n", current->posicao);
      printf("%s\n", current->cidade);
      printf("%s\n", current->timeRelacionado);
      printf("%d\n", current->idade);
      printf("%d\n", current->numeroCamisa);
    }
  }
}

// Deletar um Jogador

void deleteJogador(ListJogadores * listJogadores, char * nome) {
  NodeJogador * current = listJogadores->nodeJogador;            
  NodeJogador * previous = current;      

  while(current != NULL){           
    if(current->nome == nome){      
      previous->next = current->next;

      if(current == listJogadores->nodeJogador)
        listJogadores->nodeJogador = current->next;
      
      free(current);
      return;
    }                  

    previous = current;             
    current = current->next;        
  }                                 
}  

// Deletar todos os Jogadores

void destroyJogadores(ListJogadores * listJogadores) {
  NodeJogador * current = listJogadores->nodeJogador;
  NodeJogador * next = current;

  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  
  free(listJogadores);
}

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      Funções de Jogo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Criar Lista de Jogos

ListJogos * makeListJogos() {
  ListJogos * listJogos = malloc(sizeof(ListJogos));

  if (!listJogos) {
    printf("Não foi possível inicializar lista de jogos.");
    return NULL;
  }

  listJogos->nodeJogo = NULL;

  return listJogos;
}

// Criar Nó de Jogador

NodeJogador * createNodeJogadorEscaladoAoJogo(char * nomeJogador) {
  NodeJogador * newNodeJogadorEscaladoAoJogo = malloc(sizeof(NodeJogador));

  if (!newNodeJogadorEscaladoAoJogo) {
    printf( "Não foi possível inicializar nó de jogador escalado ao jogo.");
    return NULL;
  }

  newNodeJogadorEscaladoAoJogo->nome = nomeJogador;
  newNodeJogadorEscaladoAoJogo->next = NULL;
  
  return newNodeJogadorEscaladoAoJogo;
}

// Criar Nó de Jogo

NodeJogo * createNodeJogo(char * timeA, char * timeB) {
  NodeJogo * newNodeJogo = malloc(sizeof(NodeJogador));

  if (!newNodeJogo) {
    printf("Não foi possível inicializar nó de jogo.");
    return NULL;
  }

  newNodeJogo->timeA = timeA;
  newNodeJogo->timeB = timeB;

  printf("Insira a escalação para o time %s", timeA);
  for(int aux = 1; aux < 12; aux++) {
    char nomeJogador[100];
    printf("Insira o nome do jogador %d: ", aux);
    scanf("%s", &nomeJogador);

    NodeJogador * currentJogador = NULL;

    if(newNodeJogo->escalacaoA == NULL) {
      newNodeJogo->escalacaoA = createNodeJogadorEscaladoAoJogo(nomeJogador);
    } else {
      currentJogador = newNodeJogo->escalacaoA;
      while (currentJogador->next!=NULL) {
        currentJogador = currentJogador->next;
      }

      currentJogador->next = createNodeJogadorEscaladoAoJogo(nomeJogador);
    }
  }

  printf("Insira a escalação para o time %s", timeB);
  for(int aux = 1; aux < 12; aux++) {
    char nomeJogador[100];
    printf("Insira o nome do jogador %d: ", aux);
    scanf("%s", &nomeJogador);

    NodeJogador * currentJogador = NULL;

    if(newNodeJogo->escalacaoB == NULL) {
      newNodeJogo->escalacaoB = createNodeJogadorEscaladoAoJogo(nomeJogador);
    } else {
      currentJogador = newNodeJogo->escalacaoB;
      while (currentJogador->next!=NULL) {
        currentJogador = currentJogador->next;
      }

      currentJogador->next = createNodeJogadorEscaladoAoJogo(nomeJogador);
    }
  }
  
  newNodeJogo->next = NULL;
  
  return newNodeJogo;
}

// Adicionar informações de novo Jogo

void addJogoInfo(ListJogos * listJogos, char * timeA, char * timeB) {
  NodeJogo * currentJogo = NULL;

  if(listJogos->nodeJogo == NULL) {
    listJogos->nodeJogo = createNodeJogo(timeA, timeB);
  } else {
    currentJogo = listJogos->nodeJogo;
    while (currentJogo->next!=NULL) {
      currentJogo = currentJogo->next;
    }

    currentJogo->next = createNodeJogo(timeA, timeB);
  }
}

// Exibir informações dos Jogos

struct nodeTime * timeA, * timeB;
struct nodeJogador * escalacaoA, * escalacaoB;
struct nodeJogo * next;

void displayJogosInfo(ListJogos * listJogos) {
  if(listJogos->nodeJogo == NULL) {
    printf("\nNão há cadastrados!\n");
  } else {
    NodeJogo * currentJogo = listJogos->nodeJogo;
    for(; currentJogo != NULL; currentJogo = currentJogo->next) {
      printf("%s\n", currentJogo->timeA);
      printf("%s\n", currentJogo->timeB);
    
      printf("Escalacao A\n");
      NodeJogador * escalacaoTimeA = currentJogo->escalacaoA;
      for(; escalacaoTimeA != NULL; escalacaoTimeA = escalacaoTimeA->next) {
        printf("%s\n", escalacaoTimeA->nome);
      }

      printf("Escalacao B\n");
      NodeJogador * escalacaoTimeB = currentJogo->escalacaoB;
      for(; escalacaoTimeB != NULL; escalacaoTimeB = escalacaoTimeB->next) {
        printf("%s\n", escalacaoTimeB->nome);
      }
    }
  }
}