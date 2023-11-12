class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp)//same as the one used in house robber1
	{
		if(i==0)
			return nums[i];
		if(i<0)
			return 0;
     
     if(dp[i]!=-1)
     return dp[i];
     
    int p=nums[i]+f(i-2,nums,dp);
    int np=0+f(i-1,nums,dp);
     
    return dp[i]=max(p,np);
}
    int rob(vector<int>& nums) {
         int n=nums.size();
       
    vector<int>a;
    vector<int>b;
     if(n==1) return nums[0];//edge case
    for(int i=0;i<n-1;i++)
    {
        a.push_back(nums[i]);//skip first element
    }
    for(int i=1;i<n;i++)
    {
        b.push_back(nums[i]);//or skip last element
    }
    vector<int>dp1(a.size(),-1); //design the dp arrray accordingiy
    vector<int>dp2(b.size(),-1);
    int d= f(a.size()-1,a,dp1);//passing first skipped element
    int c= f(b.size()-1,b,dp2);//passing last skipped element
    return max(c,d);//return maximum of both
    }
};