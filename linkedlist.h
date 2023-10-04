#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct nodeTime NodeTime;

typedef struct nodeTecnico NodeTecnico;

typedef struct nodeJogador NodeJogador;

typedef struct listTimes ListTimes;

typedef struct listTecnicos ListTecnicos;

typedef struct listJogadores ListJogadores;

// Times
ListTimes * makeListTimes();
void addTimeInfo(ListTimes * listTimes, char * nome, char * estadio, char * cidade);
void displayTimesInfo(ListTimes * listTimes);
// Tecnicos
ListTecnicos * makeListTecnicos();
void addTecnicoInfo(ListTecnicos * listTecnicos, char * nome);
void displayTecnicosInfo(ListTecnicos * listTecnicos);
// Jogadores
ListJogadores * makeListJogadores();
void addJogadorInfo(ListJogadores * listJogadores, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa);
void displayJogadoresInfo(ListJogadores * listJogadores);

#endif
