class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s));
            }
            if (s == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = x + y;
                st.push(z);
            }
            if (s == "-") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = y - x;
                st.push(z);
            }
            if (s == "*") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = x * y;
                st.push(z);
            }
            if (s == "/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = y / x;
                st.push(z);
            }
        }
        return st.top();
    }
};
