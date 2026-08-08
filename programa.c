#include <stdio.h>
#include <string.h>
#include <locale.h>  // acentos
#include <stdlib.h>
#include <windows.h> // acentos

///////////////////////////////////////
/*
coluna[1]=ano da emenda
coluna[4]=nome do parlamentar
coluna[10]=estado que recebeu a emenda
coluna[24]=valor pago
*/
///////////////////////////////////////

void rankingEstados(const char *estado, int *no, int *ne, int *co, int *se, int *su){
//STRCMP NAO TA DANDO 0; VOU TESTAR DEPOIS
    if (strcmp("Norte", estado)== 0){
            printf("a");
        no++;
    }
    else if (strcmp("Nordeste", estado)== 0){
        printf("av");
        ne++;
    }
    else if (strcmp("Centro-Oeste", estado)== 0){
        printf("ac");
        co++;
    }
    else if (strcmp("Sudeste", estado)== 0){
        printf("ad");
        se++;
    }
    else if (strcmp("Sul", estado)== 0){
        printf("ae");
        su++;
    }


}





void maiorValor(const char *strValor, double *maior, int *lugarmaioreemenda, int linhaAtual) {
    if (strValor == NULL || strValor[0] == '\0') return;

    char aux[128];
    int i = 0;


    for (int k = 0; strValor[k] != '\0'; k++) {
        if (strValor[k] == '"' || strValor[k] == ' ' || strValor[k] == '\r' || strValor[k] == '\n') {
            continue;
        }
        if (strValor[k] == ',') {
            aux[i] = '.';
            i++;
        } else {
            aux[i] = strValor[k];
            i++;
        }
    }
    aux[i] = '\0';

    if (aux[0] == '\0') return;

    double valorAtual = atof(aux);

    if (valorAtual > *maior) {
        *maior = valorAtual;
        *lugarmaioreemenda = linhaAtual;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    FILE *arquivo = fopen("dados\\EmendasParlamentares.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    char linha[2048];
    char *coluna[35];

    double maioremenda = 0.0;
    double emendaestado = 0.0;
    int contemendaestado = 0;
    int contparlemenda = 0;
    int lugarmaioreemenda = 0;
    int numeroLinha = 1;

    int nordeste=0,norte=0,centroOeste=0,sudeste=0,sul=0;




    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numeroLinha++;
        int i = 0;

        char *token = strtok(linha, ";\r\n");
        while (token != NULL && i < 35) {
            coluna[i] = token;
            i++;
            token = strtok(NULL, ";\r\n");
        }

      if (i>10 && i<12){
            rankingEstados(coluna[11], &norte, &nordeste, &centroOeste, &sudeste, &sul);
      }

        // verifica se eh o maior valor
        if (i > 24) {
            maiorValor(coluna[24], &maioremenda, &lugarmaioreemenda, numeroLinha);
        }
    }

    fclose(arquivo);

    printf("Maior valor pago em emenda: R$ %.2f\n", maioremenda);
    printf("Linha no arquivo: %d\n", lugarmaioreemenda);
    printf("Norte: %d, Nordeste: %d, Centro-Oeste: %d, Sudeste: %d, Sul: %d", norte, nordeste, centroOeste, sudeste, sul);

    return 0;
}
