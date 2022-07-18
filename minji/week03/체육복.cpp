#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int student[31] = {0, };
    int answer = 0;

    int i = lost.size();
    while (--i >= 0) {
        student[lost[i]] -= 1;
    }

    i = reserve.size();
    while (--i >= 0) {
        student[reserve[i]] += 1;
    }

    for (i = 1; i <= n; i++) {
        answer++;
        if (student[i] < 0) {
            if (student[i - 1] > 0) student[i] = student[i - 1] = 0;
            else if (student[i + 1] > 0) student[i] = student[i + 1] = 0;
            else answer--;
        }
    }

    return answer;
}