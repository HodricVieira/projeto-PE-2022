#include <stdio.h>
#include "funcoes.h"


int menu_principal(){
  int opcao;
  printf("\n1-Selecionar Temporada\n2-Visao Geral\n3-Fechar Programa\n");
  printf("Selecione uma opcao: ");
  scanf("%i", &opcao);
  switch (opcao)
  {
  case 1:
    /*Chamar a função que vai printar as temporadas, a função deve retornar o numero da temporada
    selecionda, a partir daí chama a função menu temporada*/
    printf("  Lista das temporadas\n");
    printf("  Temporada tal selecionda\n");
    menu_temporada(1);
    break;
  case 2:
    /*Chamar a função que vai printar o resumo geral*/
    printf("  Resumo Geral");
    menu_principal();
    break;
  case 3:
    /*Fecha o programa*/
    break;
  default:
    printf("\nOpcao Invalida, tente novamente!");
    menu_principal();
    break;
  }
  return opcao;
}

int menu_temporada(int temporada_selecionda){
  int opcao;
  printf("\n1-Selecionar Episodio\n2-Visao Geral\n3-Voltar ao Menu Principal\n4-Fechar Programa\n");
  printf("Selecione uma opcao: ");
  scanf("%i", &opcao);
  switch (opcao)
  {
  case 1:
    /*Chamar a função que vai printar os episodios, a função deve retornar o numero do episodio
    seleciondo, a partir daí chama a função resumo_episodio*/
    printf("  Episodio tal selecionado\n");
    printf("  Chama a funcao resumo_episodio\n");
    menu_temporada(temporada_selecionda);
    break;
  case 2:
    /*Chamar a função que vai printar o resumo geral da temporada selecionada*/
    printf("  Resumo da temporada");
    menu_temporada(temporada_selecionda);
    break;
  case 3:
    menu_principal();
    break;
  case 4:
    /*Fechar programa*/
    break;
  default:
    printf("\nOpção Inválida, tente novamente!");
    menu_temporada(temporada_selecionda);
    break;
  }
}

/* ############################################################################## */
int main(){
printf("\nBem vindo ao Sistema de Consultas de Game_of_Thrones\n");
menu_principal();
}

/*Interface principal
    1-Selecionar temporada
      Chama a função que vai buscar e printar todas as temporadas
    2-Visao Geral
      Chama a função que vai buscar, calcular e printa o resumo

  Interface Temporada
    1-Selecionar Episodio
      chama a função que printa os episodios dessa temporada
    2-Visao Geral da Temporada
      chama a função que vai buscar, calcular e printa o resumo da temporada
    3-Voltar
  
  Interface Episodio
    Resumo do episodio: Chama a função que printa as inforamações do episodio
    1-Voltar para temporada
      chama a função que printa interface Temporada
    2-Voltar para Tela inicial
      chama a função que printa a interface inicial
*/