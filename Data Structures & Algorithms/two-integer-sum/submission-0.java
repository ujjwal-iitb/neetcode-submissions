class Solution {

    private int[] getAns(int a, int b){
        int[] arr = new int[2];
        arr[0] = a;
        arr[1] = b;
        return arr;
    }

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i<nums.length; i++){
            int req = target - nums[i];
            if(map.containsKey(req)){
                return getAns(map.get(req), i);
            }
            else{
                map.put(nums[i], i);
            }
        }

        return getAns(-1, -1);
    }
}
