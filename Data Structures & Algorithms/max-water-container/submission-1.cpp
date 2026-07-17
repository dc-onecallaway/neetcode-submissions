class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int maxArea = 0;

        while(start < end){
            maxArea = max(maxArea,(end - start) * min(heights[start],heights[end]));

            if(heights[start] < heights[end]){
                start++;
            } else {
                end--;
            }
        }

        return maxArea;
    }
};
