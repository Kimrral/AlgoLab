#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int t = 0;
while(true)
{
    t++;
    if(n%t==1)
    {
        answer=t;
        break;
    }
}
    return answer;
}