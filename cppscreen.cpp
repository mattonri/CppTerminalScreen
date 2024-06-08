#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <string>
char** createScreen(int screenHeight, int screenWidth){
    char** matrix = new char*[screenHeight];
    for (int i = 0; i < screenHeight; ++i) {
        matrix[i] = new char[screenWidth];
    }
    for (int i = 0; i < screenHeight; ++i) {
        for (int j = 0; j < screenWidth; ++j) {
            matrix[i][j] = '#';
        }
    }

    return matrix;
}

void refreshScreen(char** screen, int screenHeight, int screenWidth){
    #ifdef _WIN32
        system("cls");  // Clear console on Windows
    #else
        system("clear");  // Clear console on Unix-based systems
    #endif
    for (int i = 0; i < screenHeight; ++i) {
        for (int j = 0; j < screenWidth; ++j) {
            std::cout << screen[i][j];
        }
        std::cout << std::endl;
    }
}
int main(){
    const int screenHeight = 20;
    const int screenWidth = 50;
    char** screen = createScreen(screenHeight, screenWidth);
    std::cout << "Hello, World! I am invisible!" << std::endl;
    std::cout << "Hello, World! I am \033[34mblue\033[0m!" << std::endl;
    std::string output = "Hello";
    output += "\n"; // Append std::endl to the string
    output += "World";
    std::cout << output;

    // refreshScreen(screen, screenHeight, screenWidth);
    Sleep(100);
    screen[5][2] = ' ';
    Sleep(100);
    // refreshScreen(screen, screenHeight, screenWidth);
    return 0;
}
