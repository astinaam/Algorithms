#include<bits/stdc++.h>

using namespace std;

int arr[101][101];
int cal[101];

int kadane(int arr[],int n)
{
    int sum = 0, ans=arr[0];
    for(int i=0;i<n;++i)
        ans = max(ans,arr[i]);
    if(ans<0) return ans;
    ans=0;
    for(int i=0;i<n;++i)
    {
        if(sum+arr[i] < 0) sum=0;
        else sum += arr[i];
        ans = max(ans,sum);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>arr[i][j];
        }
    }

    int maximum=0;

    for(int i=0;i<n;++i)
    {
        memset(cal,0,sizeof cal);
        for(int j=i;j<n;++j)
        {
            int x=0;
            for(int k=0;k<n;++k)
            {
                cal[k] += arr[k][j];
            }
            int ret = kadane(cal,n);
            maximum = max(maximum,ret);
        }
    }
    cout<<maximum<<endl;
}
