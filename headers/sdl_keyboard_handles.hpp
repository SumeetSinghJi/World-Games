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
For Gamepad input
*/

extern SDL_Window *window;

// for Window resolution
extern int windowWidth;
extern int windowHeight;
extern int textWidth, textHeight;
extern int scene;
extern int lastScene;
extern std::string os_version;
extern bool game_started;
extern int selectedOption;
extern int menuTotalOptions;
// unique to keyboard AND possibly gamepad?
extern bool quit_event_loop;
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

void handle_keyboard_scene_1(SDL_Event event)
{
    // SDL_Rect menuLoadGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25), rectWidth, rectHeight};
    SDL_Rect menuNewGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25), rectWidth, rectHeight};
    SDL_Rect menuSettingsRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.35), rectWidth, rectHeight};
    SDL_Rect menuAchievementsRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.45), rectWidth, rectHeight};
    SDL_Rect menuHelpRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.55), rectWidth, rectHeight};
    SDL_Rect menuGameUpdateRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.65), rectWidth, rectHeight};
    SDL_Rect menuQuitRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.75), rectWidth, rectHeight};
    SDL_Rect AgniSamoohLogoRect = {static_cast<int>(windowWidth * 0.73), static_cast<int>(windowHeight * 0.73), (windowWidth) / 6, (windowHeight) / 6};

    // Highlight the selected option for keyboard arrow key and gamepad d pad key input
    SDL_Rect selectedRect = {
        static_cast<int>(windowWidth * 0.35),
        static_cast<int>(windowHeight * 0.25) + selectedOption * 100, // Spacing (must be bigger then sdl_renders.h same rect)
        rectWidth,
        rectHeight};

    SDL_Point selectedPoint = {selectedRect.x, selectedRect.y}; // This is the selectedRect which overlaps the button rects

    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quit_event_loop = true;
        break;
    case SDLK_UP:
        std::cout << "You pressed button: UP" << std::endl;
        selectedOption = (selectedOption - 1 + menuTotalOptions) % menuTotalOptions;
        break;
    case SDLK_DOWN:
        std::cout << "You pressed button: DOWN" << std::endl;
        selectedOption = (selectedOption + 1) % menuTotalOptions;
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;
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
            if (os_version == "Windows")
            {
                system("start https://agnisamooh.com");
            }
            else if (os_version == "Mac OS X")
            {
                system("open https://agnisamooh.com");
            }
            else if (os_version == "linux")
            {
                system("xdg-open https://agnisamooh.com");
            }
            else if (os_version == "Android")
            {
                system("am start -a android.intent.action.VIEW -d https://agnisamooh.com");
            }
            else if (os_version == "iOS")
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

void handle_keyboard_scene_5(SDL_Event event)
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

    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quit_event_loop = true;
        break;
    case SDLK_UP:
        std::cout << "You pressed button: UP" << std::endl;
        selectedOption = (selectedOption - 1 + menuTotalOptions) % menuTotalOptions;
        break;
    case SDLK_DOWN:
        std::cout << "You pressed button: DOWN" << std::endl;
        selectedOption = (selectedOption + 1) % menuTotalOptions;
        break;
    case SDLK_LEFT:
        std::cout << "You pressed button: LEFT" << std::endl;
        scrollY -= scrollSpeed; // Scroll up
        break;
    case SDLK_RIGHT:
        std::cout << "You pressed button: RIGHT" << std::endl;
        scrollY += scrollSpeed; // Scroll down
        break;
    case SDLK_RETURN:
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
            if (game_started)
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