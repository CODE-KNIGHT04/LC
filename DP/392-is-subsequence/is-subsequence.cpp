class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0; // i walks s, j walks t
        while(i < s.length() && j < t.length()) {
            if(s[i] == t[j])
                i++;       // matched, advance s pointer
            j++;           // always advance t pointer
        }
        return i == s.length(); // did we match all of s?
}
};