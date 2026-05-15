class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int target, vector<int> tmp, int j){
        if(target == 0){
            ans.push_back(tmp);
        }
        if(target < 0)
            return;
        
        for(int i = j;i< nums.size();i++){
            tmp.push_back(nums[i]);
            helper(nums, target - nums[i], tmp, i);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        helper(nums, target, {}, 0);
        return ans;
    }
};
