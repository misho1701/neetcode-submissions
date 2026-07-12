class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen(128, false);

        int left = 0;
        int longest = 0;

        for(int right = 0; right < s.size(); right++){
            while(seen[s[right]]){
                seen[s[left]] = false;
                left++;
            }

            seen[s[right]] = true;

            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
