/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++17
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached MANUAL.txt file
*/

#pragma once

#include "global_variables.hpp"

void handle_keyboard_scene_1(SDL_Event event) // Main menu
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
void handle_keyboard_scene_2(SDL_Event event) // Settings
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        fontButton.find_nearest_button(scene2buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        fontButton.find_nearest_button(scene2buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        fontButton.find_nearest_button(scene2buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        fontButton.find_nearest_button(scene2buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;
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
            save_settings();
        }
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_3(SDL_Event event) // Credits
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;
        if (scene3returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_4(SDL_Event event) // Achievements
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;

        if (scene4returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_5(SDL_Event event) // Help
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;

        if (scene5backButton.is_selected())
        {
            std::cout << "You clicked Back" << std::endl;
            scrollY += scrollSpeed; // Scroll down
        }
        else if (scene5forwardButton.is_selected())
        {
            std::cout << "You clicked Forward" << std::endl;
            scrollY -= scrollSpeed; // Scroll up
        }
        else if (scene5continueButton.is_selected())
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
        else if (scene5returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_6(SDL_Event event) // Leaderboard
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;

        if (scene4returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_7(SDL_Event event) //
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;

        if (scene4returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_8(SDL_Event event) //
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;

        if (scene4returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_9(SDL_Event event) //
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;

        if (scene4returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
void handle_keyboard_scene_10(SDL_Event event) // Key mapping
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;
        if (scene10acceptButton.is_selected())
        {
            std::cout << "You clicked: ACCEPT" << std::endl;
        }
        else if (scene10denyButton.is_selected())
        {
            std::cout << "You clicked: DENY" << std::endl;
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}

void keyboard_handles_11(SDL_Event event) // Online login
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
void keyboard_handles_12(SDL_Event event) // Create account
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
void keyboard_handles_13(SDL_Event event) // Multiplayer lobby
{
}

void keyboard_handles_25(SDL_Event event) // World map
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You pressed button: ESC" << std::endl;
        quitEventLoop = true;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene3returnTitleButton.find_nearest_button(scene3buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You pressed button: RETURN | ENTER" << std::endl;
        if (scene25helpButton.is_selected())
        {
            lastScene = scene;
            std::cout << "You clicked Help" << std::endl;
            scene = 5;
        }
        else if (scene25settingsButton.is_selected())
        {
            lastScene = scene;
            std::cout << "You clicked Settings" << std::endl;
            scene = 2;
        }
        else if (scene25returnTitleButton.is_selected())
        {
            std::cout << "You clicked Return to title" << std::endl;
            scene = 1;
        }
        else if (scene25beijingButton.is_selected())
        {
            std::cout << "You clicked Beijing" << std::endl;
            int target = 20;
            is_scene_unlocked(target);
        }
        else if (scene25berlinButton.is_selected())
        {
            std::cout << "You clicked London" << std::endl;
            int target = 21;
            is_scene_unlocked(target);
        }
        else if (scene25delhiButton.is_selected())
        {
            std::cout << "You clicked Paris" << std::endl;
            int target = 22;
            is_scene_unlocked(target);
        }
        else if (scene25hawaiiButton.is_selected())
        {
            std::cout << "You clicked Berlin" << std::endl;

            int target = 23;
            is_scene_unlocked(target);
        }
        else if (scene25londonButton.is_selected())
        {
            std::cout << "You clicked Dehli" << std::endl;

            int target = 24;
            is_scene_unlocked(target);
        }
        else if (scene25parisButton.is_selected())
        {
            std::cout << "You clicked Singapore" << std::endl;

            int target = 25;
            is_scene_unlocked(target);
        }
        else if (scene25seoulButton.is_selected())
        {
            std::cout << "You clicked Hawaii" << std::endl;
            int target = 26;
            is_scene_unlocked(target);
        }
        else if (scene25shanghaiButton.is_selected())
        {
            std::cout << "You clicked Tokyo" << std::endl;
            int target = 27;
            is_scene_unlocked(target);
        }
        else if (scene25singaporeButton.is_selected())
        {
            std::cout << "You clicked Seoul" << std::endl;
            int target = 28;
            is_scene_unlocked(target);
        }
        else if (scene25tokyoButton.is_selected())
        {
            std::cout << "You clicked Shanghai" << std::endl;
            int target = 29;
            is_scene_unlocked(target);
        }
        else if (scene25romeButton.is_selected())
        {
            std::cout << "You clicked Rome" << std::endl;
            int target = 32;
            is_scene_unlocked(target);
        }
    default:
        std::cout << "You pressed: a non-configured keyboard input." << std::endl;
        break;
    }
}
