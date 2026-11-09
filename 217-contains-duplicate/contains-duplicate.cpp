class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size(); i++) {
            // {nums[i] , frequency}
            mp[nums[i]]++;

            // {1: 2}
            //{2: 1}
            //{3 : 1}
           


            //frequency > 1
            if(mp[nums[i]] > 1) return true;
        }
        return false;
        
    }
};