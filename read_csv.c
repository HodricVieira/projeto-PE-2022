# include <stdio.h>


int main(){
    FILE *arquivo;

    char linha_arquivo[1000];

    arquivo = fopen("Game_of_Thrones.csv", "r");

    struct episodio
    {
        int temporada;
        int episodio;
    };
    

    while (fgets(linha_arquivo, 1000, arquivo) != NULL)
    {
        char *dados;
        char valor[100];
        dados = strtok(linha_arquivo, ";");
        while (dados !=NULL)
        {   
            strcpy(valor, dados);
            printf("%s -  ", valor);
            dados = strtok(NULL, ";");
        }
        printf("\n\n\n");
    }
    fclose(arquivo);
    

}