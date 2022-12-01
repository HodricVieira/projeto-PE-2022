# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

int ler_csv(struct_do_csv dados[]){
    FILE *arquivo;
    char linha_arquivo[1700];
    int i = 0;
    char *delimitador = ";";
    arquivo = fopen("Game_of_Thronesv2.csv", "r");
    if (arquivo == NULL)
        printf("Erro na abertura do arquivo.\n");
    rewind(arquivo);
    while(fgets(linha_arquivo, 1700,arquivo) != NULL){
        dados[i].temp = atoi(strtok(linha_arquivo, delimitador));
        dados[i].ep_temp = atoi(strtok(NULL, delimitador));
        dados[i].ep_total = atoi(strtok(NULL, delimitador));
        strcpy(dados[i].nome_ep, strtok(NULL, delimitador));
        dados[i].duracao_ep = atoi(strtok(NULL, delimitador));
        strcpy(dados[i].diretor, strtok(NULL, delimitador));
        strcpy(dados[i].escritor, strtok(NULL, delimitador));
        strcpy(dados[i].data_estreia, strtok(NULL, delimitador));
        dados[i].visualizacoes = atof(strtok(NULL, delimitador));
        strcpy(dados[i].musico, strtok(NULL, delimitador));
        strcpy(dados[i].cinematografista, strtok(NULL, delimitador));
        strcpy(dados[i].editor, strtok(NULL, delimitador));
        dados[i].IMDB = atof(strtok(NULL, delimitador));
        dados[i].RotTomat = atof(strtok(NULL, delimitador));
        dados[i].Metacritic = atof(strtok(NULL, delimitador));
        strcpy(dados[i].ordered, strtok(NULL, delimitador));
        strcpy(dados[i].filmagem, strtok(NULL, delimitador));
        strcpy(dados[i].livro, strtok(NULL, delimitador));
        strcpy(dados[i].sinopse, strtok(NULL, delimitador));
        i++;
    }
    fclose(arquivo);
    return i-1;
}

int menu_principal(struct_do_csv dados[], int ultima_linha){
  int opcao;
  printf("===========================================================");
  printf("\n1-Selecionar Temporada\n2-Visao Geral\n3-Fechar Programa\n");
  printf("\nSelecione uma opcao: ");
  scanf("%i", &opcao);
  switch (opcao)
  {
  case 1:
    /*Chamar a função que vai printar as temporadas, a função deve retornar o numero da temporada
    selecionda, a partir daí chama a função menu temporada*/
    opcao = selecionar_temporada(dados, ultima_linha);
    menu_temporada(opcao, dados, ultima_linha);
    break;
  case 2:
    /*Chamar a função que vai printar o resumo geral*/
    resumo_geral(dados, ultima_linha);
    menu_principal(dados, ultima_linha);
    break;
  case 3:
    /*Fecha o programa*/
    break;
  default:
    printf("\nOpcao Invalida, tente novamente!");
    menu_principal(dados, ultima_linha);
    break;
  }
  return opcao;
}

int menu_temporada(int temporada_selecionda, struct_do_csv dados[], int ultima_linha){
  int opcao;
  printf("\n===========================================================");
  printf("\nTemporada %i Selecionada\n\n1-Selecionar Episodio\n2-Visao Geral\n3-Voltar ao Menu Principal\n4-Fechar Programa\n", temporada_selecionda);
  printf("\nSelecione uma opcao: ");
  scanf("%i", &opcao);
  switch (opcao)
  {
  case 1:
    /*Chamar a função que vai printar os episodios, a função deve retornar o numero do episodio
    seleciondo, a partir daí chama a função resumo_episodio*/
    selecionar_episodio(temporada_selecionda, dados, ultima_linha);
    menu_temporada(temporada_selecionda, dados, ultima_linha);
    break;
  case 2:
    /*Chamar a função que vai printar o resumo geral da temporada selecionada*/
    resumo_temporada(temporada_selecionda,dados,ultima_linha);
    menu_temporada(temporada_selecionda, dados, ultima_linha);
    break;
  case 3:
    menu_principal(dados, ultima_linha);
    break;
  case 4:
    break;
  default:
    printf("\nOpcao Invalida, tente novamente!");
    menu_temporada(temporada_selecionda, dados, ultima_linha);
    break;
  }
}

int selecionar_temporada(struct_do_csv dados[], int ultima_linha){
    int contador, temp_selecionada, temp_anterior;
    temp_anterior = 0;
    printf("\n===========================================================");
    printf("\nTemporadas disponiveis\n");
    for (contador = 0; contador< ultima_linha; contador ++){
      if (dados[contador].temp != temp_anterior){
        printf("\n%i - Temporada", dados[contador].temp);
        temp_anterior = dados[contador].temp;
      }
    }
    printf("\nEscolha uma temporada atraves do numero: ");
    scanf("%i", &temp_selecionada);
    if (temp_selecionada > temp_anterior || temp_selecionada <= 0){
      printf("\nOpcao invalida, tente novamente!\n");
      selecionar_temporada(dados, ultima_linha);
    }
    else{
      return temp_selecionada;
    }
}

int selecionar_episodio(int temp_selecionada, struct_do_csv dados[], int ultima_linha){
  int linha,ep_selecionado, qtd_ep;
  qtd_ep = 0;
  printf("\n===========================================================");
  printf("\nEpisodios da temporada %i\n", temp_selecionada);
  for (linha=0; linha<=ultima_linha; linha++){
    if (dados[linha].temp == temp_selecionada){
      printf("\n%i - %s", dados[linha].ep_temp, dados[linha].nome_ep);
      qtd_ep += 1;
    }
  }
  printf("\nSelecione o episodio atraves do numero: ");
  scanf("%i", &ep_selecionado);
  if (ep_selecionado>qtd_ep || ep_selecionado <= 0){
    printf("\nOpcao invalida, tente novamente!\n");
    selecionar_episodio(temp_selecionada, dados, ultima_linha);
  }
  else{
    resumo_episodio(ep_selecionado, temp_selecionada, dados, ultima_linha);
  }
}

void resumo_episodio(int ep_selecionado, int temp_selecionada, struct_do_csv dados[], int ultima_linha){
  int linha;
  printf("\n===========================================================================================================================================");
  printf("\nResumo do episodio\n");
  for (linha=0; linha<=ultima_linha; linha++){
    if (dados[linha].temp == temp_selecionada && dados[linha].ep_temp == ep_selecionado){
      printf("\nEpisodio %d\n"
        "Titulo do episodio: %s\n"
        "Duracao do episodio: %d minutos\n"
        "Data de estreia: %s\n"
        "Numero de visualizacoes: %.2f milhoes\n"
        "Avaliacao do IMDB: %.2f\n"
        "Avaliacao do Rotten Tomatoes: %.2f\n"
        "Avaliacao do Metacritic: %.2f\n"
        "Sinopse do episodio: %s\n"
        "===========================================================================================================================================\n",
        dados[linha].ep_temp,
        dados[linha].nome_ep,
        dados[linha].duracao_ep,
        dados[linha].data_estreia,
        dados[linha].visualizacoes,
        dados[linha].IMDB,
        dados[linha].RotTomat,
        dados[linha].Metacritic,
        dados[linha].sinopse);
    }
  }
  menu_temporada(temp_selecionada, dados, ultima_linha);
}

void resumo_temporada(int temp_selecionada, struct_do_csv dados[], int ultima_linha){
  int linha, qtd_ep = 0;
  float soma_visu_temp = 0, media_imdb = 0, media_meta = 0, media_rotten = 0, visu = 0;
  char nome[100];
  char diretor[100];
  for (linha=0; linha<=ultima_linha; linha++){
    if (dados[linha].temp == temp_selecionada){
      soma_visu_temp = soma_visu_temp + dados[linha].visualizacoes;
      media_meta = media_meta + dados[linha].Metacritic;
      media_imdb = media_imdb + dados[linha].IMDB;
      media_rotten = media_rotten + dados[linha].RotTomat;
      qtd_ep = qtd_ep +1;
       if(visu< dados[linha].visualizacoes){
        visu = dados[linha].visualizacoes;

    }
    } 
  }
  media_imdb = media_imdb/qtd_ep;
  media_meta = media_meta/qtd_ep;
  media_rotten = media_rotten/qtd_ep;
  printf("\n===========================================================");
  printf("\nResumo de temporada\n");
  printf("\nVisualicoes Totais: %.2f Milhoes\nMedia do Metacritic: %.2f\nMedia do IMDB: %.2f\nMedia do Rotten Tomatoes: %.2f\n",
  soma_visu_temp,media_meta,media_imdb,media_rotten);
  for (linha=0; linha<=ultima_linha; linha++){
    if(visu == dados[linha].visualizacoes && dados[linha].temp == temp_selecionada){
      printf("\nEpisodio com mais visualizacoes da Serie\n");
      printf("\nNome do Episodio: %s\nNome do Diretor: %s\nNumero de Views: %.2f Milhoes\n",
      dados[linha].nome_ep,dados[linha].diretor,dados[linha].visualizacoes);
    }
  }
}

void resumo_geral(struct_do_csv dados[], int ultima_linha){
  char nome[100];
  char diretor[100];
  float visu;
  int linha,temp_selecionado, qtd_ep;
  float soma_visu, media_imdb, media_meta, media_rotten;
  soma_visu = 0;
  media_imdb = 0;
  media_meta = 0;
  media_rotten = 0;
  qtd_ep = 0;
  visu = 0;
  for (linha=0; linha<=ultima_linha; linha++){
    if(visu< dados[linha].visualizacoes){
      visu = dados[linha].visualizacoes;
    }
    soma_visu = soma_visu + dados[linha].visualizacoes;
    media_meta = media_meta + dados[linha].Metacritic;
    media_imdb = media_imdb + dados[linha].IMDB;
    media_rotten = media_rotten + dados[linha].RotTomat;
    qtd_ep = qtd_ep +1;
  }
  media_imdb = media_imdb/qtd_ep;
  media_meta = media_meta/qtd_ep;
  media_rotten = media_rotten/qtd_ep;
  printf("\n===========================================================");
  printf("\nResumo da Serie\n");
  printf("\nVisualicoes Totais: %.2f Milhoes\nMedia do Metacritic: %.2f\nMedia do IMDB: %.2f\nMedia do Rotten Tomatoes: %.2f\n",
  soma_visu,media_meta,media_imdb,media_rotten);
  for (linha=0; linha<=ultima_linha; linha++){
    if(visu == dados[linha].visualizacoes){
      printf("\nEpisodio com mais visualizacoes da Serie\n");
      printf("\nNome do Episodio: %s\nNome do Diretor: %s\nNumero de Views: %.2f Milhoes\n",
      dados[linha].nome_ep,dados[linha].diretor,dados[linha].visualizacoes);
    }
  }
}

int main(){
    struct_do_csv dados[73];
    int ultima_linha;
    ultima_linha = ler_csv(dados);
    printf("===========================================================");
    printf("\nBem vindo ao sistema de consulta de Game_of_Thrones\n");
    menu_principal(dados,ultima_linha);
}
