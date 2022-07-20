#include<iostream>
using namespace std;

int main(){
  int push_cnt = 1;
  string time_str;
  cin >> time_str;
  int min = (time_str[0]-48)*10+(time_str[1]-48);
  int sec = (time_str[3]-48)*10+(time_str[4]-48);
  if (sec >= 30){
    sec -= 30;
  } 
  sec += min*60;
  for(auto secIndex : {600,60,10}){
    int tmp = sec/secIndex;
    sec -= tmp*secIndex;
    push_cnt+=tmp;  
  }
  
  cout << push_cnt;
  return 0;
}
