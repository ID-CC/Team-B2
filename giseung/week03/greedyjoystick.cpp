/*
그리디 알고리즘 특성상 모든 케이스에서 성공하지 않음 따라서 반례를 적용시키거나 완전탐색을 할 칠요가 있음
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(string name) {
    int cursor = 0; // 현재 커서 위치
    int size = name.size(); // 사이즈
    int evaluation[size]; // 평가함수값 , 커서에서의 위치
    string current = string(size,'A'); // 현재 입력된 값 초기화
    
    int answer = 0;
    for (int i = 0; i<size; i++){
        if(name[i] == 'A')
            evaluation[i] = 100;
    }
    for(int i=0; i<size; i++){
        int tmp = 0;
        tmp = abs(current[i]-name[i]);
        if(tmp > 13)
            tmp = 26-tmp;
        cout << tmp << endl;
        answer += tmp;
    }
    
    current[0] = name[0];
    while(current != name){
        int minIndex = 0;
        for(int i=0; i<size; i++){
            if(evaluation[i] != 100){
                int b = abs(cursor-i);
                if (b > size/2)
                    b = size - b;
                evaluation[i] = b;
                if(evaluation[minIndex] > evaluation[i])
                    minIndex = i;    
            }
        }
        for(int i=0;i<size;i++ )
            cout << evaluation[i] <<" ";
        cout << endl;
        current[minIndex] = name[minIndex];
        cursor = minIndex;
        answer += evaluation[minIndex];
        evaluation[minIndex] = 100;
    }
    
    return answer;
    
}
