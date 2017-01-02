/*
Author - Priyanshu Jain
*/
//#include <atomic>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;


#define mod 1000000007
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
struct _{ios_base::Init i; _(){
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}}_ ;
typedef long long int  ll;
#define pll pair<ll,ll>
#define ict int t;cin>>t;while(t--)
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define ain(A, B, C) assert(IN(A, B, C))
#define ull unsigned long long int
#define pii pair<int,int>
#define MAXX 100009
#define fr(a,b,i) for(int i=a;i<b;i++)
#define dbg(x) cout<<"Here we are "<<x<<"\n"
#pragma comment(linker, "/STACK:1000000000")


int main(int argc, char const *argv[]) {
  ifstream fin("file.in");
  ofstream fout("file.out");
  int t;fin>>t; while(t--){
    int n;
    fin>>n;
    int a[n];
    rep(i,n){
      fin>>a[i];
    }
    int j=0,k=0,last=0,ans=0;
    while (j<n) {
      rep(i,4){
        if (i==0 || (last < a[j] && a[j] <= last + 10)) {
          last = a[j];
          j++;
        }else{
          last+=10;
          ans++;
        }
      }
    }
    fout<<"Case #1: "<<ans<<endl;
  }
  return 0;
}
