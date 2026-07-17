class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        long long n = 0;
        int a = x;

        while (a > 0) {
            n = n * 10 + a % 10;
            a /= 10;
        }

        return n == x;
    }
};