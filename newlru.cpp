#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findLRUIndex(vector<int> &counter) {
  int minIndex = 0;
  for (int i = 1; i < counter.size(); ++i) {
    if (counter[i] < counter[minIndex]) {
      minIndex = i;
    }
  }
  return minIndex;
}

int main() {
  int numFrames, numPages;
  cout << "Enter the number of frames: ";
  cin >> numFrames;
  cout << "Enter the number of pages: ";
  cin >> numPages;

  vector<int> frameList(numFrames, -1);
  vector<int> counter(numFrames, 0);
  map<int, int> pageTable;

  cout << "Enter the page reference string: ";
  vector<int> pageReference(numPages);
  for (int i = 0; i < numPages; ++i) {
    cin >> pageReference[i];
  }

  for (int i = 0; i < numPages; ++i) {
    int page = pageReference[i];

    if (pageTable.find(page) != pageTable.end()) {
      counter[pageTable[page]] = i;
    } else {
      int lruIndex = findLRUIndex(counter);
      pageTable.erase(frameList[lruIndex]);
      pageTable[page] = lruIndex;
      frameList[lruIndex] = page;
      counter[lruIndex] = i;
    }

    cout << "Page" << setw(4) << page;
    for (int j = 0; j < numFrames; ++j) {
      if (frameList[j] == -1) {
        cout << setw(6) << "0";
      } else {
        cout << setw(6) << frameList[j];
      }
    }
    cout << endl;
  }

  int pageFaults = 0;
  for (int i = 0; i < numFrames; ++i) {
    if (frameList[i] != -1) {
      pageFaults++;
    }
  }
  cout << "Total page faults: " << pageFaults << endl;

  return 0;
}