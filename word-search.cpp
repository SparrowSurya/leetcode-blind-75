#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r=0; r<board.size(); ++r) {
			for (int c=0; c<board[0].size(); ++c) {
				if (board[r][c] == word[0] && matches(r, c, 0, board, word)) {
					return true;
				}
			}
		}
		return false;
    }

	bool matches(int r, int c, int i, vector<vector<char>>& board, string& word) {
		if (i == word.size()) return true;
		if ((r < 0) || (r >= board.size()) || (c < 0) || (c >= board[0].size())) return false;

		char ch = board[r][c];
		board[r][c] = '\0';
		
		if (
			(ch == word[i])
			&& (
				matches(r+1, c, i+1, board, word)
				|| matches(r, c+1, i+1, board, word)
				|| matches(r-1, c, i+1, board, word)
				|| matches(r, c-1, i+1, board, word)
			)
		) return true;

		board[r][c] = ch;
		return false;
	}
};
