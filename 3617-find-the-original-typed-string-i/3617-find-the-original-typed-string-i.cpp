class Solution {
public:
  int possibleStringCount(string word) {
     
    int n = word.length();
    int count  = 1; // Original string is always valid
    int i = 0;

    while (i < n) {
        int j = i;
        // Count the group of same characters
        while (j < n && word[j] == word[i]) j++;
        int len = j - i;

        if (len > 1) {
            // For a group like 'aaa', Alice could've meant: 'a', 'aa' → len-1 choices
            count += (len - 1);
        }

        // i = j; // Move to the next group
        i =j;
    }

    return count ;
}


};
