/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached help.txt file
*/

#pragma once

#include <iostream>
#include <string>

/*
For keyboard input
*/

extern SDL_Window *window;

// for Window resolution
extern int windowWidth;
extern int windowHeight;
extern int textWidth, textHeight;
extern bool isFullScreen;
extern int scene;
extern int lastScene;
extern std::string osVersion;
extern bool gameStarted;
extern int selectedOption;
extern int menuTotalOptions;
// unique to keyboard AND possibly gamepad?
extern bool quitEventLoop;
extern int rectWidth;
extern int rectHeight;
// README SCROLL VARIABLES
extern int scrollY;
extern int scrollSpeed;

// FUNCTION PROTOTPES
void change_resolution(int newWindowWidth, int newWindowHeight);
void is_scene_unlocked(int target);
void new_game();
void exit_SDL();
std::string find_os();
void render_fps();

void handle_gamepad_scene_1(int button)
{
    // SDL_Rect menuLoadGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25), rectWidth, rectHeight};
    SDL_Rect menuNewGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25), rectWidth, rectHeight};
    SDL_Rect menuSettingsRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.35), rectWidth, rectHeight};
    SDL_Rect menuAchievementsRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.45), rectWidth, rectHeight};
    SDL_Rect menuHelpRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.55), rectWidth, rectHeight};
    SDL_Rect menuGameUpdateRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.65), rectWidth, rectHeight};
    SDL_Rect menuQuitRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.75), rectWidth, rectHeight};
    SDL_Rect AgniSamoohLogoRect = {static_cast<int>(windowWidth * 0.73), static_cast<int>(windowHeight * 0.85), (windowWidth) / 6, (windowHeight) / 6};

    // Highlight the selected option for keyboard arrow key and gamepad d pad key input
    SDL_Rect selectedRect = {
        static_cast<int>(windowWidth * 0.35),
        static_cast<int>(windowHeight * 0.25) + selectedOption * 100, // Adjust spacing as needed
        rectWidth,
        rectHeight};

    SDL_Point selectedPoint = {selectedRect.x, selectedRect.y}; // This is the selectedRect which overlaps the button rects

    switch (button)
    {
    case SDL_CONTROLLER_BUTTON_START:
        std::cout << "You pressed controller button: START" << std::endl;
        quitEventLoop = true;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        std::cout << "You pressed controller button: Up" << std::endl;
        selectedOption = (selectedOption - 1 + menuTotalOptions) % menuTotalOptions;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        std::cout << "You pressed controller button: Down" << std::endl;
        selectedOption = (selectedOption + 1) % menuTotalOptions;
        break;
    case SDL_CONTROLLER_BUTTON_A:
        std::cout << "You pressed controller button: A" << std::endl;
        /*
        if (SDL_PointInRect(&selectedPoint, &menuLoadGameRect))
        {
            std::cout << "You clicked Load Game" << std::endl;
            load_game();
        }
        */
        if (SDL_PointInRect(&selectedPoint, &menuNewGameRect))
        {
            std::cout << "You clicked Start Game" << std::endl;
            new_game();
        }
        else if (SDL_PointInRect(&selectedPoint, &menuSettingsRect))
        {
            std::cout << "You clicked Settings" << std::endl;
            scene = 2;
        }
        else if (SDL_PointInRect(&selectedPoint, &menuAchievementsRect))
        {
            std::cout << "You clicked Achievements" << std::endl;
            scene = 4;
        }
        else if (SDL_PointInRect(&selectedPoint, &menuHelpRect))
        {
            std::cout << "You clicked Help" << std::endl;
            scene = 5;
        }
        else if (SDL_PointInRect(&selectedPoint, &menuGameUpdateRect))
        {
            std::cout << "You clicked Update game" << std::endl;
            // start_game_update_1();
        }
        else if (SDL_PointInRect(&selectedPoint, &menuQuitRect))
        {
            std::cout << "You clicked Quit game" << std::endl;
            // save_game();
            exit_SDL();
            exit(0);
        }
        else if (SDL_PointInRect(&selectedPoint, &AgniSamoohLogoRect))
        {
            std::cout << "You clicked visit Agni Samooh logo" << std::endl;
            if (osVersion == "Windows")
            {
                system("start https://agnisamooh.com");
            }
            else if (osVersion == "Mac OS X")
            {
                system("open https://agnisamooh.com");
            }
            else if (osVersion == "linux")
            {
                system("xdg-open https://agnisamooh.com");
            }
            else if (osVersion == "Android")
            {
                system("am start -a android.intent.action.VIEW -d https://agnisamooh.com");
            }
            else if (osVersion == "iOS")
            {
                system("openurl://agnisamooh.com");
            }
            else
            {
                std::cout << "OS not detected, cannot open Social media link" << std::endl;
            }
            find_os();
        }
        break;
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}

void handle_gamepad_scene_5(int button)
{
    SDL_Rect backwardRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect forwardRect = {static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect returnGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    // Highlight the selected option for keyboard arrow key and gamepad d pad key input
    SDL_Rect selectedRect = {
        static_cast<int>(windowWidth * 0.35),
        static_cast<int>(windowHeight * 0.25) + selectedOption * 100, // Spacing (must be bigger then sdl_renders.h same rect)
        rectWidth,
        rectHeight};

    SDL_Point selectedPoint = {selectedRect.x, selectedRect.y}; // This is the selectedRect which overlaps the button rects

    switch (button)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        std::cout << "You pressed button: UP" << std::endl;
        selectedOption = (selectedOption - 1 + menuTotalOptions) % menuTotalOptions;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        std::cout << "You pressed button: DOWN" << std::endl;
        selectedOption = (selectedOption + 1) % menuTotalOptions;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
        std::cout << "You pressed button: LEFT" << std::endl;
        scrollY -= scrollSpeed; // Scroll up
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
        std::cout << "You pressed button: RIGHT" << std::endl;
        scrollY += scrollSpeed; // Scroll down
        break;
    case SDL_CONTROLLER_BUTTON_A:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;
        if (SDL_PointInRect(&selectedPoint, &returnTitleRect))
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
        else if (SDL_PointInRect(&selectedPoint, &forwardRect))
        {
            std::cout << "You clicked Forward" << std::endl;
            scrollY -= scrollSpeed; // Scroll up
        }
        else if (SDL_PointInRect(&selectedPoint, &backwardRect))
        {
            std::cout << "You clicked Back" << std::endl;
            scrollY += scrollSpeed; // Scroll down
        }
        else if (SDL_PointInRect(&selectedPoint, &returnGameRect))
        {
            std::cout << "You clicked Return to game" << std::endl;
            if (gameStarted)
            {
                scene = lastScene;
            }
            else
            {
                std::cout << "Cannot Continue. Game not started." << std::endl;
            }
        }
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}