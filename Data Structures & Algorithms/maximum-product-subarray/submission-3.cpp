class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int mini = 1, maxi = 1;

        for(auto x: nums) {
            int curr = maxi * x;
            maxi = max({x, maxi*x, mini*x });
            mini = min({x, curr, mini*x });
            ans = max(ans, maxi);
        }
        return ans;
    }
};
