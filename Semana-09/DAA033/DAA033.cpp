#include <cstdio>
#include <iostream>
#include <climits>
#include <list>
#include <set>

#define MAX 1000

using namespace std;
string places[MAX];
int number_places=0;

struct Node{
    list<pair<int, double>> adj;
    bool visited;
    double distance;
};


struct Graph{
    int n;
    Node nodes[MAX];
};

void addLink(Graph *g, int a, int b, double c) {
  g -> nodes[a].adj.push_back({b,c});
}

int store_name(string a){
    for(int i=0;i<number_places;i++){
        if (places[i]==a){
            return i;
        }
    }
  places[number_places++] = a;
  return number_places-1;
}

// Algoritmo de Dijkstra
  void dijkstra(Graph *g, int s) {
    
    //Inicializar nos como nao visitados e com distancia infinita
    for (int i=1; i<=g->n; i++) {
        g->nodes[i].distance = INT_MAX;
        g->nodes[i].visited  = false;
    }
    
    // Inicializar "fila" com no origem
    g->nodes[s].distance = 0;
    set<pair<int, double>> q; // By "default" um par e comparado pelo primeiro elemento 
    q.insert({0, s});      // Criar um par (dist=0, no=s)

    // Ciclo principal do Dijkstra
    while (!q.empty()) {
      
      // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
      int u = q.begin()->second;
      q.erase(q.begin());
      g->nodes[u].visited = true;
      //cout << u << " [dist=" << g->nodes[u].distance << "]" << endl;

      // Relaxar arestas do no retirado
      for (auto edge : g->nodes[u].adj) {
        int v = edge.first;
        double cost = edge.second;
        if (!g->nodes[v].visited && g->nodes[u].distance + cost < g->nodes[v].distance) {
            q.erase({g->nodes[v].distance, v});  // Apagar do set
            g->nodes[v].distance = g->nodes[u].distance + cost;
            q.insert({g->nodes[v].distance, v}); // Inserir com nova (e menor) distancia
        }
      }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    double tmpDis;
    string p1,p2;
    Graph *g = new Graph;
    g->n=n;
    cin>>p1>>p2;
    store_name(p1);
    store_name(p2);

    for (int i=0; i<e; i++){
        cin >> p1 >> p2 >> tmpDis;
        addLink(g, store_name(p1), store_name(p2), tmpDis);
        addLink(g, store_name(p2), store_name(p1), tmpDis);
    }

    dijkstra(g,0);
    printf("%.1f\n", g->nodes[1].distance);


    return 0;
}