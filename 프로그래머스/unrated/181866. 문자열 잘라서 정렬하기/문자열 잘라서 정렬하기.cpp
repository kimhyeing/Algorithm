#include <string>
#include <vector>
#include<sstream>
#include<algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    istringstream iss(myString);
    string buf;
    while(getline(iss,buf,'x')){
        if(buf == "") continue;
        answer.push_back(buf);
    }
    sort(answer.begin(), answer.end());
    return answer;
}