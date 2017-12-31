#include <iostream>
#include <vector>

int main() {
    std::vector<int> array = {-1, -2, -3, -4, -5};
    std::pair<int, int> indices = std::make_pair(-1,0);
    auto min_sum = array[0];
    auto max_sum = array[0];
    auto sum = 0;
    for(auto i = 0; i < array.size(); i++) {
        sum += array[i];
        if (sum < min_sum) {
            min_sum = sum;
            indices.first = i;
        }
        if (sum - min_sum > max_sum) {
            max_sum = sum - min_sum;
            indices.second = i;
        }
    }
    std::cout << "max_sum " << max_sum << " from " << indices.first + 1 << " to " << indices.second << std::endl;
}