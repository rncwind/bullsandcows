#include <iostream>
#include <string>
#include <array>
#include <bitset>

std::array<bool,4> indexToCode(int i);
int getBulls(const std::array<bool,4>& code, const std::array<bool,4>& guess, int& bulls);
int getCows(const std::array<bool,4>& sortedcode, const std::array<bool,4>& guess, const int bulls, int& cows);

auto const printContainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto strToBoolArr = [](auto& container, std::string input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

void bruteforce(std::array<bool,4> code)
{
    for (int i = 0; i < 15; ++i)
    {
        if (indexToCode(i) == code)
        {
            std::cout << "Your code is: ";
            printContainer(indexToCode(i));
            std::cout << "found after " << i << " Iterations";
            break;
        }
    }
}

int gm2loop()
{
    std::string input;
    std::array<bool,4> code;
    std::cout << "Input your code\n>";
    std::cin >> input;
    strToBoolArr(code,input);
    bruteforce(code);
    return 0;
}

std::array<bool,4> indexToCode(int i){
    std::string codestr = std::bitset<4>(i).to_string();
    std::array<bool,4> code;
    strToBoolArr(code,codestr);
    return code;
}
