class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mer;
        int i =0;
        int j =0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                mer.push_back(nums1[i++]);
            }
            else{
                mer.push_back(nums2[j++]);
            }
        }
        while(i<m){
            mer.push_back(nums1[i++]);
        }
        while(j<n){
            mer.push_back(nums2[j++]);
        }
        for(int i =0; i<m+n;i++){
            nums1[i]=mer[i];
        }
    }
};