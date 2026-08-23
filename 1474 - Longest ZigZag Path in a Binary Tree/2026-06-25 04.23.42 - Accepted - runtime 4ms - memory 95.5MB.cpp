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

    int ans=0;

    void dfs(TreeNode* root,bool left,int len){
        if(root==NULL){
            return;
        }
        ans=max(ans,len);
        if(left){
            dfs(root->left,false,len+1);
            dfs(root->right,true,1);
        }
        else{
            dfs(root->right,true,len+1);
            dfs(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root->left,false,1);
        dfs(root->right,true,1);

        return ans;
    }
};