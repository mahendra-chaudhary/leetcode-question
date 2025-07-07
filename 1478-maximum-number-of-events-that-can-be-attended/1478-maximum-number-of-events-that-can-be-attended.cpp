class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
   sort(events.begin(), events.end());  // sort by start time
    priority_queue<int, vector<int>, greater<int>> pq;  // min-heap by end time

    int i = 0, n = events.size(), day = 0, count = 0;

    while (!pq.empty() || i < n) {
        if (pq.empty()) {
            day = events[i][0]; // jump to next event's start day
        }

        // Push all events starting today into heap
        while (i < n && events[i][0] <= day) {
            pq.push(events[i][1]); // push end day
            i++;
        }

        // Remove all events already expired
        while (!pq.empty() && pq.top() < day) {
            pq.pop();
        }

        // Attend the event that ends the earliest
        if (!pq.empty()) {
            pq.pop();
            count++;
            day++;
        }
    }

    return count;

        
    }
};