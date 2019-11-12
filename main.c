#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct DadosAluno
{
   
    char nome[50];
    int nota01;
    int nota02;
    
} aluno;

aluno *a;

//função para criar os arquivos
void iniciaAlunos(char *n)
{
    	a=(aluno*) malloc(sizeof(aluno));
    	
    	if(access(n, F_OK)!=-1)
		{
        // existe
        	FILE *f = fopen(n, "r");
        	
        	int cod = fread(a, sizeof(aluno), 1, f);
        	
        	fclose(f);
    	}
		else
		{
        // nao existe
        	printf("Arquivo criado!\n\n");
   		
		}
		
}

//funçaõ para inserir dados no arquivo
void finalizaAlunos(aluno *al, char *n, int num)
{
   
	int i;
	
    FILE *f = fopen(n, "a");
    
	for ( i = 0; i < num; ++i)
	{
        
		fprintf(f,"%s|%2.d|%2.d\n", al[i].nome, al[i].nota01, al[i].nota02);
    
	}
    
	fclose(f);
	
}

//função para imprimir o arquivo em tela
aluno lerArquivo(char *arq)
{
	
	FILE *f;
	
	char buffer[56];
	int i;
	
	f = fopen(arq, "r"); 
	
    printf("\nConteudo do arquivo %s:\n\n", arq);
    
    for(i = 0; (! feof(f)); ++i)
    {
    	
    	fgets(buffer, 56, f);
		
		printf("%s", buffer);
    	
	}
	
	fclose(f);
	
}

//função para pegar os valores dos alunos e no final calcular a media deles e imprimir os aporvados
aluno lerAlunos(char *arq)
{
    
   	char c[50];
   	int n1;
   	int n2;
   	
    FILE *f;
    
    if ((f = fopen(arq, "r")) == NULL)
    {
    	
        printf("Ocorreu um erro ao abrir o arquivo.");
    
        exit(1); 
		        
    }
    
    while(!feof(arq))
    {
	
		fscanf(f, "%s", c);
		printf("%s\n", c);
    
	}
	
	fclose(f);
    
}

//função para deixar o nome com 50 caracteres
void ContaString(char *n)
{
	int i;
	
	for(i = strlen(n); i < 50; ++i)
	{
        
		strcat(n, " ");
		
    }
    
}

int main()
{
    
	setlocale(LC_ALL, "Portuguese");
    
	int exercicio;
	
	do	
	{
        
		printf("\n\nEscolha uma opção:\n\n");
        printf("Digite 1 para cadastrar nova turma.\n");
        printf("Digite 2 para exibir dados da turma.\n");
        printf("Digite 3 para ver os alunos aprovados de uma turma.\n");
        scanf("%d", &exercicio);
        
		switch(exercicio)
		{
			
			case 1:
			{
				
				system("cls");
				
				char nomeArquivo[50];
				int numeroDeAlunos;
                
				printf("\nInforme o nome da turma: ");
                scanf("%s", &nomeArquivo);
                strcat(nomeArquivo, ".txt");
                printf("Quantos alunos tem nesta turma?\n");
                scanf("%d", &numeroDeAlunos);
                
				aluno *p;
                p=(aluno*)malloc(sizeof(aluno));
                aluno novo[numeroDeAlunos];
                
                int i;
                
				for (i = 0; i < numeroDeAlunos; ++i)
				{
                    fflush(stdin);
                    printf("\nNome do aluno 0%d: ", i + 1);
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
				
				getch();
				
				break;
				
			}
			
			case 2:
			{
				
				system("cls");
				
				char nomeArquivo[50];
				
                printf("\nInforme o nome do arquivo que deseja visualizar: ");
                scanf("%s", &nomeArquivo);
                
                strcat(nomeArquivo, ".txt");
                               
                lerArquivo(nomeArquivo);
				
				getch();
				
				break;
				
			}
			
			case 3:
			{
				
				system("cls");
				
				char nomeArquivo[50];
				
                printf("\nInforme o nome da turma visualizar os aprovados: ");
                scanf("%s", &nomeArquivo);
                
                strcat(nomeArquivo, ".txt");
                               
                lerAlunos(nomeArquivo);
				
				getch();
				
				break;
				
			}
			
			default:
			{
				
				printf("Digito invalido!");
					
			}
			
		}
		
	system("cls");
		
	}while(exercicio);
    
}
