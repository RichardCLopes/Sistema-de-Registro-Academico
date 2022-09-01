#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cadastro No;

struct cadastro{
	float nota;
	char nome[50], ra[6];
	struct cadastro *prox;
};

void recebeDados(No **dados)
{
	struct cadastro *temp;
	temp=(No *)malloc(sizeof(No));
	printf("\nNome: ");
	fflush(stdin);
	scanf("%s", temp->nome);
	printf("RA: ");
	scanf("%s", temp->ra);
	printf("Nota: ");
	scanf("%f", &temp->nota);
	*dados=temp;
}

void cadastrAluno(No **pLista, No *temp)
{
	No *aux=*pLista;

	if(aux==NULL)
	{
		*pLista=temp;
	}
	else if(strcmp(aux->ra, temp->ra)>0)
	{
		temp->prox=aux;
		*pLista=temp;
	}
	else
	{
		cadastrAluno(&(aux->prox), temp);
	}
}

void buscaRa(No *Lista, char* ra)
{
	if(Lista==NULL)
	{
		printf("Lista vazia");
	}
	else{
		if(strcmp(ra, Lista->ra)==0)
		{
			printf("\nAluno: %s", (Lista->nome));
			printf("\nRA: %s", (Lista->ra));
			printf("\nNota: %.2f\n", (Lista->nota));
		}
		else{
			buscaRa(Lista->prox, ra);
		}
	}
}

void buscaNome(No *Lista, char* name)
{
	if(Lista==NULL)
	{
		printf("Lista vazia");
	}
	else{
		if(strcmp(name, Lista->nome)==0)
		{
			printf("\nAluno: %s\n", (Lista->nome));
			printf("RA: %s\n", (Lista->ra));
			printf("Nota: %.2f\n", (Lista->nota));
		}
		else{
			buscaNome(Lista->prox, name);
		}
	}
}

void exibeAluno(No *Lista)
{
	while(Lista!=NULL)
	{
		printf("%s\t\t%s\t\t%.2f\n", (Lista->nome), (Lista->ra), (Lista->nota));
		Lista=Lista->prox;
	}
}

void exibeNomera(No *Lista)
{
	int i=1;
	
	while(Lista!=NULL)
	{
		printf("%s\t\t%s\n", (Lista->nome), (Lista->ra));
		Lista=Lista->prox;
		i++;
	}
}

void removeAluno(No *Lista, char* ra)
{
	if((Lista)==NULL)
	{
		printf("Lista vazia");
	}
	else{
		if(ra==(Lista)->ra)
		{
			No *aux = (Lista)->prox;
			(Lista) = aux;
		}
		else{
			removeAluno((Lista)->prox, ra);
		}
	}
}

int main()
{
	int opcao;
	char name[50], ra[6];
	No *Lista, *aux;
	aux=NULL;
	Lista=NULL;
	
	do{
		printf("\n1-Cadastrar aluno.\n2-Remover Aluno.\n3-Busca por RA.\n4-Busca por nome.\n5-Exibir dados.\n6-Sair.");
		printf("\nOpcao: ");
		scanf("%i", &opcao);
		
		switch(opcao)
		{
			case 1:
				recebeDados(&aux);
				cadastrAluno(&Lista, aux);
				break;
			case 2:
				printf("\nNome:\t\tRA:\n");
				exibeNomera(Lista);
				printf("\nRA do aluno que deseja remover o cadastro:\t");
				scanf("%s", ra);
				removeAluno(Lista, ra);
				break;
			case 3:
				printf("\nRa: ");
				scanf("%s", ra);
				buscaRa(Lista, ra);
				break;
			case 4:
				printf("\nNome: ");
				fflush(stdin);
				scanf("%s", name);
				buscaNome(Lista, name);
				break;
			case 5:
				printf("\nNome:\t\tRA:\t\tNota:\t\t");
				exibeAluno(Lista);
				break;
			case 6:
				printf("\n...");
				break;
			default:
				printf("\nOpcao inexistente.\n");
				break;
		}
	}while(opcao!=6);
	
	printf("\n\n");
	
	return 0;
}