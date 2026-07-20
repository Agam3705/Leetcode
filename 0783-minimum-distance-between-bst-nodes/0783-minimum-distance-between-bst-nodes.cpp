/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void ino(TreeNode* root, vector<int>& v){
        if(root==NULL){
            return;
        }
        ino(root->left,v);
        v.push_back(root->val);
        ino(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        ino(root,v);
        int n=v.size();
        int mn=INT_MAX;
        for(int i =0; i<n;i++){
            for(int j =i+1;j<n;j++){
                mn=min(mn,v[j]-v[i]);
            }
        }
        return mn;
    }
};