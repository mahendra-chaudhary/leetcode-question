class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 

        vector<int> v(n,-1);

        int maxSum = 0;
        int curr = 0 ; 
        
        for(int i = 1;i<n;i++){

            int diff = prices[i]- prices[i-1];

            curr = max(0,curr+diff);

            maxSum = max(maxSum,curr);
 
             
        }

        return maxSum;




        
    }
};