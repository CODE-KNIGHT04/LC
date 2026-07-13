class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long maxHeight = horizontalCuts[0];

        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxHeight = max(maxHeight,
                            (long long)(horizontalCuts[i] - horizontalCuts[i - 1]));
        }

        maxHeight = max(maxHeight,
                        (long long)(h - horizontalCuts.back()));

        long long maxWidth = verticalCuts[0];

        for (int i = 1; i < verticalCuts.size(); i++) {
            maxWidth = max(maxWidth,
                           (long long)(verticalCuts[i] - verticalCuts[i - 1]));
        }

        maxWidth = max(maxWidth,
                       (long long)(w - verticalCuts.back()));

        long long MOD = 1000000007;

        return (maxHeight * maxWidth) % MOD;
    }
};