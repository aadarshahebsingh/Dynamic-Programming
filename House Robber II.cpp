// Space Optimisation Approach

#include <bits/stdc++.h>
long long int helperFunction(vector<int> &arr)
{
    long long int n = arr.size();
    long long int prev2 = 0, prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        long long int pick = arr[i];
        if (i > 1)
            pick += prev2;
        long long int notPick = prev;
        long long int curri = max(pick, notPick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    // Write your code here.
    long long int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }

    return max(helperFunction(temp1), helperFunction(temp2));
}


// Approach 1      Recurrence 

#include <bits/stdc++.h>
long long int helperFunction(vector<int> arr,long long int index){
    if(index<0)return 0;
    if(index==0 ) return arr[0];
    long long int pic=arr[index]+helperFunction(arr, index-2);
    long long int notPick=helperFunction(arr, index-1);
    return max(pic,notPick);
} 
long long int happy(vector<int> arr,long long int index){
    if(index<1)return 0;
    if(index==1 ) return arr[1];
    long long int pic=arr[index]+happy(arr, index-2);
    long long int notPick=happy(arr, index-1);
    return max(pic,notPick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    // cout<<valueInHouse.size()<<"  hello";
    if(valueInHouse.size()==1)return valueInHouse[0];
    long long int n=valueInHouse.size()-2;
    // long long tempSize=n;
    long long int temp1= helperFunction(valueInHouse,n);
    long long int temp2=happy(valueInHouse,n+1);
    return max(temp1,temp2);
}


// Approach 2                           Memoization
#include <bits/stdc++.h>
long long int helperFunction(vector<int> arr, long long int index,vector<long long int>& dp )
{
    if (index < 0)
        return 0;
    if (index == 0)
        return arr[0];
    if(dp[index]!=-1)return dp[index];
    long long int pic = arr[index] + helperFunction(arr, index - 2,dp);
    long long int notPick = helperFunction(arr, index - 1,dp);
    return dp[index]=max(pic, notPick);
}
long long int happy(vector<int> arr, long long int index,vector<long long int>& dp)
{
    if (index < 1)
        return 0;
    if (index == 1)
        return arr[1];
    if(dp[index]!=-1)return dp[index];
    long long int pic = arr[index] + happy(arr, index - 2,dp);
    long long int notPick = happy(arr, index - 1,dp);
    return dp[index]=max(pic, notPick);
}
long long int houseRobber(vector<int> &valueInHouse)
{

    
    long long int n = valueInHouse.size() - 1;
    if(n==0)return valueInHouse[0];
    // long long tempSize=n;
    vector<long long int> dp(n+1,-1);
    long long int temp1 = helperFunction(valueInHouse, n-1,dp);
    vector<long long int> dp2(n+1,-1);
    long long int temp2 = happy(valueInHouse, n,dp2);
    return max(temp1, temp2);
}




// Approach 3                               Tabulation

#include <bits/stdc++.h> 
long long int helperFunction(vector<int>& arr){
    
    long long int n=arr.size();
    vector<long long int> dp(n);
    dp[0]=arr[0];
    // cout<<arr[n-1]<<"      hi     "<<endl;
    for(int i=1;i<n;i++){
        int pick=arr[i];
        if(i>1)pick+=dp[i-2];
        int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[n-1];
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    long long int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(valueInHouse[i]);
        if(i!=n-1)temp2.push_back(valueInHouse[i]);
    }
    // cout<<temp1[0]<<"   "<<temp2[0]<<endl;
    return max(helperFunction(temp1),helperFunction(temp2));
}
