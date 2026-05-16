class Solution {
public:

    bool static compareByPos(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }


    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> positionSpeedVector;

        for(int i = 0; i<position.size(); i++){
            positionSpeedVector.push_back({position[i], speed[i]});
        }

        sort(positionSpeedVector.begin(), positionSpeedVector.end(), compareByPos);

        int count = 0;
        double currFleetTime = -1;
        
        for(int i = positionSpeedVector.size()-1; i>=0; i--){
            int startPos = positionSpeedVector[i].first, speed = positionSpeedVector[i].second;
            double timeRequiredToReachTarget = (double)(target - startPos)/(double)speed;

            if(timeRequiredToReachTarget<=currFleetTime){
                continue;
            }
            else{
                currFleetTime = timeRequiredToReachTarget;
                count++;
            }
        }

        return count;
    }
};
