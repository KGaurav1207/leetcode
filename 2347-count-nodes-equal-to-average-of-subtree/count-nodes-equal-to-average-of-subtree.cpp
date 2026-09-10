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
    void sum(TreeNode* root,int &val,int &size){
        if(!root) return;
        val+=root->val;
        size+=1;
        sum(root->left,val,size);
        sum(root->right,val,size);
    }
    void subTree(TreeNode* root,int &ans){
        if(!root) return;
        int val=0,size=0;
        sum(root,val,size);
        int avg=val/size;
        if(root->val==avg) ans++;
        subTree(root->left,ans);
        subTree(root->right,ans);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        subTree(root,ans);
        return ans;
    }
};