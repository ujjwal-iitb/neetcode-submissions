class Solution {
public:
    int climbStairs(int n) {
        //n==1 -> 1
        //n==2 -> 1+1, 2 => 2
        //n==3 -> (n-1) + (n-2)*2
        int a = 1, b = 2, c;
        if(n==1){
            return a;
        }
        if(n==2){
            return b;
        }
        for(int i = 3; i<n+1; i++){
            c = b + a;
            a = b;
            b = c;
        }

        return c;
    }
};
