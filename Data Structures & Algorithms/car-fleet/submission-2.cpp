class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,float>> time(speed.size());

        int fleetCount = 0;

        float firstTime = -1;

        for(int i = 0;i<position.size();i++){
            time[i].first = position[i];
            time[i].second = ((float)(target-position[i]))/speed[i];
        }
        sort(time.begin(),time.end());
        for(int i = 0;i<time.size();i++){
            if(time[time.size() - i - 1].second > firstTime){
                firstTime = time[time.size() - i - 1].second;
                fleetCount++;
            }
        }
        return fleetCount;
    }
};
