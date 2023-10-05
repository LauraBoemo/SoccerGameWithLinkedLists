/*

~~~~~~~~~~~~~~~~~ SOCCER GAME WITH LINKED LISTS ~~~~~~~~~~~~~~~~~~
                        By:  Laura Boemo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
  ListTimes * listTimes = makeListTimes();
  ListTecnicos * listTecnicos = makeListTecnicos();
  ListJogadores * listJogadores = makeListJogadores();
  addTimeInfo(listTimes, "Gremio", "Arena do Gremio", "Porto Alegre");
  addTimeInfo(listTimes, "Inter", "Beira Rio", "Porto Alegre");
  addTecnicoInfo(listTecnicos, "Murilo Tecnico");
  addTecnicoInfo(listTecnicos, "Laura Tecnica");
  addTecnicoInfo(listTecnicos, "Luana Tecnica");
  addJogadorInfo(listJogadores, "Laura Boemo", "Atacante", "Santa Maria", 20, 10);
  addJogadorInfo(listJogadores, "Murilo Leitao", "Goleiro", "Santa Maria", 21, 1);
  searchTimeInfo(listTimes, "Gremio");
  addJogadorRelacionadoTime(listTimes, "Gremio", listJogadores, "Laura Boemo");
  addJogadorRelacionadoTime(listTimes, "Gremio", listJogadores, "Murilo Leitao");
  displayJogadoresRelacionadosTime(listTimes, "Gremio");
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
  return 0;
}
