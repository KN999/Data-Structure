#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPerfectSquare(ll num) {
  double x = num,y=1,e=0.0001;
  while(x-y>e){
      x = (x+y)/2;
      y = num/x;
  }
  x = floor(x);
  if(x*x==num) return true;
  return false;      
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    ll t; cin>>t;
    ll c=1;
    while(t--){
      ll n; cin>>n;
      vector<ll> arr(n);
      for(int i=0;i<n;i++) cin>>arr[i];
      int ans=0;
      for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
          sum+=arr[j];
          if(isPerfectSquare(sum)) ans++;
        }
      }
      cout<<"Case #"<<c<<": "<<ans<<"\n";
      c++;
    }
    return 0;
}