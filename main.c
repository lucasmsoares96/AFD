#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "testaAFD.h"

int main(int argc, char *argv[]) {
  AFD *afd = geraAFD("afd.txt");
  char *palavra;

  if (argc > 1) {
    palavra = argv[1];
    printf("Palavra: %s\n\n", palavra);
    if (testaAFD(afd, palavra)) {
      printf("\nAceita\n\n");
    } else {
      printf("\nRejeitada\n\n");
    }
  } else
    printf(
        "Informe a palavra que deseja verificar na frente do comando\n");

  return 0;
}