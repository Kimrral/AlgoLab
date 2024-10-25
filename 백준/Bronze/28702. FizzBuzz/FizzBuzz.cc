#include <iostream>
#include <vector>
#include <string>

std::string nextFizzBuzz(const std::vector<std::string>& inputs) {
    int lastValue = 0;

    for (const auto& s : inputs) {
        if (s == "Fizz") {
            lastValue = (lastValue / 3 + 1) * 3;
        } else if (s == "Buzz") {
            lastValue = (lastValue / 5 + 1) * 5;
        } else if (s == "FizzBuzz") {
            lastValue = (lastValue / 15 + 1) * 15;
        } else {
            lastValue = std::stoi(s);
        }
    }
    
    lastValue++;

    if (lastValue % 3 == 0 && lastValue % 5 == 0) {
        return "FizzBuzz";
    } else if (lastValue % 3 == 0) {
        return "Fizz";
    } else if (lastValue % 5 == 0) {
        return "Buzz";
    } else {
        return std::to_string(lastValue);
    }
}

int main() {
    std::vector<std::string> inputs(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> inputs[i];
    }
    std::cout << nextFizzBuzz(inputs) << std::endl;
    return 0;
}
