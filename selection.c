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

void selectionSort(int *vetor, int tam)
{
    printf("Iniciando Selection Sort:\n");
    for (int i = 0; i < tam - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < tam; j++)
        {
            if (vetor[j] < vetor[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int old_i = vetor[i];
            int old_min = vetor[minIndex];

            int temp = vetor[i];
            vetor[i] = vetor[minIndex];
            vetor[minIndex] = temp;
            printf("Trocando o vetor: \n");
            printVetor(vetor, tam);
        }
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

    selectionSort(vetor, tamanho);
    printf("Vetor ordenado por selection sort:\n");
    printVetor(vetor, tamanho);
    return 0;
}