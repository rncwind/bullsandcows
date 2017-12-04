#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

int getbulls(std::array<bool,9> code, std::array<bool,9>guess, int& bulls);
int getcows(std::array<bool,9> sortedcode, std::array<bool,9> guess, int bulls, int& cows);

//lambda to print a container, saves on boilerplate
auto const printcontainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto sortcode = [](auto container)
{std::stable_sort(container.begin(),container.end()); return container;};


int gm1loop()
{
    std::cout << "Gamemode 1 Selected\n";
    std::array<bool,9> code {0,0,1,1,0,0,0,0,0};
    std::array<bool,9> guess;

    std::array<bool,9> sortedcode;
    sortedcode = sortcode(code);

    std::string input;
    while(std::cin >> input)
    {
        auto bulls = 0;
        auto cows = 0;
        //clear guess and read in values
        guess.empty();
        int it = 0;
        for (auto& i : input){              //hack to convert str to arr of bool
            guess.at(it) = (i == '1');
            ++it;
        }
        //print guess
        std::cout << "your guess is\n";
        printcontainer(guess);

        if (guess == code){
            std::cout << "You gussed correctly!" << std::endl;
            return 0;                                           //indicate success
        }
        else{
            std::cout << "Bulls: " << getbulls(code,guess, bulls);
            std::cout << "\nCows: " << getcows(sortedcode, guess, bulls, cows) << '\n';
        }
    }
    std::cout << std::endl;
    return 0;
}

int getbulls(std::array<bool,9> code, std::array<bool,9>guess, int& bulls)
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

int getcows(std::array<bool,9> sortedcode, std::array<bool,9> guess, int bulls, int& cows)
{
    std::stable_sort(guess.begin(),guess.end());
        auto tempcows = 0;
    auto cit = sortedcode.begin();
    auto git = guess.begin();
    while (git != guess.end()){
        if (*git == *cit)
            ++tempcows;
        ++git;
        ++cit;
    }
    cows = (tempcows - bulls);
    return cows;
}
