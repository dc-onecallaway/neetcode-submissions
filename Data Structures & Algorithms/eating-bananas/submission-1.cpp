class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(start <= end){
            int mid = start + (end - start)/2;
            int count = 0;
            for(int i = 0;i<piles.size();i++){
                count += piles[i]/mid;
                if(piles[i]%mid != 0){
                    count++;
                }
            }
            if(count <= h){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
