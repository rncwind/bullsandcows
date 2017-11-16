#include <iostream>
#include <string>
#include <vector>

int getbulls(std::vector<bool> code, std::vector<bool>guess);
int getcows(std::vector<bool> code, std::vector<bool>guess);


int gameloop(){
    std::vector<bool> code {true,true,false,false};
    std::vector<bool> guess;
    while(true)
    {
        std::string input;
        std::cin >> input;
        guess.clear(); //clear already existing vec on each iteration
        for (auto i : input)
            guess.push_back(i == '1');      //kind of a hack to convert string value to bool
        std::cout << "\nyour guess is\n";
        for (auto i : guess)
            std::cout << i;
        std::cout << "\n";

        if (guess == code)
        {
            std::cout << "You gussed correctly!" << std::endl;
            return 0; //indicate success
        }
        else{
            std::cout << "Bulls: " << getbulls(code,guess) << '\n';
            std::cout << "Cows: " << getcows(code,guess) << '\n';
        }
    }
}

int getbulls(std::vector<bool> code, std::vector<bool>guess)
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
    return bulls;
}

int getcows(std::vector<bool> code, std::vector<bool>guess)
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

