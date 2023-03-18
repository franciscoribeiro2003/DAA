// Conjunto S de N numeros inteiros
// Sequencia de perguntas Q indicando um numero P[i]
// Descubrir qual da soma de dois numeros diferentes S está mai proximo do numero P[i]
// Input:
// N tamanho do conjunto S
// de seguida leitura dos numeros S
// Q, quantidade de perguntas
// leitura de cada pergunta
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // ler um inteiro N
    int n;
    cin >> n;

    // leitura de N numeros inteiros
    int lista[n];
    for (int i = 0; i < n; i++)
    {
        cin >> lista[i];
    }

    //criar a lista de somas de dois numeros diferentes com 2 loops
    int soma[n*(n-1)/2];
    int k = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            soma[k] = lista[i] + lista[j];
            k++;
        }
    }

    // ordenar a lista de somas
    sort(soma, soma + n*(n-1)/2);


    // ler um inteiro Q
    int q;
    cin >> q;

    // leitura de Q numeros inteiros 
    int perguntas[q];
    for (int i = 0; i < q; i++)
    {
        cin >> perguntas[i];
        for (int j = 0; j < n*(n-1)/2; j++)
        {
            if (perguntas[i] < soma[j] && j>0 && perguntas[i] > soma[j-1])
            {
                if (soma[j] - perguntas[i] < perguntas[i] - soma[j-1])
                {
                    cout << soma[j] << endl;
                    break;
                }
                else if (soma[j] - perguntas[i] == perguntas[i] - soma[j-1])
                {
                    //print soma j-1 and a space
                    cout << soma[j-1] << " ";
                    cout << soma[j] << endl;
                    break;
                }
                else
                {
                    cout << soma[j-1] << endl;
                    break;
                }
            }
            else if (perguntas[i] == soma[j])
            {
                cout << soma[j] << endl;
                break;
            }
            else if (perguntas[i] < soma[j] && j==0 )
            {
                cout << soma[j] << endl;
            }
            else if (perguntas[i] > soma[j] && j == n*(n-1)/2-1)
            {
                cout << soma[j] << endl;
            }
            

        }

    }

    return 0;
}
