class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

        for(const string& s : strs){
                string key = s;
                sort(key.begin(), key.end());

                group[key].push_back(s);
        }

        vector<vector<string>> result;

        for(auto [key, value] : group){
            result.push_back(value);
        }
        return result;
    }
};
