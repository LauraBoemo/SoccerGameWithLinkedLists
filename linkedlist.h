#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct nodeTime NodeTime;

typedef struct nodeJogador NodeJogador;

typedef struct listTimes ListTimes;

typedef struct listJogadores ListJogadores;

ListTimes * makeListTimes();
void addTimeInfo(ListTimes * listTimes, char * nome, char * estadio, char * cidade);
void displayTimesInfo(ListTimes * listTimes);
void addJogadorInfo(ListTimes * listTimes, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa);
void displayJogadoresInfo(ListTimes * listTimes);

#endif
