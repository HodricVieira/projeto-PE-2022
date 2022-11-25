#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
int temp;
int ep_temp;
int ep_total;
char nome_ep[40];
int duracao_ep;
char diretor[50];
char escritor[70];
char data_estreia[20];
float visualizacoes;
char musico[20];
char cinematografista[50];
char editor[50];
float IMDB;
float RotTomat;
float Metacritic;
char ordered[20];
char filmagem[25];
char livro[70];
char sinopse[1700];


}struct_do_csv;

struct_do_csv GOT_dados[73];


int menu_principal(){
  int opcao;
  printf("\n1-Selecionar Temporada\n2-Visao Geral\n3-Fechar Programa\n");
  printf("Selecione uma opcao: ");
  scanf("%i", &opcao);
  switch (opcao)
  {
  case 1:
    menu_temporada(temporadas()); /*Chama a função menu_temporada com o retorno da funçao temporadas*/
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

int temporadas(){ /*Funçao responsável pela escolha da temporada. Retorna a temporada escolhida*/
  int opcao_temporada;
  printf("\nSelecione o numero da temporada desejada:\n");
  printf("\n1 - Primeira Temporada\n\n2 - Segunda Temporada\n\n3 - Terceira Temporada\n\n4 - Quarta Temporada\n\n"
         "5 - Quinta Temporada\n\n6 - Sexta Temporada\n\n7 - Setima Temporada\n\n8 - Oitava Temporada\n\n");
  scanf("%d", &opcao_temporada);
  if (opcao_temporada >= 1 && opcao_temporada <= 8)
    return opcao_temporada;

  else{
    printf("\nNúmero de temporada inválido.\n\n");
    temporadas();
  }
}

int menu_temporada(int temporada_selecionada){
  int opcao;
  printf("\n1-Selecionar Episodio\n2-Visao Geral\n3-Voltar ao Menu Principal\n4-Fechar Programa\n");
  printf("Selecione uma opcao: ");
  scanf("%i", &opcao);
  switch (opcao)
  {
  case 1:
    episodios(temporada_selecionada); /* Chama a função episódios, passando por parâmetro a temporada selecionada*/
    menu_temporada(temporada_selecionada);
    break;
  case 2:
    /*Chamar a função que vai printar o resumo geral da temporada selecionada*/
    printf("  Resumo da temporada");
    menu_temporada(temporada_selecionada);
    break;
  case 3:
    menu_principal();
    break;
  case 4:
    /*Fechar programa*/
    break;
  default:
    printf("\nOpção Inválida, tente novamente!");
    menu_temporada(temporada_selecionada);
    break;
  }
}


int episodios(int temp_selecionada){ /*O usuário escolherá o episódio de seu interesse. Após a escolha, é chamada a função resumo_episodio.*/
  int opcao_episodio;
  if(temp_selecionada >= 1 && temp_selecionada <= 6){
    printf("\nEscolha o numero de um dos episodios abaixo:\n");
    printf("\n1 - Primeiro Episodio\n\n2 - Segundo Episodio\n\n3 - Terceiro Episodio\n\n4 - Quarto Episodio\n\n"
    "5 - Quinto Episodio\n\n6 - Sexto Episodio\n\n7 - Setimo Episodio\n\n8 - Oitavo Episodio\n\n9 - Nono Episodio\n\n10 - Decimo Episodio\n\n");
    scanf("%d", &opcao_episodio);
    if(opcao_episodio >= 1 && opcao_episodio <= 10){
        resumo_episodio(temp_selecionada, opcao_episodio);

    }
    else{
        printf("\nNumero de episodio invalido.\n\n");
        episodios(temp_selecionada);
    }
  }

  if(temp_selecionada == 7){
    printf("\nEscolha o numero de um dos episodios abaixo:\n");
    printf("\n1 - Primeiro Episodio\n\n2 - Segundo Episodio\n\n3 - Terceiro Episodio\n\n4 - Quarto Episodio\n\n"
    "5 - Quinto Episodio\n\n6 - Sexto Episodio\n\n7 - Setimo Episodio\n\n");
    scanf("%d", &opcao_episodio);
    if(opcao_episodio >= 1 && opcao_episodio <= 7){
        resumo_episodio(temp_selecionada, opcao_episodio);

    }
    else{
        printf("\nNumero de episodio invalido.\n\n");
        episodios(temp_selecionada);
    }
  }

  if(temp_selecionada == 8){
    printf("\nEscolha o numero de um dos episodios abaixo:\n");
    printf("\n1 - Primeiro Episodio\n\n2 - Segundo Episodio\n\n3 - Terceiro Episodio\n\n4 - Quarto Episodio\n\n"
    "5 - Quinto Episodio\n\n6 - Sexto Episodio\n\n");
    scanf("%d", &opcao_episodio);
    if(opcao_episodio >= 1 && opcao_episodio <= 6){
        resumo_episodio(temp_selecionada, opcao_episodio);

    }
    else{
        printf("\nNumero de episodio invalido.\n\n");
        episodios(temp_selecionada);
    }
  }

}

int resumo_episodio(int temp_selecionada, int ep_selecionado){ /*Funçao que exibe as informações do episódio.*/
  int i;
  switch (temp_selecionada){
  case 1:
    i = ep_selecionado - 1; /*Vetor começa em 0, então subtrair o número do episódio por 1 para ter o ep correto.*/
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);

    break;
  case 2:
    i = ep_selecionado + 9; /*Cálculo: ep + 10 (segunda temporada) - 1 (vetor começa em 0)*/
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);
    break;
  case 3:
    i = ep_selecionado + 19; /*Cálculo: ep + 20 (terceira temporada) - 1 (vetor começa em 0)*/
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);
    break;
  case 4:
    i = ep_selecionado + 29;
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);
    break;
  case 5:
    i = ep_selecionado + 39;
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);
    break;
  case 6:
    i = ep_selecionado + 49;
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);
    break;
  case 7:
    i = ep_selecionado + 59;
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);
    break;
  case 8:
    i = ep_selecionado + 66; /*Cálculo: ep + 67 (oitava temporada, a sétima possui 3 episódios a menos) - 1 (vetor começa em 0)*/
    printf("\nEpisodio %d\n"
           "Titulo do episodio: %s\n"
           "Duracao do episodio: %d minutos\n"
           "Data de estreia: %s\n"
           "Numero de visualizacoes: %.2f milhoes\n"
           "Avaliacao do IMDB: %.2f\n"
           "Avaliacao do Rotten Tomatoes: %.2f\n"
           "Avaliacao do Metacritic: %.2f\n"
           "Sinopse do episodio: %s\n",
           GOT_dados[i].ep_temp,
           GOT_dados[i].nome_ep,
           GOT_dados[i].duracao_ep,
           GOT_dados[i].data_estreia,
           GOT_dados[i].visualizacoes,
           GOT_dados[i].IMDB,
           GOT_dados[i].RotTomat,
           GOT_dados[i].Metacritic,
           GOT_dados[i].sinopse);
    break;
  }
}


/* ############################################################################## */
int main(){
    FILE *arquivo;
    char linha_arquivo[1700];
    int i = 0;
    char *delimitador = ";";



    arquivo = fopen("Game_of_Thronesv2.csv", "r");

    if (arquivo == NULL)
        printf("Erro na abertura do arquivo.\n");

    rewind(arquivo);

    while(fgets(linha_arquivo, 1700,arquivo) != NULL){

        GOT_dados[i].temp = atoi(strtok(linha_arquivo, delimitador));
        GOT_dados[i].ep_temp = atoi(strtok(NULL, delimitador));
        GOT_dados[i].ep_total = atoi(strtok(NULL, delimitador));
        strcpy(GOT_dados[i].nome_ep, strtok(NULL, delimitador));
        GOT_dados[i].duracao_ep = atoi(strtok(NULL, delimitador));
        strcpy(GOT_dados[i].diretor, strtok(NULL, delimitador));
        strcpy(GOT_dados[i].escritor, strtok(NULL, delimitador));
        strcpy(GOT_dados[i].data_estreia, strtok(NULL, delimitador));
        GOT_dados[i].visualizacoes = atof(strtok(NULL, delimitador));
        strcpy(GOT_dados[i].musico, strtok(NULL, delimitador));
        strcpy(GOT_dados[i].cinematografista, strtok(NULL, delimitador));
        strcpy(GOT_dados[i].editor, strtok(NULL, delimitador));
        GOT_dados[i].IMDB = atof(strtok(NULL, delimitador));
        GOT_dados[i].RotTomat = atof(strtok(NULL, delimitador));
        GOT_dados[i].Metacritic = atof(strtok(NULL, delimitador));
        strcpy(GOT_dados[i].ordered, strtok(NULL, delimitador));
        strcpy(GOT_dados[i].filmagem, strtok(NULL, delimitador));
        strcpy(GOT_dados[i].livro, strtok(NULL, delimitador));
        strcpy(GOT_dados[i].sinopse, strtok(NULL, delimitador));

        i++;

    }

    fclose(arquivo);

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
