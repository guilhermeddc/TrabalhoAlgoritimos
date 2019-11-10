#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct DadosAluno {
    char nome[50];
    int nota01;
    int nota02;
} aluno;


aluno *a;

void iniciaAlunos(char *n) {
    a=(aluno*) malloc(sizeof(aluno));
    if(access(n, F_OK)!=-1) {
        // existe
        FILE *f = fopen(n, "r");
        int cod = fread(a, sizeof(aluno), 1, f);
        fclose(f);
    } else {
        // nao existe
        printf("Arquivo nao existe!\n\n");
    }
}

void finalizaAlunos(aluno *al, char *n, int num) {
    FILE *f = fopen(n, "w");
    for (int i = 0; i  < num; ++i) {
        fprintf(f,"%s|%2.d|%2.d\n", al[i].nome, al[i].nota01, al[i].nota02);
    }
    fclose(f);
}

aluno lerAlunos(aluno *al, char *n){
    FILE *f = fopen(n,"r");
    for (int i = 0; fgets(); ++i) {
        fflush(stdin);
        fscanf(f, "%s|%2.d|%2.d", &al[i].nome, &al[i].nota01, &al[i].nota02);
    }
    fclose(f);
    return *al;
}

void ContaString(char *n) {
    for (int i = strlen(n); i < 50; ++i) {
        strcat(n, " ");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int op = 100;
    while (op != 0) {
        printf("\n\nLoja da Maria\n\n");
        printf("Digite 1 para cadastrar nova turma.\n");
        printf("Digite 2 para exibir dados da turma.\n");
        printf("Digite 3 para cadastrar vendas.\n");
        printf("Digite 4 para listar vendedores.\n");
        printf("Digite 5 para listar produtos.\n");
        printf("Digite 6 para listar vendas.\n");
        printf("Digite 0 para sair.\n");
        scanf("%d", &op);
        switch (op) {
            case 1: {
                int numeroDeAlunos;
                char nomeArquivo[50];
                printf("\nInforme o nome da turma: ");
                gets(nomeArquivo);
                strcat(nomeArquivo, ".txt");
                printf("Quantos alunos tem nesta turma?\n");
                scanf("%d", &numeroDeAlunos);
                aluno *p;
                p=(aluno*)malloc(sizeof(aluno));
                aluno novo[numeroDeAlunos];
                for (int i = 0; i < numeroDeAlunos; ++i) {
                    fflush(stdin);
                    printf("Nome do aluno 0%d: ", i + 1);
                    gets(novo[i].nome);
                    fflush(stdin);
                    ContaString(novo[i].nome);
                    printf("Nota 01: ");
                    scanf("%d", &novo[i].nota01);
                    printf("Nota 02: ");
                    scanf("%d", &novo[i].nota02);
                }
                fflush(stdin);
                iniciaAlunos(nomeArquivo);
                finalizaAlunos(novo, nomeArquivo, numeroDeAlunos);
                system("pause");
                for (int j = 0; j < numeroDeAlunos; ++j) {
                    printf("%s|%2.d|%2.d\n", novo[j].nome, novo[j].nota01, novo[j].nota02);
                }
                break;
            }
            case 2: {
                char nomeArquivo[50];
                printf("\nInforme o nome do arquivo desejado: ");
                gets(nomeArquivo);
                iniciaAlunos(nomeArquivo);
                aluno novo[5];
                lerAlunos(novo, nomeArquivo);

                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 0: {
                break;
            }
            default: {
                printf("Digito invalido!");
            }
        }
    }
    return 0;
}