#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Activity {
    string name;
    int start;
    int end;
};

// Comparison function for the priority queue based on start time
struct CompareStartTime {
    bool operator()(Activity const& a1, Activity const& a2) {
        return a1.start < a2.start;
    }
};

void selectActivities(Activity activities[], int n) {
    // Build priority queue based on start time
    priority_queue<Activity, vector<Activity>, CompareStartTime> pq;
    for (int i = 0; i < n; i++) {
        pq.push(activities[i]);
    }

    // Select activities in reverse order of start time
        string names[100];
    int curr_time = pq.top().start;
    names[0]=pq.top().name;
    pq.pop();

        int no=1;
    while (!pq.empty()) {
        Activity curr_activity = pq.top();
        pq.pop();
        if (curr_activity.end <= curr_time) {
            curr_time = curr_activity.start;
            names[no]=curr_activity.name;
            no++;
        }
    }
    for(int i=no;i>-1;i--)
    cout<<names[i]<<" ";
}

int main() {
    int n;
    cin >> n;
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        cin >> activities[i].name >> activities[i].start >> activities[i].end;
    }
    selectActivities(activities, n);
    return 0;
}
