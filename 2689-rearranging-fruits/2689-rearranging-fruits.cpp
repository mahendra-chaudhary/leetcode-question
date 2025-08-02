class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        map<int,int> count;
        map<int,int> freq1,freq2;

        for(int x:basket1){
            count[x]++;
            freq1[x]++;
        }
         for(int x:basket2){
            count[x]++;
            freq2[x]++;
        }

        for(auto &[key,val]: count){
             if (val % 2 != 0) return -1;
        }

        vector<int> extra1,extra2;
         for (auto& [x, _] : count) {
            int diff = freq1[x] - count[x] / 2;
            if (diff > 0) extra1.insert(extra1.end(), diff, x);
            else if (diff < 0) extra2.insert(extra2.end(), -diff, x);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        int n = extra1.size();
        int minFruit = min(*min_element(basket1.begin(), basket1.end()),
                           *min_element(basket2.begin(), basket2.end()));

         
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += min((long long)min(extra1[i], extra2[i]), 2LL * minFruit);
        }

        return res;

    }
};