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

