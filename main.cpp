#include <iostream>
#include <vector>

int gameloop();

int main()
{
    std::cout << "enter (1) for Gamemode 1\nenter (2) for Gamemode2\n>";
    int mode = 0;
    std::cin >> mode;
    switch(mode){
    case 1:
        gameloop(); break;
    case 2:
        break;
    }
    return 0;
}
