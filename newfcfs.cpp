#include <iostream>
using namespace std;

struct Process {
  int id;
  int arrivaltime;
  int bursttime;
  int completiontime;
  int waitingtime;
  int turnaroundtime;
};

void customSwap(Process &a, Process &b) {
  Process temp = a;
  a = b;
  b = temp;
}

void selectionSort(Process processes[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    int minindex = i;
    for (int j = i + 1; j < n; ++j) {
      if (processes[j].arrivaltime < processes[minindex].arrivaltime)
        minindex = j;
    }
    if (minindex != i)
      customSwap(processes[i], processes[minindex]);
  }
}

void calculateCompletionTime(Process processes[], int n) {
  int currentTime = 0;
  for (int i = 0; i < n; ++i) {
    if (currentTime < processes[i].arrivaltime)
      currentTime = processes[i].arrivaltime;
    processes[i].completiontime = currentTime + processes[i].bursttime;
    currentTime = processes[i].completiontime;
  }
}

void calculateWaitingTime(Process processes[], int n) {
  for (int i = 0; i < n; ++i) {
    processes[i].waitingtime = processes[i].completiontime -
                               processes[i].arrivaltime -
                               processes[i].bursttime;
  }
}

void calculateTurnaroundTime(Process processes[], int n) {
  for (int i = 0; i < n; ++i) {
    processes[i].turnaroundtime =
        processes[i].completiontime - processes[i].arrivaltime;
  }
}

void displayResults(Process processes[], int n) {
  cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting "
          "Time\tTurnaround Time\n";
  for (int i = 0; i < n; ++i) {
    cout << processes[i].id << "\t\t" << processes[i].arrivaltime << "\t\t"
         << processes[i].bursttime << "\t\t" << processes[i].completiontime
         << "\t\t" << processes[i].waitingtime << "\t\t"
         << processes[i].turnaroundtime << "\n";
  }
}

int main() {
  int n;
  cout << "Enter the number of processes: ";
  cin >> n;

  Process processes[n];
  for (int i = 0; i < n; ++i) {
    cout << "Enter arrival time for process " << i + 1 << ": ";
    cin >> processes[i].arrivaltime;
    cout << "Enter burst time for process " << i + 1 << ": ";
    cin >> processes[i].bursttime;
    processes[i].id = i + 1;
  }

  selectionSort(processes, n);
  calculateCompletionTime(processes, n);
  calculateWaitingTime(processes, n);
  calculateTurnaroundTime(processes, n);
  displayResults(processes, n);

  double avgWaitingTime = 0, avgTurnaroundTime = 0, avgCompletionTime = 0;
  for (int i = 0; i < n; ++i) {
    avgWaitingTime += processes[i].waitingtime;
    avgTurnaroundTime += processes[i].turnaroundtime;
    avgCompletionTime += processes[i].completiontime;
  }
  avgWaitingTime /= n;
  avgTurnaroundTime /= n;
  avgCompletionTime /= n;

  cout << "Average Waiting Time: " << avgWaitingTime << endl;
  cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
  cout << "Average Completion Time: " << avgCompletionTime << endl;

  return 0;
}
