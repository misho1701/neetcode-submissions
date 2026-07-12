class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int answer = 0;
        while(left < right){
            int width = right - left;

            int h = min(heights[left], heights[right]);

            answer = max(answer, width * h);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return answer;
    }
};
