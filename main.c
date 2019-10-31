#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

typedef struct Pessoa {
  char nome[30];
} pessoa;

pessoa vetor[100];
int tam = 0;

FILE  *arq;

void abrir() {
  char nome[30];
  if(arq = fopen("arquivo.txt", "r")) {
    while((fscanf(arq, "%s", nome)) != EOF) {
      strcpy(vetor[tam].nome, nome);
      tam++;
    }
    fclose(arq);
  } else {
    printf("Erro ao abrir arquivo!");
  }
}

void salvarArquivo() {
  if(arq = fopen("arquivo.txt", "w")) {
    int i;
    for(i = 0; i < tam; i++) {
      fprintf(arq, "%s\n", vetor[i].nome);
    }
    fclose(arq);
  } else {
    printf("Erro ao abrir arquivo!\n");
  }
}

void inserir() {
  printf("Digite um nome: ");
  scanf("%s \n", &vetor[tam].nome);
  tam++;
}

void listar() {
  int i;
  for (i = 0; i < tam; i++) {
    printf("%s\n", vetor[i].nome);
    printf("\n");

  }
}

void pesquisar() {
  char nome[30];
  printf("Digite um nome para pesquisar: ");
  scanf("%s", &nome);
  bool achou = false;
  int i;
  for (i = 0; i < tam; i++) {
    if (strcmp(vetor[i].nome, nome) == 0) {
      printf("Nome presente na lista\n");
      achou = true;
      break;
    }
  }

  if (!achou) {
    printf("Nome não encontrado\n");
  }
}

void alterar() {
  char nome[30];
  printf("Digite um nome para alterar: ");
  scanf("%s", &nome);
  bool achou = false;
  int i;
  for (i = 0; i < tam; i++) {
    if (strcmp(vetor[i].nome, nome) == 0) {
      printf("Nome presente na lista\n");
      printf("Digite o novo nome: ");
      scanf("%s\n", &vetor[i].nome);
      printf("Nome alterado com sucesso\n");
      achou = true;
      break;
    }
  }

  if (!achou) {
    printf("Erro ao alterar nome\n");
  }
}

void exlcuirTrue(int pos) {
  printf("%d\n", pos);
  if (pos < tam) {
    vetor[pos] = vetor[tam-1];
  }

  tam--;
}

void excluir() {
  char nome[30];
  printf("Digite um nome para excluir: ");
  scanf("%s", &nome);
  bool achou = false;
  int i;
  for (i = 0; i < tam; i++) {
    if (strcmp(vetor[i].nome, nome) == 0) {
      printf("Nome presente na lista: %s\n", vetor[i].nome);
      printf("Digite 1 para confirmar a exclusao: ");
      int op;
      scanf("%d", &op);
      if (op == 1) {
        exlcuirTrue(i);
        printf("Nome excluido com sucesso\n");
      }

      achou = true;
      break;
    }
  }

  if (!achou) {
    printf("Erro ao exlcuir nome\n");
  }

}


void ordenar() {
  int i, j;
  for (i = 0; i < tam; i++) {
    for (j = 0; j<tam; j++) {
      if (strcmp(vetor[i].nome, vetor[j].nome)<0) {
        pessoa aux = vetor[j];
        vetor[j] = vetor[i];
        vetor[i] = aux;
      }
    }
  }
  listar();
  printf("\n");
}

int main() {
  abrir();
  int op;
  do {
    printf("1-Listar \n2-Inserir \n3-Pesquisar \n4-Alterar \n5-Excluir \n6-Ordenar \n0-Sair\n");
    scanf("%d", &op);

  if (op == 1){
    listar();
  } else if (op == 2) {
    inserir();
  } else if (op == 3) {
    pesquisar();
  } else if (op == 4) {
    alterar();
  } else if (op == 5) {
    excluir();
  } else if (op == 6) {
    ordenar();
  }

  } while (op != 0);

  salvarArquivo();

  return 0;
}