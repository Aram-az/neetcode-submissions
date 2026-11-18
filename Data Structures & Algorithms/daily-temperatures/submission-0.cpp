class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size());
        if (temperatures.size() == 0) return {};
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        while (!st.empty()) {
            res[st.top().second] = 0;
            st.pop();
        }
        return res;
    }
};
