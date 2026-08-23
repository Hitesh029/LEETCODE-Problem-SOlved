class TrieNode {
public:
    TrieNode* child[26];
    vector<string> words;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord)
    {
        sort(products.begin(), products.end());

        TrieNode* root = new TrieNode();

        for(string word : products)
        {
            TrieNode* node = root;

            for(char ch : word)
            {
                int idx = ch - 'a';

                if(node->child[idx] == NULL)
                    node->child[idx] = new TrieNode();

                node = node->child[idx];

                if(node->words.size() < 3)
                    node->words.push_back(word);
            }
        }

        vector<vector<string>> ans;

        TrieNode* node = root;

        for(char ch : searchWord)
        {
            if(node)
                node = node->child[ch-'a'];

            if(node)
                ans.push_back(node->words);
            else
                ans.push_back({});
        }

        return ans;
    }
};