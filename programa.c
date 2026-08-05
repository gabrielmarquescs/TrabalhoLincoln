#include <stdio.h>
#include <string.h>


int main(){
    FILE *arquivo = fopen ("dados\2025_OrcamentoDespesa.csv", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o programa");
    }

    char linha[27000];
    char *coluna[26];



    fclose(arquivo);
return 0;
}
