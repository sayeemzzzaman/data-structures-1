#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int n;
  cin >> n;

  double cuberoot = n/3.000;
  double temp = 0.000;

  while(cuberoot!=temp){
    temp = cuberoot;
    cuberoot = (n/(temp*temp)+(temp*2.000))/3.000;
  }
  cout << setprecision(3) << fixed << cuberoot << endl;
}