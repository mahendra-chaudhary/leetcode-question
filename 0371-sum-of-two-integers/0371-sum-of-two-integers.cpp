class Solution {
public:
    int getSum(int a, int b) {
       while(b != 0){
        int sum = a^b;   // firstly use XOR 
        int carry = (a&b)<<1;// SECOND USE OF AND 
        a = sum; // reprocess of th after
        b = carry;

       }

        return a;

       
        
    }
};