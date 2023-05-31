#include <iostream>
#include <list>

using namespace std;

#define MAX 200

list<int> output;

struct petri
{
    int n;
    int l,c;
    int maior=0;
    bool cels[MAX][MAX];
    bool visited[MAX];

    void dfs(int v){
        //printf("dfs (%d)\n", v);
        visited[v]=true;
        for (int i=0;i<n;i++){
            if (cels[v][i] && !visited[i]){
                dfs(i);
            }
        }
    }

    void read(int l, int c){
        this->l=l;
        this->c=c;
        for (int i=0;i<l;i++){
            for (int j=0;j<c;j++){
                char cel;
                scanf ("%c", &cel);
                if (cel=='\n') scanf ("%c", &cel);
                if (cel=='#') cels[i][j]=true;
                else cels[i][j]=false;
           }
        }
    }

    void print(){
        for (int i=0;i<l;i++){
            for (int j=0;j<c;j++){
                printf ("%d", cels[i][j]);
           }
           printf("\n");
        }
        printf("\n");
    }

    //calcular maior tamanho de um componente conexo
    void maiorComp(){
        n=l*c;
        int maxlocal=0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                maxlocal=celulas(i,0);
                
            }
            if (maxlocal>maior) {
                maior=maxlocal;
            }
        }
        output.push_back(maior);
    }
    // valor bolleano de visitados para cels
    bool loc(int v){
        int i=v/c;
        int j=v%l;
        return visited[i][j];
    }

    //celulas juntas, horizontal e vertical e diagonal
    int celulas(int v,int vizinhos){
        printf("celulas (%d)\n", v);
        printf("vizinhos (%d)\n", vizinhos);
        visited[v]=true;
        
        for (int i=0;i<n;i++){
            if (cels[v][i+1] && !visited[i+1]){
                vizinhos++;
                vizinhos+=celulas(i+1,vizinhos);
            }
            if (cels[v+1][i] && !visited[i+l]){
                vizinhos++;
                vizinhos+=celulas(i+l,vizinhos);
            }
            if (cels[v+1][i+1] && !visited[i+l+1]){
                vizinhos++;
                vizinhos+=celulas(i+l+1,vizinhos);
            }
            else return 0;
        }
        return vizinhos;
    }

};




int main(){
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        petri p;
        int l,c;
        scanf("%d %d",&l,&c);
        p.read(l,c);
        p.print();
        p.maiorComp();
    }

    for (int i:output){
        printf("%d\n",i);
    }

    return 0;
}