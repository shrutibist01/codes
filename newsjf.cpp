#include <algorithm>
#include <iostream>

using namespace std;

class Process {
public:
  int id;
  int bt;
  int at;
  int ct;
  int tat;
  int wt;

  Process() : id(0), bt(0), at(0), ct(0), tat(0), wt(0) {}
};

bool compareArrivalTime(Process a, Process b) { return a.at < b.at; }

bool compareBurstTime(Process a, Process b) { return a.bt < b.bt; }

void calculateCompletionTime(Process proc[], int n) {
  int currentTime = 0;
  for (int i = 0; i < n; ++i) {
    if (currentTime < proc[i].at)
      currentTime = proc[i].at;
    currentTime += proc[i].bt;
    proc[i].ct = currentTime;
  }
}

void calculateTurnaroundTime(Process proc[], int n) {
  for (int i = 0; i < n; ++i)
    proc[i].tat = proc[i].ct - proc[i].at;
}

void calculateWaitingTime(Process proc[], int n) {
  for (int i = 0; i < n; ++i)
    proc[i].wt = proc[i].tat - proc[i].bt;
}

int main() {
  int n;
  cout << "Enter the number of processes: ";
  cin >> n;

  Process proc[n];

  cout << "Enter arrival time and burst time for each process:\n";
  for (int i = 0; i < n; i++) {
    proc[i].id = i + 1;
    cout << "Process " << i + 1 << " - Arrival Time: ";
    cin >> proc[i].at;
    cout << "Process " << i + 1 << " - Burst Time: ";
    cin >> proc[i].bt;
  }

  // Sort processes based on arrival time
  sort(proc, proc + n, compareArrivalTime);

  // Sort processes based on burst time
  sort(proc, proc + n, compareBurstTime);

  calculateCompletionTime(proc, n);
  calculateTurnaroundTime(proc, n);
  calculateWaitingTime(proc, n);

  cout << "Process\tBurst Time\tArrival Time\tCompletion Time\tTurnaround "
          "Time\tWaiting Time\n";
  for (int i = 0; i < n; i++) {
    cout << proc[i].id << "\t\t" << proc[i].bt << "\t\t" << proc[i].at << "\t\t"
         << proc[i].ct << "\t\t" << proc[i].tat << "\t\t" << proc[i].wt << endl;
  }

  // Calculate average turnaround time and average waiting time
  double totalTAT = 0, totalWT = 0;
  for (int i = 0; i < n; i++) {
    totalTAT += proc[i].tat;
    totalWT += proc[i].wt;
  }
  cout << "Average Turnaround Time = " << totalTAT / n << endl;
  cout << "Average Waiting Time = " << totalWT / n << endl;

  return 0;
}