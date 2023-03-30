#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int cobrir; // [0,cobrir]
    cin >> cobrir;

    int n;
    cin >> n;

    vector<pair<int, int>> intervalos(n);

    for (int i = 0; i < n; i++) {
        cin >> intervalos[i].first >> intervalos[i].second;
    }

    sort(intervalos.begin(), intervalos.end());

    int cont = 0;
    int max = 0;

    for (int i = 0; i <= cobrir; i = max) {
        for (int j = 0; j < n; j++) {
            if (intervalos[j].first <= i ) {
                if (intervalos[j].second > max) {
                    max = intervalos[j].second;
                }
            } else {
                break;
            }
        }
        cont++;
        if (max >= cobrir) break;
    }

    cout << cont << endl;

    return 0;
}
