class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
  // custom comparator for max-heap
        auto gain = [&](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        
        priority_queue<pair<double, pair<int,int>>> pq;
        
        // initial push
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        
        // assign extra students
        while (extraStudents--) {
            auto [g, p] = pq.top(); pq.pop();
            int pass = p.first, total = p.second;
            pass++, total++;
            pq.push({gain(pass, total), {pass, total}});
        }
        
        // calculate final average
        double ans = 0.0;
        while (!pq.empty()) {
            auto [g, p] = pq.top(); pq.pop();
            ans += (double)p.first / p.second;
        }
        
        return ans / classes.size();

        
    }
};