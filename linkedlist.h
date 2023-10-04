#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

// Times
typedef struct nodeTime NodeTime;
typedef struct listTimes ListTimes;

// Tecnicos

typedef struct nodeTecnico NodeTecnico;
typedef struct listTecnicos ListTecnicos;

// Jogadores

typedef struct nodeJogador NodeJogador;
typedef struct listJogadores ListJogadores;

// Times

ListTimes * makeListTimes();
void addTimeInfo(ListTimes * listTimes, char * nome, char * estadio, char * cidade);
void displayTimesInfo(ListTimes * listTimes);
void searchTimeInfo(ListTimes * listTimes, char * nome);
void deleteTime(ListTimes * listTimes, char * nome);
void destroyTimes(ListTimes * listTimes);

// Tecnicos

ListTecnicos * makeListTecnicos();
void addTecnicoInfo(ListTecnicos * listTecnicos, char * nome);
void displayTecnicosInfo(ListTecnicos * listTecnicos);
void searchTecnicoInfo(ListTecnicos * listTecnicos, char * nome);
void deleteTecnico(ListTecnicos * listTecnicos, char * nome);
void destroyTecnicos(ListTecnicos * listTecnicos);

// Jogadores

ListJogadores * makeListJogadores();
void addJogadorInfo(ListJogadores * listJogadores, char * nome, char * posicao, char * cidade, int idade, int numeroCamisa);
void displayJogadoresInfo(ListJogadores * listJogadores);
void searchJogadorInfo(ListJogadores * listJogadores, char * nome);
void deleteJogador(ListJogadores * listJogadores, char * nome);
void destroyJogadores(ListJogadores * listJogadores);

#endif
