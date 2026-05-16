class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> checkSet = new HashSet<>();
        Map<Integer, Integer> seenMap = new HashMap<>();
        int ans = 0;

        for(int i : nums){
            checkSet.add(i);
        }

        for(int i : nums){
            if(!seenMap.containsKey(i)){
                int j = i; 
                int curr = 0;
                while(!seenMap.containsKey(j) && checkSet.contains(j)){
                    curr++;
                    checkSet.remove(j);
                    j++;
                }
                if(seenMap.containsKey(j)){
                    curr += seenMap.get(j);
                }
                seenMap.put(i, curr);
                ans = Math.max(ans, curr);
            }
        }

        return ans;
    }
}
