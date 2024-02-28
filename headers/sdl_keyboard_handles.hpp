/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached help.txt file
*/

#pragma once

#include "global_variables.hpp"

void handle_keyboard_scene_1(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;
        if (scene1newGameButton.is_selected())
        {
            std::cout << "You selected: Start Game" << std::endl;
            // scene = 11;
            new_game(); // uncomment this and remove scene = 11, after testing;
        }
        else if (scene1settingsButton.is_selected())
        {
            std::cout << "You selected: Settings" << std::endl;
            scene = 2;
        }
        else if (scene1AchievementsButton.is_selected())
        {
            std::cout << "You selected: Achievements" << std::endl;
            scene = 4;
        }
        else if (scene1HelpButton.is_selected())
        {
            std::cout << "You selected: Help" << std::endl;
            scene = 5;
        }
        else if (scene1multiplayerButton.is_selected())
        {
            std::cout << "You selected: Online Multiplayer" << std::endl;
            // start_game_update_1();
        }
        else if (scene1QuitButton.is_selected())
        {
            std::cout << "You selected Quit game" << std::endl;
            // save_game();
            exit_SDL();
            exit(0);
        }
        else if (scene1DeveloperLogoLinkButton.is_selected())
        {
            std::cout << "You selected visit Agni Samooh logo" << std::endl;
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
        quitEventLoop = true;
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

void keyboard_handles_11(SDL_Event event)
{
    if (!showPrivacyPolicyPopup)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            std::cout << "You clicked button: ESC" << std::endl;
            scene = 1; // Go back to main menu
            break;
        case SDLK_UP:
            std::cout << "You clicked button: UP" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_UP, 0);
            break;
        case SDLK_DOWN:
            std::cout << "You clicked button: DOWN" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_DOWN, 0);
            break;
        case SDLK_LEFT:
            std::cout << "You clicked button: LEFT" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_LEFT, 0);
            break;
        case SDLK_RIGHT:
            std::cout << "You clicked button: RIGHT" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_RIGHT, 0);
            break;
        case SDLK_RETURN:
            std::cout << "You clicked button: ENTER" << std::endl;
            if (scene11submitUsernameButton.is_selected())
            {
                std::cout << "You clicked: SUBMIT" << std::endl;
                submitUsername = true;
                scene = 13; // To multiplayer lobby
            }
            else if (scene11registerButton.is_selected())
            {
                std::cout << "You clicked: REGISTER" << std::endl;
                showPrivacyPolicyPopup = true;
            }
            break;
        default:
            std::cout << "You pressed a non-configured keyboard input." << std::endl;
            break;
        }
    }
    if (showPrivacyPolicyPopup)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            std::cout << "You clicked button: ESC" << std::endl;
            scene = 1; // Go back to main menu
            break;
        case SDLK_UP:
            std::cout << "You clicked button: UP" << std::endl;
            scene11acceptButton.find_nearest_button(scene11buttons, SDLK_UP, 0);
            break;
        case SDLK_DOWN:
            std::cout << "You clicked button: DOWN" << std::endl;
            scene11acceptButton.find_nearest_button(scene11buttons, SDLK_DOWN, 0);
            break;
        case SDLK_LEFT:
            std::cout << "You clicked button: LEFT" << std::endl;
            scene11acceptButton.find_nearest_button(scene11buttons, SDLK_LEFT, 0);
            break;
        case SDLK_RIGHT:
            std::cout << "You clicked button: RIGHT" << std::endl;
            scene11acceptButton.find_nearest_button(scene11buttons, SDLK_RIGHT, 0);
            break;
        case SDLK_RETURN:
            std::cout << "You clicked button: ENTER" << std::endl;
            if (scene11acceptButton.is_selected())
            {
                std::cout << "You clicked: Accept Privacy Policy" << std::endl;
                showPrivacyPolicyPopup = false;
                acceptedPrivacyPolicy = true;
                scene = 13; // To multiplayer lobby
            }
            else if (scene11denyButton.is_selected())
            {
                std::cout << "You clicked: Deny Privacy Policy" << std::endl;
                showPrivacyPolicyPopup = false;
            }
            break;
        default:
            std::cout << "You pressed a non-configured keyboard input." << std::endl;
            break;
        }
    }
}
void keyboard_handles_12(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You clicked button: ESC" << std::endl;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You clicked button: ENTER" << std::endl;
        if (scene12submitEmailPasswordButton.is_selected())
        {
            std::cout << "You clicked: SUBMIT" << std::endl;
            submitUsername = true;
            scene = 13; // To Multiplayer lobby
        }
        else if (scene12backButton.is_selected())
        {
            std::cout << "You clicked: Back" << std::endl;
            scene = 11; // back to login page
        }
        break;
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}
void keyboard_handles_13(SDL_Event event)
{
}
