class Solution {
public:

    bool possibleToEatAllBananas(int k, vector<int> piles, int h){
        int count = 0; 
        for(int i = 0; i<piles.size(); i++){
            int t = piles[i]/k;
            if(piles[i]%k>0){
                t++;
            }
            count+=t;
            if(count>h){
                return false;
            }
        }
        return count<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 1; 

        for(int i = 0; i<piles.size(); i++){
            end = max(end, piles[i]);
        }

        int ans = end;

        while(start<=end){
            int mid = end - (end - start)/2;
            if(possibleToEatAllBananas(mid, piles, h)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return ans;
    }
};
