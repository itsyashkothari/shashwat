#include<bits/stdc++.h>
#define PI 3.14159
#define MOD 1000000007
#define lli long long int
using namespace std;

lli pages(vector<lli> &a, int m, lli l, lli r) {
    lli ans=INT_MAX;
    while(l<=r) {
        lli mid = (l+r)/2;
        //cout<<"mid: "<<mid<<endl;
        int no=1;
        lli sum=0;
        for(int i=0; i<a.size(); i++) {
            if(sum+a[i]<=mid) sum+=a[i];
            else {
                no++;
                sum=a[i];
            }
        }
            if(no>m) l = mid+1;
            else {ans=min(ans, mid); r = mid-1;}
            //cout<<l<<" "<<r<<endl;
        }
        return ans;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<lli> a(n);
    lli sum=0;
    for(int i=0; i<n; i++) {cin>>a[i]; sum+=a[i];}
    cout<<pages(a, m, 0, sum);
    return 0;
}
