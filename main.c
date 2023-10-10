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

  addTimeInfo(listTimes, "Time 01", "Arena 01", "Cidade 01");
  addTimeInfo(listTimes, "Time 02", "Arena 02", "Cidade 02");
  addTimeInfo(listTimes, "Time 03", "Arena 03", "Cidade 03");
  addTimeInfo(listTimes, "Time 04", "Arena 04", "Cidade 04");
  addTimeInfo(listTimes, "Time 05", "Arena 05", "Cidade 05");
  addTimeInfo(listTimes, "Time 06", "Arena 06", "Cidade 06");
  addTimeInfo(listTimes, "Time 07", "Arena 07", "Cidade 07");
  addTimeInfo(listTimes, "Time 08", "Arena 08", "Cidade 08");
  addTimeInfo(listTimes, "Time 09", "Arena 09", "Cidade 09");
  addTimeInfo(listTimes, "Time 10", "Arena 10", "Cidade 10");

  addJogadorInfo(listJogadores, "Jogador 01", "Posição 01", "Cidade 01", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 02", "Posição 02", "Cidade 02", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 03", "Posição 03", "Cidade 03", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 04", "Posição 04", "Cidade 04", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 05", "Posição 05", "Cidade 05", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 06", "Posição 06", "Cidade 06", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 07", "Posição 07", "Cidade 07", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 08", "Posição 08", "Cidade 08", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 09", "Posição 09", "Cidade 09", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 10", "Posição 10", "Cidade 10", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 11", "Posição 11", "Cidade 11", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 12", "Posição 12", "Cidade 12", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 13", "Posição 13", "Cidade 13", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 14", "Posição 14", "Cidade 14", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 15", "Posição 15", "Cidade 15", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 16", "Posição 16", "Cidade 16", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 17", "Posição 17", "Cidade 17", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 18", "Posição 18", "Cidade 18", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 19", "Posição 19", "Cidade 19", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 20", "Posição 20", "Cidade 20", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 21", "Posição 21", "Cidade 21", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 22", "Posição 22", "Cidade 22", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 23", "Posição 23", "Cidade 23", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 24", "Posição 24", "Cidade 24", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 25", "Posição 25", "Cidade 25", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 26", "Posição 26", "Cidade 26", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 27", "Posição 27", "Cidade 27", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 28", "Posição 28", "Cidade 28", 20, 10);
  addJogadorInfo(listJogadores, "Jogador 29", "Posição 29", "Cidade 29", 20, 10);

  addTecnicoInfo(listTecnicos, "Tecnico 01");
  addTecnicoInfo(listTecnicos, "Tecnico 02");
  addTecnicoInfo(listTecnicos, "Tecnico 03");
  addTecnicoInfo(listTecnicos, "Tecnico 04");
  addTecnicoInfo(listTecnicos, "Tecnico 05");
  addTecnicoInfo(listTecnicos, "Tecnico 06");
  addTecnicoInfo(listTecnicos, "Tecnico 07");
  addTecnicoInfo(listTecnicos, "Tecnico 08");
  addTecnicoInfo(listTecnicos, "Tecnico 09");
  addTecnicoInfo(listTecnicos, "Tecnico 10");

  displayTimesInfo(listTimes);
  displayJogadoresInfo(listJogadores);
  displayTecnicosInfo(listTecnicos);

  searchTimeInfo(listTimes, "Time 01");
  searchJogadorInfo(listJogadores, "Jogador 01");
  searchTecnicoInfo(listTecnicos, "Tecnico 01");

  // deleteTime(listTimes, "Time 04");
  // deleteJogador(listJogadores, "Jogador 01");
  // deleteTecnico(listTecnicos, "Tecnico 01");

  addTimeJogadorRelacionadoInfo(listTimes, listJogadores, "Time 04", "Jogador 04");
  addTimeJogadorRelacionadoInfo(listTimes, listJogadores, "Time 03", "Jogador 05");
  addTimeJogadorRelacionadoInfo(listTimes, listJogadores, "Time 02", "Jogador 06");

  displayJogadoresRelaciondosAoTimeInfo(listTimes, "Time 04");
  displayJogadoresRelaciondosAoTimeInfo(listTimes, "Time 03");
  displayJogadoresRelaciondosAoTimeInfo(listTimes, "Time 02");

  addJogoInfo(listJogos, "Grenal", "Time 08", "Time 09");
  addJogoLance(listJogos, "Grenal", "Time 08", "Jogador 09", "Falta");
  addJogoLance(listJogos, "Grenal", "Time 09", "Jogador 02", "Falta");
  displayJogosInfo(listJogos);
  
  return 0;
}
