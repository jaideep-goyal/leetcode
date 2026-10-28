class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){

            mp[nums[i]]++ ;

        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp){

            pq.push({it.second , it.first});

        }

        while(k > 0){

            ans.push_back(pq.top().second);
            pq.pop();

            k--;

        }

        return ans;     
    }
};