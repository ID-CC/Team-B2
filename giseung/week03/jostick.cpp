#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int solution(string name) {
    int cursor = 0; // 현재 커서 위치
    int size = name.size(); // 사이즈
    string current = string(size,'A'); // 현재 입력된 값 초기화
    int answer = 0;
    int left_a = 0;
    int right_a = 0;
    for(int i=0; i<size; i++){
        int tmp = 0;
        tmp = abs(current[i]-name[i]);
        if(tmp > 13)
            tmp = 26-tmp;
        answer += tmp;
    }
    if(size >2){
        if(name[1] == 'A'){
            left_a++;
            for(int i=2; i<size; i++){
                if(name[i] == 'A')
                    left_a++;
                else
                    break;
            }
        }
        if(name[size-1] == 'A'){
            right_a++;
            for(int i=size-2; i>0; i--){
                if(name[i] == 'A')
                    right_a++;
                else
                    break;
            }
        }
    }
    int front_end_acnt = left_a>right_a? left_a:right_a;
    int max_a = 0;
    int max_index = 0;
    int min_index = 0;
    for(int i=1; i<size; i++){
        if(name[i] == 'A'){
            int cnt = 0;
            for(int j = i; name[j] == 'A' && j<size; j++)
                cnt ++;
            cout << cnt <<endl;
            if(max_a < cnt) {
                max_a = cnt;
                max_index = cnt + i-1;
                min_index = i;
            }
        }   
    }
    vector<int> result;
    result.push_back(size-1-front_end_acnt);
    result.push_back((min_index-1)*2+ (size - max_index-1));
    result.push_back((min_index-1)+ (size - max_index-1)*2);
    if(max_a == 0)
        return result[0] + answer;
    cout << max_index << " " <<min_index<< " " <<max_a << endl;
    for(auto r : result)
        cout << r <<" ";
    sort(result.begin(),result.end());
    answer += result[0];
    return answer;
}
