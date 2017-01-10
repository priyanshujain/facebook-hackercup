/*
Author - Priyanshu Jain
*/
//#include <atomic>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

#define mod 1000000007
#define inf 100000000000000000LL
double pi = 3.1415926535897;
struct _{ios_base::Init i; _(){
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}}_ ;
typedef long long int  ll;
#define pll pair<ll,ll>
#define ict int t;cin>>t;while(t--)
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define endl '\n'

int main() {

    std::ifstream in("lazy_loading.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("lazy_loading_output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    int t; cin>>t;
    rep(k,t){
      int n;
      cin>>n;
      int v[n];
      rep(j,n){
        cin>>v[j];
      }
      sort(v,v+n);
      int count=0;
      int sum= v[n-1];
      int start =0,end = n-1;
      while (start <= end) {
        if (sum >= 50 ) {
          count++;
          end--;
          sum = v[end];
        }else{
          sum = sum + v[end];
          start++;
        }
      }
      cout <<"Case #"<<k+1<<": "<<count<< endl;
    }
    return 0;
  }
