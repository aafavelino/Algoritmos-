#include <iostream>
using namespace std;
	int Busca_binaria_recursiva(int A[], int x, int l, int r);
	int Busca_binaria(int A[], int x, int l, int r);
	int bubble_sort(int *vetor, int tamanho);

	int main(int argc, char const *argv[])
	{	int tamanho, x;
		std::cout << ">>> Insira o tamanho desejado para o vetor:";
		std::cin >> tamanho;

		int vetor[tamanho];

		std::cout << ">>> Informe os valores do vetor:";
		for (int i = 0; i < tamanho; ++i)
		{
			std::cin >> vetor[i];
		}

		std::cout << ">>> Executando o Bubble Sort..." << endl;

		bubble_sort(vetor,tamanho);

		std::cout << ">>> Informe qual número deseja procurar..." << endl;
		std::cin >> x;

		std::cout << ">>> Busca Binária" << endl;
		std::cout << Busca_binaria(vetor,x,0,tamanho) << endl;
		std::cout << ">>> Busca Binária Recursiva" << endl;
		std::cout << Busca_binaria_recursiva(vetor,x,0,tamanho) << endl;
		
		return 0;
	}

	int Busca_binaria_recursiva(int A[], int x, int l, int r){
		if (l>r)
			return -1;
		int n = (r+l)/2;
		if (x == A[n])
			return n;
		else if (x > A[n])
			 return Busca_binaria_recursiva(A, x, n+1, r);
		else  
			 return Busca_binaria_recursiva(A, x, l, n-1);
	}

	int Busca_binaria(int A[], int x, int l, int r){
		while (l <= r){

		int n = (r+l)/2;
		if (x == A[n])
			return n;
		else if (x > A[n])
			 l = n + 1;
		else  
			 r = n - 1;
		}
			return -1;
	}

	int bubble_sort(int *vetor, int tamanho){
		
		for (int i = tamanho - 1; i > 0 ; --i)
		{
			for (int j = 0; j < tamanho; ++j)
			{
				if (vetor[j] > vetor[j+1])
				{
					 swap(vetor[j],vetor[j+1]);
				}
			}
		}
	}
