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

/* imprime segmento vetor[low..high] */
void printSegmento(int *vetor, int low, int high)
{
    printf("[ ");
    for (int i = low; i <= high; i++)
        printf("%d ", vetor[i]);
    printf("]\n");
}

/* Lomuto partition com prints */
int partition(int *vetor, int low, int high)
{
    int pivot = vetor[high];
    int i = low - 1;

    printf("Particionando %d..%d com pivo=%d\n  segmento antes: ", low, high, pivot);
    printSegmento(vetor, low, high);

    for (int j = low; j < high; j++)
    {
        if (vetor[j] < pivot)
        {
            i++;
            if (i != j)
            {
                int tmp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = tmp;
                printf("  troca: índice %d <-> %d -> ", i, j);
                printSegmento(vetor, low, high);
            }
        }
    }
    if (i + 1 != high)
    {
        int tmp = vetor[i + 1];
        vetor[i + 1] = vetor[high];
        vetor[high] = tmp;
        printf("  movendo pivo para posição %d -> ", i + 1);
        printSegmento(vetor, low, high);
    }

    printf("  resultado partição índice pivo=%d\n", i + 1);
    return i + 1;
}

void quickSortRec(int *vetor, int low, int high)
{
    if (low < high)
    {
        int pi = partition(vetor, low, high);
        quickSortRec(vetor, low, pi - 1);
        quickSortRec(vetor, pi + 1, high);
    }
}

/* wrapper simples */
void quickSort(int *vetor, int tam)
{
    if (tam <= 0)
        return;
    quickSortRec(vetor, 0, tam - 1);
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

    quickSort(vetor, tamanho);
    printf("Vetor ordenado por quick sort:\n");
    printVetor(vetor, tamanho);
    free(vetor);
    return 0;
}