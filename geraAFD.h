#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OUT 0
#define IN 1

/*
  Sigma -> alfabeto
  Q     -> conjunto de estados possíveis
  sigma -> função de transição
  q0    -> estago inicial
  F     -> conjuto de estados finais

  M = (Sigma, Q, sigma, q0, F)
*/
typedef struct Conjunto {
  int tamanho;
  char **vetor;
} Conjunto;

typedef struct Matriz {
  int tamanho;
  Conjunto **matriz;
} Matriz;

typedef struct AFD {
  Conjunto *Sigma, *Q, *Q0, *F;
  Matriz *sigma;
} AFD;

unsigned countWords(char *str);
Conjunto *geraConjunto(unsigned qtdPalavra, char *linha);
Matriz *geraTabela(unsigned qtdPalavra, char *linha, Matriz *matriz);
void imprimeConjunto(Conjunto *conjunto);
void imprimeTabela(Matriz *matriz);
AFD *geraAFD(char *nomeArquivo);