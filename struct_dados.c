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


int main(){
    FILE *arquivo;
    char linha_arquivo[1700];
    int i = 0;
    char *delimitador = ";";
    char c;
    struct_do_csv GOT_dados[73];

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



    for(i=0; i<73; i++){
         printf("%d - %d - %d - %s - %d - %s - %s - %s - %.2f - %s - %s - %s - %.2f - %.2f - %.2f - %s - %s - %s - %s\n",
                GOT_dados[i].temp,
                GOT_dados[i].ep_temp,
                GOT_dados[i].ep_total,
                GOT_dados[i].nome_ep,
                GOT_dados[i].duracao_ep,
                GOT_dados[i].diretor,
                GOT_dados[i].escritor,
                GOT_dados[i].data_estreia,
                GOT_dados[i].visualizacoes,
                GOT_dados[i].musico,
                GOT_dados[i].cinematografista,
                GOT_dados[i].editor,
                GOT_dados[i].IMDB,
                GOT_dados[i].RotTomat,
                GOT_dados[i].Metacritic,
                GOT_dados[i].ordered,
                GOT_dados[i].filmagem,
                GOT_dados[i].livro,
                GOT_dados[i].sinopse);

        printf("\n\n\n");


    }

}


