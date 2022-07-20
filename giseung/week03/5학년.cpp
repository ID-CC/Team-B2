#include<iostream>
using namespace std;

int main(){
  int semester, gpa, major;
  cin >> semester >> major >> gpa;
  while(semester < 8){
    semester++;
    int major_sub;
    int sub;
    cin >> major_sub >> sub;
    gpa += (major_sub + sub) > 6? 18 :(major_sub + sub)*3;
    major += major_sub > 6? 18 :major_sub*3;
  }
  if(major >= 66 && gpa >= 130)
    cout << "Nice";
  else
    cout << "Nae ga wae";
  return 0;
}
