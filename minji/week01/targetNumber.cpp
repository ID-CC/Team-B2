#include <string>
#include <vector>

using namespace std;
int count = 0;

int DFS(int chkLen, int sum, vector<int> num, int target)
{
    int numLen = num.size();
    
    if(chkLen == numLen)
    {
        if(sum == target)
        {
            count++;
        }
    }
    else
    {
        DFS(chkLen+1, sum+num[chkLen], num, target);
        DFS(chkLen+1, sum-num[chkLen], num, target);
    }
    return count;
}

int solution(vector<int> numbers, int target) {
    return DFS(0, 0, numbers, target);
}