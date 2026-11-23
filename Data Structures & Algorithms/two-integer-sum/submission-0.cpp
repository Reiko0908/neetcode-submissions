class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for (int i = 0; i < nums.size(); i++) {
            int to_target = target - nums[i];
            if (mp.count(to_target)) return {mp[to_target], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};