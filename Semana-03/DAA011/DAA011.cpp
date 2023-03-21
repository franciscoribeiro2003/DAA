#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(int mid, int n, int distancias[], int dias){
    int sum = 0; // soma acumulada
    int count = 1; // quantidade de dias
    for (int i = 0; i < n; i++){
        //se a distancia do dia for maior que a distancia maxima por dia
        if (distancias[i] > mid) return false;
        sum += distancias[i];
        if (sum > mid) // se a soma acumulada for maior que a distancia maxima por dia
        {
            sum = distancias[i]; // a soma acumulada passa a ser a distancia do dia
            count++;            // aumenta a quantidade de dias
        }
    }
    if (count > dias) // se a quantidade de dias for maior que a quantidade de dias que o Aniceto quer dividir o percurso
    {
        return false; // nao e possivel dividir o percurso
    }
    return true;
}


int main(int argc, char const *argv[]){
    // Ler o número de distâncias
    int n;
    cin >> n;
    // Ler as distâncias
    int distancias[n];
    for (int i = 0; i < n; i++) cin >> distancias[i];
    

    //soma acumulada
    int soma[n];
    soma[0] = distancias[0];
    for (int i = 1; i < n; i++) soma[i] = soma[i - 1] + distancias[i];

    int p; //quantidade de perguntas
    cin >> p;

    //Minimo maximo distancia por dia
    int dias; //dias que o Aniceto quer dividir o percurso


    for (int i = 0; i < p; i++){ //para cada pergunta

        int high = soma[n - 1];
        int low = 0;
        int mid;

        int maxi=0; //distancia maxima por dia
        cin>>dias; //ler dias

        while (low<=high){ //pesquisa binaria
            mid=(high+low)/2; 
            if (isPossible(mid, n, distancias, dias)){
                high=mid-1; //se for possivel, diminui a distancia maxima
                maxi=mid;
            }
            else{
                low=mid+1; //se nao for possivel, aumenta a distancia maxima
            }
        }
        
        cout << maxi << endl; //imprime a distancia maxima
    }
    return 0;
}

