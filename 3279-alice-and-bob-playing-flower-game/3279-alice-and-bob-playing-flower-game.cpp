class Solution {
public:
    long long flowerGame(int n, int m) {

        // long long odd_x = (n+1)/2;
        // long long even_x = m/2;
        // long long odd_y = (m+1)/2;
        // long long even_y = m/2;        
        
        // return odd_x*even_y + even_x*odd_y;

        return 1LL*((n+1)/2)*(m/2) + 1LL*(n/2)*((m+1)/2);
    }
};