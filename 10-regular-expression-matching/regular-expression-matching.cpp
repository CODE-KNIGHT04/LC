class Solution {
public:
    bool solve(string &s, string &p, int i, int j) {
        int n = s.size(), m = p.size();

        if (j == m) return i == n;

        bool firstMatch = (i < n) && (p[j] == s[i] || p[j] == '.');

        if (j + 1 < m && p[j + 1] == '*') {
            return solve(s, p, i, j + 2) ||               
                   (firstMatch && solve(s, p, i + 1, j));  
        } else {
            return firstMatch && solve(s, p, i + 1, j + 1);
        }
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};