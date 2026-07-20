class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> h;
        for(auto x:nums){
            h.push(x);
            if(h.size()>k){
                h.pop();
            }
        }
        return h.top();

    }
};