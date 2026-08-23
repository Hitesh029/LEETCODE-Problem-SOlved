class TrieNode {
public:
    unordered_map<int, TrieNode*> child;
    int count = 0;
};

class Solution {
public:

    TrieNode* root = new TrieNode();

    void insert(vector<int>& row)
    {
        TrieNode* node = root;

        for(int x : row)
        {
            if(!node->child.count(x))
            {
                node->child[x] = new TrieNode();
            }

            node = node->child[x];
        }

        node->count++;
    }

    int search(vector<int>& col)
    {
        TrieNode* node = root;

        for(int x : col)
        {
            if(!node->child.count(x))
            {
                return 0;
            }

            node = node->child[x];
        }

        return node->count;
    }

    int equalPairs(vector<vector<int>>& grid)
    {
        int n = grid.size();

        // Insert all rows
        for(auto &row : grid)
        {
            insert(row);
        }

        int ans = 0;

        // Search every column
        for(int c = 0; c < n; c++)
        {
            vector<int> col;

            for(int r = 0; r < n; r++)
            {
                col.push_back(grid[r][c]);
            }

            ans += search(col);
        }

        return ans;
    }
};