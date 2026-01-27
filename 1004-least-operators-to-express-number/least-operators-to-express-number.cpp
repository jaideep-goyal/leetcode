class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        if(target<x){
            return min((x-target)*2, target*2-1);
        }
        
        if(x==target) return 0;
        
        long long int sum=x;
        int ans=0;
        
        while(sum<target){
             ans++;
            sum =sum*x;
           
        }
        if(sum==target)
            return ans;
        int op1 = INT_MAX, op2 = INT_MAX;
        if(sum-target<target){
            op1 = leastOpsExpressTarget(x, sum-target) + ans;
        }
        op2 = leastOpsExpressTarget(x, target-sum/x) + ans-1;
        
        return min(op1,op2)+1;
    }
};