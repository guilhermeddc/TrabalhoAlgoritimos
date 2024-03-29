#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct DadosAluno
{
   
    int nota01;
    int nota02;
    char nome[50];
    
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
void finalizaAlunos(aluno *al, char *arq, int num)
{
   
	int i;
	
    FILE *f = fopen(arq, "a");
    
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
	
	char buffer[57];
	int i;
	
	f = fopen(arq, "r"); 
	
    printf("\nConteudo do arquivo %s:\n\n", arq);
    
    for(i = 0; (! feof(f)); i++)
    {
    	
    	fgets(buffer, 57, f);
		
		printf("%s", buffer);
    	
	}
	
	fclose(f);
	
}

//função para calcular media e ja printar lista de aprovados
void calculaMedia(char *copiaArq)
{
	
    char listaAprov[300] = {" "};
    int j;
    float media;

    aluno Aux;

    char n1[2];
    char n2[2];

        for(j = 0; j < 56; j++)
        {
			
            if(j < 50)
            {

                Aux.nome[j] = copiaArq[j];
                					
            }
			
            if(j == 51 || j == 52)
            {

                n1[0] = copiaArq[51];
                n1[1] = copiaArq[52];
                
                Aux.nota01 = atoi(n1);
				
            }         

            if(j == 54 || j == 55)
            {

                n2[0] = copiaArq[54];
                n2[1] = copiaArq[55];
                
                Aux.nota02 = atoi(n2);
				
            }
            
    	}
    	
        media = ((Aux.nota01 + Aux.nota02)/2);
        if( media > 6)
        {
					
          	strcpy(listaAprov, Aux.nome);

        }
            
       	printf("%s\n", listaAprov);

}

//função para armazenar o arquivo numa string
aluno armazenaArq(char *arq)
{
    
   	char c[200];
   	int n1;
   	int n2;
   	int i;
   	
    FILE *f;
    
    if ((f = fopen(arq, "r")) == NULL)
    {
    	
        printf("Ocorreu um erro ao abrir o arquivo.");
    
        exit(1); 
		        
    }
    
    int tamanho;
    int qtdL = 0;
    
    while(fgets(c, 200, f)){
    	
    	qtdL++;
	}
    
    fclose(f);
    
    tamanho = strlen(c);
	
	f = fopen(arq, "r");
	
	for(i = 0; i < qtdL; i++)
    {
    	
    	fgets(c, 100, f);
    	calculaMedia(c);
		
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
        printf("Digite 3 para ver os alunos aprovados de uma turma.\n\n");
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
                printf("\nQuantos alunos tem nesta turma?\n");
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
				
				system("pause");
				
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
				
				system("pause");
				
				break;
				
			}
			
			case 3:
			{
				
				system("cls");
				
				char nomeArquivo[50];
				
                printf("\nInforme o nome da turma visualizar os aprovados: ");
                scanf("%s", &nomeArquivo);
                
                strcat(nomeArquivo, ".txt");
                               
                armazenaArq(nomeArquivo);
				
				system("pause");
				
				break;
				
			}
			
			default:
			{
				
				printf("Digito invalido!");
					
			}
			
		}
		
	system("cls");
		
	}
	while(exercicio);
    
}
