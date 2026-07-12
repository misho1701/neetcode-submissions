class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        vector<int> counts1(26, 0);
        vector<int> counts2(26, 0);

        for(char c : s1){
            counts1[c - 'a']++;
        }

        int windowSize = s1.size();

        for(int i = 0; i < windowSize; i++){
            counts2[s2[i] - 'a']++;
        }

        if(counts1 == counts2){
            return true;
        }

        for(int i = windowSize; i < s2.size(); i++){
            counts2[s2[i] - 'a']++;

            counts2[s2[i - windowSize] - 'a']--;

            if(counts1 == counts2){
                return true;
            }
        }
        return false;
    }
};
