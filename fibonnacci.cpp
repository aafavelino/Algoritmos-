/*
 * Autor: Adelino Afonso
 */

/**
 * Altere e complete o programa de maneira que ele seja capaz de
 * calcular a serie de Fibonacci ate 10^19 ou 10000000000000000000.
 */

#include <iostream>
#include <new>

using namespace::std;


//-------------------------------------------------------------------------------
//! Imprime um vetor de inteiros longos sem sinal.
/*! Esta funcao imprime na saida padrao um vetor de inteiros cujo tamanho eh
 *  passado como argumento.
 *  @param _A O vetor a ser impresso na saida padrao.
 *  @param _sz O tamanho do vetor passado como argumento.
 */
void printArray( long unsigned int _A[ ], int _sz )
{
    // Imprimir o vetor.
    cout << ">>> [ ";
    for ( int i(0) ; i < _sz ; ++i )
        cout << _A[ i ] << " ";
    cout << "]\n";
}

//-------------------------------------------------------------------------------
//! Gera a sequencia de Fibonacci em um vetor ate um limite informado.
/*! Esta funcao gera em um vetor alocado dinamicamente a serie de Fibonacci ate
 *  antes de atingir um limite inteiro passado por parametro.
 *  Por exemplo, se limite = 15, o vetor gerado deve ser [ 1 1 2 3 5 8 13 ],
 *  visto que o ultimo elemento da serie e 13 < limite (=15).
 *
 *  @param _limit O limite inteiro que determina o fim da serie.
 *  @param _A Pointeiro que deverah conter o vetor com a serie.
 *  @return Number of elements in the Fibonacci series (size of _A)
 */
int fib( long unsigned int _limit,  long unsigned int  * &_A )
{
    int count = 0;
    long unsigned int fib0 = 0;
    long unsigned int fib1 = 0;
    long unsigned int fib2 = 1;
    while ( fib2 < _limit )
    {

        cout << fib2 << " "; // imprimir na tela apenas para depurar
        count++; // usado para determinar o comprimento da serie.
        fib0 = fib1;
        fib1 = fib2;
        fib2 = fib0 + fib1;
    }
    cout << endl; // descarregar a lista.

    // TODO: Aqui devemos criar e preencher o vetor com a serie
    //

    long unsigned int *v = new long unsigned int[count];

     count = 0;
     fib0 = 0;
     fib1 = 0;
     fib2 = 1;

     _A = v;

    for (count; fib2 < _limit; ++count)
    {
        

        v[count] = fib2;
        fib0 = fib1;
        fib1 = fib2;
        fib2 = fib0 + fib1;
    }
    
    return count;
}

int main () {
   long unsigned int iLimit; // Valor limite da serie, cujo valor maximo deve ser inferior.
   long unsigned int *A = nullptr; // Ponteiro para o vetor a ser criado dinamicamente.

    cout << ">>> Indique o limite para a serie de Fibonacci (n > 0): ";
     cin >> iLimit; // Ler valor do terminal.

    if ( iLimit >= 0 ) {
        auto sz = fib( iLimit, A ); // Gerar a Fibonacci em vetor.

        cout << ">>> The Fibonacci series up to " << iLimit << " is: \n";
        printArray( A, sz ); // Imprimir vetor na saida padrao.
    }
    else cout << ">>> Sorry, only positive integers accepted. Aborting...\n";
}
