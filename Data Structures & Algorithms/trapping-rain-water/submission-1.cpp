class Solution {
   public:
    int trap(vector<int>& height) {
        int leftHigh;
        int rightHigh;

        int left = 1;
        int right = height.size() - 2;

        leftHigh = height[0];
        rightHigh = height[height.size() - 1];

        int ans = 0;

        while(left <= right){
            if(leftHigh < rightHigh){
                ans += max(0,leftHigh - height[left]);
                leftHigh = max(leftHigh,height[left]);
                left++;
            } else {
                ans += max(0,rightHigh - height[right]);
                rightHigh = max(rightHigh,height[right]);
                right--;
            }
        }
        return ans;
    }
};
