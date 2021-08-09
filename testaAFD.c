#include "geraAFD.h"

bool testaAlfabeto(AFD *afd, char *palavra) {
  bool igual = false;
  for (size_t i = 0; i < strlen(palavra); i++) {
    for (int j = 0; j < afd->Sigma->tamanho; j++) {
      if (palavra[i] == afd->Sigma->vetor[j][0]) {
        igual = true;
      }
    }
    if (igual == false) {
      printf("Palavra não pertence ao alfabeto\n");
      return false;
    } else {
      igual = false;
    }
  }
  return true;
}

bool testaAFD(AFD *afd, char *palavra) {
  char *estadoAtual = afd->Q0->vetor[0];
  size_t entradaAtual = 0;
  int i, j;
  if (testaAlfabeto(afd, palavra)) {
    while (entradaAtual < strlen(palavra)) {
      for (i = 0; i < afd->sigma->tamanho; i++) {
        if (!strcmp(afd->sigma->matriz[i]->vetor[0], estadoAtual)) {
          printf("%s + ", afd->sigma->matriz[i]->vetor[0]);
          break;
        }
      }
      for (j = 0; j < afd->sigma->matriz[0]->tamanho; j++) {
        if (afd->sigma->matriz[0]->vetor[j][0] == palavra[entradaAtual]) {
          printf("%c -> ", afd->sigma->matriz[0]->vetor[j][0]);
          break;
        }
      }
      estadoAtual = afd->sigma->matriz[i]->vetor[j];
      printf("%s \n", estadoAtual);
      entradaAtual++;
    }
  }
  for (int k = 0; k < afd->F->tamanho; k++) {
    if (!strcmp(estadoAtual, afd->F->vetor[k])) {
      return true;
    }
  }
  return false;
}