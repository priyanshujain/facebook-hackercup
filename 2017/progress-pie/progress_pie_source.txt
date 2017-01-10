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

struct point{
  int x;
  int y;
};

float angleBetween(point v1, point v2)
{
    float len1 = sqrt(v1.x * v1.x + v1.y * v1.y);
    float len2 = sqrt(v2.x * v2.x + v2.y * v2.y);

    float dot = v1.x * v2.x + v1.y * v2.y;

    float a = dot / (len1 * len2);

    if (a >= 1.0)
        return 0.0;
    else if (a <= -1.0)
        return pi;
    else
        return acos(a); // 0..PI
}
bool areClockwise(point p1,point p2, int p) {
  p1.x = p1.x - 50;
  p1.y = p1.y - 50;
  p2.x = p2.x - 50;
  p2.y = p2.y - 50;
  int k = angleBetween(p1, p2)* 180 /pi;
  if (p2.x < 0 ) {
    k = 360 -k;
  }
  return ( k < p*0.01*360);
}

bool isWithinRadius(point v,int radiusSquared) {
  v.x = abs(v.x - 50);
  v.y = abs(v.y - 50);
  return v.x*v.x + v.y*v.y <= radiusSquared;
}

bool isInsideSector(point v, int p, int radiusSquared) {
  point center;
  center.x = 50;
  center.y = 50;
  //v.x = v.x - center.x;
  //v.y = v.y - center.y;
  point sectorStart, sectorEnd;
  sectorStart.x = 50;
  sectorStart.y = 100;
  sectorEnd.x = (sectorStart.y-50)*sin(p*0.001*360* pi / 180) + (sectorStart.x-50)*cos(p*0.001*360* pi / 180) + 50;

  sectorEnd.y = (sectorStart.y-50)*cos(p*0.001*360* pi / 180) - (sectorStart.x-50)*sin(p*0.001*360* pi / 180) + 50;

  return areClockwise(sectorStart, v,p) && isWithinRadius(v, radiusSquared);
}

int main() {

    std::ifstream in("progress_pie.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("progress_pie_output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    int t; cin>>t;
    rep(i,t){
      int p,a,b;
      cin>>p>>a>>b;
      point v;
      v.x = a;
      v.y = b;
      if (!(isInsideSector(v, p, 50*50))) {
        cout<<"Case #"<<(i+1)<<": white"<<endl;
      }else{
        cout<<"Case #"<<(i+1)<<": black"<<endl;
      }
    }
    return 0;
  }
