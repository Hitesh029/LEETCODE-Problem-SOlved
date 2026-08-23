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
    unordered_map<int,int>mp;
    int preorderIndex=0;
    TreeNode* solve(vector<int>& preorder, 
                    vector<int>& inorder,
                    int left,
                    int right){

        if(left>right)
             return NULL;
        int rtval=preorder[preorderIndex++];
        TreeNode* root=new TreeNode(rtval);

        int index=mp[rtval];
        root->left=solve(preorder,inorder,left,index - 1);
        root->right=solve(preorder,inorder,index + 1,right);
        return root;     
                    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++)
           mp[inorder[i]]=i;

        return solve(preorder,inorder,0,inorder.size()-1);   

        
    }
};