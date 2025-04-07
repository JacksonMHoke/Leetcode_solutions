#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> startTimes{1, 4, 8};
    vector<int> endTimes{5, 6, 12};
    vector<int> costs{5, 10, 12};
    long long discountPrice=13;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    for (int i=0; i<startTimes.size(); ++i) {
        pq.push({startTimes[i], costs[i]});
        pq.push({endTimes[i]+1, -costs[i]});
    }
    int prev=pq.top().first;
    long long score=0;
    long long currScore=0;
    while (!pq.empty()) {
        auto [time, offset]=pq.top();
        pq.pop();

        score+=min(currScore, discountPrice)*(time-prev);
        currScore+=offset;
        prev=time;
    }
    cout << score << endl;
}