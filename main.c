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
  addTimeInfo(listTimes, "Gremio", "Arena do Gremio", "Porto Alegre");
  addJogadorInfo(listTimes, "Laura Boemo", "Atacante", "Santa Maria", 20, 10);
  addJogadorInfo(listTimes, "Murilo Leitao", "Goleiro", "Santa Maria", 21, 1);
  displayTimesInfo(listTimes);
  displayJogadoresInfo(listTimes);
  return 0;
}
