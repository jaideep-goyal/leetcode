class Solution
{
    public:
        int scoreOfParentheses(string s)
        {
            //with stack
            // stack<int> st;
            // st.push(0);
            // for (char ch: s)
            // {
            //     if (ch == '(')
            //     {
            //         st.push(0);
            //     }
            //     else
            //     {
            //         int v = st.top();
            //         st.pop();
            //         int add = max(v*2 , 1);
            //         st.top() += add;
            //     }
            // }
            // return st.top();

            //without stack
            int depth = 0;
            int score = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                {
                    depth++;
                }
                else
                {
                    depth--;
                    if (s[i - 1] == '(')
                    {
                        score += pow(2, depth);
                    }
                }
            }
            return score;
        }
};