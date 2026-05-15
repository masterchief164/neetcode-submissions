class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMin = 1, currMax = 1;

        for(int num: nums) {
            int tmp = currMax*num;
            currMax = max({num*currMax, num*currMin, num});
            currMin = min({tmp, num*currMin, num});

            res = max(res, currMax);
        }
        return res;
    }
};
