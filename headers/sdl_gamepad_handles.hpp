/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached MANUAL.txt file
*/

#pragma once

#include "global_variables.hpp"

void handle_gamepad_scene_1(int button)
{
    switch (button)
    {
    case SDL_CONTROLLER_BUTTON_START:
        std::cout << "You pressed controller button: START" << std::endl;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        std::cout << "You pressed controller button: UP" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_UP);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        std::cout << "You pressed controller button: DOWN" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
        std::cout << "You pressed controller button: LEFT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
        std::cout << "You pressed controller button: RIGHT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
        break;
    case SDL_CONTROLLER_BUTTON_A:
        std::cout << "You pressed controller button: A" << std::endl;
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

void handle_gamepad_scene_2(int button)
{
    switch (button)
    {
    case SDL_CONTROLLER_BUTTON_START:
        std::cout << "You pressed controller button: START" << std::endl;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        std::cout << "You pressed controller button: UP" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_UP);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        std::cout << "You pressed controller button: DOWN" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
        std::cout << "You pressed controller button: LEFT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
        std::cout << "You pressed controller button: RIGHT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
        break;
    case SDL_CONTROLLER_BUTTON_A:
        std::cout << "You pressed controller button: A" << std::endl;
        if (fontButton.is_selected())
        {
            std::cout << "You clicked font toggle" << std::endl;
            if (fontSize == 24)
            {
                fontSize = 36;
                std::cout << "Font size set to: " << fontSize << std::endl;
            }
            else if (fontSize == 36)
            {
                fontSize = 48;
                std::cout << "Font size set to: " << fontSize << std::endl;
            }
            else if (fontSize == 48)
            {
                fontSize = 24;
                std::cout << "Font size set to: " << fontSize << std::endl;
            }
        }
        else if (soundButton.is_selected())
        {
            std::cout << "You clicked: Sound toggle" << std::endl;
            if (isMusicPlaying)
            {
                Mix_PauseMusic();
                isMusicPlaying = false;
                std::cout << "Music is: " << isMusicPlaying << std::endl;
            }
            else
            {
                Mix_ResumeMusic();
                isMusicPlaying = true;
                std::cout << "Music is: " << isMusicPlaying << std::endl;
            }
        }
        else if (languageButton.is_selected())
        {
            std::cout << "You clicked change Language" << std::endl;
            if (language == "English")
            {
                language = "日本語";
                localisation("日本語");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "日本語")
            {
                language = "ภาษาไทย";
                localisation("ภาษาไทย");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "ภาษาไทย")
            {
                language = "संस्कृतम्";
                localisation("संस्कृतम्");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "संस्कृतम्")
            {
                language = "中文";
                localisation("中文");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "中文")
            {
                language = "العربية";
                localisation("العربية");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "العربية")
            {
                language = "ግዕዝ";
                localisation("ግዕዝ");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "ግዕዝ")
            {
                language = "Ελληνικά";
                localisation("Ελληνικά");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "Ελληνικά")
            {
                language = "Latina";
                localisation("Latina");
                std::cout << "Language is now set to: " << language << std::endl;
            }
            else if (language == "Latina")
            {
                language = "English";
                localisation("English");
                std::cout << "Language is now set to: " << language << std::endl;
            }
        }
        else if (fpsButton.is_selected())
        {
            std::cout << "You clicked FPS toggle" << std::endl;
            render_fps();
            fpsRendering = true;
        }
        else if (keyRemapButton.is_selected())
        {
            std::cout << "You clicked: Key Remap" << std::endl;
        }
        else if (resolution800x600Button.is_selected())
        {
            std::cout << "You clicked: set to 800 x 600 resolution" << std::endl;
            change_resolution(800, 600);
            fontSize = 24;
            for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
            {
                button->set_font_size(24);
            }
        }
        else if (resolution1366x768Button.is_selected())
        {
            std::cout << "You clicked: set to 1366 x 768 resolution" << std::endl;
            change_resolution(1366, 768);
            fontSize = 36;
            for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
            {
                button->set_font_size(36);
            }
        }
        else if (resolutionFullScreenButton.is_selected())
        {
            std::cout << "You clicked: Full Screen to Windowed resolution" << std::endl;

            int borderFlag = SDL_GetWindowFlags(window);
            bool isFullscreen = (borderFlag & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0;
            if (isFullscreen)
            {
                SDL_SetWindowFullscreen(window, 0);
            }
            else
            {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            }

            SDL_GetWindowSize(window, &windowWidth, &windowHeight);
            change_resolution(windowWidth, windowHeight);

            fontSize = 48;
            for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
            {
                button->set_font_size(48);
            }
        }
        else if (returnGameButton.is_selected())
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
        else if (returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title toggle" << std::endl;
            scene = 1;
        }
        else if (settingsResetButton.is_selected())
        {
            std::cout << "You clicked: Reset settings" << std::endl;
            change_resolution(1366, 768);
            fontSize = 36;
            for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
            {
                button->set_font_size(36);
            }
            if (!isMusicPlaying)
            {
                Mix_ResumeMusic();
            }
            if (fpsRendering)
            {
                render_fps();
            }
            language = "English";
        }
        else if (settingsSaveButton.is_selected())
        {
            std::cout << "You clicked: Save settings" << std::endl;
        }
    default:
        std::cout << "You pressed a non-configured controller input." << std::endl;
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

void handle_gamepad_scene_11(int button)
{
    if (!showPrivacyPolicyPopup)
    {
        switch (button)
        {
        case SDL_CONTROLLER_BUTTON_START:
            std::cout << "You pressed controller button: START" << std::endl;
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_UP:
            std::cout << "You pressed controller button: UP" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_UP);
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
            std::cout << "You pressed controller button: DOWN" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
            std::cout << "You pressed controller button: LEFT" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
            std::cout << "You pressed controller button: RIGHT" << std::endl;
            scene11submitUsernameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
            break;
        case SDL_CONTROLLER_BUTTON_A:
            std::cout << "You pressed controller button: A" << std::endl;
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
        switch (button)
        {
        case SDL_CONTROLLER_BUTTON_START:
            std::cout << "You pressed controller button: START" << std::endl;
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_UP:
            std::cout << "You pressed controller button: UP" << std::endl;
            scene11acceptButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_UP);
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
            std::cout << "You pressed controller button: DOWN" << std::endl;
            scene11acceptButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
            std::cout << "You pressed controller button: LEFT" << std::endl;
            scene11acceptButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
            std::cout << "You pressed controller button: RIGHT" << std::endl;
            scene11acceptButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
            break;
        case SDL_CONTROLLER_BUTTON_A:
            std::cout << "You pressed controller button: A" << std::endl;
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

void handle_gamepad_scene_12(int button)
{
    switch (button)
    {
    case SDL_CONTROLLER_BUTTON_START:
        std::cout << "You pressed controller button: START" << std::endl;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        std::cout << "You pressed controller button: UP" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_UP);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        std::cout << "You pressed controller button: DOWN" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
        std::cout << "You pressed controller button: LEFT" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
        std::cout << "You pressed controller button: RIGHT" << std::endl;
        scene12submitEmailPasswordButton.find_nearest_button(scene12buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
        break;
    case SDL_CONTROLLER_BUTTON_A:
        std::cout << "You pressed controller button: A" << std::endl;
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
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}

void handle_gamepad_scene_13(int button)
{
    switch (button)
    {
    case SDL_CONTROLLER_BUTTON_START:
        std::cout << "You pressed controller button: START" << std::endl;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        std::cout << "You pressed controller button: UP" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_UP);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        std::cout << "You pressed controller button: DOWN" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
        std::cout << "You pressed controller button: LEFT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
        std::cout << "You pressed controller button: RIGHT" << std::endl;
        scene1newGameButton.find_nearest_button(scene1buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
        break;
    case SDL_CONTROLLER_BUTTON_A:
        std::cout << "You pressed controller button: A" << std::endl;
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
