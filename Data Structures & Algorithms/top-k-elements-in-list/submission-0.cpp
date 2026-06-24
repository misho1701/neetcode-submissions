class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto& c : nums){
            freq[c]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for(auto [nums, count] : freq){
            buckets[count].push_back(nums);
        }

        vector<int> result;

        for(int i = nums.size(); i >= 1 && result.size() < k; i--){
            for(int num : buckets[i]){
                result.push_back(num);

                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
