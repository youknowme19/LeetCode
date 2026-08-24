class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        for (int i = 1; i < stones.size(); ++i) {
            stones[i] += stones[i - 1];
        }

        int best = stones.back();

        for (int i = stones.size() - 2; i >= 1; --i) {
            best = max(best, stones[i] - best);
        }

        return best;
    }
};