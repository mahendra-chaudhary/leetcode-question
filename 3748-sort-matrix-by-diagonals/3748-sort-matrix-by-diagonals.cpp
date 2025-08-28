class Solution {
public: 
   int n ;
   void sortdiagonal(int r,int c,vector<vector<int>>& grid, bool asc){
   vector<int> re;
        int i = r, j = c;
        while (i < n && j < n) {
            re.push_back(grid[i][j]);
            i++;
            j++;
        }

        if (asc)
            sort(re.begin(), re.end());
        else
            sort(re.begin(), re.end(), greater<int>());

        // Reset to starting positions
        i = r; j = c;
        int idx = 0;
        while (i < n && j < n) {
            grid[i][j] = re[idx++];
            i++;
            j++;
        }
    }


    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         n = grid.size();
        for(int  row  = 0;row<n;row++){
            sortdiagonal(row,0,grid,false); // here are false-> is acending not 
        }
        for(int col = 1;col<n;col++){
            sortdiagonal(0,col,grid,true);// here re acending order inmy output 
        }


      return grid;
        
    }
};