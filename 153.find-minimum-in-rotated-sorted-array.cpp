class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                break;
            }
            int middle = left + (right - left) / 2;
            if (nums[middle] < nums[left]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return nums[left];
    }
};
