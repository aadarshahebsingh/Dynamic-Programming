#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

/*
// Approach 1
int helper(vector<int> nums, int index, int size, vector<int> &dp)
{
    // cout<<index<<" hello"<<endl;
    if (index > size)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int ans = INT_MIN;
    for (int increment = 2; increment <= size; increment++)
    {
        // cout<<nums[index];
        int subSum = helper(nums, index + increment, size, dp) + nums[index];
        ans = max(subSum, ans);
        // cout<<ans<<"hello"<<endl;
    }
    dp[index] = ans;
    // return ans;
    return dp[index];
}

int maximumNonAdjacentSum(vector<int> &nums)
{

    // Write your code here.
    int n = nums.size() - 1;
    if (n == 0)
        return nums[0];
    else if (n == 1)
    {
        // nums[0] > nums[1] ? return nums[0] : return nums[1];
        if (nums[0] > nums[1])
            return nums[0];
        else
            return nums[1];
    }
    int ans = INT_MIN;
    vector<int> dp(n + 1, -1);
    // cout<<ans<<endl;
    for (int i = 0; i < nums.size(); i++)
    {
        // cout<<"hello"<<endl;
        ans = max(ans, helper(nums, i, n, dp));
    }
    return ans;
}


*/

/*
// Approach 2         Recurrence


#include <bits/stdc++.h>
int NonAdjacentSum(vector<int> arr,int n,vector<int> &dp){
    if(n==0)return arr[0];
    if(n<0)return 0;

    int  pick= arr[n]+NonAdjacentSum(arr, n-2,dp);
    int notPick=NonAdjacentSum(arr, n-1,dp);
    return max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size()-1;
    vector<int> dp(n,-1);
    int ans=NonAdjacentSum(nums,n,dp);
    return ans;
}

*/

/*

// Approach          -> memoization  method


#include <bits/stdc++.h>
int NonAdjacentSum(vector<int> arr,int n,vector<int> &dp){
    if(n==0)return arr[0];
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    int  pick= arr[n]+NonAdjacentSum(arr, n-2,dp);
    int notPick=NonAdjacentSum(arr, n-1,dp);

    dp[n]=max(pick,notPick);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size()-1;
    vector<int> dp(n+1,-1);
    int ans=NonAdjacentSum(nums,n,dp);
    return ans;
}
*/

/*
Approach 4  -> Tabulation

#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1)pick+=dp[i-2];
        int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[n-1];
}

*/

int maximumNonAdjacentSum(vector<int> &nums)
{
    int prev2 = 0, prev = nums[0], curri;
    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i] + prev2;
        int notPick = prev;
        curri = max(pick, notPick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int ans = maximumNonAdjacentSum(arr);
    cout << ans << endl;
    return 0;
}
