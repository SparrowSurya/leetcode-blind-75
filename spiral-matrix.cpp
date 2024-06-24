#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;

		int minrows = 0;
		int mincols = 0;
		int maxrows = matrix.size();
		int maxcols = matrix[0].size();
		int count = maxrows * maxcols;

		int dirs[][2] = {
			{0, 1}, {1, 0}, {0, -1}, {-1, 0},
		};
		int d = 0;
		int r = 0;
		int c = -1;

		while (count > 0) {
			int nr = r + dirs[d][0];
			int nc = c + dirs[d][1];

			if ((minrows <= nr) && (nr < maxrows) && (mincols <= nc) && (nc < maxcols)) {
				ans.push_back(matrix[nr][nc]);
				r = nr;
				c = nc;
				count -= 1;
			} else {
				if (d == 0) {
					minrows += 1;
				} else if (d == 1) {
					maxcols -= 1;
				} else if (d == 2) {
					maxrows -= 1;
				} else if (d == 3) {
					mincols += 1;
				}

				d = (d+1)%4;
			}
		}

		return ans;
    }
};
