#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int calculateTotalDistance(std::vector<int>& leftList, std::vector<int>& rightList) {
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); ++i) {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    return totalDistance;
}

void readFileToVector(std::vector<int>& leftList, std::vector<int>& rightList) {
    std::ifstream file("../day1.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int left, right;
        if (iss >> left >> right) {
            leftList.push_back(left);
            rightList.push_back(right);
        }
    }

    file.close();
}

int calculateSimilarityScore(const std::vector<int>& leftList, const std::vector<int>& rightList) {
    std::unordered_map<int, int> rightFrequency;
    int similarityScore = 0;

    for (int num : rightList) {
        rightFrequency[num]++;
    }

    for (int leftNum : leftList) {
        similarityScore += leftNum * rightFrequency[leftNum];
    }

    return similarityScore;
}

int main() {
    std::vector<int> leftList = {};
    std::vector<int> rightList = {};

    readFileToVector(leftList, rightList);
    const int totalDistance = calculateTotalDistance(leftList, rightList);
    const int similarityScore = calculateSimilarityScore(leftList, rightList);

    std::cout << "Total Distance: " << totalDistance << std::endl;
    std::cout << "Similarity Score: " << similarityScore << std::endl;

    /*
     *  Right answers for me
     *  Total Distance: 1873376
     *  Similarity Score: 18997088
     */
}
