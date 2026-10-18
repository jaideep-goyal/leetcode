class Solution {
public:
    vector<vector<int>> ans ;
    vector<int> v ;

    void solve(int idx , int sum , vector<int>& candidates , int target) {
        if(sum == target) {
            ans.push_back(v) ;
            return ;
        }

        if(idx == candidates.size() || sum > target) return ;

        //take the current element 
        v.push_back(candidates[idx]) ;
        solve(idx , sum + candidates[idx] , candidates ,target) ;
        v.pop_back() ;

        //skip the current number
        solve(idx + 1 , sum , candidates, target) ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0 , 0 , candidates , target) ;
        return ans ;
    }
};