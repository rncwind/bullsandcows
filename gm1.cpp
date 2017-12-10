#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <vector>

//function prototypes
int getBulls(const std::array<bool,9>& code, const std::array<bool,9>& guess, int& bulls);
int getCows(const std::array<bool,9>& sortedcode, const std::array<bool,9>& guess, const int& bulls, int& cows);

//lambdas for reccurant boilerplate
//names are self doccumenting, code on one line for style
auto const printContainer = [](const auto& container)
{for(auto& i : container) std::cout << i; std::cout << '\n';};

//takes a copy of the code and sorts it returning the sorted copy. used later to find cows
auto sortCode = [](auto container)
{std::stable_sort(container.begin(),container.end()); return container;};

//takes in a string and an array, convers string to array values
auto strToBoolArr = [](auto& container, const std::string& input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

void generateCode(std::array<bool,9>& code)
{
    //get entropy from platform entropy source (eg /dev/random for *nix)
    //create a mersenne twister from it and use that in a [0,1] distribution
    //to generate randoms for the code passed in as refference
    std::random_device rdev;
    std::mt19937 twister(rdev());
    std::uniform_int_distribution<int> distrib(0,1);
    for (int it = 0; it < 9; ++it)
           code.at(it) = distrib(twister);
}

//main game loop and control logic
//lots of pretty printing and other magic, pretty boring
int gm1loop()
{
    std::array<bool,9> code;
    generateCode(code);
    std::array<bool,9> guess;
    std::array<bool,9> sortedcode;
    sortedcode = sortCode(code);
    int attempts = 0;
    std::string input;
    auto bulls = 0;
    auto cows = 0;
    while (attempts < 7)
    {
        bulls = 0;
        cows = 0;
        std::cout << "Attempt " << attempts+1 << "/7\n>";
        std::cin >> input;
        strToBoolArr(guess,input);
        std::cout << "Your guess is: ";
        printContainer(guess);
        if (guess == code){
            std::cout << "You guessed correctly" << std::endl;
            return 0;
        }
        else{
            std::cout << "Bulls: " << getBulls(code,guess,bulls) << '\n';
            std::cout << "Cows: " << getCows(sortedcode,guess,bulls,cows) << '\n';
        }
        ++attempts;
    }
    std::cout << "You ran out of attempts! Game over!\n";
    std::cout.flush();
    return 1;
}

//iterate through the contents of the guess and the code comparing values symmetrically
//if the same incriment bulls. bulls passed as refference for genericism's sake
int getBulls(const std::array<bool,9>& code, const std::array<bool,9>& guess, int& bulls)
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

//simmilar to getCows, however operating on a sorted copy of the code to break.
//if there are more matches found in this version, subtracts the amount of bulls from the cows to
//provide an accurate figure.
//cows passed in for genericism, bulls passed in as a copy
int getCows(const std::array<bool,9>& sortedcode, const std::array<bool,9>& guess, const int& bulls, int& cows){
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
