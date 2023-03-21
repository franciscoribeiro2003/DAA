# [DAA010](https://www.dcc.fc.up.pt/~pribeiro/aulas/daa2223/problemas/daa010.html) Somas mais próximas

## O Problema
Dada um conjunto S de N números inteiros, e uma sequência de Q perguntas (queries), cada uma indicando um número Pi, a tua tarefa é descobrir qual é a soma de dois números diferentes de S que está mais próxima do número Pi de cada pergunta.

## Input
Na primeira linha do input vem um único número indicando N, o tamanho do conjunto S de números. Na segunda linha vêm os números Si do conjunto (é garantido que são todos números distintos).

Na terceira linha vem um número Q, indicando quantidade de perguntas, seguindo-se na quarta linha os números Pi de cada pergunta.

## Output
O output deve ser constituído por Q linhas, uma por cada pergunta, na mesma ordem em que vinham no input. Cada uma das linhas deve indicar a soma mais próxima da respectiva pergunta. No caso de existirem várias somas à mesma distância mínima, devem vir todas, por ordem crescente e separadas por um espaço.

### Restrições
São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:

2 ≤ N ≤ 1 000	   	Tamanho do conjunto de números
1 ≤ Si ≤ 1 000 000	   	Números do conjunto
1 ≤ Q ≤ 2 000	   	Quantidade de perguntas
1 ≤ Pi ≤ 1 000 000	   	Números de cada pergunta
### Exemplo de Input
```
6
12 3 17 5 34 33
4
1 51 41 21
```
### Exemplo de Output
```
8
51
39
20 22
```

**Explicação do Input/Output**
Neste caso temos S = {3,5,12,17,33,34} e 4 perguntas.
Para a pergunta 1, a resposta é 8 (3+5), a soma de um par mais próxima de 1.
Para a pergunta 51, a resposta é 51 (17+34).
Para a pergunta 41, a resposta é 39 (5+34).
Finalmente, para a pergunta 21, a resposta é 20 (3+17) e 22 (5+17), ambos à mesma distância de 21.

# Sobre o programa
Compilar o programa com `gcc`
```shell
gcc -o DAA010 DAA010.cpp -lstdc++ 
```

Executar o programa
```shell
./DAA010 
```

Poderá fazer tudo junto já com o teste como input
```shell
gcc -o DAA010 DAA010.cpp -lstdc++ && ./DAA010 < t1.txt
```

## Código
```cpp
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
```
