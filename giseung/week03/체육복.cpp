#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    vector<int>::iterator iter = lost.begin();
    while(iter != lost.end()){
        for(int j = 0; j<reserve.size(); j++){
            if(*iter == reserve[j]){
                lost.erase(iter);
                reserve.erase(reserve.begin()+j);
                iter--;
                break;
            }
        }
        iter++;
    }
    int answer = n - lost.size();
    for(auto i : lost)
        cout << i << " ";
    cout << endl;
    for(auto i : reserve)
        cout << i << " ";
    cout << endl;
    for(auto lnum : lost){
        for(int i = 0; i< reserve.size();i++){
            if(lnum + 1 == reserve[i] || lnum - 1 == reserve[i] || lnum == reserve[i]){
                reserve.erase(reserve.begin()+i);
                answer++;
                break;
            }
        }
    }
    
    return answer;
}
