#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";   
    
    for(int i=0; i<s.length(); i++)
    {
        s[i]=tolower(s[i]);
    }
    
    s[0]=toupper(s[0]);
    
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==' ')
        {
            s[i+1]=toupper(s[i+1]);
        }
    }
    return s;
}