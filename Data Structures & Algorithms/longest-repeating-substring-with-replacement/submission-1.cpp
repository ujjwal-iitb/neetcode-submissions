class Solution {
public:
    int maxFrequencyChar(unordered_map<char, int> &mp){
        int ans = 0;
        for(auto i: mp){
            ans = max(ans, i.second);
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        int start = 0, end = 0, ans = 0;
        unordered_map<char, int> mp;
        while(end<s.length()){
            mp[s[end]]++;

            if(end-start+1 - maxFrequencyChar(mp)>k){
                mp[s[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};
