class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

      sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int y1 = points[i][1];
            int maxY = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    ans++;
                    maxY = y2;
                }
            }
        }

        return ans;


        
    }
};