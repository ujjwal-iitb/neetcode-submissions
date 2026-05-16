class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<List<Integer>, List<String>> map = new HashMap<>();

        for (String s : strs) {
            // Step 1: Build 26-length frequency array
            int[] freq = new int[26];
            for (char c : s.toCharArray()) {
                freq[c - 'a']++;
            }

            // Step 2: Convert int[] → List<Integer> (safe for HashMap key)
            List<Integer> key = new ArrayList<>(26);
            for (int f : freq) key.add(f);

            // Step 3: Insert into map
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }

        // Print the map
        return new ArrayList<>(map.values());
    }
}
