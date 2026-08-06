#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void AparaString(char *str){
    int tam = strlen(str);

    if (tam > 0 && str[tam-1] == '"'){
        str[tam-1] = '\0';
        tam--;
    }

    if (tam > 0 && str[0] == '"'){
        int i;
        for (i = 0; i < tam; i++){
            str[i] = str[i+1];
        }
    }
}

double TrocarVirgula(char *str){
    char copia[64];
    strcpy(copia,str);

    for (int i=0;copia[i]!= '\0';i++){
        if (copia[i]==','){
            copia[i]='.';
        }
    }
    return atof(copia);
}




int main(){
    setlocale(LC_ALL,"Portuguese");
    FILE *arquivo = fopen ("dados\\2025_OrcamentoDespesa.csv", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o programa");
        return 1;
    }

    char linha[2048];
    char *coluna[26];
    char ministerio[128]="";
    double somaMinisterio=0;
    int primeiraLinha=1;



    fgets(linha, sizeof(linha), arquivo);  //pula o cabeçalho tentar entender dps


   while (fgets(linha, sizeof(linha), arquivo)!= NULL){
    int i=0;
    char *token = strtok(linha, ";\n");
    while (token != NULL){
        AparaString(token);
        coluna[i]=token;
        i++;
        token=strtok(NULL,";\n");
    }

    char *orgao = coluna[2];//aponta pra o nome do orgao
    double valor = TrocarVirgula(coluna[23]);

    if (primeiraLinha){
        strcpy(ministerio,orgao);
        somaMinisterio=valor;
        primeiraLinha=0;
    }
    else if(strcmp(orgao,ministerio)==0){
        somaMinisterio=somaMinisterio+valor;
    }
    else{
        printf("ORGAO: %s; ORCAMENTO: %.2f\n", ministerio, somaMinisterio);
        strcpy(ministerio,orgao);
        somaMinisterio=valor;
    }

            if (strcpy)
        if (!primeiraLinha){
        printf("ORGAO: %s; ORCAMENTO: %.2f\n", ministerio, somaMinisterio);
    }








    //int strcmp(str1,str2); compara as strings; 0 se igual
   /* for (int j=0;j<i;j++){
        if (j==2){
        printf("ORGÃO: %s; ORÇAMENTO: %.2f\n",coluna[j],atof(coluna[23]));
    }
    }*/
   }



    fclose(arquivo);
return 0;
}
