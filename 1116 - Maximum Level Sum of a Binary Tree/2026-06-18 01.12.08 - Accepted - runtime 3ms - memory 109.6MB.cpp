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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        long long maxsum=LLONG_MIN;

        int level=1;
        int ans=1;

        while(!q.empty()){
            int size=q.size();
            long long  cursum=0;

            while(size--){
                TreeNode* node=q.front();
                q.pop();
                cursum+=node->val;

                if(node->left)
                   q.push(node->left);

                if(node->right){
                    q.push(node->right);
                }   
            } 

                if (cursum>maxsum){
                    maxsum=cursum;
                    ans=level;
                }
                level++;
            }
            return ans;
        }
    
};