#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n,1);
    
    for(auto l : lost)
        students[l-1]--;
    for(auto r : reserve)
        students[r-1]++;
    for(int i=1; i<=students.size();i++){
        if(students[i-1]==2 && students[i]==0)
            students[i-1] = students[i] =1;
        if(students[i]==0 && students[i+1]==2)
            students[i] = students[i+1] =1;
    }
    for(int i=0; i<students.size();i++){
        if(students[i] > 0) answer++;
    }
    
    return answer;
}