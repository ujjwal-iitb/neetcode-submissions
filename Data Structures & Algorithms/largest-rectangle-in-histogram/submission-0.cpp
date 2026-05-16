class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        stack<pair<int, int>> st;

        vector<int> prefixNearestMinPosVector(n, -1), suffixNearestMinPosVector(n, -1);

        for(int i = n-1; i>=0; i--){

            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                suffixNearestMinPosVector[i] = -1;
            }
            else{
                suffixNearestMinPosVector[i] = st.top().second;
            }
            st.push({heights[i], i});
        }

        while (!st.empty()) {
            st.pop();
        }

        for(int i = 0; i<n; i++){
            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                prefixNearestMinPosVector[i] = -1;
            }
            else{
                prefixNearestMinPosVector[i] = st.top().second;
            }
            st.push({heights[i], i});
        }

        int ans = 0;

        for(int i = 0; i<n; i++){
            int h = heights[i];

            int left = i, right = n-1 - i; 
            if(i>0 && prefixNearestMinPosVector[i]!=-1){
                left = i - prefixNearestMinPosVector[i]-1;
            }

            if(i<n-1 && suffixNearestMinPosVector[i]!=-1){
                right = suffixNearestMinPosVector[i] - i - 1;
            }

            int b = left + right + 1;

            ans = max(ans, h*b);
        }
        return ans;

    }
};
