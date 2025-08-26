class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int n= dimensions.size();

        int maxi = 0;
        int diag = 0;

        for(int i = 0;i<n;i++){
            int x = dimensions[i][0];
            int y = dimensions[i][1];

            int z = x*x + y*y ;
            int area = x*y;

            if(z > maxi){
                maxi  = z ;
                diag = area;

            }
            else if(z ==  maxi){
                diag = max(diag,area);
            }
        }
        return diag ;


       
        
    }
};