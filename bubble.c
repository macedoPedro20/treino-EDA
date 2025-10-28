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

void bubbleSort(int *vetor, int tam)
{
    printf("Iniciando Bubble Sort:\n");
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;

                // Printando o vetor após cada troca
                printf("Passo (i=%d, j=%d): ", i, j);
                printVetor(vetor, tam);
            }
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

    bubbleSort(vetor, tamanho);

    printf("Vetor ordenado:\n");
    printVetor(vetor, tamanho);

    free(vetor);
    return 0;
}