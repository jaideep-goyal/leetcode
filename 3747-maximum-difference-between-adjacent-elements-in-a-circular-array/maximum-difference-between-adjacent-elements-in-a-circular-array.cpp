class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        vector<int> v = nums;
        int n = nums.size();
        for(int i = 0; i < n; i++) v.push_back(nums[i]);
        int maxi = -1;
        for(int i = 0; i < n+n - 1; i++) {
            if(abs(v[i] - v[i + 1]) > maxi) maxi = abs(v[i] - v[i + 1]);
        }

        return maxi;
    }
};