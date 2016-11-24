#include<bits/stdc++.h>

using namespace std;

int max_sum_subarray(int arr[],int n)
{
    int ans=arr[0],sum=0;
    for(int i=0;i<n;++i)
    {
        ans = max(ans,arr[i]);
    }
    if(ans<0) return ans;
    ans=0;
    for(int i=0;i<n;++i)
    {
        if(sum+arr[i] > 0)
            sum += arr[i];
        else sum=0;
        ans = max(ans,sum);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int ans = max_sum_subarray(arr,n);
    cout<<"Maximum Sum of any Subarray is "<<ans<<endl;
}
