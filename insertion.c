#include <stdio.h>
#include <stdlib.h>

int *lerVetor(int *tam)
{
    printf("Digite o tamanho do vetor: ");
    scanf("%d", tam);

    int *vetor = (int *)malloc((*tam) * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    printf("Digite os elementos do vetor:\n");

    for (int i = 0; i < *tam; i++)
    {
        scanf("%d", &vetor[i]);
    }

    return vetor;
}

void printVetor(int *vetor, int tam)
{
    printf("[ ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

void insertionSort(int *vetor, int tam)
{
    printf("Iniciando Insertion Sort:\n");
    for (int i = 1; i < tam; i++)
    {
        int chave = vetor[i];
        int j = i - 1;

        printf("Passo i=%d, chave=%d", i, chave);
        printVetor(vetor, tam);

        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
            printVetor(vetor, tam);
        }

        vetor[j + 1] = chave;
        printVetor(vetor, tam);
    }
}
int main()
{
    int tamanho;
    int *vetor = lerVetor(&tamanho);
    if (vetor == NULL)
    {
        return 1;
    }
    printf("Vetor original:\n");
    printVetor(vetor, tamanho);

    insertionSort(vetor, tamanho);
    printf("Vetor ordenado por insertion sort:\n");
    printVetor(vetor, tamanho);
    free(vetor);
    return 0;
}