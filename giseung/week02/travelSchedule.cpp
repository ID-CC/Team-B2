#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> answers;

void DFS(vector<vector<string>> tickets, vector<string> answer){
    if(tickets.empty())
        answers.push_back(answer);
    int cnt = 0;
    for(auto ticket:tickets){
        if(answer.empty()){
            if(ticket[0] == "ICN"){
                vector<vector<string>> tmptickets = tickets;
                tmptickets.erase(tmptickets.begin()+cnt);
                answer.push_back(ticket[0]);
                answer.push_back(ticket[1]);
                DFS(tmptickets, answer);
                answer.pop_back();
                answer.pop_back();
            }
        }
        else if((answer.back()) == ticket[0]){
            vector<vector<string>> tmptickets = tickets;
            tmptickets.erase(tmptickets.begin()+cnt);
            answer.push_back(ticket[1]);
            DFS(tmptickets, answer);
            answer.pop_back();
        }
        cnt ++;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    DFS(tickets, answer);
    sort(answers.begin(),answers.end());
    return answers[0];
}
