#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int v[], int tam)
{
    int i, j, item, menor;

    for (i = 0; i < tam - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < tam; j++)
        {
            if (v[j] < v[menor])
            {
                menor = j;
            }
        }

        item = v[i];
        v[i] = v[menor];
        v[menor] = item;
    }
}

int main()
{
    const int tamanhoBase = 50000;
    int i, j, k, contExec = 3, escala = 8;
    int v[tamanhoBase * escala];
    clock_t inicio, fim;
    double tempoGasto = 0, tempoMedio = 0;

    srand(time(NULL));

    for (i = 1; i <= escala; i++)
    {
        printf("Tamanho: %d\n\n", (tamanhoBase * i));

        for (j = 0; j < contExec; j++)
        {
            for (k = 0; k < (tamanhoBase * i); k++)
            {
                v[k] = rand() % 101;
            }

            inicio = clock();

            insertionSort(v, (tamanhoBase * i));

            fim = clock();

            tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempoMedio += tempoGasto;

            printf("Tempo %d de execucao do vetor: %f\n\n", j + 1, tempoGasto);
        }

        tempoMedio /= contExec;

        printf("Media: %f\n\n", tempoMedio);

        tempoMedio = 0;
    }
}
