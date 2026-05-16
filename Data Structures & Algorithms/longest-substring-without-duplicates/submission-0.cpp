class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, ans = 0; 

        unordered_map<char, int> charPosMap;

        while(end<s.length()){
            //if the char at end is already seen
            if(charPosMap.find(s[end])!=charPosMap.end()){

                //the char is part of the current substring
                if(charPosMap[s[end]]>=start){
                    start = charPosMap[s[end]]+1;
                }
            }
            charPosMap[s[end]] = end;

            ans = max(ans, end - start + 1);
            end++;
        }

        return ans;
    }
};
