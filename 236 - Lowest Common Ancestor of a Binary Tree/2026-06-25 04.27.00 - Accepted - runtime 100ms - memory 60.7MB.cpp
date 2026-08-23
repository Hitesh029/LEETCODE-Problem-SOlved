class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        stack<TreeNode*> st;
        st.push(root);

        parent[root] = NULL;

        while(!parent.count(p) || !parent.count(q))
        {
            TreeNode* node = st.top();
            st.pop();

            if(node->left)
            {
                parent[node->left] = node;
                st.push(node->left);
            }

            if(node->right)
            {
                parent[node->right] = node;
                st.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestors;

        while(p)
        {
            ancestors.insert(p);
            p = parent[p];
        }

        while(!ancestors.count(q))
        {
            q = parent[q];
        }

        return q;
    }
};