#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct activity {
    string name;
    int start_time, finish_time;
};

bool cmp(activity a, activity b) {
    return a.finish_time < b.finish_time;
}

void activitySelection(vector<activity>& activities, vector<string>& selected_activities, int last_finish_time, int start_index) {
    if(start_index == activities.size()) {
        return;
    }

    if(activities[start_index].start_time >= last_finish_time) {
        selected_activities.push_back(activities[start_index].name);
        last_finish_time = activities[start_index].finish_time;
    }

    activitySelection(activities, selected_activities, last_finish_time, start_index+1);
}

int main() {
    int n;
    cin >> n;

    vector<activity> activities(n);

    for(int i = 0; i < n; i++) {
        cin >> activities[i].name >> activities[i].start_time >> activities[i].finish_time;
    }

    sort(activities.begin(), activities.end(), cmp);

    vector<string> selected_activities;
    selected_activities.push_back(activities[0].name);

    int last_finish_time = activities[0].finish_time;

    activitySelection(activities, selected_activities, last_finish_time, 1);

    for(int i = 0; i < selected_activities.size(); i++) {
        cout << selected_activities[i] << " ";
    }

    return 0;
}
