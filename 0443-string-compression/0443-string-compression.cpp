class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index =  0;

        for(int i = 0;i<n;){
            int count = 0;
            char current =  chars[i];


            while(i<n &&  chars[i] == current ){
                i++;
                count++;

            }
            chars[index++] = current;

            if(count > 1){
                string cnt = to_string(count);

                for(char c : cnt){
                    chars[index++] = c;
                }
            }

        }
        return index;
    }
};