#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// 문자열을 공백 기준으로 분리하여 정수 벡터로 변환
std::vector<int> parseNumbers(const std::string& line) {
    std::vector<int> numbers;
    std::istringstream iss(line);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// 벡터가 정렬되었는지 확인
bool isSorted(const std::vector<int>& numbers) {
    for (std::size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i - 1] > numbers[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        // "After: "로 시작하는 줄만 처리
        if (line.substr(0, 7) == "After: ") {
            std::string sequence = line.substr(7); // "After: " 뒤의 내용
            std::vector<int> numbers = parseNumbers(sequence);

            // 정렬 여부 확인
            bool sorted = isSorted(numbers);

            // 결과 출력
            std::cout << "sequence sorted: "
                      << (sorted ? "Yes" : "No") << std::endl;
        }
    }

    file.close();
    return 0;
}
