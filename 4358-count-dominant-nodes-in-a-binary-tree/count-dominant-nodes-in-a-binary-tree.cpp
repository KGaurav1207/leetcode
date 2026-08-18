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
    void count(TreeNode* root, int &ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans++;
            return;
        }
        count(root->left, ans);
        count(root->right, ans);

        int left = root->left? root->left->val: INT_MIN;
        int right = root->right? root->right->val: INT_MIN;

        if(left<=root->val && root->val>=right){
            ans++;
        }
        root->val = max({left,right,root->val});
    }
public:
    int countDominantNodes(TreeNode* root) {
       int ans = 0;

       count(root, ans);

       return ans;

    }
};