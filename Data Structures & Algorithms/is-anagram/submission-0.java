class Solution {
    public boolean isAnagram(String s, String t) {

        if(s.length()!=t.length()){
            return false;
        }

        Map<String, Integer> map = new HashMap<>();
        for(int i = 0; i<s.length(); i++){
            if(map.containsKey(s.substring(i, i+1))){
                map.put(s.substring(i, i+1), map.get(s.substring(i, i+1)) + 1);
            }
            else{
                map.put(s.substring(i, i+1), 1);
            }

            if(map.containsKey(t.substring(i, i+1))){
                map.put(t.substring(i, i+1), map.get(t.substring(i, i+1)) - 1);
            }
            else{
                map.put(t.substring(i, i+1), -1);
            }
        }

        for(String key: map.keySet()){
            if(map.get(key)!=0){
                return false;
            }
        }

        return true;
    }
}
