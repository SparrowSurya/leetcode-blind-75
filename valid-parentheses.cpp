#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<int> st;

		for (char ch: s) {
			if (
				(ch == '(')
				|| (ch == '{')
				|| (ch == '[')
			) {
				st.push(ch);
				continue;
			}

			if (st.size() == 0) return false;

			char p = st.top();
			if (
				(p == '(' && ch == ')')
				|| (p == '{' && ch == '}')
				|| (p == '[' && ch == ']')
			) {
				st.pop();
			} else {
				return false;
			}
		}

		return st.size() == 0;
    }
};
