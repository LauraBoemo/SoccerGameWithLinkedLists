/*

~~~~~~~~~~~~~~~~~ SOCCER GAME WITH LINKED LISTS ~~~~~~~~~~~~~~~~~~
                        By:  Laura Boemo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
  ListTime * listTime = makeListTime();
  addTimeInfo(listTime, "LAURA", "LAURA", "LAURA");
  display(listTime);
  return 0;
}
