#include <iostream>
#include <bits/stdc++.h>

void junta(int vet[], int inicio, int meio, int fim, int vet_aux[]) {
  int esq = inicio;
  int dir = meio;

  for (int i = inicio; i < fim; ++i) {
    if ((esq < meio) && ((dir >= fim) || (vet[esq] < vet[dir]))) {
      vet_aux[i] = vet[esq];
      ++esq;
    }
    else {
      vet_aux[i] = vet[dir];
      ++dir;
    }
  }

  for (int i = inicio; i < fim; ++i)
  vet[i] = vet_aux[i];

}

void merge_sort(int vet[], int inicio, int fim, int vet_aux[]) {
  if ((fim - inicio) < 2) return;

  int meio = ((inicio + fim)/2);

  merge_sort(vet, inicio, meio, vet_aux);
  merge_sort(vet, meio, fim, vet_aux);
  junta(vet, inicio, meio, fim, vet_aux);
}

void merge_sort(int vet[], int tamanho) {
  int vet_aux[tamanho]; //vetor auxiliar
  merge_sort(vet, 0, tamanho, vet_aux);
}

int main(){

  printf("Digite o tamanho do array: \n");

  int tamanho;
  int array[tamanho];

  scanf("%d", &tamanho);

  for(int i = 0; i < tamanho; i++){
    int valor = rand() % 100 + 1;
    array[i] = valor;
  }

  merge_sort(array, tamanho);

  printf("Vetor ordenado pelo metodo Merge Sorte:\n\n");

  for(int k = 0; k < tamanho; k++){
    if (k < tamanho -1)
    printf("%d ", array[k]);
    else
    printf("%d.", array[k]);
  }

  printf("\n");

  return 0;
}
