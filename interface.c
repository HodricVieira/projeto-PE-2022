#include <stdio.h>
#include "funcoes.h"


int interf_temp(int tempr){

}

int main(){
int ip, temp;
bool closeip, closetemp;
do{
printf("Digite 1 para ter a visão geral, 2 para escolher a temporada para visualizar ou 0 para fechar o programa/n");
scanf("%d", &ip);
  switch (ip)
  {
  case 0: closeip = TRUE;
    break;
  
  case 1: /* Função da visão geral */
    break;
  
  case 2: 
    do{
    printf("Digite o numero da temporada que deseja ver:/n
            1 temporada/n
            2 temporada/n
            3 temporada/n
            4 temporada/n
            5 temporada/n
            6 temporada/n
            7 temporada/n
            8 temporada/n
            Digite 0 para voltar");
    scanf("%d", &temp);
    if (temp >= 1 or temp <= 8)
      interf_temp(temp);
    else if (temp == 0)
      closetemp = TRUE;
    else 
      printf("Comando invalido");
    
    } while (closetemp != TRUE);
    break;
  
  default: printf("Comando Invalido digite novamente./n");
    break;
  }
  }while (closeip != TRUE);
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