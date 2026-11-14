class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};

        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for (auto words : strs) {
            string word = words;
            sort(word.begin(), word.end());
            map[word].push_back(words);
        }
        for (auto pair : map)
            result.push_back(pair.second);
        
        return result;
    }
};