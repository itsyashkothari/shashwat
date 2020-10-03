#include "bits/stdc++.h"
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
        for(int &x:a) {
            if(sum+x<=mid) sum+=x;
            else {
                no++;
                sum=x;
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
    for(int &x:a) {cin>>x; sum+=x;}
    cout<<pages(a, m, 0, sum);
    return 0;
}
