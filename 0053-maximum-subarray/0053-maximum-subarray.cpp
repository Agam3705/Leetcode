class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx=INT_MIN;
        int sum =0;
        for(int i  =0; i<n;i++){
            sum+=nums[i];
            mx=max(mx,sum);
            if(sum<0){
                sum=0;
            }
        }
        return mx;
    }
};