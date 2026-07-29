class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Calculate the total sum of all elements
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // Edge cases check
        if ((total_sum + target) % 2 != 0 || abs(target) > total_sum || (total_sum + target) < 0) {
            // No valid configuration possible
            return 0;
        }
        
        int subset_target = (total_sum + target) / 2;
        
        // dp[j] stores the number of ways to reach sum j
        vector<int> dp(subset_target + 1, 0);
        dp[0] = 1; // Base case: 1 way to make a sum of 0 (using an empty subset)
        
        for (int num : nums) {
            // Traverse backward to prevent using the same element multiple times
            for (int j = subset_target; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[subset_target];
    }
};
