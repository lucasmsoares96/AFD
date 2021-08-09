#include "geraAFD.h"

unsigned countWords(char *str) {
  int state = OUT;
  unsigned wc = 0;

  while (*str) {
    if (*str == ',' || *str == ' ' || *str == '\n' || *str == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++wc;
    }
    ++str;
  }
  return wc;
}

Conjunto *geraConjunto(unsigned qtdPalavra, char *linha) {
  char delimitadores[] = " ,";
  Conjunto *conjunto = (Conjunto *)malloc(sizeof(Conjunto));
  conjunto->vetor = (char **)malloc(qtdPalavra * sizeof(char *));
  conjunto->tamanho = qtdPalavra;
  unsigned i = 0;
  conjunto->vetor[i] = strtok(linha, delimitadores);
  i++;
  while (i != qtdPalavra) {
    conjunto->vetor[i] = strtok(NULL, delimitadores);
    i++;
  }
  return conjunto;
}

Matriz *geraTabela(unsigned qtdPalavra, char *linha, Matriz *matriz) {
  Conjunto *conjunto = geraConjunto(qtdPalavra, linha);
  matriz->matriz[(matriz->tamanho) - 1] = conjunto;
  return matriz;
}

void imprimeConjunto(Conjunto *conjunto) {
  for (int i = 0; i < conjunto->tamanho; i++) {
    printf("%s, ", conjunto->vetor[i]);
  }
  printf("\n");
}

void imprimeTabela(Matriz *matriz) {
  for (int i = 0; i < matriz->tamanho; i++) {
    imprimeConjunto(matriz->matriz[i]);
  }
}

AFD *geraAFD(char *nomeArquivo) {
  FILE *arquivo;
  int tamanholinha = 255;
  char *linha;
  char dupLinha[tamanholinha];
  unsigned qtdPalavra;
  Conjunto *Sigma, *Q, *Q0, *F;
  Matriz *sigma = NULL;
  AFD *afd;
  char *comando;
  if ((arquivo = fopen(nomeArquivo, "r")) == NULL) {
    printf("Arquivo não encontrado");
    return NULL;
  }

  while (fgets(dupLinha, tamanholinha, arquivo)) {
    linha = strdup(dupLinha);
    qtdPalavra = countWords(linha);
    linha[strcspn(linha, "\n")] = 0;
    if (!strcmp(linha, "Sigma") || !strcmp(linha, "Q") ||
        !strcmp(linha, "sigma") || !strcmp(linha, "Q0") ||
        !strcmp(linha, "F")) {
      comando = strdup(linha);
      continue;
    } else {
      if (!strcmp(comando, "Sigma")) {
        Sigma = geraConjunto(qtdPalavra, linha);
      } else if (!strcmp(comando, "Q")) {
        Q = geraConjunto(qtdPalavra, linha);
      } else if (!strcmp(comando, "sigma")) {
        if (sigma == NULL) {
          sigma = (Matriz *)malloc(sizeof(Matriz));
          sigma->tamanho++;
          sigma->matriz =
              (Conjunto **)malloc(sigma->tamanho * sizeof(Conjunto *));
          sigma = geraTabela(qtdPalavra, linha, sigma);
        } else {
          sigma->tamanho++;
          sigma->matriz = (Conjunto **)realloc(
              sigma->matriz, sigma->tamanho * sizeof(Conjunto *));
          sigma = geraTabela(qtdPalavra, linha, sigma);
        }
      } else if (!strcmp(comando, "Q0")) {
        Q0 = geraConjunto(qtdPalavra, linha);
      } else if (!strcmp(comando, "F")) {
        F = geraConjunto(qtdPalavra, linha);
      }
    }
  }

  afd = (AFD *)malloc(sizeof(AFD));
  afd->sigma = sigma;
  afd->Q = Q;
  afd->Sigma = Sigma;
  afd->F = F;
  afd->Q0 = Q0;

  // imprimeConjunto(Sigma);
  // imprimeConjunto(Q);
  // imprimeTabela(sigma);
  // imprimeConjunto(F);
  // imprimeConjunto(Q0);
  // printf("\n");
  // fclose(arquivo);
  return afd;
}