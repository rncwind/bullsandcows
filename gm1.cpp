#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

int getbulls(std::array<bool,9> code, std::array<bool,9>guess);
int getcows(std::array<bool,9> code, std::array<bool,9>guess, int bulls);

//lambda to print a container, saves on boilerplate
auto const printcontainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

int gm1loop()
{
    std::cout << "Gamemode 1 Selected\n";
    std::array<bool,9> code {0,0,1,1,0,0,0,0,0};
    std::array<bool,9> guess;

    std::array<bool,9> sortedcode;
    auto sortcode = [](auto container)
    {std::stable_sort(container.begin(),container.end()); return container;};
    sortedcode = sortcode(code);

    std::string input;
    while(std::cin >> input)
    {
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
            std::cout << "Bulls: ";
            int bulls = getbulls(code,guess);
            getcows(sortedcode, guess, bulls);
            std::cout << '\n';
        }
    }
    std::cout << std::endl;
    return 0;
}

int getbulls(std::array<bool,9> code, std::array<bool,9>guess)
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
    std::cout << bulls << ' ';
    return bulls;
}

int getcows(std::array<bool,9> sortedcode, std::array<bool,9> guess, int bulls)
{
    std::stable_sort(guess.begin(),guess.end());
    std::cout << "\nsorted guess\n";
    printcontainer(guess);
    std::cout << "sorted code\n";
    printcontainer(sortedcode);

    auto tempcows = 0;
    auto cit = sortedcode.begin();
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
