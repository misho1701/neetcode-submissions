class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int size = nums.size();

        for(int i = 0; i < size; i++){
            int complement = target - nums[i];

            if(seen.count(complement)){
                int j = seen[complement];
                return {j, i};
            }

            seen[nums[i]] = i;
        }
        return {};
    }
};
