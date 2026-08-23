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

    vector<long long>levelsum;
    void dfs(TreeNode* root,int level)
    {
        if(!root)
            return;

        if(level==levelsum.size()){
            levelsum.push_back(root->val);
        }
        else{
            levelsum[level]+=root->val;
        }    
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {

        dfs(root,0);
        long long max=levelsum[0];
        int ans=1;

        for(int i=1; i<levelsum.size(); i++){
            if(levelsum[i]>max){
                max=levelsum[i];
                ans=i+1;
            }
        }
        /*queue<TreeNode*>q;
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
            }*/


            return ans;
        }
    
};