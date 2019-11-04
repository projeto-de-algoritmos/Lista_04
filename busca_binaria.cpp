#include<bits/stdc++.h>

using namespace std;

int busca_binaria (int x, int v[], int e, int d);
void junta(int vet[], int inicio, int meio, int fim, int vet_aux[]);
void merge_sort(int vet[], int inicio, int fim, int vet_aux[]);
void merge_sort(int vet[], int tamanho);

int main() {
	
	int tamanho;
	int chave,resultado;

	cout << "Digite o tamanho do vetor" << endl;
	cin >> tamanho;
	
	int vetor[tamanho - 1];

	for(int i = 0; i < tamanho; i++){
		int valor = rand() % (100 + 1);
		vetor[i] = valor;
	}

	  merge_sort(vetor, tamanho);
	cout << "O vetor é:" << endl;

	for ( int i = 0; i < tamanho; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;

	cout << "Qual valor a ser procurado?" << endl;
	cin >> chave;

 	resultado = busca_binaria (chave, vetor, 0, tamanho);
	
	if (resultado==-1)
		cout << "O valor procurado não foi encontrado." << endl;
	else
		cout << "O valor procurado encontra-se na posição " << resultado  << endl;

	return 0;

}


int busca_binaria (int x, int v[], int e, int d){
	int meio = (e + d)/2;

	if (v[meio] == x)
		return meio;
	if (e >= d)
		return -1; // não encontrado
	else
		if (v[meio] < x)
			return busca_binaria(x, v, meio+1,      d);
		else
			return busca_binaria(x, v,      e, meio-1);
}

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
