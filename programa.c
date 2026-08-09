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

/*

*/


///////////////////////////////////////
void emendaestados(const char *estado, double valor, double *ac, double *al, double *am, double *ap, double *ba, double *ce, double *df, double *es, double *go, double *ma,
double *mg, double *ms, double *mt, double *pa, double *pb, double *pe, double *pi, double *pr, double *rj, double *rn, double *ro, double *rr, double *rs,
double *sc, double *se, double *sp, double *to) {

    if (estado == NULL) return;

    if (strcmp("ACRE", estado) == 0) {
        *ac += valor;
    }
    else if (strcmp("ALAGOAS", estado) == 0) {
        *al += valor;
    }
    else if (strcmp("AMAPÁ", estado) == 0) {
        *ap += valor;
    }
    else if (strcmp("AMAZONAS", estado) == 0) {
        *am += valor;
    }
    else if (strcmp("BAHIA", estado) == 0) {
        *ba += valor;
    }
    else if (strcmp("CEARÁ", estado) == 0) {
        *ce += valor;
    }
    else if (strcmp("DISTRITO FEDERAL", estado) == 0) {
        *df += valor;
    }
    else if (strcmp("ESPÍRITO SANTO", estado) == 0) {
        *es += valor;
    }
    else if (strcmp("GOIÁS", estado) == 0) {
        *go += valor;
    }
    else if (strcmp("MARANHÃO", estado) == 0) {
        *ma += valor;
    }
    else if (strcmp("MATO GROSSO", estado) == 0) {
        *mt += valor;
    }
    else if (strcmp("MATO GROSSO DO SUL", estado) == 0) {
        *ms += valor;
    }
    else if (strcmp("MINAS GERAIS", estado) == 0) {
        *mg += valor;
    }
    else if (strcmp("PARÁ", estado) == 0) {
        *pa += valor;
    }
    else if (strcmp("PARAÍBA", estado) == 0) {
        *pb += valor;
    }
    else if (strcmp("PARANÁ", estado) == 0) {
        *pr += valor;
    }
    else if (strcmp("PERNAMBUCO", estado) == 0) {
        *pe += valor;
    }
    else if (strcmp("PIAUÍ", estado) == 0) {
        *pi += valor;
    }
    else if (strcmp("RIO DE JANEIRO", estado) == 0) {
        *rj += valor;
    }
    else if (strcmp("RIO GRANDE DO NORTE", estado) == 0) {
        *rn += valor;
    }
    else if (strcmp("RIO GRANDE DO SUL", estado) == 0) {
        *rs += valor;
    }
    else if (strcmp("RONDÔNIA", estado) == 0) {
        *ro += valor;
    }
    else if (strcmp("RORAIMA", estado) == 0) {
        *rr += valor;
    }
    else if (strcmp("SANTA CATARINA", estado) == 0) {
        *sc += valor;
    }
    else if (strcmp("SÃO PAULO", estado) == 0) {
        *sp += valor;
    }
    else if (strcmp("SERGIPE", estado) == 0) {
        *se += valor;
    }
    else if (strcmp("TOCANTINS", estado) == 0) {
        *to += valor;
    }
}
///////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////
void rankingEstados(const char *estado, int *no, int *ne, int *co, int *se, int *su){
    if (strcmp("Norte", estado)== 0){
        (*no)++;
    }
    else if (strcmp("Nordeste", estado)== 0){
        (*ne)++;
    }
    else if (strcmp("Centro-Oeste", estado)== 0){
        (*co)++;
    }
    else if (strcmp("Sudeste", estado)== 0){
        (*se)++;
    }
    else if (strcmp("Sul", estado)== 0){
        (*su)++;
    }
}
/////////////////
typedef struct {
    char nome[30];
    double valor;
} EstadoRank;

void imprimirTop5(double ac, double al, double am, double ap, double ba, double ce,
                  double df, double es, double go, double ma, double mg, double ms,
                  double mt, double pa, double pb, double pe, double pi, double pr,
                  double rj, double rn, double ro, double rr, double rs, double sc,
                  double se, double sp, double to) {


    EstadoRank ranking[27] = {
        {"ACRE", ac}, {"ALAGOAS", al}, {"AMAZONAS", am}, {"AMAPÁ", ap},
        {"BAHIA", ba}, {"CEARÁ", ce}, {"DISTRITO FEDERAL", df}, {"ESPÍRITO SANTO", es},
        {"GOIÁS", go}, {"MARANHÃO", ma}, {"MINAS GERAIS", mg}, {"MATO GROSSO DO SUL", ms},
        {"MATO GROSSO", mt}, {"PARÁ", pa}, {"PARAÍBA", pb}, {"PERNAMBUCO", pe},
        {"PIAUÍ", pi}, {"PARANÁ", pr}, {"RIO DE JANEIRO", rj}, {"RIO GRANDE DO NORTE", rn},
        {"RONDÔNIA", ro}, {"RORAIMA", rr}, {"RIO GRANDE DO SUL", rs}, {"SANTA CATARINA", sc},
        {"SERGIPE", se}, {"SÃO PAULO", sp}, {"TOCANTINS", to}
    };

    for (int i = 0; i < 27 - 1; i++) {
        for (int j = i + 1; j < 27; j++) {
            if (ranking[j].valor > ranking[i].valor) {
                EstadoRank aux = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = aux;
            }
        }
    }
    printf("\n================ TOP 5 ESTADOS =====================\n");
    for (int i = 0; i < 5; i++) {
        printf("%dº Lugar: %-20s -> R$ %.2f\n", i + 1, ranking[i].nome, ranking[i].valor);
    }
    printf("====================================================\n");
}

////////////////////////////////////////////////////
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
    int lugarmaioreemenda = 0;
    int numeroLinha = 1;
    double ac = 0, al = 0, am = 0, ap = 0, ba = 0, ce = 0, df = 0, es = 0, go = 0, ma = 0, mg = 0, ms = 0, mt = 0, pa = 0, pb = 0, pe = 0,
    pi = 0, pr = 0, rj = 0, rn = 0, ro = 0, rr = 0, rs = 0, sc = 0, se = 0, sp = 0, to = 0;
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

        if (i > 24) {
            double valorLinha = atof(coluna[24]);

            emendaestados(coluna[10], valorLinha, &ac, &al, &am, &ap, &ba, &ce, &df, &es, &go, &ma, &mg, &ms, &mt, &pa, &pb, &pe, &pi, &pr, &rj, &rn, &ro, &rr, &rs, &sc, &se, &sp, &to);
            rankingEstados(coluna[11], &norte, &nordeste, &centroOeste, &sudeste, &sul);
            maiorValor(coluna[24], &maioremenda, &lugarmaioreemenda, numeroLinha);
        }
    }

    fclose(arquivo);
    int escolha=0;int contescolha=0;


    printf("Bem vindo! Digite o numero correspondente a funcao desejada:\n1. Emenda mais cara\n2. Quantas emendas cada regiao recebeu\n3. Estados que mais receberam\n");
    while (1){
    if (contescolha>=3){
        printf("\n\n\n\n================ INFORMACOES GERAIS ================\n");
        printf("Alunos: Gabriel Marques Rodrigues da Silva; Joao Gabriel Almeida Barbosa; Joao Paulo de Oliveira Xavier\n");
        printf("Dados: Legislatura atual (2023-2026)\n");
        printf("====================================================\n");
        return 2;
    }
    scanf("%d", &escolha);
    if (escolha==1){
        printf("\n================ MAIOR VALOR PAGO ==================\n");
        printf("R$ %.2f\n", maioremenda);//printf("Linha no arquivo: %d\n", lugarmaioreemenda);
        printf("====================================================\n");
        contescolha++;
    }
    else if (escolha == 2) {
        printf("\n================ EMENDAS POR REGIAO ================\n");
        printf("%-20s -> %d emendas\n", "Norte", norte);
        printf("%-20s -> %d emendas\n", "Nordeste", nordeste);
        printf("%-20s -> %d emendas\n", "Centro-Oeste", centroOeste);
        printf("%-20s -> %d emendas\n", "Sudeste", sudeste);
        printf("%-20s -> %d emendas\n", "Sul", sul);
        printf("====================================================\n");
        contescolha++;
    }
    else if (escolha == 3){
        imprimirTop5(ac, al, am, ap, ba, ce, df, es, go, ma, mg, ms, mt, pa, pb, pe, pi, pr, rj, rn, ro, rr, rs, sc, se, sp, to);
        contescolha++;
    }
    else return 2;

    }
    return 0;
}
