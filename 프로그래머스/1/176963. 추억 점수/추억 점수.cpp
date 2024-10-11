#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> solution(std::vector<std::string> name, std::vector<int> yearning, std::vector<std::vector<std::string>> photo) {
    // 그리움 점수를 이름을 기준으로 매핑
    std::unordered_map<std::string, int> yearningMap;
    for (size_t i = 0; i < name.size(); ++i) {
        yearningMap[name[i]] = yearning[i];
    }

    // 결과를 저장할 배열 초기화
    std::vector<int> result;
    
    for (size_t i = 0; i < photo.size(); ++i) {
        int score = 0;
        for (const std::string& person : photo[i]) {
            auto it = yearningMap.find(person);
            if (it != yearningMap.end()) {
                score += it->second;
            }
        }
        result.push_back(score);
    }

    return result;
}

int main() {
    std::vector<std::string> name1 = {"may", "kein", "kain", "radi"};
    std::vector<int> yearning1 = {5, 10, 1, 3};
    std::vector<std::vector<std::string>> photo1 = {{"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}};
    std::vector<int> result1 = solution(name1, yearning1, photo1);

    std::vector<std::string> name2 = {"kali", "mari", "don"};
    std::vector<int> yearning2 = {11, 1, 55};
    std::vector<std::vector<std::string>> photo2 = {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}};
    std::vector<int> result2 = solution(name2, yearning2, photo2);

    std::vector<std::string> name3 = {"may", "kein", "kain", "radi"};
    std::vector<int> yearning3 = {5, 10, 1, 3};
    std::vector<std::vector<std::string>> photo3 = {{"may"}, {"kein", "deny", "may"}, {"kon", "coni"}};
    std::vector<int> result3 = solution(name3, yearning3, photo3);

    // 출력
    for (int score : result1) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    for (int score : result2) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    for (int score : result3) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    return 0;
}