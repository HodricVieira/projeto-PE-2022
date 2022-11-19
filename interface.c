#include <stdio.h>
#include "funcoes.h"

int ver_ep(int eps, int temp){
  int volta;
  bool close_ver_ep;

  /* Funcao para o resumo do episodio*/
  
  do {
  printf("Digite 0 para voltar a tela principal ou 1 para voltar para seleção de episodios:/n");
  scanf("%d", &volta);
  if (volta == 0 or volta == 1)
    close_ver_ep = TRUE;
  else 
    printf("Comando invalido digite novamente./n");
  }while (close_ver_ep != TRUE);
  return volta;
}

/* ##################################################################################### */
int interf_temp(int tempr){
  int it, ep_max, vp;
  bool closeit, closeep;
  do{
    printf("Digite 1 para ter a visão geral da temporada, 2 para escolher o episodio para visualizar ou 0 para voltar:/n");
    scanf("%d", &it);
    switch (it){
    case 0: closeit = TRUE;
      break;
    
    case 1: /* Função da visão geral */
      break;
    
    case 2: 
      do {
      if (tempr == 7){
        printf("Digite o numero do episodio de 1 a 7 ");
        ep_max = 7}
      else if (tempr == 8){
        printf("Digite o numero do episodio de 1 a 6 ");
        ep_max = 6}
      else{
        printf("Digite o numero do episodio de 1 a 10 ");
        ep_max = 10}
      printf("ou digite 0 para voltar/n");
      scanf("%d", &ep);
      if (ep >= 1 or ep <= ep_max){
        vp = ver_ep(ep, tempr);
        if (vp == 0)
          closeep = TRUE;
          closeit = TRUE;
      }else if (ep == 0)
        closeep = TRUE;
      else 
        printf("Comando invalido digite novamente./n");
      } while (closeep != TRUE);
      break;

    default: printf("Comando Invalido digite novamente./n");
      break;
  }while (closeit != TRUE);
  return;
}
}
/* ############################################################################## */
int main(){
int ip, temprd;
bool closeip, closetemp;
do{
printf("Digite 1 para ter a visão geral, 2 para escolher a temporada para visualizar ou 0 para fechar o programa/n");
scanf("%d", &ip);
  switch (ip){
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
    scanf("%d", &temprd);
    if (temprd >= 1 or temprd <= 8)
      interf_temp(temp);
    else if (temprd == 0)
      closetemp = TRUE;
    else 
      printf("Comando invalido digite novamente./n");
    
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