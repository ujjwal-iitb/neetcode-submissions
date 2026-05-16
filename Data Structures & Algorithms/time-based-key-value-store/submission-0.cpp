class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> timeMap; 
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(timeMap.find(key)==timeMap.end()){
            vector<pair<int,string>> v;
            timeMap[key] = v;
        }

        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timeMap.find(key)==timeMap.end()){
            return "";
        }
        int start = 0, end = timeMap[key].size()-1;

        int i = -1;
        while(start<=end){
            int mid = (start + end)/2;

            if(timeMap[key][mid].first<=timestamp){
                i = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(i==-1){
            return "";
        }
        else{
            return timeMap[key][i].second;
        }
    }
};
