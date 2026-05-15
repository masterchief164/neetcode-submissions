class Solution {
public:
    int climbStairs(int n) {
        int ways = 0;
        if(n==0) return 1;
        if(n > 0)
            ways +=climbStairs(n-1);
        if(n > 1)
            ways +=climbStairs(n-2);
        return ways;
    }

    // int helper(int n)
};
