#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

void getbulls(std::array<bool,4> code, std::array<bool,4>guess);
int getcows(std::array<bool,4> code, std::array<bool,4>guess, int bulls);

int gameloop()
{
    std::array<bool,4> code {false,false,true,true};
    std::array<bool,4> guess;
    std::string input;
    while(std::cin >> input)
    {
        guess.empty();
        int it = 0;
        for (auto& i : input){              //hack to convert str to arr of bool
            guess.at(it) = (i == '1');
            ++it;
        }
        std::cout << "\nyour guess is\n";
        for (auto i : guess)
            std::cout << i;
        std::cout << "\n";

        if (guess == code)
        {
            std::cout << "You gussed correctly!" << std::endl;
            return 0;                                           //indicate success
        }
        else{
            std::cout << "Bulls: ";
            getbulls(code,guess);
            std::cout << '\n';
        }
    }
    return 0;
}

void getbulls(std::array<bool,4> code, std::array<bool,4>guess)
{
    auto bulls = 0;
    auto cit = code.begin();
    auto git = guess.begin();
    while (git != guess.end()){
        if (*git == *cit)
            ++bulls;
        ++git;
        ++cit;
    }
    std::cout << bulls;
    getcows(code,guess,bulls);
}

int getcows(std::array<bool,4> code, std::array<bool,4> guess, int bulls)
{
    std::stable_sort(guess.begin(),guess.end());
    std::stable_sort(code.begin(), code.end());
    std::cout << "\nsorted guess\n";
    for (auto i : guess)
        std::cout << i;
    std::cout << "\nsorted code\n";
    for (auto i : code)
        std::cout << i;
    std::cout << '\n';

    auto tempcows = 0;
    auto cit = code.begin();
    auto git = guess.begin();
    while (git != guess.end()){
        if (*git == *cit)
            ++tempcows;
        ++git;
        ++cit;
    }
    std::cout << "Cows: " << (tempcows-bulls);
    return tempcows;
}

/*
int getcows(std::array<bool,4> code, std::array<bool,4>guess)
{
    auto cows = 0;
    auto cit = code.begin();
    auto git = guess.begin();
    while (git != guess.end()){
        if (*git != *cit)
            ++cows;
        ++git;
        ++cit;
    }
    return cows;    
}
*/
