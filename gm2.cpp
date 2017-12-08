#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <algorithm>
#include <map>

std::array<bool,9> indexToCode(int i);
int getBulls(const std::array<bool,9>& code, const std::array<bool,9>& guess, int& bulls);
int getCows(const std::array<bool,9>& sortedcode, const std::array<bool,9>& guess, const int& bulls, int& cows);
void informed(std::array<bool,9> code, std::array<bool,512>& guesses);

auto const printContainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto sortCode = [](auto container)
{std::stable_sort(container.begin(),container.end()); return container;};

auto strToBoolArr = [](auto& container, std::string input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

void fillmap(std::array<bool,512>& guesses)
{
    for (auto i = 0; i < 512; ++i)
    {
        guesses[i] = true;
    }
}

int gm2loop()
{
    std::array<bool,512> guesses;
    std::string input;
    std::array<bool,9> code;
    std::cout << "Input your code\n>";
    std::cin >> input;
    strToBoolArr(code,input);
    std::cout << "\nInformed Values\n";
    informed(code, guesses);
    return 0;
}

std::array<bool,9> indexToCode(int i){
    std::string codestr = std::bitset<4>(i).to_string();
    std::array<bool,9> code;
    strToBoolArr(code,codestr);
    return code;
}

//gets the next guess from the list of valid guesses
int getnextguess(std::array<bool,512>& guesses)
{
    for(int i = 0; i < 512; ++i)
    {
        if(guesses.at(i) == true)
            return i;
    }
    return 0;
}

//invalidates guesses based on the previous guesses, and the amount of bulls in the previous guess
void invalidateguesses(std::array<bool,9>& code, std::array<bool,512>& guesses, int bulls, int tempguess)
{
    for(int i = 0; i < 512; ++i)
    {
        auto tbulls = 0;
        guesses.at(tempguess) = false;
        if(getBulls(code,indexToCode(i),tbulls) < bulls)
            guesses.at(i) = false;
    }
}

void informed(std::array<bool,9> code, std::array<bool,512>& guesses)
{
    int tempguess = 0;
    std::array<bool,9> guess = {0,0,1,1,0,0,1,1,0};
    while (guess != code)
    {
        auto bulls = 0;
        auto cows = 0;
        tempguess = getnextguess(guesses);
        guess = indexToCode(tempguess);
        std::cout << "\nBulls: " << getBulls(code,guess,bulls);
        std::cout << "\nCows: " << getCows(sortCode(code),guess,bulls,cows);
        if (bulls == 9)
        {
            break;
        }
        invalidateguesses(code,guesses,bulls, tempguess);
    }
    std::cout << "\nCode found!\n";
}
