#include <iostream>
using namespace std;

const int max_pro = 10;
const int max_res = 10;
int main() {
  int n, m;
  cout << "Enter number of Processes: ";
  cin >> n;
  cout << "Enter number of Resources: ";
  cin >> m;
  int alloc[max_pro][max_res];
  int max[max_pro][max_res];
  int avail[max_res];
  int need[max_pro][max_res];

  // input allocation matrix
  cout << "Enter allocation matrix: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> alloc[i][j];
    }
  }
  // input max matrix
  cout << "Enter max matrix: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> max[i][j];
    }
  }
  // input available vector
  cout << "Enter available vector: " << endl;
  for (int i = 0; i < m; i++) {
    cin >> avail[i];
  }
  // calc need matrix
  cout << "Need matrix: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
      cout << need[i][j] << " ";
    }
    cout << endl;
  }
  bool safe = false;
  bool marked[max_pro] = {false};
  int safeseq[max_pro];
  int safeindex = 0;
  while (!safe) {
    safe = true;
    for (int i = 0; i < n; i++) {
      if (!marked[i]) {
        bool canExecute = true;
        for (int j = 0; j < m; j++) {
          if (need[i][j] > avail[j]) {
            canExecute = false;
            break;
          }
        }
        if (canExecute) {
          marked[i] = true;
          safeseq[safeindex++] = i;
          for (int j = 0; j < m; j++) {
            avail[j] += alloc[i][j];
          }
          safe = false;
        }
      }
    }
  }
  // print safe seq
  cout << "Safe sequence: " << endl;
  for (int i = 0; i < safeindex; i++) {
    cout << "P" << safeseq[i] << " ";
  }
  cout << endl;

  return 0;
}