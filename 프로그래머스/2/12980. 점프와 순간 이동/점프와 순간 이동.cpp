#include <iostream>

int solution(int n) {
    const int K = 2; // 순간이동 가능한 칸수 (고정값)
    int ans = 0; // 건전지 사용량 초기값
    
    while (n > 0) {
        if (n % 2 == 0) {
            // n이 짝수인 경우, 순간이동 가능
            n /= 2;
        } else {
            // n이 홀수인 경우, 1 칸 앞으로 점프
            n--;
            ans++;
        }
    }
    
    return ans;
}

