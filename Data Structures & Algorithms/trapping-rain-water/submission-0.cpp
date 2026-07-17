class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int> leftHigh(height.size());
        vector<int> rightHigh(height.size());

        leftHigh[0] = height[0];
        rightHigh[height.size() - 1] = height[height.size() - 1];

        for (int i = 1; i < height.size(); i++) {
            leftHigh[i] = max(leftHigh[i - 1], height[i]);
            rightHigh[height.size() - i - 1] =
                max(rightHigh[height.size() - i], height[height.size() - i - 1]);
        }

        int ans = 0;

        for (int i = 1; i < height.size() - 1; i++) {
            ans += max(0, min(leftHigh[i - 1], rightHigh[i + 1]) - height[i]);
        }
        return ans;
    }
};
