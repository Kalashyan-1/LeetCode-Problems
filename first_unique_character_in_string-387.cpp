/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        if (s.size() == 1) {return 0;}
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (i == j && j == size - 1) {
                    return i;
                } else if (i == j){
                    continue;
                }

                if (s[j] == s[i]) {
                    break;
                }
                if (j == s.size() - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};
