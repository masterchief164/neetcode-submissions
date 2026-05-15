class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if(total%2) return 0;
        
        vector<int> currDp(total/2+1, 0), nextDp(total/2+1, 0);

        currDp[0] = 1;
        nextDp[0] = 1;

        for(int i = 0;i<n;i++) {
            for(int j = 1;j<total/2+1;j++) {
                bool notTake = currDp[j];

                bool take = 0;
                if(nums[i] <= j) {
                    take |= currDp[j-nums[i]];
                }

                nextDp[j] = take | notTake;
            }
            swap(currDp, nextDp);
        }

        return currDp[total/2];
    }
};
