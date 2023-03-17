/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int first = 0;
        int last = nums.size() - 1;
        int mid = 0;
        while (first < last) {
            mid  = first + (last - first)/2;
                if (mid == 0) {break;}
                if ((!(mid & 1) && (nums[mid + 1] == nums[mid])) || ((nums[mid]) == nums[mid - 1] && (mid & 1))){
                    first = mid + 1;
                } else {
                    last = mid;
                }
        }
        return nums[first];
    }
};
