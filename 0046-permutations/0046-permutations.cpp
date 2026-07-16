class Solution {

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
        //if current permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        //Try each number that hasn't been used yet
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // Skip already used elements
            
            //add current element to permutation
            current.push_back(nums[i]);
            used[i] = true;
            
            //recursively build the rest of permutation
            backtrack(nums, result, current, used);
            
            //backtrack to try other elements
            current.pop_back();
            used[i] = false;
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, result, current, used);
        return result;
    }
};