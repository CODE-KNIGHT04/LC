class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        int index = 0;
        int sign = 1;
        long ans = 0;

        // remove spaces
        while(index < len && s[index] == ' ') {
            index++;
        }

        // check for + or -
        if(index < len) {
            if(s[index] == '-') {
                sign = -1;
                index++;
            }
            else if(s[index] == '+') {
                sign = 1;
                index++;
            }
        }

        // now read digits one by one
        while(index < len) {
            char ch = s[index];

            if(ch < '0' || ch > '9') {
                break;
            }

            int d = ch - '0';
            ans = ans * 10 + d;

            if(sign == 1 && ans > INT_MAX) {
                ans = INT_MAX;
                break;
            }

            if(sign == -1 && ans > INT_MAX) {
                ans = (long)INT_MAX + 1;
                break;
            }

            index++;
        }

        ans = ans * sign;

        // final safety check
        if(ans < INT_MIN) {
            ans = INT_MIN;
        }
        if(ans > INT_MAX) {
            ans = INT_MAX;
        }

        return (int)ans;
    }
};