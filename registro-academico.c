#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dadosAluno {
char nome[50], ra[6];
float nota;
};

struct dadosAluno recebedados();
int buscara(struct dadosAluno lista[], int max);
int buscanome(struct dadosAluno lista[], int max);
int removeraluno(struct dadosAluno lista[], int max);
int mostrardados(struct dadosAluno lista[], int max);

int main()
{
    struct dadosAluno listAlunos[100], aux;
    int opcao, i = 0, j, k, confirmacao, numbusca;
    do
    {
        printf("1-Cadastrar aluno.\n2-Remover cadastro de aluno.\n");
        printf("3-Buscar aluno por RA.\n4-Buscar aluno por nome.\n");
        printf("5-Exibir dados.\n6-Sair.\n");
        printf("Opcao: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            listAlunos[i] = recebedados();
            i++;
            break;
        case 2:
            i = removeraluno(listAlunos, i);
            break;
        case 3:
            numbusca = buscara(listAlunos, i);
            if (numbusca == -1)
            {
                printf("\nAluno inexistente (verifique se o RA esta certo).\n\n");
            }
            else
            {
                printf("\nAluno buscado ...");
                printf("\nNome:\t%s\n", listAlunos[numbusca].nome);
                printf("RA:\t");
                printf("%s\n", listAlunos[numbusca].ra); 
                printf("Nota:\t%.2f\n\n", listAlunos[numbusca].nota);
            }
            break;
        case 4:
            numbusca = buscanome(listAlunos, i);
            if (numbusca == -1)
            {
                printf("\nAluno inexistente (verifique se o nome esta certo).\n\n");
            }
            else
            {
                printf("\nAluno buscado ...");
                printf("\nNome:\t%s\n", listAlunos[numbusca].nome);
                printf("RA:\t");
                printf("%s\n", listAlunos[numbusca].ra); 
                printf("Nota:\t%.2f\n\n", listAlunos[numbusca].nota);
            }
            break;
        case 5:
            confirmacao = mostrardados(listAlunos, i);
            if (confirmacao == 1)
            {
                printf("\nFim da lista de dados.\n\n");
            }
            break;
        case 6:
            printf("\nFim do programa.\n");
            break;
        default:;
            printf("\nOpcao inexistente.\n\n");
            break;
        }

        //ORDEM ALFABETICA
        for (j = 0; j < i; j++)
        {
            for (k = 0; k < i; k++)
            {
                if (strcmp(listAlunos[j].nome, listAlunos[k].nome) < 0) {
                    aux = listAlunos[j];
                    listAlunos[j] = listAlunos[k];
                    listAlunos[k] = aux;
                }
            }
        }

        //FIM DA ORDEM
        } while (opcao != 6);

        return 0;
}

struct dadosAluno recebedados()
{
    struct dadosAluno aluno;
    printf("\nNome:\t");
    fflush(stdin);
    scanf("%s", aluno.nome);
    printf("RA:\t");
    fflush(stdin);
    scanf("%s", aluno.ra);
    printf("Nota:\t");
    scanf("%f", &aluno.nota);
    printf("\n");
    return aluno;
}

int removeraluno(struct dadosAluno lista[], int max)
{
    int i, num;

    printf("\nAlunos:\n");
    for (i = 0; i < max; i++)
    {
        printf("%i - %s\n", i + 1, lista[i].nome);
    }
    do{
        printf("\nNumero do aluno que deseja remover o cadastro:\t");
        scanf("%i", &num);
    }while(num<1 || num>max);
    
    printf("\n");
    lista[num - 1] = lista[max - 1];
    if (max == 0)
    {
        return max;
    }
    else
    {
        return max - 1;
    }
}

int buscara(struct dadosAluno lista[], int max)
{
    int i, j;
    char ra[7];
    
    printf("\nDigite o RA do aluno que deseja encontrar:\t");
    fflush(stdin);
    scanf("%s", ra);
    for (i = 0; i < max; i++)
    {
        if (strcmp(ra, lista[i].ra) == 0)
        {
            return i;
        }
    }
    return -1;
}

int buscanome(struct dadosAluno lista[], int max)
{
    int i;
    char nome[50];

    printf("\nDigite o nome do aluno que deseja encontrar:\t");
    fflush(stdin);
    scanf("%s", nome);
    for (i = 0; i < max; i++)
    {
        if (strcmp(nome, lista[i].nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

int mostrardados(struct dadosAluno lista[], int max)
{
    int i, j;

    printf("\nNome:\t\tRA:\t\tNota:\n");
    for (i = 0; i < max; i++)
    {
        printf("%s\t\t", lista[i].nome);
        printf("%s\t\t", lista[i].ra); 
        printf("%.2f\n", lista[i].nota);
    }
    return 1;
}