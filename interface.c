#include <stdio.h>
#include "funcoes.h"

int main(){
int ip;
bool close;
do{
printf("Digite 1 para selecionar a temporada ou digite 2 para ver a visão geral ou 3 para fechar o programa./n");
scanf("%d", &ip);
  switch (ip)
  {
  case 1:
    break;
  
  case 2:
    break;
  
  case 3: close = TRUE
    break;
  
  default: printf("Comando Invalido digite novamente./n")
    break;
  }
  }while (close != TRUE);
}
/*Interface principal
    1-Selecionar temporada
    2-Visao Geral

  Interface Temporada
    1-Selecionar Episodio
    2-Visao Geral da Temporada
    3-Voltar
  
  Interface Episodio
    Resumo do episodio
    1-Voltar para temporada
    2-Voltar para Tela inicial
*/