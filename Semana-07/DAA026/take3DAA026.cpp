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
