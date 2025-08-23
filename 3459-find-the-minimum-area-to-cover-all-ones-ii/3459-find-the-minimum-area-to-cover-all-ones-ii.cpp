class Solution {
public:
        int minimumArea(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        int minRow = INT_MAX, maxRow = INT_MIN;
        int minCol = INT_MAX, maxCol = INT_MIN;

        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        if (minRow == INT_MAX) return 0;  // No 1s in this subgrid
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
    int minimumSum(vector<vector<int>>& grid ) {

      int n =  grid.size();
      int m = grid[0].size();
      int ans  = INT_MAX;
       for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int a1 = minimumArea(grid, 0, i, 0, m - 1);
                int a2 = minimumArea(grid, i + 1, j, 0, m - 1);
                int a3 = minimumArea(grid, j + 1, n - 1, 0, m - 1);
                ans = min(ans, a1 + a2 + a3);
            }
        }

        // Case 2: 3 vertical strips
        for (int i = 0; i < m - 2; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                int a1 = minimumArea(grid, 0, n - 1, 0, i);
                int a2 = minimumArea(grid, 0, n - 1, i + 1, j);
                int a3 = minimumArea(grid, 0, n - 1, j + 1, m - 1);
                ans = min(ans, a1 + a2 + a3);
            }
        }

        // Case 3: Horizontal + 2 vertical on bottom
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int top = minimumArea(grid, 0, i, 0, m - 1);
                int bottomLeft = minimumArea(grid, i + 1, n - 1, 0, j);
                int bottomRight = minimumArea(grid, i + 1, n - 1, j + 1, m - 1);
                ans = min(ans, top + bottomLeft + bottomRight);
            }
        }

        // Case 4: Horizontal + 2 vertical on top
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int bottom = minimumArea(grid, i + 1, n - 1, 0, m - 1);
                int topLeft = minimumArea(grid, 0, i, 0, j);
                int topRight = minimumArea(grid, 0, i, j + 1, m - 1);
                ans = min(ans, bottom + topLeft + topRight);
            }
        }

        // Case 5: Vertical + 2 horizontal on left
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                int left = minimumArea(grid, 0, n - 1, 0, i);
                int topRight = minimumArea(grid, 0, j, i + 1, m - 1);
                int bottomRight = minimumArea(grid, j + 1, n - 1, i + 1, m - 1);
                ans = min(ans, left + topRight + bottomRight);
            }
        }

        // Case 6: Vertical + 2 horizontal on right
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                int right = minimumArea(grid, 0, n - 1, i + 1, m - 1);
                int topLeft = minimumArea(grid, 0, j, 0, i);
                int bottomLeft = minimumArea(grid, j + 1, n - 1, 0, i);
                ans = min(ans, right + topLeft + bottomLeft);
            }
        }

        return ans; 

     
    }
};