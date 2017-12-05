#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <algorithm>
#include <map>

std::array<bool,4> indexToCode(int i);
int getBulls(const std::array<bool,4>& code, const std::array<bool,4>& guess, int& bulls);
int getCows(const std::array<bool,4>& sortedcode, const std::array<bool,4>& guess, const int bulls, int& cows);
void bruteforce(std::array<bool,4> code);
void informed(std::array<bool,4> code, std::map<int,bool>& guesses);

auto const printContainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto sortCode = [](auto container)
{std::stable_sort(container.begin(),container.end()); return container;};

auto strToBoolArr = [](auto& container, std::string input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

void fillmap(std::map<int,bool>& guesses)
{
    for (auto i = 0; i < 16; ++i)
    {
        guesses[i] = true;
    }
}

int gm2loop()
{
    std::map<int,bool> guesses;
    fillmap(guesses);
    std::string input;
    std::array<bool,4> code;
    std::cout << "Input your code\n>";
    std::cin >> input;
    strToBoolArr(code,input);
    std::cout << "Bruteforce\n";
    bruteforce(code);
    std::cout << "\n\nInformed Values\n";
    informed(code, guesses);
    return 0;
}

std::array<bool,4> indexToCode(int i){
    std::string codestr = std::bitset<4>(i).to_string();
    std::array<bool,4> code;
    strToBoolArr(code,codestr);
    return code;
}

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

//gets the next guess from the list of valid guesses
int getnextguess(std::map<int,bool>& guesses)
{
    for(int i = 0; i < 16; ++i)
    {
        if(guesses.at(i) == true)
            return i;
    }
    std::cout << "\n\nGETNEXTGUESS WENT WRONG!\n\n";
    return -1;
}

//invalidates guesses based on the previous guesses, and the amount of bulls in the previous guess
void invalidateguesses(std::array<bool,4>& code, std::map<int,bool>& guesses, int bulls, int tempguess)
{
    for(int i = 0; i < 16; ++i)
    {
        auto tbulls = 0;
        guesses.at(tempguess) = false;
        if(getBulls(code,indexToCode(i),tbulls) < bulls)
            guesses.at(i) = false;
    }
}

void informed(std::array<bool,4> code, std::map<int,bool>& guesses)
{
    int tempguess = 0;
    std::array<bool,4> guess = {0,0,1,1};
    while (guess != code)
    {
        auto bulls = 0;
        auto cows = 0;
        tempguess = getnextguess(guesses);
        guess = indexToCode(tempguess);
        std::cout << "Bulls: " << getBulls(code,guess,bulls);
        std::cout << "\nCows: " << getCows(sortCode(code),guess,bulls,cows);
        invalidateguesses(code,guesses,bulls, tempguess);
    }
    std::cout << "\n\nCode found!\n\n";
}
