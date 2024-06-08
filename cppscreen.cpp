#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include "screen.h"

void refreshScreen(Screen& screen){
    std::string newFrame = screen.returnScreen();
    #ifdef _WIN32
        system("cls");  // Clear console on Windows
    #else
        system("clear");  // Clear console on Unix-based systems
    #endif
    std::cout << newFrame << std::flush;
    Sleep(50);
}

void drawCircle(Screen& terminalScreen, char character) {
    std::vector<std::pair<int, int>> coordinates = {
    {0, 6}, {0, 7}, {0, 8}, {0, 9}, {0, 10}, {0, 11}, {0, 12}, {0, 13},
    {1, 14}, {1, 15}, {1, 16},
    {2, 17}, {2, 18},
    {3, 19}, {4, 19}, {5, 19}, {6, 19},
    {7, 18}, {7, 17},
    {8, 16}, {8, 15}, {8, 14},
    {9, 13}, {9, 12}, {9, 11}, {9, 10}, {9, 9}, {9, 8}, {9, 7}, {9, 6},
    {8, 5}, {8, 4}, {8, 3},
    {7, 2}, {7, 1},
    {6, 0}, {5, 0}, {4, 0}, {3, 0},
    {2, 1}, {2, 2},
    {1, 3}, {1, 4} ,{1, 5}
    };
    for (const auto& coord : coordinates) {
        refreshScreen(terminalScreen);
        terminalScreen.writePixel(coord.second, coord.first, character);
    }
}

int main(){
    const int screenHeight = 10;
    const int screenWidth = 20;
    Screen terminalScreen(screenHeight, screenWidth, '.');
    refreshScreen(terminalScreen);
    while(true)
    {
    drawCircle(terminalScreen, 'O');
    drawCircle(terminalScreen, 'X');
    }
    return 0;
}