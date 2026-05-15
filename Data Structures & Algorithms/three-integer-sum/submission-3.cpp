class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0;i<n;i++){
            int a = nums[i];
            if(a > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1, k = n - 1;
            
            while(j < k){
                int curr = a + nums[j] + nums[k];
                if(curr > 0){
                    k --;
                } else if(curr < 0){
                    j ++;
                } else {
                    ans.push_back({a, nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};
