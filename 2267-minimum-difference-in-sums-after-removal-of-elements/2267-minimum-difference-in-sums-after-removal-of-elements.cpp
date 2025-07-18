class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n = nums.size();

        priority_queue<int> L;

        priority_queue<int,vector<int>,greater<int>> R;

        long N = n/3,right = 0,left = 0,ans = LLONG_MAX;


        vector<long>temp(n);

        for(int i = n-1;i>=N;i--){
            R.push(nums[i]);
            right +=nums[i];
            if(R.size()>N){
                right -=R.top();
                R.pop();

            }

            if(R.size() == N) temp[i]=right;
        }

        for(int i = 0;i<n-N;i++){
            L.push(nums[i]);
            left += nums[i];
            if(L.size()>N){
                left -= L.top();
                L.pop();
            }
            if(L.size() == N) ans = min(ans,left-temp[i+1]);

        }

        return ans;

        
    }
};