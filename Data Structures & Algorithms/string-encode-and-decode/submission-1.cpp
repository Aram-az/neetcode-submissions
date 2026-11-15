class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;
        string ret;
        for (string& s : strs) 
            sizes.push_back(s.size());
        for (int sz : sizes) {
            ret.append(to_string(sz));
            ret.push_back(',');
        }
        ret.push_back('#');
        for (string& s : strs)
            ret.append(s);
        return ret;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> ret;
        int i = 0;
        while (s[i] != '#') {
            int j = i;
            while (s[j] != ',')
                j++;
            sizes.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }
        i++;
        for (int sz : sizes) {
            ret.push_back(s.substr(i, sz));
            i += sz;
        }
        return ret;
    }
};
