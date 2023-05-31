
```shell
g++ -Wall -o D26 D26.cpp && ./D26 < t3.txt 
```

## **Teórica:**

- Imprimir a ordem em que os nós são visitados como DFS:

DFS visita todos nós em profundidade, explora um ramo do grafo o máximo possível antes de voltar e explorar outros ramos. A ordem em que os nós são visitados pode ser registrada e impressa à medida que a DFS percorre o grafo.

**Pseudócodigo:**
```
dfs(nó v):
    marcar v como visitado
    Para todos os nós w adjacente a v fazer
        Se w ainda não foi visitado então
            dfs(w)
```

-----------------------------------------------------------

- Calcular quantidade e/ou tamanho/peso de componentes conexos

Um componente conexo num grafo é um conjunto de nós em que há um caminho entre qualquer par de nós. Para calcular quantidade de componentes conexos, podemos usar a DFS para percorrer o grafo e contar o número de vezes que a DFS é chamada, representando a exploração de um componente conexo diferente. É possivel calcular o tamanho ou peso de cada componente conexo ao contabilizar o número de nós visitados em cada chamada da DFS.

**Pseudócodigo**:

```
contador = 0
marcar todos os nós como não visitados
Para todos os nós v do grafo fazer
    Se v ainda não foi visitado então
        contador = contador + 1
        dfs(v)
escrever(contador)
```

------------------------------------------------------

- Verifcar se um grafo é bipartido

Um grafo bipartido é um grafo onde é possivel dividir os nós em dois grupos A e B tal que cada aresta liga um nó de A a um nó de B:

A DFS pode ser utilizada para verificar se um grafo é bipartido, durante a DFS, atribuiu-se uma cor (por exemplo 0 ou 1) para cada nó visitado. Caso seja encontrada uma aresta que conecte dois nós com a mesma cor, o grafo não é bipartido.

Nota: Não podem exitir arestas de A para A e de B para B

**Pseudócodigo**:

```
Fazer um dfs a partir de um nó u e colorir esse nó com uma cor.
Para cada nó w vizinha de u:

    - Se w não foi visitado , fazer dfs(w) e pintar w com cor diferente de v
    - Se w já foi visitado, verificar se cor é diferente
        Se cor for igual, grafo não é bipartido!
```

------------------------------------------------------------

- Calcular uma ordenação topológica

A ordenação topológica é uma ordenação linear dos nós de um grafo direcionado, de modo que para cada aresta (u,v) o nó u aparece antes do nó v na ordenação. Durante a DFS, à medida que o nó é completamente explorado, é adicionado a uma pilha. A ordem inversa dos nós na pilha representa uma ordenação topológica válida.

**Pseudócodigo**:

```
ordem = lista vazia
marcar todos os nós como não visitados
Para todos os nós v do grafo fazer
    Se v ainda não foi visitado então
        dfs(v)
escrever(ordem)

dfs(nó v):
    marcar v como visitado
    Para todos os nós w adjacentes a v fazer
        Se w ainda não foi visitado então
            dfs(w)
    adicionar v ao início da lista ordem
```


---
---
---
---

# PROBLEMA A - DFS Saber usar pesquisa em profundidade (DFS) para percorrer um grafo
```c++

#include <iostream>

#define MAX 25      // Maximo numero de nos

using namespace std;

int n;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Que nos ja foram visitados?

void dfs(int v) {
  cout << v << " ";
  visited[v] = true;
  for (int i=1; i<=n; i++)
    if (adj[v][i] && !visited[i])
      dfs(i);
}

int main() {
  int edges, a, b;

  cin >> n;
  cin >> edges;
  for (int i=0; i<edges; i++) {
    cin >> a >> b;
    adj[a][b] = adj[b][a] = true;
  }

  dfs(1); // Pesquisa em profundidade a partir do no 1
  cout << endl;
  
  return 0;
}
```

- marisa

```c++

#include <iostream>

using namespace std;

#define MAX 101

int number_of_nodes;
bool matrix[MAX][MAX] = {false}; // Matriz de adjacência
bool visited[MAX] = {false}; // Array para acompanhar os nós visitados

void dfs(int node) {
    visited[node] = true; // Marca o nó como visitado

    for(int i = 1; i <= number_of_nodes; i++) {
        if(matrix[node][i] && !visited[i]) { // Verifica se há uma aresta entre o nó atual e o nó i e se o nó i ainda não foi visitado
            dfs(i); // Chama a função dfs recursivamente para o nó i
        }
    }
}

int main() {
    int number_of_edges, node1, node2;

    cin >> number_of_nodes >> number_of_edges; // Lê o número de nós e o número de arestas

    // Lê as arestas e preenche a matriz de adjacência
    for(int i = 0; i < number_of_edges; i++) {
        cin >> node1 >> node2;
        matrix[node1][node2] = matrix[node2][node1] = true; // Define a aresta entre o nó node1 e o nó node2
    }

    int count = 0;
    // Percorre todos os nós
    for(int i = 1; i <= number_of_nodes; i++) {
        if(!visited[i]) { // Se o nó não foi visitado ainda
            count++; // Incrementa o contador de componentes conectados
            dfs(i); // Chama a função dfs para explorar todos os nós conectados a partir do nó i
        }
    }

    cout << count << endl; // Imprime o número de componentes conectados

    return 0;
}
```

## Imprimir a ordem em que os nós são visitados com DFS
## DAA025
Um circuito electrónico consiste em diversos componentes, pontos de contacto (pins) e ligações (wires). 
A figura seguinte mostra um circuito com 3 componentes: A, B e C. Cada ligação envolve um par de pontos de contacto.

Dois pontos de contacto a e b dizem-se electronicamente equivalentes se têm uma ligação directa entre eles, ou se se existe um sequência de pontos de contacto `a1, a2, ..., ak`, tal que existe ligação entre `(a,a1), (a1,a2), ..., (ak, b)`. 

Uma rede é um conjunto máximo de pontos de contacto electronicamente equivalentes. 

Máximo é aqui usado no sentido de traduzir que nenhum ponto de contacto fora da rede é electronicamente equivalente a qualquer ponto dentro da rede.

**O Problema**

Dado um conjunto de pontos de contacto e as suas respectivas ligações, a tua tarefa é descobrir o número de redes diferentes que existem no circuito. A figura seguinte ilustra um circuito com 3 redes.


**Input**

- Na primeira linha vem um número N indicando o número de pontos de contacto existentes.
- Na segunda linha vem um número L indicando o número de ligações existentes.
- Seguem-se L linhas, cada uma com um par de números diferentes indicando que pontos de contacto estão conectados pela ligação.
- Os pontos de contacto são sempre identificados por números de 1 até N.
- Note que as ligações não vêm por nenhuma ordem em específico e que nunca aparecem ligações repetidas.

**Output**

Deve ser imprimida uma única linha, contendo o número de redes do respectivo circuito.

**Restrições**

São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
```
1 ≤ N ≤ 100	   	Número de pontos de contacto
0 ≤ L ≤ 100	   	Número de ligações
Exemplo de Input
14
11
1 11
7 11
11 12
12 2
12 8
3 13
13 4
13 14
14 9
14 5
10 6
```
Exemplo de Output
```
3
```
```c++
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
```
-----
## Calcular quantidade e/ou tamanho/peso de componentes conexos
## DAA026
O Aniceto tem um trabalho laboratorial de Biologia e precisa da tua ajuda. Ele está a cultivar pequenos micróbios numa caixa de Petri e necessita de os observar ao microscópio para perceber qual é a maior micróbio visível.

A caixa de Petri pode ser considerada como uma grelha 2D, ou seja uma matriz, onde em cada posição pode ou não existir uma célula. Duas células estão ligadas se forem adjacentes vertical, horizontal ou diagonalmente. Um micróbio é um conjunto de células ligadas. Por exemplo, a caixa de Petri seguinte tem exactamente três micróbios ('.' é uma posição vazia, '#' é uma posição com uma célula):
```
#	#	.	#	.	.	.
.	#	#	#	.	.	.
.	.	.	.	.	#	#
.	#	.	.	.	#	#
#	.	#	.	.	.	.
```
O tamanho de um micróbio é igual ao número de células que o constitui. Na figura de cima, os 3 micróbios têm tamanho 6 (o amarelo), 3 (o azul) e 4 (o verde). O maior micróbio é o de maior tamanho. Neste caso o maior micróbio é o amarelo.

**O Problema**

Dado o estado de várias culturas de micróbios (indicados por uma matriz de células) a tua tarefa é descobrir qual o tamanho do maior micróbio em cada uma delas, ou seja, qual o tamanho do maior conjunto conexo de células em cada caso.

**Input**

Na primeira linha do input vem um número N indicando o número de casos a considerar. Cada dos casos começa com dois números L e C indicando respectivamente o número de linhas e colunas da caixa de petri a considerar, seguido de L linhas, cada uma com C caracteres, indicando o conteúdo de cada posição: '.' para uma posição vazia e '#' para uma posição com célula.

**Output**

O output deve ser constituido por N linhas, cada uma com o tamanho do maior micróbio do caso correspondente.

**Restrições**

São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
```
1 ≤ N ≤ 20	   	Número de casos
1 ≤ L ≤ 100	   	Número de linhas da caixa de petri
1 ≤ C ≤ 100	   	Número de colunas da caixa de petri
```
**Exemplo de Input**
```
2
5 7
##.#...
.###...
.....##
.#...##
#.#....
4 4
##.#
...#
#...
..#.
```
**Exemplo de Output**
```
6
2
```
Explicação do Input/Output
O primeiro caso de input é o da figura de cima. O segundo caso tem 4 micróbios: dois de tamanho 2 (verde e amarelo) e dois de tamanho 1 (azul e laranja). Desse modo, o maior micróbio tem tamanho 2:
```c++
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> petri;
vector<vector<bool>> visited;
int rows, columns;
int maxMicrobeSize;

void dfs(int x, int y, int& size) {
  if (x < 0 || x >= rows || y < 0 || y >= columns || visited[x][y] || petri[x][y] == '.') {
    return;
  }

  visited[x][y] = true;
  size++;

  dfs(x - 1, y - 1, size);  // Top left
  dfs(x - 1, y, size);      // Top
  dfs(x - 1, y + 1, size);  // Top right
  dfs(x, y - 1, size);      // Left
  dfs(x, y + 1, size);      // Right
  dfs(x + 1, y - 1, size);  // Bottom left
  dfs(x + 1, y, size);      // Bottom
  dfs(x + 1, y + 1, size);  // Bottom right
}

int findLargestMicrobe() {
  maxMicrobeSize = 0;
  visited.assign(rows, vector<bool>(columns, false));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (!visited[i][j] && petri[i][j] == '#') {
        int size = 0;
        dfs(i, j, size);
        maxMicrobeSize = max(maxMicrobeSize, size);
      }
    }
  }

  return maxMicrobeSize;
}

int main() {
  int numCases;
  cin >> numCases;

  while (numCases--) {
    cin >> rows >> columns;
    petri.assign(rows, vector<char>(columns));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        cin >> petri[i][j];
      }
    }

    int largestMicrobeSize = findLargestMicrobe();
    cout << largestMicrobeSize << endl;
  }

  return 0;
}
```
----------------------
Má implementação, (apenas para ver coisas de c++)
```c++
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 200

//int directions[][2]= {{-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}};
int directions[][2]= {{-1,-1}, {1,0}, {1,0}, {0,1}, {0,1}, {-1,0}, {-1,0}, {0,-1}};

struct petri{
  int rows, columns;
  bool cels[MAX][MAX];
  bool visited[MAX][MAX];


  int dfs(int x, int y, int size) {
    if (y < 0 || y >= rows || x < 0 || x >= columns || visited[x][y] || !cels[x][y])
      return 0;

    visited[x][y] = true;

    size++;
    
    for (int j = 0; j < 8; j++) {
      size += dfs(x - 1, y - 1, size);  // Top left
      size += dfs(x - 1, y, size);      // Top
      size += dfs(x - 1, y + 1, size);  // Top right
      size += dfs(x, y - 1, size);      // Left
      size += dfs(x, y + 1, size);      // Right
      size += dfs(x + 1, y - 1, size);  // Bottom left
      size += dfs(x + 1, y, size);      // Bottom
      size += dfs(x + 1, y + 1, size);  // Bottom right
    }
    return size;
  }

  int maximo(){
    int maximo=0;
    memset(visited, false, sizeof(visited));
    for (int i=0;i<rows;i++){
      for (int j=0;j<columns;j++){
        if (!visited[i][j] && cels[i][j]) {
          int buf=dfs(i,j,0);
          if (buf>maximo) maximo=buf;
        }

      }
    }
    return maximo;
  }


  void read(int l, int c){
      this->rows=l;
      this->columns=c;
      for (int i=0;i<l;i++){
          for (int j=0;j<c;j++){
              char cel;
              cin>>cel;
              //if (cel=='\n') cin>>cel;
              if (cel=='#') cels[i][j]=true;
              else cels[i][j]=false;
         }
      }
  }

};


int main(){
    int n;
    int l,c;
    scanf("%d",&n);
    petri p[n];

    for (int i=0;i<n;i++){
        scanf("%d %d",&l,&c);
        p[i].read(l,c);
    }

    for (petri i:p){
        printf("%d\n",i.maximo());
    }

    return 0;
}
```
- Resoluçao Marisa
```c++
#include <iostream>
#include <cstring>

#define MAX 101

int rows, columns;
char matrix[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int y, int x) {
  if (y < 0 || y >= rows || x < 0 || x >= columns)
    return 0;

  if (visited[y][x])
    return 0;

  if (matrix[y][x] == '#') {
    visited[y][x] = true;
    return 1 + dfs(y + 1, x - 1) + dfs(y + 1, x) + dfs(y + 1, x + 1) +
           dfs(y, x - 1) + dfs(y, x + 1) + dfs(y - 1, x - 1) +
           dfs(y - 1, x) + dfs(y - 1, x + 1);
  }

  return 0;
}

int main() {
  int max, count, cases = 0;

  std::cin >> cases;

  for (int w = 0; w < cases; w++) {
    count = 0;
    max = 0;

    std::cin >> rows >> columns;

    for (int i = 0; i < rows; i++)
      std::cin >> matrix[i];

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (matrix[i][j] == '#') {
          count = 0;
          count = dfs(i, j);
          if (count > max)
            max = count;
        }
      }
    }

    std::cout << max << "\n";
  }

  return 0;
}
```
- Marisa 2
```c++
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 101

int rows, columns;
char matrix[MAX][MAX];
bool visited[MAX][MAX];

// Função para realizar a busca em profundidade (DFS)
int dfs(int y, int x) {
  // Verifica se as coordenadas estão dentro dos limites da matriz
  if (y < 0 || y >= rows || x < 0 || x >= columns)
    return 0;

  // Verifica se a célula já foi visitada
  if (visited[y][x])
    return 0;

  // Verifica se a célula contém um '#'
  if (matrix[y][x] == '#') {
    visited[y][x] = true;
    // Realiza a busca recursivamente nas células adjacentes
    return 1 + dfs(y + 1, x - 1) + dfs(y + 1, x) + dfs(y + 1, x + 1) +
           dfs(y, x - 1) + dfs(y, x + 1) + dfs(y - 1, x - 1) +
           dfs(y - 1, x) + dfs(y - 1, x + 1);
  }

  return 0;
}

int main() {
  int max, count, cases = 0;

  // Lê o número de casos de teste
  cin >> cases;

  for (int w = 0; w < cases; w++) {
    count = 0;
    max = 0;

    // Lê o número de linhas e colunas da matriz
    cin >> rows >> columns;

    // Lê a matriz
    for (int i = 0; i < rows; i++)
      cin >> matrix[i];

    // Inicializa o array visited como falso
    memset(visited, false, sizeof(visited));

    // Percorre todas as células da matriz
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        // Verifica se a célula contém um '#'
        if (matrix[i][j] == '#') {
          count = 0;
          // Chama a função dfs para calcular o tamanho do componente
          count = dfs(i, j);
          // Atualiza o tamanho máximo encontrado
          if (count > max)
            max = count;
        }
      }
    }

    // Imprime o tamanho máximo do componente
    cout << max << "\n";
  }

  return 0;
}
```


----
## Saber verificar se um grafo é bipartido
### DAA027
Uma empresa de alojamento de websites teve um problema de hardware e algumas das suas unidades de armazenamento ficaram com problemas. Um dos seus melhores clientes é uma loja de produtos tecnológicos. A base de dados dessa loja continha dados sobre as compras, na forma de um grafo onde os nós eram compradores e produtos. Nesse grafo, existiam arestas unicamente entre compradores e produtos.

Como os dados ficaram corrompidos, os dados sobre o tipo de cada nó (comprador ou produto) foram perdidos. A empresa quer agora perceber se o grafo ainda armazenado é plausível. Em particular, quer saber se é possível dividir os nós do grafo em dois grupos A e B tal que cada aresta liga um nó de A a um nó de B, ou seja, tal que não existem arestas entre dois nós de A, ou entre dois nós de B (não faria sentido haver uma aresta de um comprador para um comprador, ou de um produto para um produto). Um grafo com esta propriedade diz-se bipartido.

Considere por exemplo o grafo da figura seguinte com 8 nós. O grafo é bipartido, pois a divisão indicada na imagem da direita divide o grafo em dois grupos, um vermelho e um verde, de tal modo que todas as arestas ligam nós de grupos diferentes.



Já o grafo da figura de baixo não é bipartido. Os nós 2 e 5 têm de ter cor diferente do nó 1, pois são seis vizinhos. Por sua vez, isto implica que o nó 6 tem de ter cor diferente do nó 5. Em conjunto, isto significa que não é possível colorir o nó 3, pois este é vizinho de dois nós de cor diferente.



Podes ajudar a empresa de alojamento a perceber se um grafo é plausível, ou seja, se é bipartido?

**O Problema**

Dados vários grafos não dirigidos, a tua tarefa é indicar se cada um deles é ou não bipartido.

**Input**

Na primeira linha do input vem um número N indicando o número de casos a considerar. Cada dos casos começa uma linha com um inteiro V indicando o número de nós, seguido de uma linha com um inteiro E indicando o número de arestas. Seguem-se E linhas, cada uma com dois inteiros A e B indicando que existe uma aresta entre A e B. Os nós estão numerados entre 1 e V, ou seja, 1 ≤ A, B ≤ N. É garantido que os grafos são conexos.

**Output**

O output deve ser constituido por N linhas, cada uma com a palavra sim se o grafo correspondente for bipartido, ou nao, se o grafo não for bipartido.

**Restrições**

São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
```
1 ≤ N ≤ 10	   	Número de casos
1 ≤ V ≤ 50	   	Número de nós
1 ≤ E ≤ 500	   	Número de arestas
```
Exemplo de Input
```
2
8
9
1 5
1 2
1 6
2 3
6 3
3 4
3 7
4 8
7 8
8
8
1 2
1 5
5 6
2 3
6 3
3 7
7 8
8 4
```
Exemplo de Output
```
sim
nao
```
- Resolução Marisa
```c++
#include <iostream>
#include <vector>

#define MAX 51
#define NaoVisitado 0
#define AZUL 1
#define VERMELHO 2

using namespace std;

int nos, arestas, cor;
vector<vector<bool>> adj(MAX, vector<bool>(MAX)); // matriz de adjacências
vector<int> colored(MAX); // matriz "pintada"

void reset(int n) {
  // Reinicializa a matriz de adjacências e a matriz "pintada"
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      adj[i][j] = false;
    colored[i] = NaoVisitado;
  }
}

bool paint(int x, int cor) {
  // Define uma nova cor oposta à atual
  int novaCor = (cor == AZUL) ? VERMELHO : AZUL;

  // Se o nó já foi visitado, verifica se a cor é válida
  if (colored[x] != NaoVisitado) {
    if (colored[x] != novaCor)
      return false; // Cor inválida
    return true; // Cor válida
  }

  // Se o nó não foi visitado, pinta-o com a nova cor
  if (colored[x] == NaoVisitado) {
    colored[x] = novaCor;
    for (int i = 0; i < nos; i++) {
      // Pinta os nós adjacentes recursivamente
      if (adj[x][i])
        if (!paint(i, novaCor))
          return false; // Cor inválida
    }
  }
  return true; // Cor válida
}

int main() {
  int cases = 0;
  cin >> cases;

  for (int a = 0; a < cases; a++) {
    int tmpX, tmpY;
    cin >> nos >> arestas;

    // Leitura das arestas e preenchimento da matriz de adjacências
    for (int i = 0; i < arestas; i++) {
      cin >> tmpY >> tmpX;
      tmpY--;
      tmpX--;
      adj[tmpY][tmpX] = true;
      adj[tmpX][tmpY] = true;
    }

    bool answer = paint(0, AZUL);

    // Imprime a resposta
    if (answer)
      cout << "sim" << endl;
    else
      cout << "nao" << endl;

    reset(nos);
  }

  return 0;
}

```
---
## Saber calcular uma ordenação topológica
### DAA029
Um coleccionador de livros raros descobriu recentemente um livro escrito numa língua pouco familiar mas que usa o mesmo conjunto de caracteres usados na língua inglesa. 

O livro possui um pequeno índice, contudo a ordem dos itens do índice é diferente da que se esperaria encontrar caso os caracteres estivessem ordenados da mesma forma que no alfabeto inglês (composto por 26 letras). 

O coleccionador tentou usar o índice para determinar a ordem dos caractéres (i.e. a sequência de junção) do alfabeto estranho, mas acabou por desistir atendendo a que a tarefa se revelava frustante e fastidiosa.

O índice é constituído por um conjunto de palavras que sabemos que vêm ordenadas na "ordem que queremos descobrir". Por exemplo, o indíce poderia ser:
```
XWY
ZX
ZXY
ZXW
YWWX
```
Com isto consegue-se descobrir as relações entre letras. Por exemplo, como a palavra XWY vem antes de ZX, sabemos que na língua do livro a letra 'X' vem antes da letra 'Z'. Sabemos também que a letra 'Y' vem depois de 'Z' porque ZXW aparece antes de YWWX. Finalmente, sabemos que a letra 'W' vem depois de 'Y', porque a palavra ZXW vem depois de ZXY.

Com todas estas considerações, sabemos que a ordem correcta das letras da lingua "estranha" só pode ser XZYW.

**O Problema**

A tua tarefa é escrever um programa para completar o trabalho do coleccionador. Em particular, o teu programa deverá receber um conjunto de palavras ordenadas associadas a uma dada sequência de ordem das letras e determinar qual é essa sequência.

**Input**

Na primeira linha vem um número inteiro N indicando o número de palavras a ler. Seguem-se N linhas, cada uma com uma palavra Pi contendo apenas letras maiúsculas.

As linhas vêm ordenada pela ordem que pretende descobrir.

**Output**

Deve ser imprimida uma única linha contendo as letras maiúsculas na ordem determinada pela sequência de junção usada para produzir o input. Apenas devem aparecer os caracteres que aparecem no input.

Para os casos de teste dados, é garantido que existe uma e só uma ordem para a qual o input faz sentido.

Restrições
São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
```
1 ≤ N ≤ 100	   	Número de palavras
1 ≤ |Pi| ≤ 10	   	Tamanho de cada palavra
```
**Exemplo de Input**
```
5
XWY
ZX
ZXY
ZXW
YWWX
Exemplo de Output
XZYW
```
- Resolução Marisa
```c++
#include <iostream>
#include <list>

#define MAX_ALPHABET_SIZE 26

using namespace std;

int num_words;
bool adjacency_matrix[MAX_ALPHABET_SIZE][MAX_ALPHABET_SIZE];
bool visited[MAX_ALPHABET_SIZE];
bool character_exists[MAX_ALPHABET_SIZE];

string words[100];
list<char> result;

void createAdjacencyMatrix() {
    // Cria a matriz de adjacência com base nas palavras
    for (int i = 0; i < num_words - 1; i++) {
        int current_word_size = words[i].length();
        int next_word_size = words[i + 1].length();
        for (int j = 0; j < current_word_size && j < next_word_size; j++) {
            if (words[i][j] != words[i + 1][j]) {
                // Se as letras forem diferentes, há uma aresta entre elas
                adjacency_matrix[words[i][j] - 'A'][words[i + 1][j] - 'A'] = true;
                // Marca os caracteres como existentes
                character_exists[words[i][j] - 'A'] = true;
                character_exists[words[i + 1][j] - 'A'] = true;
                break;
            }
        }
    }
}

void depthFirstSearch(int v) {
    visited[v] = true;
    for (int j = 0; j < MAX_ALPHABET_SIZE; j++) {
        if (adjacency_matrix[v][j] && !visited[j]) {
            // Explora os vértices adjacentes não visitados
            depthFirstSearch(j);
        }
    }
    // Adiciona o vértice no início da lista (ordem reversa)
    result.push_front(v);
}

int main() {
    cin >> num_words;
    for (int i = 0; i < num_words; i++) {
        cin >> words[i];
    }

    createAdjacencyMatrix();

    for (int i = 0; i < MAX_ALPHABET_SIZE; i++) {
        if (character_exists[i] && !visited[i]) {
            // Executa a busca em profundidade a partir de cada vértice não visitado
            depthFirstSearch(i);
        }
    }

    // Imprime a ordem topológica das letras
    for (int j : result) {
        cout << (char)(j + 'A');
    }

    cout << endl;
    return 0;
}
```
---
---
---
---
# PROBLEMA B - Saber usar pesquisa em largura (BFS) para calcular distâncias num grafo não pesado


## **Teórica:**

- Uma pesquisa em largura (BFS) é muito semelhante a um DFS. Essencialmente só muda a ordem em que se visita os nós, em vez de usarmos recursividade(e a pilha de recursão), vamos manter explicitamente uma fila de nós nao visitados (q)

**Pseudócodigo:**

```
bfs(nó v):
    q = 0 // Fila de nós não visitados
    q.enqueue(v)
    marcar v como visitado
    Enquanto q != 0 // Enquanto exisiterem nós por processar
        u = q.dequeue() // Retirar o primeiro elemento de q
        Para todos os nós w adjacente a u fazer
            Se w ainda não visitado **então // Novo nó
                q.enqueue(w)
                marcar w como visitado
```

--------------------------------------------------------------------

- Diâmetro ou raio de um grafo:

O diâmetro de um grafo é a maior distância existente entre dois nós do grafo. O raio de um grafo é a menor distância entre um nó e todos os outros nós do grafo. Utilizando a BFS, é possível calcular o diâmetro e o raio de um grafo encontrando o caminho mais longo e o caminho mais curto, respetivamente.

**Pseudócodigo:**

```
BFS_Diametro_Raio(nóInicial):
    fila = FilaVazia()
    marca nóInicial como visitado
    insere nóInicial na fila
    distâncias = DicionárioVazio()

    enquanto fila não estiver vazia:
        nóAtual = remove nó da fila

        para cada nó adjacente adj de nóAtual:
            se adj não foi visitado:
                marca adj como visitado
                insere adj na fila
                distânciaAdj = distâncias[nóAtual] + 1
                distâncias[adj] = distânciaAdj

    maiorDistancia = maior valor em distâncias
    menorDistancia = menor valor em distâncias

    retornar maiorDistancia, menorDistancia
```

------------------------------------------------------------

- Nó mais próximo/longe de um dado conjunto de nós:

Dado um conjunto de nós, é possível utilizar a BFS para encontrar o nó mais próximo ou mais distante desse conjunto. Ao aplicar a BFS a partir dos nós do conjunto, calcula-se a distância de cada nó a todos os nós do conjunto. Com isso, é possível determinar qual nó possui a menor ou a maior distância em relação ao conjunto.

**Pseudócodigo:**

```
BFS_NóMaisPróximoMaisLonge(nósConjunto):
    fila = FilaVazia()
    para cada nó em nósConjunto:
        marca nó como visitado
        insere nó na fila

    enquanto fila não estiver vazia:
        nóAtual = remove nó da fila

        para cada nó adjacente adj de nóAtual:
            se adj não foi visitado:
                marca adj como visitado
                insere adj na fila

    maiorDistancia = maior distância entre nósConjunto e os nós visitados
    menorDistancia = menor distância entre nósConjunto e os nós visitados

    retornar nó com a maiorDistancia, nó com a menorDistancia
```

---------------------------------------------------------------

- Calcular nós a uma dada distância:

Utilizando a BFS, é possível calcular todos os nós que estão a uma determinada distância de um nó inicial. A BFS visita os nós em camadas, começando pelo nó inicial. À medida que a BFS se expande para os nós adjacentes, é possível rastrear a distância de cada nó em relação ao nó inicial. Dessa forma, é possível identificar quais nós estão a uma determinada distância do nó inicial.

**Pseudócodigo:**

```
BFS_NósDadaDistância(nóInicial, distânciaDesejada):
    fila = FilaVazia()
    marca nóInicial como visitado
    insere nóInicial na fila
    distâncias = DicionárioVazio()
    distâncias[nóInicial] = 0

    enquanto fila não estiver vazia:
        nóAtual = remove nó da fila

        para cada nó adjacente adj de nóAtual:
            se adj não foi visitado:
                marca adj como visitado
                insere adj na fila
                distânciaAdj = distâncias[nóAtual] + 1
                distâncias[adj] = distânciaAdj

    nósDistânciaDesejada = nós com distância igual a distânciaDesejada

    retornar nósDistânciaDesejada
```


```c++
// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao limpa no final a memoria criada - a cada "new" deve corresponder um "delete")
#include <iostream>
#include <list>

using namespace std;

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) { // Constructor: chamado quando um objeto Graph for criado
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
  }

  ~Graph() { // Destructor: chamado quando um objeto Graph for destruido
    delete[] nodes;
  }

  void addLink(int a, int b) {
    nodes[a].adj.push_back(b);
    nodes[b].adj.push_back(a);
  }
  
  void bfs(int v) {
    list<int> q;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    
    q.push_back(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;

    while (q.size() > 0) {
      int u = q.front(); q.pop_front();
      cout << u << " [dist=" << nodes[u].distance << "]" << endl;
      for (auto w : nodes[u].adj)
        if (!nodes[w].visited) {
          q.push_back(w);
          nodes[w].visited  = true;
          nodes[w].distance = nodes[u].distance + 1; 	  
        }
    }
  }
};

int main() {
  int n, e, a, b;
  
  cin >> n;
  Graph g(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b;
    g.addLink(a, b);
  }

  // Pesquisa em largura a partir do no 1
  g.bfs(1);

  return 0;
}
```
---
### implementacao sem classes
```c++
// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (compilar com g++)

#include <cstdio>
#include <list>

using namespace std; // Para incluir o namespace std

#define MAX 100

typedef struct {
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia do no origem da pesquisa
} Node;

typedef struct {
  int n;
  Node nodes[MAX];
} Graph;

void addLink(Graph *g, int a, int b) {
  g->nodes[a].adj.push_back(b);
  g->nodes[b].adj.push_back(a);
}

void bfs(Graph *g, int v) {
  list<int> q;
  for (int i=1; i<=g->n; i++) g->nodes[i].visited = false;
  
  q.push_back(v);
  g->nodes[v].visited  = 1;
  g->nodes[v].distance = 0;

  while (q.size() > 0) {
    int u = q.front(); q.pop_front();
    printf("%d [dist=%d]\n", u, g->nodes[u].distance);
    for (auto w : g->nodes[u].adj)
      if (!g->nodes[w].visited) {
        q.push_back(w);
        g->nodes[w].visited  = true;
        g->nodes[w].distance = g->nodes[u].distance + 1; 	  
      }      
  }
}

int main() {
  int e, a, b;

  Graph g;
  scanf("%d", &g.n);
  scanf("%d", &e);
  for (int i=0; i<e; i++) {
    scanf("%d %d", &a, &b);
    addLink(&g, a, b);
  }
  
  // Pesquisa em largura a partir do no 1
  bfs(&g, 1);

  return 0;
}
```
---
## Diâmetro ou raio de um grafo
## Nó mais perto/longe de um dado conjunto de nós
### DAA030
Tens de ajudar um grupo de biólogos a analisarem uma rede de interação de proteínas. Os biológos resolveram modelar a rede como um grafo não dirigido e não pesado e estão interessados em dados sobre distâncias entre nós. Podes assumir que a rede que estão a estudar é completamente conexa, ou seja, existe um caminho entre qualquer par de nós do grafo associado.

Considera por exemplo a rede modelada pelo grafo da seguinte figura:



A distância mínima entre dois nós do grafo é o número mínimo de arestas num caminho entre esses dois nós. Para a rede da figura, uma matriz de distâncas mínimas seria:

| Nos | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|-----|---|---|---|---|---|---|---|---|
| 1   | --| 1 | 1 | 3 | 2 | 2 | 4 | 3 |
| 2   | 1 | --| 1 | 3 | 2 | 2 | 4 | 3 |
| 3   | 1 | 1 | --| 2 | 1 | 1 | 3 | 2 |
| 4   | 3 | 3 | 2 | --| 3 | 1 | 1 | 2 |
| 5   | 2 | 2 | 1 | 3 | --| 2 | 4 | 3 |
| 6   | 2 | 2 | 1 | 1 | 2 | --| 2 | 1 |
| 7   | 4 | 4 | 3 | 1 | 4 | 2 | --| 1 |
| 8   | 3 | 3 | 2 | 2 | 3 | 1 | 1 | --|

A excentricidade de um nó é igual à maior distância mínima dele próprio a um qualquer outro nó. Por exemplo:

`excentricidade(1) = 4`

`excentricidade(3) = 3`

Os biólogos estão a tentar perceber a importância dos vários nós e por isso querem saber várias coisas sobre a excentricidade. Em particular, desejam saber as seguintes propriedades da rede:

*Diâmetro:* é igual ao maior caminho mínimo entre dois nós, ou seja, à máxima excentricidade. Para o exemplo dado o diâmetro é 4.

*Raio:* é igual à menor excentricidade de um nó. Para o exemplo dado o raio é 2.

*Nós centrais:* os que têm excentricidade mínima (igual ao raio) são considerados centrais. Para o exemplo dado o único nó central é o 6.

*Nós periféricos:* todos os nós para quais existe um nó à máxima distância mínima, ou seja, se um grafo tem diâmetro d, são os nós que têm pelo menos um outro nó à distância mínima de d. 

Para o exemplo dados os nós periféricos são o `1, 2, 5 e 7`.
Tens de ajudar os biólogos a conseguirem estes dados.

**Tarefa**

Dada um grafo conexo não dirigido e não pesado descrevendo uma rede biológica, a tua tarefa é calcular o seu diâmetro, o seu raio, quais os nós centrais e quais os nós periféricos.

**Input**

Na primeira linha vem um único número inteiro N indicando o número de nós do grafo a considerar. Os nós são identificados por números inteiros consecutivos de 1 até N.

Na segunda linha vem um único número inteiro E indicando o número de arestas do grafo. Seguem-se E linhas, cada uma contendo dois inteiros A e B indicando que existe uma aresta (ligação direta) entre os nós A e B.

As arestas podem vir por qualquer ordem mas é garantido que nunca aparecem arestas repetidas. É também garantido que dão origem a um grafo completamente conexo.

O exemplo de input corresponde à figura dada anteriormente.

**Output**
- Na primeira linha deve vir um único inteiro indicando o diâmetro da rede.

- Na segunda linha deve vir um único inteiro indicando o raio.

- Na terceira linha devem vir os nós centrais. Se existir mais que um nó central, deves escrevê-los por ordem crescente e com um espaço a separar cada par de nós.

- Na quarta linha devem vir os nós periféricos. Se existir mais que um nó periférico, deves escrevê-los por ordem crescente e com um espaço a separar cada par de nós.

Restrições
São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
```
1 ≤ N ≤ 1500	   	Número de nós
1 ≤ E ≤ 5000	   	Número de arestas (ligações)
```
**Exemplo de Input**
```
8
9
1 3
2 3
3 5
3 6
6 4
6 8
4 7
1 2
8 7
```
**Exemplo de Output**
```
4
2
6
1 2 5 7
```
- Resolução de alguém
```c++
#include <iostream>
#include <list>
#include <climits>
#include <set>
#define MAX 1505

using namespace std;

int n;
int matriz[MAX][MAX];

// Classe que representa um nó
class Node {
public:
  list<int> adj;  // Lista de adjacências
  bool visited;   // Indica se foi visitado em uma pesquisa
  int distance;   // Distância até o nó de origem da pesquisa

  Node() {
    // Construtor vazio
  };
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Número de nós do grafo
  Node *nodes;    // Array para conter os nós

  Graph(int n) {
    this->n = n;
    nodes = new Node[n + 1];  // +1 se os nós começam em 1 ao invés de 0
  }

  void addLink(int a, int b) {
    nodes[a].adj.push_back(b);
    nodes[b].adj.push_back(a);
  }

  void bfs(int v) {
    list<int> q;
    for (int i = 1; i <= n; i++) {
      nodes[i].visited = false;
    }

    q.push_back(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;
    matriz[v][v] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop_front();
      for (auto w : nodes[u].adj) {
        if (!nodes[w].visited) {
          q.push_back(w);
          nodes[w].visited = true;
          nodes[w].distance = nodes[u].distance + 1;
          matriz[v][w] = nodes[w].distance;
        }
      }
    }
  }
};

int excentricidade(int v) {
  int max_distance = 0;
  for (int i = 1; i <= n; i++) {
    if (max_distance <= matriz[v][i]) {
      max_distance = matriz[v][i];
    }
  }
  return max_distance;
}

int main() {
  int e, a, b;

  set<int> centrais;
  set<int> perifericos;

  cin >> n;

  Graph *g = new Graph(n);

  cin >> e;
  for (int i = 0; i < e; i++) {
    cin >> a >> b;
    g->addLink(a, b);
  }

  // Executa a busca em largura a partir de cada nó
  for (int i = 1; i <= n; i++) {
    g->bfs(i);
  }

  int diametro = 0;
  int excentricidade_atual = 0;
  int raio = INT_MAX;

  // Calcula o diâmetro e o raio do grafo
  for (int i = 1; i <= n; i++) {
    excentricidade_atual = excentricidade(i);
    if (diametro <= excentricidade_atual) {
      diametro = excentricidade_atual;
    }
    if (raio >= excentricidade_atual) {
      raio = excentricidade_atual;
    }
  }

  // Imprime o diâmetro e o raio
  cout << diametro << '\n';
  cout << raio << '\n';

  // Encontra os nós centrais e periféricos
  for (int i = 1; i <= n; i++) {
    excentricidade_atual = excentricidade(i);
    if (raio == excentricidade_atual) {
      centrais.insert(i);
    }
    if (diametro == excentricidade_atual) {
      perifericos.insert(i);
    }
  }

  // Imprime os nós centrais
  int size = centrais.size();
  int incr = 0;

  for (int i : centrais) {
    incr++;
    if (size == incr) {
      cout << i;
    } else {
      cout << i << " ";
    }
  }
  putchar('\n');

  // Imprime os nós periféricos
  size = perifericos.size();
  incr = 0;
  for (int i : perifericos) {
    incr++;
    if (size == incr) {
      cout << i;
    } else {
      cout << i << " ";
    }
  }
  putchar('\n');

  return 0;
}
```
## Calcular nós a uma dada distância
## DAA031
É o caos nos aeroportos! Um vulcão acaba de entrar em erupção provocando uma nuvem de cinzas que se alastra e impede a circulação aérea. O governo da Onilândia está muito preocupado e quer saber quando é que a nuvem de cinzas irá atingir os aeroportos onilandeses.

O governo tem acesso a um mapa obtido via satélite que detalha a situação corrente. O mapa é um rectângulo que está dividido em quadrículas mais pequenas. Tendo em conta a situação em análise, apenas são distinguidos três tipos de quadrículas: nuvem (indicando que esse sector do mapa está neste momento coberto por uma nuvem de cinzas), aeroporto (letra 'A', indicando que esse sector do mapa contém um aeroporto) e todas as outras (que não têm neste momento nem uma nuvem nem um aeroporto). Um exemplo de um mapa seria o indicado na figura seguinte:



À medida que o tempo vai passando a situação vai piorando. De facto, por cada dia que passa, a nuvem expande-se uma quadrícula na horizontal e na vertical. Dito de outro modo, ao fim de um dia, todas as quadrículas que estavam adjacentes (vertical ou horizontalmente) a uma quadrícula com nuvem, passam também elas a conter nuvens. Exemplificando a evolução da situação ao fim de dois dias, teríamos o seguinte:

				
Para preparar convenientemente os planos de contingência, o governo necessita de saber duas coisas: quantos dias demorará até pelo menos um aeroporto ficar coberto pela nuvem e daqui a quantos dias os aeroportos estarão todos eles cobertos pela nuvem. Tens de ajudar!

**O Problema**

Dado um quadriculado de L linhas por C colunas indicando a posição actual da nuvem e dos aeroportos, a tua tarefa é descobrir Nmin, o número de dias até um primeiro aeroporto ficar debaixo da nuvem de cinzas e Nmax, o número de dias até todos os aeroportos ficarem cobertos pelas cinzas.

**Input**

Na primeira linha do input vem dois números inteiros L e C, separados por um espaço, indicando respectivamente o número de linhas e o número de colunas do mapa.

Seguem-se exactamente L linhas, cada uma contendo exactamente C caracteres, descrevendo o mapa. Cada um dos caracteres pode ser:

- '#', indicando que a quadrícula tem presentemente uma nuvem
- 'A', indicando que a quadrícula tem um aeroporto
- '.', indicando que a quadrícula não tem neste momento uma nuvem nem um aeroporto

Existe sempre pelo menos uma quadrícula com nuvem e uma quadrícula com um aeroporto, mas não deves assumir à partida mais nada sobre as outras quadrículas.

**Output**

O output deve ser constituído exactamente por uma única linha contendo dois números inteiros Nmin e Nmax, separados por um único espaço, indicando respectivamente o número de dias até que um primeiro aeroporto fique coberto pela nuvem e o número de dias até que todos os aeroportos fiquem cobertos.

**Restrições**

São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
```
1 ≤ L ≤ 250	     	Número de linhas do mapa
1 ≤ C ≤ 250	     	Número de colunas do mapa
```
**Exemplo de Input**

```
7 8
..#...##
.##.....
###.A..A
.#......
.#....A.
...A....
........
```
**Exemplo de Output**

```
2 4
```

- Resolucao Rodrigo

```c++
#include <iostream>
#include <list>
#include <climits>
using namespace std;

#define MAX 255
#define INC 4
#define CLOUD '#'
#define AIRP 'A'
#define EMPTY '.'

int rows, cols;
char m[MAX][MAX];
bool visited[MAX][MAX];
int distMin[MAX][MAX];

int incx[INC] = {-1, 1, 0, 0};
int incy[INC] = { 0, 0,-1, 1};

int nAirports;

class Point {
public:
    int x;
    int y;
    int dist;

    Point(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

void bfs(){
    list<Point*> q;
    list<int> result;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] == AIRP) nAirports++;
            if (m[i][j] == CLOUD) {
                Point *u = new Point(i,j,0);
                q.push_back(u);
                visited[i][j] = true;
                distMin[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        Point *u = q.front(); q.pop_front();

        for (int k = 0; k < INC; k++) {
            int xp2 = u->x + incx[k];
            int yp2 = u->y + incy[k];
            if (xp2 >= 0 && xp2 < rows && yp2 >= 0 && yp2 < cols && !visited[xp2][yp2]) {
                Point *w = new Point(xp2,yp2, u->dist+1);
                q.push_back(w);
                distMin[xp2][yp2] = w->dist + 1;
                visited[xp2][yp2] = true;

                if (m[xp2][yp2] == AIRP) 
                    result.push_back(u->dist+1);
            }
        }
    }

    int min = INT_MAX;
    int max = 0;

    for (int t : result) {
        if (t > max) max = t;
        if (t < min) min = t;
    }
    printf("%d %d\n", min, max);
}

int main() {
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++)
        cin >> m[i];
    
    bfs();
    
    return 0;
}
```

- Resolucao Marisa
```c++
#include <iostream>
#include <vector>
#include <queue>

#define MAX_ROWS 255
#define MAX_COLS 255
#define NDIRS 4

using namespace std;

int numRows, numCols;

int dx[NDIRS] = {0, 0, +1, -1};
int dy[NDIRS] = {+1, -1, 0, 0};

struct Position {
    int y;
    int x;
    int distance;
};

// Verifica se uma posição (y, x) é válida dentro do mapa
bool isValidPosition(int y, int x) {
    if (y >= 0 && x >= 0 && y < numRows && x < numCols)
        return true;
    return false;
}

// Encontra as distâncias até os aeroportos no mapa
vector<int> findAirportDistances(string map[]) {
    vector<vector<int>> visited(numRows, vector<int>(numCols, -1)); // Matriz de visitados para marcar as posições já visitadas
    vector<int> distancesToAirport; // Vetor para armazenar as distâncias até aos aeroportos
    queue<Position> q; // Fila de posições

    // Preenche a fila inicial com as posições das nuvens ('#')
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (map[i][j] == '#')
                q.push({i, j, 0}); // Insere a posição na fila com distância zero
        }
    }

    while (!q.empty()) {
        Position current = q.front(); // Obter a posição atual da frente da fila
        q.pop(); // Remove a posição da fila

        int currentY = current.y; // Coordenada Y da posição atual
        int currentX = current.x; // Coordenada X da posição atual
        int distance = current.distance; // Distância até a posição atual

        for (int i = 0; i < NDIRS; i++) { // Para cada direção (cima, baixo, esquerda, direita)
            int nextY = currentY + dy[i]; // Calcula a próxima linha
            int nextX = currentX + dx[i]; // Calcula a próxima coluna

            // Verifica se a próxima posição é válida, se não contém uma nuvem ('#') e se ainda não foi visitada
            if (isValidPosition(nextY, nextX) && map[nextY][nextX] != '#' && visited[nextY][nextX] == -1) {
                if (map[nextY][nextX] == 'A')
                    distancesToAirport.push_back(distance + 1); // Se a próxima posição contém um aeroporto adiciona a distância até ele
                q.push({nextY, nextX, distance + 1}); // Adiciona a próxima posição à fila com a distância atualizada
                visited[nextY][nextX] = distance + 1; // Marca a próxima posição como visitada com a distância atualizada
            }
        }
    }

    return distancesToAirport; // Retorna o vetor de distâncias até os aeroportos
}

int main() {
    cin >> numRows >> numCols;
    string map[MAX_ROWS];
    for (int i = 0; i < numRows; i++) {
        cin >> map[i];
    }
    vector<int> airportDistances = findAirportDistances(map);
    cout << airportDistances[0] << " " << airportDistances[airportDistances.size() - 1] << "\n";
    return 0;
}
```


---
---
---
---
# PROBLEMA C - Saber usar o algoritmo de Dijkstra para calcular distâncias num grafo pesado
```cpp
// (assumindo um grafo pesado e dirigido, sem pesos negativos)

#include <iostream>
#include <climits>
#include <list>
#include <set>

using namespace std;

// Classe que representa um no
class Node {
public:
  list<pair<int, int>> adj;  // Lista de adjacencias
  bool visited;              // No ja foi visitado?
  int distance;              // Distancia ao no origem da pesquisa
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) { // Constructor: chamado quando um objeto Graph for criado
    this->n = n;
    nodes = new Node[n+1];  // +1 se os nos comecam em 1 ao inves de 0
  }
  
  ~Graph() { // Destructor: chamado quando um objeto Graph for destruido
    delete[] nodes;
  }
  
  void addLink(int a, int b, int c) {
    nodes[a].adj.push_back({b,c});
  }

  // Algoritmo de Dijkstra
  void dijkstra(int s) {
    
    //Inicializar nos como nao visitados e com distancia infinita
    for (int i=1; i<=n; i++) {
      nodes[i].distance = INT_MAX;
      nodes[i].visited  = false;
    }
    
    // Inicializar "fila" com no origem
    nodes[s].distance = 0;
    set<pair<int, int>> q; // By "default" um par e comparado pelo primeiro elemento 
    q.insert({0, s});      // Criar um par (dist=0, no=s)

    // Ciclo principal do Dijkstra
    while (!q.empty()) {
      
      // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
      int u = q.begin()->second;
      q.erase(q.begin());
      nodes[u].visited = true;
      cout << u << " [dist=" << nodes[u].distance << "]" << endl;

      // Relaxar arestas do no retirado
      for (auto edge : nodes[u].adj) {
        int v = edge.first;
        int cost = edge.second;
        if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
          q.erase({nodes[v].distance, v});  // Apagar do set
          nodes[v].distance = nodes[u].distance + cost;
          q.insert({nodes[v].distance, v}); // Inserir com nova (e menor) distancia
        }
      }
    }
  }
};

int main() {
  int n, e, a, b, c;
  
  cin >> n;
  Graph g(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b >> c;
    g.addLink(a, b, c);
  }

  // Execucao exemplo a partir do no 1
  g.dijkstra(1);

  return 0;
}
```
## Nó mais perto/longe de um dado conjunto de nós
## Calcular nós a uma dada distância
### DAA033
Aniceto é um caloiro que estuda no Departamento de Ciência de Computadores da FCUP. O seu grande problema é que a maior parte das aulas foram marcadas para muito cedo, e como ele não conhece muito sobre a cidade do Porto, por vezes perde-se e não chega a horas...

Estudioso como é, arranjou um mapa das estradas, e resolveu que ia fazer um programa para o ajudar, procurando que este lhe desse o caminho mínimo entre a sua casa e o DCC. O problema é que ele não está a ver que tipo de algoritmo pode usar! Claro que se lembrou da UC de Desenho e Análise de Algoritmos e veio falar contigo. Prontamente, disseste-lhe que isso era um problema de grafos, e que não terias problemas em ajudá-lo. O Aniceto deu-te então o mapa e a tua tarefa é descobrir qual o caminho mínimo da sua casa até ao Departamento.

Obviamente que na tua infinita generosidade, decidiste fazer um programa mais geral, que ajudasse todos os alunos que chegam atrasados às aulas...

**O Problema**

Dado um mapa de de estradas, a localização duma casa e a localização das aulas teóricas, a tua tarefa é escrever um programa indicando qual a distância mínima a percorrer desde a casa até às aulas.

**Input**

A primeira linha contém dois números: N , o número de pontos ou sítios diferentes no mapa e E, o número de estradas.

De seguida vem uma linha indicando primeiro o sítio onde fica a casa do Aniceto, seguido do local das aulas (o seu destino, portanto).

Seguem-se de E linhas, indicando quais os pontos que a estrada liga, e o comprimento (em Km) da estrada que os liga, no formato ponto_1 ponto_2 comprimento_estrada. O comprimento da estrada não ultrapassa os 1000 Km e não é necessariamente um número inteiro. Podes assumir que as estradas têm sempre dois sentidos (isto é, quando existe estrada de A para B, automaticamente também existe uma de B para A, com a mesma distancia).

Cada ponto é representado por uma palavra contendo apenas letras mínusculas ou hifens (-), tendo no máximo 30 caracteres.

**Output**

Deve ser imprimida uma única linha, contendo a distância mínima a percorrer para ir da casa do Aniceto até ao local das aulas (a distância deve vir arredondada a uma casa decimal).

Podes assumir que existe sempre pelo menos um caminho entre a casa do Aniceto e o seu destino.

**Restrições**

São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
```
2 ≤ N ≤ 1000	   	Número de nós
1 ≤ E ≤ 5000	   	Número de arestas (ligações)
```
**Exemplo de Input**
```
11 15
ermesinde dcc
ermesinde s-joao 20.2
ermesinde freixo 18.6
s-joao aliados 2.3
aliados palacio 1.0
palacio dcc 1.2
freixo campo-alegre 4.1
campo-alegre dcc 0.4
campo-alegre palacio 0.8
s-joao campo-alegre 2.3
freixo lisboa 322.1
freixo arrabida 4.9
arrabida lisboa 321.8
lisboa algarve 350.2
algarve covilha 451.2
covilha freixo 245.1
```
**Exemplo de Output**
```
22.9
```
Explicação do Input/Output
O exemplo de input corresponde ao seguinte grafo:
- Resolução Joao
```c++
#include <cstdio>
#include <iostream>
#include <climits>
#include <list>
#include <set>

using namespace std;

#define MAX 1000 // Maxima quantidade de nos
string arrayNomes[MAX];
int indiceNomes=0;

typedef struct {
  list<pair<int, double>> adj;  // Lista de adjacencias
  bool visited;              // No ja foi visitado?
  double distance;              // Distancia ao no origem da pesquisa
} Node;

// Classe que representa um grafo
typedef struct {
  int n;           // Numero de nos do grafo
  Node nodes[MAX]; // Array para conter os nos
} Graph;

void addLink(Graph *g, int a, int b, double c) {
  g->nodes[a].adj.push_back({b,c});
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
  set<pair<double,int>> q; // By "default" um par e comparado pelo primeiro elemento
  q.insert({0, s});      // Criar um par (dist=0, no=s)

  // Ciclo principal do Dijkstra
  while (!q.empty()) {

    // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
    int u = q.begin()->second;
    q.erase(q.begin());
    g->nodes[u].visited = true;
    // printf("%d [dist=%lf]\n", u, g->nodes[u].distance);

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

int find(string a) {
  for (int i = 0 ; i < indiceNomes ; i++) {
    if (arrayNomes[i] == a ) 
      return i;
  }
  arrayNomes[indiceNomes++] = a;
  return indiceNomes-1;
}


int main () {
  Graph *g = new Graph;
  int n,e; double tmpValue;
  string tmp1,tmp2;
  cin >> n >> e;
  g->n = n;
  cin >> tmp1 >> tmp2;
  find(tmp1); find(tmp2);
  for (int i = 0; i<e;i++){
    cin >> tmp1 >> tmp2 >> tmpValue;
    addLink(g, find(tmp1),find(tmp2),tmpValue);
    addLink(g, find(tmp2),find(tmp1),tmpValue);
    // cout << tmp1 << " " <<  tmp2 << " " <<  tmpValue << " " << indiceNomes << endl;
  }

  dijkstra(g,0);
  printf("%.1lf\n",g->nodes[1].distance);

  return 0;
}
```

## Caminho mínimo entre dois nós
### DAA035
Uma companhia áerea tem vários voos. O seu departamento de Marketing resolveu criar uma página na internet indicando que cidades estão ligadas por voos da companhia.

**O Problema**

A tua tarefa é ajudá-los, fazendo um programa que descubra que cidades estão ligadas por voos, quer directamente, quer indirectamente, através de outros voos, passando por cidades intermédias.

**Input**

A primeira linha contém um único inteiro N, o número de cidades a considerar. Cada cidade é representada por uma letra maiúscula, começando a partir do A. Por exemplo, se tivermos 4 cidades, serão representadas por A, B, C e D.

Seguem-se N linhas, cada uma indicando os voos directos entre a cidade correspondente e outras cidades, no formato: cidade-origem num_destinos destino_1 destino_2 ... destino_m.

Existe uma linha para cada cidade (mesmo que não tenha voos) e as cidades-origem vêm sempre por ordem alfabética. Nota que o facto de existir um voo de A para B não significa que exista um voo de B para A.

**Output**

Deve ser imprimida uma matriz, de N por N, indicando todas as cidades que estão ligadas, no formato:
```
  A B C ...
A 1 0 0 ...
B 1 1 1 ...
C 0 0 1 ...
. . . . ...
. . . . ...
. . . . ...
```
0 (zero) significa que não existe maneira de chegar de uma cidade a outra e 1 (um) precisamente o contrário, ou seja, que existe maneira (directa ou indirecta) de o fazer.

Podes assumir que na diagonal principal vêm sempre uns, ou seja, é sempre possível viajar de uma cidade para ela própria (basta não sair do sitio...)

Nota que não devem existir espaços a mais no final de cada linha do input (existe um único espaço a separar cada letra ou número, excepto no caso da primeira linha, onde o A é precedido de dois espaços, de modo a que a tabela fique alinhada).

Restrições
```
São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:

2 ≤ N ≤ 26	   	Número de cidades
```
**Exemplo de Input**
```
4
A 1 B
B 2 A C
C 0
D 1 C
```
**Exemplo de Output**
```
  A B C D
A 1 1 1 0
B 1 1 1 0
C 0 0 1 0
D 0 0 1 1
```
**Explicação do Input/Output**

O exemplo de input corresponde ao seguinte grafo:


```
Da cidade A consegue chegar-se às cidades A, B e C.
Da cidade B consegue chegar-se às cidades A, B e C.
Da cidade C consegue chegar-se apenas a si própria
Da cidade D consegue chegar-se às cidades C e D.
```
- Resolucao joao
```c++
#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 30

int N;
bool adj[MAX][MAX];
int distancia[MAX][MAX];


void floyd_warshall(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i == j) distancia[i][j] = 1;
      else if(adj[i][j]) distancia[i][j] = 1;
      else distancia[i][j] = 0;
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
 if(adj[j][i] && adj[i][k]){
   distancia[j][k] = 1;
   adj[j][k] = true;
 }
      }
    }
  }
}

void imprimir(){
  for(int i = -1; i < N; i++){
    for(int j = -1; j < N; j++){
      if(i == -1){
 if(j == -1)printf(" ");
 else printf(" %c", (char)(j+'A'));
 //if(j != N) printf(" ");
      }
      else if(j == -1){
 printf("%c", (char)(i+'A'));
      }
      else{
        printf(" %d", distancia[i][j]);
 //if(j != N) printf(" ");
      }
    }
    putchar('\n');
  }
}

int main(){
  int k;
  char cidade1, cidade2;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    cin >> cidade1 >> k;
    for(int j = 0; j < k; j++){
      cin >> cidade2;
      adj[cidade1 - 'A'][cidade2 - 'A'] = true;
    }
  }


  floyd_warshall();

  imprimir();
  
  return 0;
}
```
Para este problema é garantido que os pesos não são negativos (sendo que por isso não precisará de um Bellman-Ford).

Se optar por algo como um Floyd-Warshall (ou Bellman-Ford) poderá não ter a cotação completa. 

Para além disso, para ter 100% será necessário ter uma implementação eficiente em O(E|log|V|) (ou seja, com uma fila de prioridade
 . Uma implementação quadrática dará apenas pontuação parcial.

 ---
 ---
 ---
 ---
 ---
-------------------------------------------------------

## Syntaxe

1. - Como criar um Vetor:

- vector<int> vetor;

2. - Como criar uma Lista:

- list<int> lista;

3. - Como criar um Mapa:

- map<string, int> mapa; // mapa vazio com chaves de string e valores inteiros

4. - Como criar um Conjunto:

- set<int> conjunto; // conjunto vazio de inteiros

5. - Como criar um Conjunto de pares de inteiros:

- set<pair<int, int>> q;

6. - Como criar uma Lista de Pares de um Inteiro e Float:

- list<pair<int, float>> adj;

7. - Como criar um Vetor de Vetores de Inteiros

- vector<vector<int>> matrix;
