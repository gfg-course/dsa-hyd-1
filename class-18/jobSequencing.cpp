#include <bits/stdc++.h>
using namespace std;

class Job {
    public:

    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool profitsComparator(Job* &a, Job* &b) {

    if (a->profit == b->profit) {
        return a->deadline > b->deadline;
    }

    return a->profit > b->profit;
}

// TC: O(n^2)
// AS: O(maxDeadline)
pair<int, int> jobSequencing(vector<Job*> jobs) {

    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), profitsComparator);

    int maxDeadline = jobs[0]->deadline;
    for (int i = 1; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i]->deadline);
    }

    vector<int> timeline(maxDeadline, -1);

    int jobsDone = 0, maxProfit = 0;

    for (int i = 0; i < n; i++) {

        int j = jobs[i]->deadline - 1;
        while (j >= 0) {
            
            if (timeline[j] == -1) {
                timeline[j] = jobs[i]->id;
                jobsDone++;
                maxProfit += jobs[i]->profit;
                break;
            }
            j--;
        }
    }

    return {jobsDone, maxProfit};
}

// ------------------------------

bool deadlinesComparator(Job* &a, Job* &b) {
    if (a->deadline == b->deadline) {
        return a->profit > b->profit;
    }
    return a->deadline < b->deadline;
}


// TC: O(n * log(n))
pair<int, int> jobSequencingUsingPQ(vector<Job*> jobs) {
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), deadlinesComparator);


    priority_queue<int> profits;
    int jobsDone = 0, maxProfit = 0;

    for (int i = 0; i < n; i++) {
        if (jobsDone < jobs[i]->deadline) {
            jobsDone++;
            maxProfit += jobs[i]->profit;

            profits.push(jobs[i]->profit);
        } else {
            if (jobs[i]->profit > profits.top()) {
                maxProfit += jobs[i]->profit - profits.top();
                profits.pop();
                profits.push(jobs[i]->profit);
            }
        }
    }

    return {jobsDone, maxProfit};
}

int main() {
    
    pair<int, int> res = jobSequencing({new Job(1, 4, 20), new Job(2, 1, 10), 
                                    new Job(3, 1, 40), new Job(4, 1, 30)});
    cout << res.first << " " << res.second << endl;

    pair<int, int> res2 = jobSequencingUsingPQ({new Job(1, 4, 20), new Job(2, 1, 10), 
                                    new Job(3, 1, 40), new Job(4, 1, 30)});
    cout << res2.first << " " << res2.second << endl;
}