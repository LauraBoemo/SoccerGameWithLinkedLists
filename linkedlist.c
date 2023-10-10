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
                      Typedefining Jogo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

// Struct do nó gerado para cada jogo 

struct nodeJogo {
  char * nomeJogo;
  struct nodeTime * timeA, * timeB;
  struct nodeJogador * escalacaoA, * escalacaoB;
  struct nodeLance * lance;
  struct nodeJogo * next;
};

// Struct da lista gerada para os jogo

struct listJogos {
  NodeJogo * nodeJogo;
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
  
    
  puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("-- Novo Técnico cadastrado com sucesso: %s\n", nome);
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
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
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Não há técnicos cadastrados!");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  } else {
    NodeTecnico * current = listTecnicos->nodeTecnico;
    int auxTecnicos = 1;

    for(; current != NULL; current = current->next) {
	    puts("~~~~~~~~~~~");
      printf("Técnico #%d\n", auxTecnicos);
	    puts("~~~~~~~~~~~\n");

      printf("%s\n", current->nome);

      auxTecnicos++;
	    puts("~~~~~~~~~~~\n");
    }
  }
}

// Pesquisar informacao de um Tecnico

void searchTecnicoInfo(ListTecnicos * listTecnicos, char * nome) {
  NodeTecnico * current = listTecnicos->nodeTecnico;

  if(listTecnicos->nodeTecnico == NULL) {
    printf("Não existem técnicos cadastrados!\n\n");
    return;
  }
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
	    puts("~~~~~~~~~~~");
      printf("Resultado da pesquisa por %s\n", nome);
	    puts("~~~~~~~~~~~\n");

      printf("%s\n", current->nome);

	    puts("~~~~~~~~~~~\n");
    }
  }
}

// Deletar um Tecnico

void deleteTecnico(ListTecnicos * listTecnicos, char * nome) {                         
  NodeTecnico * current = listTecnicos->nodeTecnico;            
  NodeTecnico * previous = current;      

  if(listTecnicos->nodeTecnico == NULL) {
    printf("Não existem técnicos cadastrados!\n\n");
    return;
  }
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
      previous->next = current->next;

      if(current == listTecnicos->nodeTecnico) 
        listTecnicos->nodeTecnico = current->next;
      
      free(current);
      puts("~~~~~~~~~~~");
      printf("Técnico %s deletado\n", nome);
      puts("~~~~~~~~~~~\n");
    }
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

NodeTime * createNodeTime(char nome[50], char estadio[50], char cidade[50]){
  NodeTime * newNodeTime = malloc(sizeof(NodeTime));

  if (!newNodeTime) {
    return NULL;
  }

  newNodeTime->nome = nome;
  newNodeTime->estadio = estadio;
  newNodeTime->cidade = cidade;
  
	puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("-- Novo Time cadastrado com sucesso: %s\n", nome);
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
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

NodeJogador * createNodeJogadorRelacionadoAoTime(ListJogadores * listJogadores, char * nomeTime, char * nomeJogador) {
  if(listJogadores->nodeJogador == NULL) {
    printf("Não existem jogadores cadastrados!\n\n");
    return NULL;
  }
  
  NodeJogador * newNodeJogador = malloc(sizeof(NodeJogador));
  NodeJogador * currentJogador = listJogadores->nodeJogador;

  if(!newNodeJogador) {
    printf("Não foi possível relacionar novo jogador ao time.");
    return NULL;
  }

  for(; currentJogador != NULL; currentJogador = currentJogador->next) {
    if(currentJogador->nome == nomeJogador) {
      newNodeJogador->nome = currentJogador->nome;
      newNodeJogador->posicao = currentJogador->posicao;
      newNodeJogador->cidade = currentJogador->cidade;
      newNodeJogador->idade = currentJogador->idade;
      newNodeJogador->numeroCamisa = currentJogador->numeroCamisa;

      newNodeJogador->next = NULL;
      
      puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      printf("-- Novo Jogador relacionado ao time %s com sucesso: %s\n", nomeTime, nomeJogador);
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
      return newNodeJogador;
    }
  }
}

// Adicionar informações de novo Jogador relacionado ao Time

void addTimeJogadorRelacionadoInfo(ListTimes * listTimes, ListJogadores * listJogadores, char * nomeTime, char * nomeJogador) {
  NodeTime * currentTime = listTimes->nodeTime;

  if(listTimes->nodeTime == NULL) {
    printf("Não existem times cadastrados para relacionar a um jogador.\n\n");
    return;
  }
  
  for(; currentTime != NULL; currentTime = currentTime->next) {
    if(currentTime->nome == nomeTime) {
      if(listTimes->nodeTime->jogadores == NULL) {
        listTimes->nodeTime->jogadores = createNodeJogadorRelacionadoAoTime(listJogadores, currentTime->nome, nomeJogador);
        return;
      } else {
        NodeJogador * currentJogador = listTimes->nodeTime->jogadores;

        while (currentJogador->next!=NULL){
          currentJogador = currentJogador->next;
        }

        currentJogador->next = createNodeJogadorRelacionadoAoTime(listJogadores, currentTime->nome, nomeJogador);
        return;
      }
    }
  }

  printf("O time desejado não foi encontrado.");
}

// Exibir informações dos Times

void displayTimesInfo(ListTimes * listTimes) {
  if(listTimes->nodeTime == NULL) {
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Não há times cadastrados!");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  } else {
    NodeTime * current = listTimes->nodeTime;
    int auxTimes = 1;

    for(; current != NULL; current = current->next) {
	    puts("~~~~~~~~~~~");
      printf("Time #%d\n", auxTimes);
	    puts("~~~~~~~~~~~\n");

      printf("Nome: %s\n", current->nome);
      printf("Estadio: %s\n", current->estadio);
      printf("Cidade: %s\n", current->cidade);

      auxTimes++;
	    puts("~~~~~~~~~~~\n");
    }
  }
}

// Exibir informações dos Jogadores relacionados ao Time
void displayJogadoresRelaciondosAoTimeInfo(ListTimes * listTimes, char * nomeTime) {
  if(listTimes->nodeTime == NULL) {
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Não há times cadastrados!");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  } else {
    NodeTime * current = listTimes->nodeTime;

    for(; current != NULL; current = current->next) {
      if(current->nome == nomeTime) {
        puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("Jogadores relacionados ao time %s:\n", nomeTime);
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        NodeJogador * currentJogador = current->jogadores;

        for(; currentJogador != NULL; currentJogador = currentJogador->next) {
          puts("\n~~~~~~~~~~~");
          printf("Nome: %s\n", currentJogador->nome);
          printf("Posição: %s\n", currentJogador->posicao);
          printf("Cidade: %s\n", currentJogador->cidade);
          printf("Idade: %d\n", currentJogador->idade);  
          printf("Número Camisa: %d\n", currentJogador->numeroCamisa);  
          puts("~~~~~~~~~~~");
        }

        return;
      }
    }

    printf("O time buscado não foi encontrado.");
  }
}

// Pesquisar informacao de um Time

void searchTimeInfo(ListTimes * listTimes, char * nome) {
  NodeTime * current = listTimes->nodeTime;

  if(listTimes->nodeTime == NULL) {
    printf("Não existem times cadastrados!\n\n");
    return;
  }
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
	    puts("~~~~~~~~~~~");
      printf("Resultado da pesquisa por %s\n", nome);
	    puts("~~~~~~~~~~~\n");

      printf("%s\n", current->nome);
      printf("%s\n", current->estadio);
      printf("%s\n", current->cidade);  

	    puts("~~~~~~~~~~~\n");
    }
  }
}

// Deletar um Time

void deleteTime(ListTimes * listTimes, char * nome) {
  NodeTime * current = listTimes->nodeTime;            
  NodeTime * previous = current;         

  while(current != NULL){           
    if(current->nome == nome){      
      previous->next = current->next;
      
      if(current == listTimes->nodeTime)
        listTimes->nodeTime = current->next;

      free(current);

      puts("~~~~~~~~~~~");
      printf("Time %s deletado\n", nome);
      puts("~~~~~~~~~~~\n");
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

	puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("-- Novo Jogador cadastrado com sucesso: %s\n", nome);
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

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
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Não há jogadores cadastrados!");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  } else {
    NodeJogador * current = listJogadores->nodeJogador;
    int auxContadores = 1;

    for(; current != NULL; current = current->next) {
	    puts("~~~~~~~~~~~");
      printf("Jogador #%d\n", auxContadores);
	    puts("~~~~~~~~~~~\n");

      printf("Nome: %s\n", current->nome);
      printf("Posição: %s\n", current->posicao);
      printf("Cidade: %s\n", current->cidade);
      printf("Idade: %d\n\n", current->idade);
      printf("Numero Camisa: %d\n\n", current->numeroCamisa);
      
	    puts("~~~~~~~~~~~\n");
      auxContadores++;
    }
  }
}

// Pesquisar informacao de um Jogador

void searchJogadorInfo(ListJogadores * listJogadores, char * nome) {
  NodeJogador * current = listJogadores->nodeJogador;

  if(listJogadores->nodeJogador == NULL) {
    printf("Não existem jogadores cadastrados!\n\n");
    return;
  } 
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
	    puts("~~~~~~~~~~~");
      printf("Resultado da pesquisa por %s\n", nome);
	    puts("~~~~~~~~~~~\n");

      printf("%s\n", current->nome);
      printf("%s\n", current->posicao);
      printf("%s\n", current->cidade);
      printf("%d\n", current->idade);
      printf("%d\n", current->numeroCamisa);

	    puts("~~~~~~~~~~~\n");
    }
  }
}

// Deletar um Jogador

void deleteJogador(ListJogadores * listJogadores, char * nome) {
  NodeJogador * current = listJogadores->nodeJogador;            
  NodeJogador * previous = current;               

  if(listJogadores->nodeJogador == NULL) {
    printf("Não existem jogadores cadastrados!\n\n");
    return;
  }
  
  for(; current != NULL; current = current->next) {
    if(current->nome == nome) {
      previous->next = current->next;

      if(current == listJogadores->nodeJogador) 
        listJogadores->nodeJogador = current->next;
      
      free(current);
      puts("~~~~~~~~~~~");
      printf("Jogador %s deletado\n", nome);
      puts("~~~~~~~~~~~\n");
    }
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

NodeJogador * createNodeJogadorEscalado(char * nome) {
  NodeJogador * newNodeJogadorEscalado = malloc(sizeof(NodeJogador));

  if(!newNodeJogadorEscalado) {
    printf("Não foi possível relacionar novo jogador a escalacao do time.");
    return NULL;
  }

  newNodeJogadorEscalado->nome = nome;
  newNodeJogadorEscalado->next = NULL;

  return newNodeJogadorEscalado;
}

NodeJogo * createNodeJogo(char * nomeJogo, char * timeA, char * timeB) {
  NodeJogo * newNodeJogo = malloc(sizeof(NodeJogo));

  if(!newNodeJogo) {
    printf("Não foi possível relacionar novo jogo ao time.");
    return NULL;
  }

  puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("Informe as escalações do jogo: %s\n", nomeJogo);
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  newNodeJogo->nomeJogo = nomeJogo;
  newNodeJogo->timeA = timeA;
  newNodeJogo->timeB = timeB;

  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("Informe a escalação para o time: %s\n", timeA);
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  for(int auxA = 1; auxA < 12; auxA++) {
    char * nomeJogador;
    printf("Informe o nome do jogador %d:", auxA);
    scanf("%s", &nomeJogador);

    if(newNodeJogo->escalacaoA == NULL) {
      newNodeJogo->escalacaoA = createNodeJogadorEscalado(nomeJogador);
    } else {
      NodeJogador * currentJogadorEscalacao = newNodeJogo->escalacaoA;

      while (currentJogadorEscalacao->next!=NULL){
        currentJogadorEscalacao = currentJogadorEscalacao->next;
      }

      currentJogadorEscalacao->next = createNodeJogadorEscalado(nomeJogador);
    }
  }

  puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("Informe a escalação para o time: %s\n", timeB);
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(int auxB = 1; auxB < 12; auxB++) {
    char * nomeJogador;
    printf("Informe o nome do jogador %d:", auxB);
    scanf("%s", &nomeJogador);

    if(newNodeJogo->escalacaoB == NULL) {
      newNodeJogo->escalacaoB = createNodeJogadorEscalado(nomeJogador);
    } else {
      NodeJogador * currentJogadorEscalacao = newNodeJogo->escalacaoB;

      while (currentJogadorEscalacao->next!=NULL){
        currentJogadorEscalacao = currentJogadorEscalacao->next;
      }

      currentJogadorEscalacao->next = createNodeJogadorEscalado(nomeJogador);
    }
  }

  newNodeJogo->next = NULL;

  puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("-- Novo jogo cadastrado com sucesso!\n");
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return newNodeJogo;
}

void addJogoInfo(ListJogos * listJogos, char * nomeJogo, char * timeA, char * timeB) {
  if(listJogos->nodeJogo == NULL) {
    listJogos->nodeJogo = createNodeJogo(nomeJogo, timeA, timeB);
    return;
  }
  
  NodeJogador * currentJogo = listJogos->nodeJogo;

  while (currentJogo->next!=NULL){
    currentJogo = currentJogo->next;
  }

  currentJogo->next = createNodeJogo(nomeJogo, timeA, timeB);
}

NodeLance * createNodeLance(char * nomeTime, char * nomeJogador, char * lance) {
  NodeLance * newNodeLance = malloc(sizeof(NodeLance));

  if(!newNodeLance) {
    printf("Não foi possivel gerar no do lance.");
    return NULL;
  }

  newNodeLance->jogador = nomeJogador;
  newNodeLance->time = nomeTime;
  newNodeLance->lance = lance;
  
  newNodeLance->next = NULL;

  return newNodeLance;
}

void addJogoLance(ListJogos * listJogos, char * nomeJogo, char * nomeTime, char * nomeJogador, char * lance) {
  if(listJogos->nodeJogo == NULL)  {
    printf("Não há jogos cadastrados.");
    return;
  }
  
  NodeJogo * currentJogo = listJogos->nodeJogo;
  
  for(; currentJogo != NULL; currentJogo = currentJogo->next) {
    if(currentJogo->nomeJogo == nomeJogo) {
      if(currentJogo->lance == NULL) {
        currentJogo->lance = createNodeLance(nomeTime, nomeJogador, lance);
        return;
      } 

      NodeLance * currentLance = currentJogo->lance;

      while (currentLance->next!=NULL){
        currentLance = currentLance->next;
      }

      currentLance->next = createNodeLance(nomeTime, nomeJogador, lance);
    }
  }
}

void displayJogosInfo(ListJogos * listJogos) {
  if(listJogos->nodeJogo == NULL)  {
    printf("Não há jogos cadastrados");
    return;
  }
  
  NodeJogo * currentJogo = listJogos->nodeJogo;
  
  for(; currentJogo != NULL; currentJogo = currentJogo->next) {
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Informações da partida %s: %s X %s \n", currentJogo->nomeJogo, currentJogo->timeA, currentJogo->timeB);
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Jogadores escalados do time %s\n", currentJogo->timeA);
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    NodeJogador * currentJogadorEscalacaoA = currentJogo->escalacaoA;
    for(; currentJogadorEscalacaoA != NULL; currentJogadorEscalacaoA = currentJogadorEscalacaoA->next) {
      printf("%s\n", &currentJogadorEscalacaoA->nome);
    }

    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Jogadores escalados do time %s\n", currentJogo->timeB);
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    NodeJogador * currentJogadorEscalacaoB = currentJogo->escalacaoB;
    for(; currentJogadorEscalacaoB != NULL; currentJogadorEscalacaoB = currentJogadorEscalacaoB->next) {
      printf("%s\n", &currentJogadorEscalacaoB->nome);
    }

    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Lances marcados ao longo da partida\n");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    NodeLance * currentLance = currentJogo->lance;
    int auxLances = 1;
    for(; currentLance != NULL; currentLance = currentLance->next) {
      printf("%d. O jogador %s, do time %s, executou o seguinte lance: %s.\n", auxLances, currentLance->jogador, currentLance->time, currentLance->lance);
      auxLances++;
    }
  }
}