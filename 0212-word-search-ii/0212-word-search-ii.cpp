class Solution {
public:

    struct TrieNode {
        TrieNode* child[26];
        int wordIndex;
        int childCount;

        TrieNode() {
            wordIndex = -1;
            childCount = 0;

            for(int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;
    vector<string>* wordsPtr;
    vector<string> ans;

    void insert(string& word, int index) {

        TrieNode* node = root;

        for(char c : word) {

            int x = c - 'a';

            if(node->child[x] == nullptr) {

                node->child[x] = new TrieNode();
                node->childCount++;
            }

            node = node->child[x];
        }

        node->wordIndex = index;
    }

    void dfs(vector<vector<char>>& board,
             int i,
             int j,
             TrieNode* node) {

        int m = board.size();
        int n = board[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n)
            return;

        char c = board[i][j];

        if(c == '#')
            return;

        int x = c - 'a';

        TrieNode* next = node->child[x];

        if(next == nullptr)
            return;

        if(next->wordIndex != -1) {

            ans.push_back((*wordsPtr)[next->wordIndex]);

            next->wordIndex = -1;
        }

        board[i][j] = '#';

        dfs(board, i + 1, j, next);
        dfs(board, i - 1, j, next);
        dfs(board, i, j + 1, next);
        dfs(board, i, j - 1, next);

        board[i][j] = c;

        if(next->wordIndex == -1 && next->childCount == 0) {

            delete next;

            node->child[x] = nullptr;
            node->childCount--;
        }
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new TrieNode();
        wordsPtr = &words;

        for(int i = 0; i < words.size(); i++)
            insert(words[i], i);

        for(int i = 0; i < board.size(); i++) {

            for(int j = 0; j < board[0].size(); j++) {

                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};