class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int res = 0;

        // First, collect fruits along the diagonal
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
        }

        // Process both original and transposed grids
        for (int pass = 0; pass < 2; pass++) {
            if (pass == 1) {
                // Transpose the matrix
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        swap(fruits[i][j], fruits[j][i]);
                    }
                }
            }

            // Initialize dp arrays
            vector<int> prev(n, -1), curr(n, -1);

            prev[n - 1] = fruits[0][n - 1];  // Start from the top-right corner

            // Loop through each row (excluding the last one)
            for (int row = 1; row < n - 1; row++) {
                fill(curr.begin(), curr.end(), -1);  // Reset curr for the new row

                for (int i = 0; i < n; i++) {
                    if (prev[i] < 0) {
                        continue;  // Skip invalid states
                    }

                    // Check all 4 possible directions (up, down, left, right)
                    if (i > 0) {
                        curr[i - 1] = max(curr[i - 1], prev[i] + fruits[row][i - 1]);  // Left move
                    }

                    if (i < n - 1) {
                        curr[i + 1] = max(curr[i + 1], prev[i] + fruits[row][i + 1]);  // Right move
                    }

                    curr[i] = max(curr[i], prev[i] + fruits[row][i]);  // Current position
                }

                swap(prev, curr);  // Move to the next row
            }

            res += prev[n - 1];  // Add the result from the last column
        }

        return res;
    }
};
