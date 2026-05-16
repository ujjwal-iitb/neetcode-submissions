class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i : nums){
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> mp.get(a) - mp.get(b));

        for(Integer i: mp.keySet()){
            if(pq.size()<k){
                pq.add(i);
            }
            else{
                if(mp.get(pq.peek())<mp.get(i)){
                    pq.poll();
                    pq.add(i);
                }
            }
        }

        int[] res = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pq.poll();
        }
        return res;

    }
}
