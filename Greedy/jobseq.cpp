#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

// Comparator to sort jobs based on profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void printJobSequence(vector<Job>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    // result array to store indices of jobs in the sequence
    vector<int> result(maxDeadline + 1, -1);
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (result[j] == -1) {
                result[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Optimal Job Sequence: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != -1)
            cout << jobs[result[i]].id << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    // Instance (a) data from manual
    vector<Job> jobs = {
        {"J1", 2, 60}, {"J2", 3, 100}, {"J3", 1, 20},
        {"J4", 4, 40}, {"J5", 2, 20}, {"J6", 1, 110}
    };

    printJobSequence(jobs);
    return 0;
}