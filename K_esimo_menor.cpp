#include <iostream>
	using namespace std;


		int preenche(int *v, int n){
			for (int i = 0; i < n; ++i)
				std::cin >> v[i];
			return *v;
		}

		int ordena(int *vetor, int tamanho){
		
			for (int i = tamanho - 1; i > 0 ; --i)
				for (int j = 0; j < tamanho; ++j)
					if (vetor[j] > vetor[j+1])
						 swap(vetor[j],vetor[j+1]);
		}

		int main(int argc, char const *argv[])
		{
			std::cout << ">>> Informe o tamanho desejado de numeros a serem inseridos: \n";
		int n, k;
			std::cin >> n;
		int vetor[n];


		preenche(vetor, n);

			std::cout << ">>> Informe qual o 'K-ésimo termo' a ser procurado: ";
			std::cin >> k;

		ordena(vetor, n);


			if(k<1 || k > n)
				std::cout << ">>> informe um K entre o intervalo[1,"<< n <<"]: \n",
				std::cin >> k;



			std::cout << ">> O "<< k <<"º menor termo é: "<< vetor[k-1] << endl;
			
			return EXIT_SUCCESS;
		}

