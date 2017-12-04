#include <array>
#include <iostream>
#include <string>
#include <algorithm>

int getbulls(std::array<bool,9> code, std::array<bool,9>guess, int& bulls);
int getcows(std::array<bool,9> sortedcode, std::array<bool,9> guess, int bulls, int& cows);

auto sortcode = [](auto container)
{std::stable_sort(container.begin(),container.end()); return container;};

int gm2loop()
{
    std::string input;
    std::array<bool,9> code;
    std::cout << "Please enter the code\n>";
    auto sortedcode = sortcode(code);

    std::array<bool,9> guess {0,0,0,0,0,0,0,0,0};
    while(std::cin >> input)
    {
        auto bulls = 0;
        auto cows = 0;
        int it = 0;
        for(auto& i : input){
            code.at(it) = (i == '1');
            ++it;
        }
        std::cout << "autobulls: " << getbulls(code,guess,bulls);
        std::cout << "autocows: " << getcows(sortedcode, guess, bulls, cows);
    }
    return 0;
}
