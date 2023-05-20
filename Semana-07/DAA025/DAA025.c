#include <stdio.h>
#include <stdbool.h>

#define MAX 200

int n;
bool adj[MAX][MAX];
bool visited[MAX];

void dfs(int v){
    //printf("dfs (%d)\n", v);
    visited[v]=true;
    for (int i=1;i<=n;i++){
        if (adj[v][i] && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    int l,a,b;
    scanf("%d %d",&n,&l);

    for (int i=0;i<l;i++){
        scanf("%d %d", &a, &b);
        adj[a][b]=adj[b][a]=true;
    }
    int count=0;
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            count ++; 
            dfs(i);
        }
    }
    
    printf("%d\n", count);
    return 0;
}