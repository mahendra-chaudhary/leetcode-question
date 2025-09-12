class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n  = prices.size();
        vector<int>ans = prices;
        // int max  = 0 ;


        for(int i = 0; i<n;i++){
            for(int j = i+1;j<n;j++){
                if(prices[i]>=prices[j]){
                    ans[i] = prices[i] - prices[j];
                    break;
                    
                }

            }
        }

        return ans;




        
    }
};