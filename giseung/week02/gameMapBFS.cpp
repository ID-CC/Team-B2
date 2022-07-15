#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    queue<int> nexts; // 다음에 방문할 노드
    int answer = -1; // 기본 answer -1로 초기화 (해 못찾으면 -1을 반환해야하므로)
    int row = maps.size(); 
    int col = maps[0].size();
    int cals[4][2] = { {1,0},{-1,0},{0,1},{0,-1}};
    // 위, 아래, 오른쪽, 왼쪽 방문배열
    nexts.push(0); // 처음 방문 하는곳 입력
    for (auto &map : maps){
    // 기본적으로 벽이 0이고 길이 1인데 길자체를 이동한 거리로 입력할 것이므로 벽을 -1, 길을 0으로 변경한다.
        for(auto &m : map){
            if(m == 1)
                m =0;
            else
                m = -1;
        }
    }
    while(!nexts.empty()){
        int n = nexts.front();
        nexts.pop();
        int r = n/col;
        int c = n%col;
        if(r == row-1 && c == col-1){
            answer = maps[r][c]+1; // 처음 시작한 길도 포함이므로 1을 더해중
            break;
        }
        for (auto cal : cals){
            if(0<=cal[0]+r && cal[0]+r < row && 0<=cal[1]+c && cal[1]+c < col){
                if(maps[cal[0]+r][cal[1]+c] == 0){
                    maps[cal[0]+r][cal[1]+c] = maps[r][c] +1;
                    nexts.push((cal[0]+r)*col + cal[1]+c);
                }
            }
        }    
    }
    
    return answer;
}
