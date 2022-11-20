# include <stdio.h>

typedef struct{
int temp[4];
int ep_temp[4];
int ep_total[4];
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
    int numEp = 0;
    int read = 0;
    int i;

    arquivo = fopen("Game_of_Thrones.csv", "r");

    while (fgets(linha_arquivo, 1700, arquivo) != NULL)
    {
        char *dados;
        char valor[100];
        dados = strtok(linha_arquivo, ";");
        while (dados !=NULL)
        {
            strcpy(valor, dados);
            printf("%s =  ", valor);
            dados = strtok(NULL, ";");
        }
        printf("\n\n\n");
    }


    struct_do_csv leitura_arq[80];

    do{
        read = fscanf(arquivo,
                      "%d,%d,%d,%39[^,],%d,%49[^,],%69[^,],%19[^,],%f,%19[^,],%49[^,],%49[^,],%f,%f,%f,%19[^,],%24[^,],%69[^,], %1699[^*]\n",
                      &leitura_arq[numEp].temp,
                      &leitura_arq[numEp].ep_temp,
                      &leitura_arq[numEp].ep_total,
                      leitura_arq[numEp].nome_ep,
                      &leitura_arq[numEp].duracao_ep,
                      leitura_arq[numEp].diretor,
                      leitura_arq[numEp].escritor,
                      leitura_arq[numEp].data_estreia,
                      &leitura_arq[numEp].visualizacoes,
                      leitura_arq[numEp].musico,
                      leitura_arq[numEp].cinematografista,
                      leitura_arq[numEp].editor,
                      &leitura_arq[numEp].IMDB,
                      &leitura_arq[numEp].RotTomat,
                      &leitura_arq[numEp].Metacritic,
                      leitura_arq[numEp].ordered,
                      leitura_arq[numEp].filmagem,
                      leitura_arq[numEp].livro,
                      leitura_arq[numEp].sinopse);

        numEp++;
        printf("passando %d vezes.\n", numEp);

        if(read != 4 && !feof(arquivo)){
            printf("Erro no formato do arquivo.\n");
            return 1;
        }

        if(ferror(arquivo)){
            printf("Erro na leitura do arquivo.\n");
            return 1;
        }


    } while(!feof(arquivo));



    fclose(arquivo);

    printf("\n%d episodios catalogados.\n\n", numEp);

    for(i=0; i<3; i++){
         printf("%d - %d - %d - %s - %d - %s - %s - %s - %f - %s - %s - %s - %f - %f - %f - %s - %s - %s - %s\n",
                leitura_arq[i].temp,
                leitura_arq[i].ep_temp,
                leitura_arq[i].ep_total,
                leitura_arq[i].nome_ep,
                leitura_arq[i].duracao_ep,
                leitura_arq[i].diretor,
                leitura_arq[i].escritor,
                leitura_arq[i].data_estreia,
                leitura_arq[i].visualizacoes,
                leitura_arq[i].musico,
                leitura_arq[i].cinematografista,
                leitura_arq[i].editor,
                leitura_arq[i].IMDB,
                leitura_arq[i].RotTomat,
                leitura_arq[i].Metacritic,
                leitura_arq[i].ordered,
                leitura_arq[i].filmagem,
                leitura_arq[i].livro,
                leitura_arq[i].sinopse);
        printf("\n\n\n");


    }

}



