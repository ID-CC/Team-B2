#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int minNum = 201;

void dfs(string begin, string target, vector<string> words, int cnt, int len, vector<string> isVisited) {
    if(begin == target){
        if (minNum > cnt)
            minNum = cnt;
    }
    for(auto word: words){
        int strCnt = len;
        for(int i = 0; i< len; i++){
            if(word[i] == begin[i])
                strCnt--;
        }
        if(strCnt == 1){
            
            auto it = find(isVisited.begin(),isVisited.end(),word);
            if (it == isVisited.end()){
                //cout << "word: " << word << endl;
                isVisited.push_back(word);
                dfs(word, target, words, cnt+1, len,isVisited);
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    vector<string> isVisited;
    dfs(begin, target,words, 0, begin.length(),isVisited);
    int answer = minNum;
    if(answer == 201)
        answer = 0;
    return answer;
}