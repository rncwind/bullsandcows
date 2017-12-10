#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <algorithm>
#include <map>

std::array<bool,9> indexToCode(int i);
int getBulls(const std::array<bool,9>& code, const std::array<bool,9>& guess, int& bulls);
void informed(std::array<bool,9>& code, std::array<bool,512>& guesses);

auto const printContainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto sortCode = [](auto container)
{std::stable_sort(container.begin(),container.end()); return container;};

auto strToBoolArr = [](auto& container, std::string input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

int gm2loop()
{
    std::array<bool,512> guesses;
    std::string input;
    std::array<bool,9> code;
    std::cout << "Input your code\n>";
    std::cin >> input;
    guesses.fill(true);
    strToBoolArr(code,input);
    informed(code, guesses);
    return 0;
}

std::array<bool,9> indexToCode(int i){
    std::string codestr = std::bitset<9>(i).to_string();
    std::array<bool,9> code;
    strToBoolArr(code,codestr);
    return code;
}

//gets the next guess from the list of valid guesses
int getnextguess(const std::array<bool,512>& guesses)
{
    for(int i = 0; i < 512; ++i)
    {
        if(guesses.at(i) == true)
            return i;
    }
    std::cout << "Something went wrong";
    return 0;
}

//invalidates guesses based on the previous guesses, and the amount of bulls in the previous guess
void invalidateguesses(std::array<bool,9>& code, std::array<bool,512>& guesses, int bulls, int tempguess)
{
    auto tbulls = 0;
    auto tcows = 0;
    guesses.at(tempguess) = false;
    for(int i = 0; i < 512; ++i)
    {
        tbulls = 0;
        tcows = 0;
        getBulls(code,indexToCode(i),tbulls);
        if(tbulls <= bulls)
            guesses.at(i) = false;
    }
}

void informed(std::array<bool,9>& code,std::array<bool,512>& guesses)
{
    int attempts = 0;
    int tempguess = 0;
    std::array<bool,9> guess = {0,0,0,0,0,0,0,0,0};
    while (attempts < 7)
    {
        auto bulls = 0;
        tempguess = getnextguess(guesses);
        guess = indexToCode(tempguess);
        std::cout << "Attempt " << attempts+1 << "/7 guess is: ";
        printContainer(guess);
        std::cout << "Bulls: " << getBulls(code,guess,bulls);
        std::cout << '\n';
        if (bulls == 9)
        {
            std::cout << "\nCode found!\n";
            std::cout << "Your code was ";
            printContainer(code); 
            break;
        }
        invalidateguesses(code,guesses,bulls,tempguess);
        ++attempts;
    }
}
