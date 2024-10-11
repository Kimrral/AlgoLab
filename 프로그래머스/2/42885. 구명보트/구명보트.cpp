#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    std::sort(people.begin(), people.end()); // 사람들의 몸무게를 오름차순으로 정렬
    int left = 0; // 가장 가벼운 사람을 가리키는 포인터
    int right = people.size() - 1; // 가장 무거운 사람을 가리키는 포인터
    int boats = 0; // 필요한 보트의 개수

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            // 가장 가벼운 사람과 가장 무거운 사람을 한 보트에 태울 수 있다면
            left++;
        }
        // 가장 무거운 사람은 항상 보트에 태움
        right--;
        boats++;
    }

    return boats; // 필요한 보트의 개수 반환
}