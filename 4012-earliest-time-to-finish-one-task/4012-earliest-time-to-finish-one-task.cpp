class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int ans = 1e9;
        


         for(int i = 0;i<n;i++){
            int finishtime = tasks[i][0]+tasks[i][1];
            ans = min(ans,finishtime);

         }
         return ans;






        
    }
};