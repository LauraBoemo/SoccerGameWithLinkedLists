/*

~~~~~~~~~~~~~~~~~ SOCCER GAME WITH LINKED LISTS ~~~~~~~~~~~~~~~~~~
                        By:  Laura Boemo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
  // Inicialização das listas
  ListTimes * listTimes = makeListTimes();
  ListJogos * listJogos = makeListJogadores();
  ListTecnicos * listTecnicos = makeListTecnicos();
  ListJogadores * listJogadores = makeListJogadores();

  // Inicialização da variável da ação selecionada
  int acaoSelecionada;

  // Output nome do jogo 
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	puts("    Jogo de Administração Futebolística com Listas Encadeadas");
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

  // Output opções do jogo 
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  puts("    Ações possíveis:\n");
  puts("    1) Cadastrar novo time.");
  puts("    2) Cadastrar novo jogador.");
  puts("    3) Cadastrar novo técnico.");
  puts("    4) Visualizar times cadastrados.");
  puts("    5) Visualizar jogadores cadastrados.");
  puts("    6) Visualizar técnicos cadastrados.");
  puts("    7) Pesquisar informações de um time.");
  puts("    8) Pesquisar informações de um jogador.");
  puts("    9) Pesquisar informações de um técnico.");
  puts("    10) Remover um time.");
  puts("    11) Remover um jogador.");
  puts("    12) Remover um técnico.");
  puts("    13) Relacionar um jogador a um time.");
  puts("    14) Visualizar os jogadores relacionados a um time.");
  puts("    15) Cadastrar novo jogo.");
  puts("    16) Cadastrar lance a um jogo.");
  puts("    17) Visualizar jogos cadastrados.");
  puts("    18) Encerrar jogo.");
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

  // Output de selecao do jogo
  while(acaoSelecionada != 18) {
    printf("Informe o número da ação que desejas realizar: ");
    scanf("%d", &acaoSelecionada);

    if(acaoSelecionada == 1) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Cadastro de Time");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      char nome[100], arena[100], cidade[100];
      
      printf("Informe o nome do time: ");
      fflush(stdin);
      fgets(nome, 100, stdin);
      printf("Informe a arena do time: ");
      fflush(stdin);
      fgets(arena, 100, stdin);
      printf("Informe a cidade do time: ");
      fflush(stdin);
      fgets(cidade, 100, stdin);

      addTimeInfo(listTimes, nome, arena, cidade);
    }

    if(acaoSelecionada == 2) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Cadastro de Jogador");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      char nome[50], posicao[50], cidade[50];
      int idade, numeroCamisa;
      
      printf("Informe o nome do jogador: ");
      fflush(stdin);
      fgets(nome, 50, stdin);
      printf("Informe a posição do jogador: ");
      fflush(stdin);
      fgets(posicao, 50, stdin);
      printf("Informe a cidade do jogador: ");
      fflush(stdin);
      fgets(cidade, 50, stdin);
      printf("Informe a idade do jogador: ");
      scanf("%d", &idade);
      printf("Informe o número da camisa do jogador: ");
      scanf("%d", &numeroCamisa);

      addJogadorInfo(listJogadores, nome, posicao, cidade, idade, numeroCamisa);
    }

    if(acaoSelecionada == 3) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Cadastro de Técnico");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      char nome[50];
      
      printf("Informe o nome do técnico: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      addTecnicoInfo(listTecnicos, nome);
    }

    if(acaoSelecionada == 4) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Tabela dos times cadastrados");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      displayTimesInfo(listTimes);
    }

    if(acaoSelecionada == 5) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Tabela dos times cadastrados");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      displayJogadoresInfo(listJogadores);
    }

    if(acaoSelecionada == 6) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Tabela dos técnicos cadastrados");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      displayTecnicosInfo(listTecnicos);
    }

    if(acaoSelecionada == 7) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Pesquisar informação de um time");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do time: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      searchTimeInfo(listTimes, nome);
    }

    if(acaoSelecionada == 8) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Pesquisar informação de um jogador");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do jogador: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      searchTimeInfo(listJogadores, nome);
    }

    if(acaoSelecionada == 9) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Pesquisar informação de um técnico");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do técnico: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      searchTimeInfo(listTecnicos, nome);
    }

    if(acaoSelecionada == 10) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Remover um time");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do time: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      deleteTime(listTimes, nome);
    }

    if(acaoSelecionada == 11) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Remover um jogador");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do jogador: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      deleteJogador(listJogadores, nome);
    }

    if(acaoSelecionada == 12) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Remover um técnico");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do técnico: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      deleteTecnico(listTecnicos, nome);
    }

    if(acaoSelecionada == 13) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Relacionar um jogador a um time");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nomeTime[50], nomeJogador[50];
      
      printf("Informe o nome do time: ");
      fflush(stdin);
      fgets(nomeTime, 50, stdin);

      printf("Informe o nome do jogador: ");
      fflush(stdin);
      fgets(nomeJogador, 50, stdin);

      addTimeJogadorRelacionadoInfo(listTimes, listJogadores, nomeTime, nomeJogador);
    }

    if(acaoSelecionada == 14) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Visualizar os jogadores relacionados a um time");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do time: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      displayJogadoresRelaciondosAoTimeInfo(listTimes, nome);
    }

    if(acaoSelecionada == 15) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Visualizar os jogadores relacionados a um time");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50];
      
      printf("Informe o nome do time: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      displayJogadoresRelaciondosAoTimeInfo(listTimes, nome);
    }

    if(acaoSelecionada == 16) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Cadastrar novo jogo");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nome[50], timeA[50], timeB[50];
      
      printf("Informe o nome do jogo: ");
      fflush(stdin);
      fgets(nome, 50, stdin);

      printf("Informe o nome do timeA: ");
      fflush(stdin);
      fgets(timeA, 50, stdin);

      printf("Informe o nome do timeB: ");
      fflush(stdin);
      fgets(timeB, 50, stdin);

      addJogoInfo(listJogos, nome, timeA, timeB);
    }

    if(acaoSelecionada == 17) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Cadastrar lance a um jogo");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      char nomeJogo[50], nomeTime[50], nomeJogador[50], lance[50];
      
      printf("Informe o nome do jogo: ");
      fflush(stdin);
      fgets(nomeJogo, 50, stdin);

      printf("Informe o nome do time: ");
      fflush(stdin);
      fgets(nomeTime, 50, stdin);

      printf("Informe o nome do jogador: ");
      fflush(stdin);
      fgets(nomeJogador, 50, stdin);

      printf("Informe o nome do lance: ");
      fflush(stdin);
      fgets(lance, 50, stdin);

      addJogoLance(listJogos, nomeJogo, nomeTime, nomeJogador, lance);
    }
  }

  return 0;
}
