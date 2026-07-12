class Solution {
public:
    string minWindow(string s, string t) {
         if (t.length() > s.length())
            return "";

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int needCount = 0;

        for (int i = 0; i < 128; i++) {
            if (need[i] > 0)
                needCount++;
        }

        int have = 0;

        int left = 0;

        int minLength = s.length() + 1;
        int start = 0;


        for (int right = 0; right < s.length(); right++) {

            char c = s[right];

            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                have++;
            }


            while (have == needCount) {

                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }


                char leftChar = s[left];

                window[leftChar]--;


                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }


        if (minLength == s.length() + 1)
            return "";

        return s.substr(start, minLength);
    }
};
