class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, t, dp);
}
int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(i == 0)
            return 1; // empty prefix of s is always a subsequence
        if(j == 0)
            return 0; // s still has chars left but t ran out

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = solve(i, j-1, s, t, dp); // skip t[j-1]

        if(s[i-1] == t[j-1])
            ans = ans || solve(i-1, j-1, s, t, dp); // also try matching here

        return dp[i][j] = ans;
    }
};