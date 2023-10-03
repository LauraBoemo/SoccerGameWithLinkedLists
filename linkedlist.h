#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct node Node;

typedef struct list List;

typedef struct listTime ListTime;

ListTime * makeListTime(char * nome, char * estadio, char * cidade);
List * makeList();
void add(int data, List * list);
void delete(int data, List * list);
void display(ListTime * listTime);
void destroy(ListTime * listTime);

#endif
