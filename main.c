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
  addTecnicoInfo(listTecnicos, "Murilo Tecnico");
  addJogadorInfo(listJogadores, "Laura Boemo", "Atacante", "Santa Maria", 20, 10);
  displayTimesInfo(listTimes);
  displayTecnicosInfo(listTecnicos);
  displayJogadoresInfo(listJogadores);
  return 0;
}
