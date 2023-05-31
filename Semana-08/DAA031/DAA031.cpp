#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define MAX 251

#define CLOUD '#'
#define AIRPORT 'A'
#define FREE '.'

char map[MAX][MAX];
bool visited[MAX][MAX];

int l, c; // linhas, colunas
int numAirp = 0; // número de aeroportos
int AirpSalvos = 0; // número de aeroportos salvos
int maxDias = 0; // máximo de dias
int minDias = MAX; // mínimo de dias

bool isInside(int x, int y) {
  return (x >= 0 && y >= 0 && x < l && y < c);
}

// Classe que representa um Ponto
class Point {
public:
  int x;
  int y;
  int days;
  char type;

  Point(int x, int y, int days, char type) {
    this->x = x;
    this->y = y;
    this->days = days;
    this->type = type;
  }
};

queue<pair<Point, int>> q; // pair of Point and days

void bfs() {
  while (!q.empty()) {
    pair<Point, int> buf = q.front();
    q.pop();

    Point point = buf.first;
    int days = buf.second;

    if (visited[point.x][point.y]) continue;
    visited[point.x][point.y] = true;

    if (point.type == AIRPORT) {
      if (days < minDias) minDias = days;
      AirpSalvos--;
      if (AirpSalvos == 0) {
        maxDias = max(days, maxDias);
        return;
      }
    }

    int x = point.x;
    int y = point.y;

    if (isInside(x + 1, y) && !visited[x + 1][y] && map[x + 1][y] != CLOUD) {
      Point p(x + 1, y, days + 1, map[x + 1][y]);
      q.push(make_pair(p, days + 1));
    }

    if (isInside(x - 1, y) && !visited[x - 1][y] && map[x - 1][y] != CLOUD) {
      Point p(x - 1, y, days + 1, map[x - 1][y]);
      q.push(make_pair(p, days + 1));
    }

    if (isInside(x, y + 1) && !visited[x][y + 1] && map[x][y + 1] != CLOUD) {
      Point p(x, y + 1, days + 1, map[x][y + 1]);
      q.push(make_pair(p, days + 1));
    }

    if (isInside(x, y - 1) && !visited[x][y - 1] && map[x][y - 1] != CLOUD) {
      Point p(x, y - 1, days + 1, map[x][y - 1]);
      q.push(make_pair(p, days + 1));
    }
  }
}

int main() {
  cin >> l >> c;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      cin >> map[i][j];
      if (map[i][j] == AIRPORT) {
        numAirp++;
      }
    }
  }

  AirpSalvos = numAirp;

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      visited[i][j] = false;
      if (map[i][j] == CLOUD) {
        Point p(i, j, 0, CLOUD);
        q.push(make_pair(p, 0));
      }
    }
  }

  bfs();

  cout << minDias << " " << maxDias << endl;

  return 0;
}
