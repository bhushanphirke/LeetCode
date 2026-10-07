class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int index, int leftRem, int rightRem,
               int open, string curr) {

        if (index == s.size()) {
            if (leftRem == 0 && rightRem == 0 && open == 0)
                ans.insert(curr);
            return;
        }

        char c = s[index];

        if (c == '(' && leftRem > 0) {
            solve(s, index + 1, leftRem - 1, rightRem, open, curr);
        }
  
        if (c == ')' && rightRem > 0) {
            solve(s, index + 1, leftRem, rightRem - 1, open, curr);
        }


        if (c == '(') {
            solve(s, index + 1, leftRem, rightRem,
                  open + 1, curr + c);
        }
        else if (c == ')') {
            if (open > 0) {
                solve(s, index + 1, leftRem, rightRem,
                      open - 1, curr + c);
            }
        }
        else {
            solve(s, index + 1, leftRem, rightRem,
                  open, curr + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0;
        int rightRem = 0;

        for (char c : s) {
            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        solve(s, 0, leftRem, rightRem, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};