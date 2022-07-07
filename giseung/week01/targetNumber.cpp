#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int sum, int cnt, int target){
    if(cnt >= numbers.capacity()){
        if(target == sum)
            return 1;        
        else
            return 0;
    }
    cnt++;
    return dfs(numbers, sum+numbers[cnt-1],cnt,target) + dfs(numbers, sum-numbers[cnt-1],cnt,target);
}
int solution(vector<int> numbers, int target) {
    int answer = dfs(numbers, 0, 0, target);
    return answer;
}