#include "bits/stdc++.h"
#define PI 3.14159
#define MOD 1000000007
#define lli long long int
using namespace std;

int searchPivot(vector<int> &a, int l, int r) {
    while(l<=r) {
        int mid=(l+r)/2;
        if(a[mid]<a[mid-1]) return mid-1;
        if(a[mid]>a[mid+1]) return mid;
        if(a[mid]>=a[l]) l=mid+1;
        else if(a[mid]<=a[r]) r=mid-1;
    }
}

int searchElement(vector<int> &a, int l, int r, int m) {
    int pivot = searchPivot(a, 0, r);
    if(m>=a[l]) r=pivot;
    else if(m<=a[r]) l=pivot+1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(a[mid]==m) return mid;
        if(a[mid]<m) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main() {
    int n, m;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>m;
    cout<<searchElement(a, 0, n-1, m);
    return 0;
}
