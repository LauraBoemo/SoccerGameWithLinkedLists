/*

~~~~~~~~~~~~~~~~~ SOCCER GAME WITH LINKED LISTS ~~~~~~~~~~~~~~~~~~
                        By:  Laura Boemo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
  ListTime * listTime = makeListTime("LAURA", "LAURA", "LAURA");
  ListTime * listTime2 = makeListTime("MURILO", "MURILO", "MURILO");
  display(listTime);
  return 0;
}
