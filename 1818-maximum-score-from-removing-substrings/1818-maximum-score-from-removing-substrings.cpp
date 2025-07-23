class Solution {
public:
      int remove(string& s ,string pattern ,int score){
       string temp;
        int total = 0;
        for (char c : s) {
            if (!temp.empty() && temp.back() == pattern[0] && c == pattern[1]) {
                temp.pop_back();  // remove pattern
                total += score;
            } else {
                temp.push_back(c);
            }
        }
        s = temp;  // remaining string for second pass
        return total;
    }



    int maximumGain(string s, int x, int y) {

        int total =  0;

        if(x>y){
        total += remove(s,"ab",x);
        total += remove(s,"ba",y);
        }
        else{

            total += remove(s,"ba",y);
            total += remove(s,"ab",x);

        }
        return total;
        
    }
};