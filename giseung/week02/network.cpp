#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    queue<int> visited;
    int answer = 0;
    for(int i = 0; i<n; i++){
        if(accumulate(computers[i].begin(),computers[i].end(),0) == 1)
            answer++;
        for(int j = 0; j<n; j++)
            if(i!=j && computers[i][j] == 1 && computers[j][i] == 0){
                computers[j][i] = 1;
            }
    }
    for(int k = 0; k<n; k++){
        if(accumulate(computers[k].begin(),computers[k].end(),0) != 1){
            visited.push(k);
            answer++;
            while(!visited.empty()){
                int i = visited.front();
                visited.pop();
                for(int j = 0; j<n; j++){
                    if(j!=i && computers[i][j]){
                        visited.push(j);
                        computers[i][j]=0;
                        computers[j][i]=0;
                    }
                }          
            }    
        }
    }
    return answer;
}
