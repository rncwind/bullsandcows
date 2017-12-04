#include <iostream>
#include<string>
#include <vector>
#include <array>
#include <algorithm>

int getbulls(const std::array<bool,4>& code, const std::array<bool,4>& guess, int& bulls);
int getcows(const std::array<bool,4>& sortedcode, const std::array<bool,4>& guess, const int bulls, int& cows);

auto const printcontainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto sortcode = [](auto container)
{std::stable_sort(container.begin(),container.end()); return container;};

auto strtoboolarr = [](auto& container, std::string input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

int gm1loop()
{
    std::array<bool,4> code {1,0,0,0};
    std::array<bool,4> guess;

    std::array<bool,4> sortedcode;
    sortedcode = sortcode(code);
    
    std::string input;
    while (std::cin >> input)
    {
        auto bulls = 0;
        auto cows = 0;
        guess.empty();
        strtoboolarr(guess,input);
        std::cout << "Your guess is: ";
        printcontainer(guess);
        if (guess == code){
            std::cout << "You guessed correctly" << std::endl;
            return 0;
        }
        else{
            std::cout << "Bulls: " << getbulls(code,guess,bulls) << '\n';
            std::cout << "\nCows: " << getcows(sortedcode,guess,bulls,cows) << '\n';
        }
    }
    return 0;
}

int getbulls(const std::array<bool,4>& code, const std::array<bool,4>& guess, int& bulls)
{
    auto cit = code.begin();
    auto git = guess.begin();
    while (git != guess.end()){
        if (*git == *cit)
            ++bulls;
        ++git;
        ++cit;
    }
    return bulls;
}


int getcows(const std::array<bool,4>& sortedcode, const std::array<bool,4>& guess, const int bulls, int& cows){
    auto scit = sortedcode.begin();
    auto guessit = guess.begin();
    while (guessit != guess.end()){
        if(*guessit == *scit)
            ++cows;
        ++scit;
        ++guessit;
    }
    if (cows > bulls)
        return (cows-bulls);
    else
        return 0;
}
