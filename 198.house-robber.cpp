/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (48.42%)
 * Total Accepted:    272.1K
 * Total Submissions: 560.4K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,1]
 * 输出：4
 * 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2：
 * 
 * 输入：[2,7,9,3,1]
 * 输出：12
 * 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 * 
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) return std::numeric_limits<int>::min();
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);
        std::vector<int> result{nums[0],
            std::max(nums[0], nums[1])};
        int N = nums.size();
        for (int i = 2; i < N; ++i) {
            result.push_back(std::max(result[i - 2] + nums[i], result[i - 1]));
        }
        return result.back();
    }
};
#if 0
int main() {
    Solution sol;
    // 2,7,9,3,1
    {
        std::vector<int> nums{2, 7, 9, 3, 1};
        int ans = sol.rob(nums);
        std::cout << ans << std::endl;
    }
    // 3,7,0,2,9,1
    {
        std::vector<int> nums{3,7,0,2,9,1};
        int ans = sol.rob(nums);
        std::cout << ans << std::endl;
    }
    return 0;
}
#endif
