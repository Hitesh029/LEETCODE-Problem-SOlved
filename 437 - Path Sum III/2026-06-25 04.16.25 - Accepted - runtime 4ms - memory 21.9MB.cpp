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

    unordered_map<long long ,int>mp;

    int dfs(TreeNode* root,long long curr,int target){
        if(root==NULL)
           return 0;

        curr+=root->val;

        int ans=mp[curr-target];
        mp[curr]++;

        ans+=dfs(root->left,curr,target);
        ans+=dfs(root->right,curr,target);

        mp[curr]--;

        return ans;   
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        return dfs(root,0,targetSum);
        
    }
};