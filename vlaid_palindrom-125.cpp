/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        std::string str = "";
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] >= 65 && s[i] <= 90) ||(s[i] >= 97 && s[i] <= 122)
                || (s[i] >= 48 && s[i] <= 57)) {
                str += s[i];
            }
        }
        int j = str.size() - 1;
        for (int i = 0; i < str.size() / 2; ++i, --j) {
            str[i] |= 32;
            str[j] |= 32;
            if (str[i] != str[j]) {return false;}
        }
        return true;
    }
};
