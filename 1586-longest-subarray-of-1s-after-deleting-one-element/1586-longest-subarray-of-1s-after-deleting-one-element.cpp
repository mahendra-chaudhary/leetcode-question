class Solution {
public:
    int n ;
    int find(vector<int>& nums,int skip_idx ){
        int currentLength = 0;
        int maxLength  = 0;

        for(int i = 0;i<n;i++){
            if(i == skip_idx)  continue;

            if(nums[i] == 1){
                currentLength ++;
                maxLength = max(maxLength,currentLength);
            }
            else{
                currentLength = 0;
            }
        }
             return maxLength;
    }

    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        //  vector<int>result(n,-1);
        int result = 0;
        int countZero = 0;
        int i = 0;
        for(int  j =0;j<n;j++){
            if(nums[j] == 0)
               countZero++;

               while(countZero  > 1){
                // nums[i] = 0;
                if(nums[i] == 0)
                countZero--;
                i++ ;
               }
            result =  max(result,j-i);
            
        }
            // if(countZero == 0) { 
            //     return  n-1;
            //     }
        return result;
    }
};