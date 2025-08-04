class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         map<int, int> fruit_count;
        int max_fruits = 0;
        int start = 0;

        for (int end = 0; end < fruits.size(); ++end) {
            fruit_count[fruits[end]]++;

            // Shrink the window if more than 2 types
            while (fruit_count.size() > 2) {
                fruit_count[fruits[start]]--;
                if (fruit_count[fruits[start]] == 0)
                    fruit_count.erase(fruits[start]);
                start++;
            }

            // Update max fruits picked
            max_fruits = max(max_fruits, end - start + 1);
        }

        return max_fruits;
    }
};