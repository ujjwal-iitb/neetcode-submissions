class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> net (2*n, 0);

        for(int i = 0; i<n; i++){
            net[i] = gas[i] - cost[i];
            net[n+i] = gas[i] - cost[i];
        }

        int curr = 0, start = 0;

        for(int i = 0; i<2*n; i++){
            if(curr + net[i] >= 0){
                curr += net[i];
                if(i-start+1>=n){
                    return start;
                }
            }
            else{
                curr = 0;
                start = i+1;
            }
        }
        return -1;
    }
};
