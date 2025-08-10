
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        // helper: signature = sorted digits string
        auto sig = [](int x){
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        
        // precompute signatures of powers of two
        unordered_set<string> powers;
        for (int i = 0; i <= 30; ++i) {         // 2^0 .. 2^30
            powers.insert(sig(1 << i));
        }
        return powers.count(sig(N)) > 0;
    }
};