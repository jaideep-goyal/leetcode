class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        vector<int>ans;

        for(int i = 0; i < nums1.size(); i++){
            int idx = mp[nums1[i]];
            bool found = false;
            for(int j = idx + 1;  j < nums2.size();j++){
                if(nums2[j] > nums1[i]){
                    ans.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }
            if(found == false) ans.push_back(-1);
        }
        return ans;
        
    }
};