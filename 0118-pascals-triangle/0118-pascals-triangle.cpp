class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;

        vector<vector<int>> result(numRows);

        for(int i = 0;i<n;i++){
            result[i].resize(i+1);
            result[i][0] = result[i][i] = 1;


        for(int j = 1;j<i;j++){
            result[i][j] = result[i-1][j-1] + result[i-1][j];
    }
          }
       return result;



        



        
    }
};