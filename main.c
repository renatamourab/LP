//Trabalho final da uc Linguagem de Programação
//feito por: Renata Moura Barreto

#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct {

  char num[TAM];

} Telefone;

typedef struct {

  char nome[TAM];
  Telefone tel;

} Contato;

void Ler_acao(int *acao) { // o que o usuário quer fazer

  scanf("%d", &(*acao));

  return;
}

void Limpar() {
  Contato agenda[TAM];

  int i;

  for (i = 1; i <= TAM; i++) {
    strcpy(agenda[i].nome, "");
    strcpy(agenda[i].tel.num, "");
  }
  return;
}

void Cadastrar(int *acao) {
  Contato agenda[TAM];

  int i, cont, n;

  scanf("%d", &i);

  if (i > 100 || i < 1) {
    printf("Índice digitado não existe [1,100]!\n");
  }
  if (i < 100 && i >= 1) {
    scanf("%s", agenda[i].nome);
  }
  if (i < 100 && i >= 1) {
    scanf("%s", agenda[i].tel.num);
  }

  if (strlen(agenda[i].tel.num) != 10 && strlen(agenda[i].tel.num) != 11) {
    printf("Telefone não tem 10 ou 11 dígitos! Favor digite novamente.\n");
    scanf("%s", agenda[i].tel.num);
  }

  if (strlen(agenda[i].tel.num) == 10 || strlen(agenda[i].tel.num) == 11) {
    scanf("%d", &(*acao));
  }

  if (strlen(agenda[i].tel.num) == 10 || strlen(agenda[i].tel.num) == 11) {
    printf("Contato cadastrado com sucesso!\n");
  }

  return;
}

void Listar_todos(int *acao) {
  Contato agenda[TAM];

  int cont, a = 0;

  for (cont = 1; cont <= TAM; cont++) {
    if (strlen(agenda[cont].nome) != 0 && strlen(agenda[cont].nome) != 1) {
      printf("Contato[%d]- Nome:%s Tel:%s\n", cont, agenda[cont].nome,
             agenda[cont].tel.num);
    }
    if (strlen(agenda[cont].nome) == 0 || strlen(agenda[cont].nome) == 1) {
      a++;
    }
  }
  if (a == (TAM)) {
    printf("Agenda vazia\n");
  }

  scanf("%d", &(*acao));

  return;
}

void Mostrar(int *acao) {
  Contato agenda[TAM];

  int i, cont, a = 0;

  scanf("%d", &i);

  if (i > 100 || i < 1) {
    printf("Índice digitado não existe [1,100]!\n");
  }

  if (strlen(agenda[i].nome) != 0 &&
      strlen(agenda[i].nome) != 1) { // se possui alg dentro
    printf("Contato[%d]- Nome:%s Tel:%s\n", i, agenda[i].nome,
           agenda[i].tel.num);
  } else {
    for (cont = 1; cont <= TAM;
         cont++) { // verificando se tem algum contato salvo
      if (strlen(agenda[cont].nome) == 0 || strlen(agenda[cont].nome) == 1) {
        a++;
      }
    }
    if (a == (TAM)) {
      printf("Agenda vazia\n");
    }
  }
  if (strlen(agenda[i].nome) == 0 || strlen(agenda[i].nome) == 1) {
    printf("Contato digitado não existe!\n");
  }

  scanf("%d", &(*acao));

  return;
}

void Apagar_cm_num(int *acao) {
  Contato agenda[TAM];

  int i, cont, a;

  scanf("%d", &i);

  if (i > 100 || i < 1) {
    printf("Índice digitado não existe [1,100]!\n");
  }

  if (i < 100 && i >= 1) {
    strcpy(agenda[i].nome, "");
    strcpy(agenda[i].tel.num, "");
    printf("Contato removido com sucesso!\n");
  }

  for (cont = 1; cont <= TAM; cont++) {
    if (strlen(agenda[cont].nome) != 0 && strlen(agenda[cont].nome) != 1) {
      printf("Contato[%d]- Nome:%s Tel:%s\n", cont, agenda[cont].nome,
             agenda[cont].tel.num);
    }
  }

  scanf("%d", &(*acao));

  return;
}

void Apagar_cm_nome(int *acao) {
  Contato agenda[TAM];

  char nome2[1];
  int cont, a = 0;

  scanf("%s", nome2);

  for (cont = 1; cont <= TAM; cont++) {
    if (agenda[cont].nome == nome2) {
      strcpy(agenda[cont].nome, "");
      strcpy(agenda[cont].tel.num, "");
      printf("Contato removido com sucesso!\n");
    }
  }

  for (cont = 1; cont <= TAM; cont++) {
    if (agenda[cont].nome != nome2) {
      a++;
    }
  }

  if (a == (TAM)) {
    printf("Contato digitado não existe!\n");
  }

  for (cont = 1; cont <= TAM; cont++) {
    if (strlen(agenda[cont].nome) != 0 && strlen(agenda[cont].nome) != 1) {
      printf("Contato[%d]- Nome:%s Tel:%s\n", cont, agenda[cont].nome,
             agenda[cont].tel.num);
    }
  }

  scanf("%d", &(*acao));

  return;
}

int main() {
  Contato agenda[TAM];

  int acao;

  Ler_acao(&acao);
  Limpar();

  while (acao != 0) {
    if (acao == 1) {
      Cadastrar(&acao);
    }
    if (acao == 2) {
      Listar_todos(&acao);
    }
    if (acao == 3) {
      Mostrar(&acao);
    }
    if (acao == 4) {
      Apagar_cm_num(&acao);
    }
    if (acao == 5) {
      Apagar_cm_nome(&acao);
    }
    if (acao > 5 || acao < 0) {
      Ler_acao(&acao);
      printf("Escolha valores entre 0 e 5!\n");
    }
  }
  if (acao == 0) {
    printf("Tchau!");
  }

  return 0;
}
