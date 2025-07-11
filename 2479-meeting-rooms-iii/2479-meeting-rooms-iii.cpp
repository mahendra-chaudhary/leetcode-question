class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Min-heap for available rooms (sorted by room number)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        // Step 3: Min-heap for busy rooms (sorted by end time)
        // Each entry: (end_time, room_number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        // Step 4: Count meetings per room
        vector<int> count(n, 0);

        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            // Free rooms whose meetings have ended before this meeting's start time
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            // If a room is available, assign directly
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                count[room]++;
                busy.push({end, room});
            } else {
                // No room is free → delay the meeting
                auto [end_time, room] = busy.top();
                busy.pop();
                count[room]++;
                long long duration = end - start;
                busy.push({end_time + duration, room});
            }
        }

        // Step 5: Find room with max meeting count
        int maxCount = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                resultRoom = i;
            }
        }
        return resultRoom;
    }
};
