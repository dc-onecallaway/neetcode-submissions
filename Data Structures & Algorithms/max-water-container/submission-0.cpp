class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;

        int maximumArea = 0;

        while(i < j){
            maximumArea = max(maximumArea,(j-i)*min(heights[i],heights[j]));

            if(heights[i] < heights[j]){
                i++;
            } else {
                j--;
            }

        }
        return maximumArea;
        
    }
};
