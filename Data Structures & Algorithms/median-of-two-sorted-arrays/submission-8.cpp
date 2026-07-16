class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = nums1.size();
        int half = (nums1.size() + nums2.size())/2;

        while(left <= right){
            int mid = left + (right - left)/2;
            int complement = half - mid;

            int l1 = (mid - 1 >= 0) ? nums1[mid-1] : INT_MIN;
            int r1 = (complement - 1 >= 0) ? nums2[complement-1] : INT_MIN;
            int l2 = (mid < nums1.size()) ? nums1[mid] : INT_MAX;
            int r2 = (complement < nums2.size()) ? nums2[complement] : INT_MAX;

            cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            if(max(l1,r1) <= min(l2,r2)){
                if((nums1.size()+nums2.size())%2 == 0){
                    return ((double)(max(l1,r1)+min(l2,r2)))/2;
                } else {
                    return (double)min(l2,r2);
                }
            }

            if(r1 > l2){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};
