//
// Created by Mahidhar Rajala on 9/17/17.
//

#include <vector>
#include <string>
#include <iostream>

std::vector<int> get_prefix_table(const std::string& str) {
    std::vector<int> prefix_table(str.size());
    // j have longest prefix match length for the string of length i.
    int j = 0;
    int i = 1;
    // prefix match length for 0th index is 0. As string of length 1, don't have
    // either prefix or suffix
    prefix_table[0] = 0;
    while ( i < str.size()) {
        // check if ith char in string matches char at longest_prefix_match_length
        if (str[i] == str[j]) {
            prefix_table[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = prefix_table[j - 1];
            } else {
                prefix_table[i] = 0;
                i++;
            }
        }
    }
    return prefix_table;
}

int main(int argc, char* argv[]) {
    //std::string str("BANANA");
    //std::string str("ANANAB");
    std::string str("ABAB");
    // get the reverse string
    std::string rstr(str);
    std::reverse(rstr.begin(), rstr.end());
    std::string cstr(str + rstr);
    // find the longest prefix match
    std::vector<int> lpt = get_prefix_table(cstr);
    std::for_each(lpt.begin(), lpt.end(), [] (auto item) {
        std::cout << item << " ";
    });
    std::cout << std::endl;
    // from reverse string get the substring excluding longest prefix match string and prepend to the
    // original string
    std::cout << "prefix string for making shortest palinedrome " << rstr.substr(0, rstr.size() - lpt[cstr.size()-1]) << std::endl;
    std::string palinedrome(rstr.substr(0, rstr.size() - lpt[cstr.size()-1]) + str);
    std::cout << "shortest palinedrome of " << str << " is " << palinedrome << std::endl;
}

