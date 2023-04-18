#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct compareDNA
{

    string dna;
    compareDNA(string a){
        dna=a;
    }

    bool operator()(pair<char,int> & a, pair<char,int> & b) {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            int pos_a = dna.find(a.first);
            int pos_b = dna.find(b.first);
            return pos_a < pos_b;
        }
    }
};


int main(){
    string dna;
    cin >> dna;
    int size=dna.size();

    string backup=dna;
    sort(dna.begin(), dna.end());
    
    int j=0;
    char past=dna[0];

    vector<pair<char, int>> letras(size);
    letras[j].first=past;
    letras[j].second=0;

    for (int i=0;i<size;i++){
        char present=dna[i];
        
        if (present!=past) {
            j++;
            letras[j].first=present;
            letras[j].second=1;
        }

        else {
            letras[j].first=present;
            letras[j].second++;
        }
        past=present;
    }

    sort(letras.begin(),letras.end() , compareDNA(backup));
    for (int l=0;l<=j;l++) cout<<letras[l].first<< " " << letras[l].second << '\n';
    

}   