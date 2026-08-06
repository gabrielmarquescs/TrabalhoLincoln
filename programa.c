#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL,"Portuguese");
    FILE *arquivo = fopen ("dados\\2025_OrcamentoDespesa.csv", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o programa");
        return 1;
    }

    char linha[2048];
    char *coluna[26];

   while (fgets(linha, sizeof(linha), arquivo)!= NULL){

    int i=0;

    char *token = strtok(linha, ";\n");

    while (token != NULL){
        coluna[i]=token;
        i++;
        token=strtok(NULL,";\n");
    }


    for (int j=0;j<i;j++){
        if ((j==2) || (j==23)){
        printf("[Indice %d]: %s\n",j,coluna[j]);
    }
    }
   }



    fclose(arquivo);
return 0;
}
