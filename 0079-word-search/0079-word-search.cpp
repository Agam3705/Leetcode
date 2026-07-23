class Solution {
public:
    bool found = false;

    void helper(vector<vector<char>>& board, string word,
                int m, int n, int i, int j, int idx) {

        if (found) return;

        if (idx == word.length()) {
            found = true;
            return;
        }

        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (board[i][j] != word[idx])
            return;

        char temp = board[i][j];
        board[i][j] = '@';

        helper(board, word, m, n, i + 1, j, idx + 1);
        helper(board, word, m, n, i - 1, j, idx + 1);
        helper(board, word, m, n, i, j + 1, idx + 1);
        helper(board, word, m, n, i, j - 1, idx + 1);

        board[i][j] = temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(board, word, m, n, i, j, 0);
                if (found)
                    return true;
            }
        }

        return false;
    }
};