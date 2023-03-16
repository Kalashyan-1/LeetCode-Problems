/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> new_arr(nums.size());
        int n = 1;
        new_arr[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            new_arr[i] = new_arr[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            new_arr[i] = new_arr[i] * nums[i + 1] * n;
            n *= nums[i + 1];
        }
        return new_arr;
    }
};
