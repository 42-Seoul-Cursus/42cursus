#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdexcept>
#include <cstdlib>

std::vector<int> generateUniqueRandomNumbers(int count) {
    // 숫자 범위를 벡터로 생성
    std::vector<int> numbers;
    for (int i = 1; i <= count; ++i) {
        numbers.push_back(i);
    }

    // 벡터를 무작위로 섞기
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(numbers.begin(), numbers.end(), generator);

    // 요청한 개수만큼 반환
    return std::vector<int>(numbers.begin(), numbers.begin() + count);
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            throw std::invalid_argument("사용법: ./test [생성할 숫자의 개수]");
        }

        // 명령행 인자 파싱
        int count = std::atoi(argv[1]);

        // 난수 생성
        auto randomNumbers = generateUniqueRandomNumbers(count);

        // 결과 출력
        for (int num : randomNumbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "오류: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
