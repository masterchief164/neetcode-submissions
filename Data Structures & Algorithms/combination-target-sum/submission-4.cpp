class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(target, nums, 0, 0, vector<int>(), res);
        return res;

    }
    
    void helper(int& target, vector<int> &nums, int i, int total, vector<int> tmp, vector<vector<int>> &res){
        if(total == target) {
            res.push_back(tmp);
            return;
        }

        for(int j = i;j<nums.size();j++){
            if(total + nums[j] > target) {
                return;
            }
            tmp.push_back(nums[j]);
            helper(target, nums, j, total + nums[j], tmp, res);
            tmp.pop_back();
        }
    }
};
