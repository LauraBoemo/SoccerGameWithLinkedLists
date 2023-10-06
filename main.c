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
  puts("    Ações possíveis:");
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
  puts("    18) Pesquisar informações de um jogo.");
  puts("    19) Encerrar jogo.");
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

  // Output de selecao do jogo
  while(acaoSelecionada != 19) {
    printf("Informe o número da ação que desejas realizar: ");
    scanf("%d", &acaoSelecionada);

    if(acaoSelecionada == 1) {
      puts("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      puts("-- Cadastro de Time");
      puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      char nome[100], arena[100], cidade[100];
      
      printf("Informe o nome do time: ");
      scanf("%s", nome);
      printf("Informe a arena do time: ");
      scanf("%s", arena);
      printf("Informe a cidade do time: ");
      scanf("%s", cidade);
      addTimeInfo(listTimes, nome, arena, cidade);
    }

    // switch(acaoSelecionada) {
    //   case 1: {
    //     char * nome, arena, cidade;
    //     printf("Informe o nome do time: ");
    //     scanf("%s", nome);
    //     printf("Informe a arena do time: ");
    //     scanf("%s", arena);
    //     printf("Informe a cidade do time: ");
    //     scanf("%s", cidade);
    //     addTimeInfo(listTimes, nome, arena, cidade);
    //   }
    //   break;
      
    //   case 2: {
    //     char * nome, posicao, cidade;
    //     int idade, numeroCamisa;
    //     printf("Informe o nome do jogador: ");
    //     scanf("%s", nome);
    //     printf("Informe a posicao do jogador: ");
    //     scanf("%s", posicao);
    //     printf("Informe a cidade do jogador: ");
    //     scanf("%s", cidade);
    //     printf("Informe a idade do jogador: ");
    //     scanf("%d", idade);
    //     printf("Informe o número da camisa do jogador: ");
    //     scanf("%d", numeroCamisa);
    //     addJogadorInfo(listJogadores, nome, posicao, cidade, idade, numeroCamisa);
    //   }
    //   break;

    //   case 3: {
    //     char * nome;
    //     printf("Informe o nome do técnico: ");
    //     scanf("%s", nome);
    //     addTecnicoInfo(listTecnicos, nome);
    //   }
    //   break;

    //   case 19:
    //     return 0;
    //     break;
      
    //   default:
    //     break;
    // }
  }
  return 0;
  // searchTimeInfo(listTimes, "Gremio");
  // addJogadorRelacionadoTime(listTimes, "Gremio", listJogadores, "Laura Boemo");
  // addJogadorRelacionadoTime(listTimes, "Gremio", listJogadores, "Murilo Leitao");
  // displayJogadoresRelacionadosTime(listTimes, "Gremio");
  // displayTimesInfo(listTimes);
  // displayTecnicosInfo(listTecnicos);
  // deleteTecnico(listTecnicos, "Murilo Tecnico");
  // displayTecnicosInfo(listTecnicos);
  // displayJogadoresInfo(listJogadores);
  // destroyJogadores(listJogadores);
  // displayJogadoresInfo(listJogadores);
  // searchTimeInfo(listTimes, "Gremio");
  // searchJogadorInfo(listJogadores, "Laura Boemo");
  // searchTecnicoInfo(listTecnicos, "Laura Tecnica");
  // addTimeJogadorRelacionadoInfo(listTimes, listJogadores, "Gremio", "Laura Boemo");
  // addTimeJogadorRelacionadoInfo(listTimes, listJogadores, "Gremio", "Murilo Leitao");
  // displayJogadoresRelaciondosAoTimeInfo(listTimes, "Gremio");
  // addJogoInfo(listJogos, "Grenal", "Gremio", "Inter");
  // addJogoLance(listJogos, "Grenal", "Gremio", "Laura Boemo", "Falta");
  // displayJogosInfo(listJogos);
  // return 0;
}
