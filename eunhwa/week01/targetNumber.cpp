#include <string>
#include <vector>

using namespace std;

void dfs_target_number(int& answer, vector<int> numbers, int target, int sum, int cnt){
    // 모든 n개의 정수를 모두 이용했고
    if(cnt == numbers.size()){
        // 모든 n개의 정수의 합이 target과 동일하면 방법횟수(answer) 증가++
        if(sum == target){
            answer++;
        }
        return;
    }
    dfs_target_number(answer, numbers,target, sum+numbers[cnt], cnt+1); // 더해주거나
    dfs_target_number(answer, numbers,target, sum-numbers[cnt], cnt+1); // 빼주거나
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs_target_number(answer,numbers,target,0,0);
    return answer;
}