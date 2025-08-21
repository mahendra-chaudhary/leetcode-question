class Solution {
public:
   

    int numSubmat(vector<vector<int>>& mat) {

        int n =  mat.size();
        int m = mat[0].size();
        int result = 0;

        vector<vector<int>> height(n,vector<int>(m,0));
        
               for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) height[i][j] = 0;
                else {
                    if (i == 0) height[i][j] = 1;
                    else height[i][j] = height[i-1][j] + 1;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int minHeight = height[i][j];
                for(int k = j;k >=0 && minHeight > 0;k--){

                    minHeight = min(minHeight,height[i][k]);

                    result +=minHeight;

                }
            }
        }

        return result;
 
        
    }
};