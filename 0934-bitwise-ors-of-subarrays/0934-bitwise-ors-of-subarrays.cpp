class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
           unordered_set<int> result;
           set<int> curr;

    for (int num : arr) {
        set<int> next;
        next.insert(num);

        for (int x : curr) {
            next.insert(x | num);
        }

        curr = next;

        for (int x : curr) {
            result.insert(x);
        }
    }

    return result.size();
}

};  