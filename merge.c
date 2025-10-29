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

/* Imprime apenas o segmento vetor[l..r] */
void printSegmento(int *vetor, int l, int r)
{
    printf("[ ");
    for (int i = l; i <= r; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

/* mescla vetor[l..m] e vetor[m+1..r], imprimindo o passo */
void merge(int *vetor, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    if (L == NULL || R == NULL)
    {
        printf("Erro ao alocar memoria durante merge!\n");
        free(L);
        free(R);
        return;
    }

    for (int i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vetor[m + 1 + j];

    printf("Mesclando subvetores %d..%d e %d..%d: ", l, m, m + 1, r);
    printSegmento(vetor, l, r);
    printf("  esquerda: ");
    printSegmento(L, 0, n1 - 1);
    printf("  direita: ");
    printSegmento(R, 0, n2 - 1);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k++] = L[i++];
        }
        else
        {
            vetor[k++] = R[j++];
        }
    }
    while (i < n1)
        vetor[k++] = L[i++];
    while (j < n2)
        vetor[k++] = R[j++];

    printf("  resultado segmento %d..%d: ", l, r);
    printSegmento(vetor, l, r);

    free(L);
    free(R);
}

void mergeSortRec(int *vetor, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSortRec(vetor, l, m);
    mergeSortRec(vetor, m + 1, r);
    merge(vetor, l, m, r);
}

void mergeSort(int *vetor, int tam)
{
    if (tam > 0)
        mergeSortRec(vetor, 0, tam - 1);
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
    mergeSort(vetor, tamanho);
    printf("Vetor ordenado por merge sort:\n");
    printVetor(vetor, tamanho);
    free(vetor);
    return 0;
}