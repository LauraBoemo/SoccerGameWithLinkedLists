#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct node Node;

typedef struct nodeTime NodeTime;

typedef struct nodeJogador NodeJogador;

typedef struct list List;

typedef struct listTime ListTime;

typedef struct listJogadores ListJogadores;

ListTime * makeListTime();
void addTimeInfo(ListTime * listTime, char * nome, char * estadio, char * cidade);
void delete(int data, List * list);
void display(ListTime * listTime);
void destroy(ListTime * listTime);

#endif
