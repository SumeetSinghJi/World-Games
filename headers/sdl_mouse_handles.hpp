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

void handle_click_scene_1(int mouseX, int mouseY) // Main menu
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (displaySavefileExistsPopup)
    {
        if (scene1continueButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Load Game" << std::endl;
            displaySavefileExistsPopup = false;
            load_game();
            scene = 25;
        }
        else if (scene1overwriteGameButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Overwrite Game" << std::endl;
            overwriteGame = true;
            does_save_file_exist();
        }
    }
    else
    {
        if (scene1LoadGameButton.isClicked(mousePosition))
        {
            std::cout << "You clicked Load Game" << std::endl;
            load_game();
            scene = 25;
        }
        else if (scene1newGameButton.isClicked(mousePosition))
        {
            std::cout << "You clicked Start Game" << std::endl;
            does_save_file_exist();
        }
        else if (scene1settingsButton.isClicked(mousePosition))
        {
            std::cout << "You clicked Settings" << std::endl;
            scene = 2;
        }
        else if (scene1AchievementsButton.isClicked(mousePosition))
        {
            std::cout << "You clicked Achievements" << std::endl;
            scene = 4;
            coutAchievements = true;
        }
        else if (scene1HelpButton.isClicked(mousePosition))
        {
            std::cout << "You clicked Help" << std::endl;
            scene = 5;
        }
        else if (scene1multiplayerButton.isClicked(mousePosition))
        {
            std::cout << "You clicked Update game" << std::endl;
            start_application_update("https://github.com/SumeetSinghJi/ancient-games", "https://github.com/SumeetSinghJi/ancient-games/archive/refs/heads/master.zip");
        }
        else if (scene1QuitButton.isClicked(mousePosition))
        {
            std::cout << "You clicked Quit game" << std::endl;
            save_game();
            exit_SDL();
            exit(0);
        }
        else if (scene1DeveloperLogoLinkButton.isClicked(mousePosition))
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
    }
}
void handle_click_scene_2(int mouseX, int mouseY) // Settings
{
    SDL_Point mousePosition = {mouseX, mouseY};

    // Settings Buttons
    if (fontButton.isClicked(mousePosition))
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
    else if (soundButton.isClicked(mousePosition))
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
    else if (languageButton.isClicked(mousePosition))
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
    else if (fpsButton.isClicked(mousePosition))
    {
        std::cout << "You clicked FPS toggle" << std::endl;
        render_fps();
        fpsRendering = true;
    }
    else if (keyRemapButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Key Remap" << std::endl;
    }
    else if (resolution800x600Button.isClicked(mousePosition))
    {
        std::cout << "You clicked: set to 800 x 600 resolution" << std::endl;
        change_resolution(800, 600);
        fontSize = 24;
        for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
        {
            button->set_font_size(24);
        }
    }
    else if (resolution1366x768Button.isClicked(mousePosition))
    {
        std::cout << "You clicked: set to 1366 x 768 resolution" << std::endl;
        change_resolution(1366, 768);
        fontSize = 36;
        for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
        {
            button->set_font_size(36);
        }
    }
    else if (resolutionFullScreenButton.isClicked(mousePosition))
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
    else if (returnGameButton.isClicked(mousePosition))
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
    else if (returnTitleButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Return to title toggle" << std::endl;
        scene = 1;
    }
    else if (settingsResetButton.isClicked(mousePosition))
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
    else if (settingsSaveButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Save settings" << std::endl;
        save_settings();
    }
}
void handle_click_scene_3(int mouseX, int mouseY) // Credits
{
    SDL_Point mousePosition = {mouseX, mouseY};
    // Settings Buttons
    if (scene3returnTitleButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
}
void handle_click_scene_4(int mouseX, int mouseY) // Achievements
{
    SDL_Point mousePosition = {mouseX, mouseY};

    // Settings Buttons
    if (scene4returnTitleButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Return to title" << std::endl;
        coutAchievements = true; // To show Achievements again when back in this scene once
        scene = 1;
    }
}
void handle_click_scene_5(int mouseX, int mouseY) // Help
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene5backButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Back" << std::endl;
        scrollY += scrollSpeed; // Scroll down
    }
    else if (scene5forwardButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Forward" << std::endl;
        scrollY -= scrollSpeed; // Scroll up
    }
    else if (scene5continueButton.isClicked(mousePosition))
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
    else if (scene5returnTitleButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
}
void handle_click_scene_6(int mouseX, int mouseY) // Leaderboard
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene5backButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Back" << std::endl;
        scrollY += scrollSpeed; // Scroll down
    }
}
void handle_click_scene_7(int mouseX, int mouseY) //
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene5backButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Back" << std::endl;
        scrollY += scrollSpeed; // Scroll down
    }
}
void handle_click_scene_8(int mouseX, int mouseY) //
{
    SDL_Point mousePosition = {mouseX, mouseY};
}
void handle_click_scene_9(int mouseX, int mouseY) //
{
    SDL_Point mousePosition = {mouseX, mouseY};

    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    // Settings Buttons
    if (SDL_PointInRect(&mousePosition, &returnTitleRect))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
}

void handle_click_scene_10(int mouseX, int mouseY) // Keybindings
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene10acceptButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: ACCEPT" << std::endl;
    }
    else if (scene10denyButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: DENY" << std::endl;
    }
}
void handle_click_scene_11(int mouseX, int mouseY) // Online login
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (!showPrivacyPolicyPopup)
    {
        if (scene11submitUsernameButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: SUBMIT" << std::endl;
            submitUsername = true;
            scene = 12; // To world map
        }
        else if (scene11registerButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Register for online access" << std::endl;
            showPrivacyPolicyPopup = true;
        }
    }
    if (showPrivacyPolicyPopup)
    {
        if (scene11acceptButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Accept Privacy Policy" << std::endl;
            acceptedPrivacyPolicy = true;
                if (scene11acceptButton.isClicked(mousePosition))
                { 
                    std::cout << "You clicked: Accept Terms and Conditions" << std::endl;
                    acceptedTermsAndConditions = true;
                    showPrivacyPolicyPopup = false;
                    scene = 13; // To multiplayer lobby
                }
        }
        else if (scene11denyButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Deny Privacy Policy" << std::endl;
            showPrivacyPolicyPopup = false;
        }
    }
}
void handle_click_scene_12(int mouseX, int mouseY) // Create account
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene12submitEmailPasswordButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: SUBMIT" << std::endl;
        submitUsername = true;
        scene = 13; // To Multiplayer lobby
    }
    else if (scene12backButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Back" << std::endl;
        scene = 11; // back to login page
    }
}
void handle_click_scene_13(int mouseX, int mouseY) // Multiplayer lobby
{
    SDL_Point mousePosition = {mouseX, mouseY};

    SDL_Rect joinAvailableGameRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect createAvailableGameRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect inviteFriendToAvailableGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};

    SDL_Rect refreshAvailableGamesRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.7), rectWidth, rectHeight};
    SDL_Rect returnToAvailableGamesRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7), rectWidth, rectHeight};

    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    // Settings Buttons
    if (SDL_PointInRect(&mousePosition, &joinAvailableGameRect))
    {
        std::cout << "You clicked Join available game" << std::endl;
    }
    else if (SDL_PointInRect(&mousePosition, &createAvailableGameRect))
    {
        std::cout << "You clicked Create multiplayer game" << std::endl;
    }
    else if (SDL_PointInRect(&mousePosition, &inviteFriendToAvailableGameRect))
    {
        std::cout << "You clicked Invite friend to game" << std::endl;
    }
    else if (SDL_PointInRect(&mousePosition, &refreshAvailableGamesRect))
    {
        std::cout << "You clicked Refresh available multiplayer games" << std::endl;
    }
    else if (SDL_PointInRect(&mousePosition, &returnToAvailableGamesRect))
    {
        std::cout << "You clicked Return to Multiplayer lobby" << std::endl;
        scene = 8;
    }
    else if (SDL_PointInRect(&mousePosition, &returnTitleRect))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
}

void handle_click_scene_25(int mouseX, int mouseY) // World map
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene25helpButton.isClicked(mousePosition))
    {
        lastScene = scene;
        std::cout << "You clicked Help" << std::endl;
        scene = 5;
    }
    else if (scene25settingsButton.isClicked(mousePosition))
    {
        lastScene = scene;
        std::cout << "You clicked Settings" << std::endl;
        scene = 2;
    }
    else if (scene25returnTitleButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
    else if (scene25beijingButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Beijing" << std::endl;
        int target = 20;
        is_scene_unlocked(target);
    }
    else if (scene25berlinButton.isClicked(mousePosition))
    {
        std::cout << "You clicked London" << std::endl;
        int target = 21;
        is_scene_unlocked(target);
    }
    else if (scene25delhiButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Paris" << std::endl;
        int target = 22;
        is_scene_unlocked(target);
    }
    else if (scene25hawaiiButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Berlin" << std::endl;

        int target = 23;
        is_scene_unlocked(target);
    }
    else if (scene25londonButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Dehli" << std::endl;

        int target = 24;
        is_scene_unlocked(target);
    }
    else if (scene25parisButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Singapore" << std::endl;

        int target = 25;
        is_scene_unlocked(target);
    }
    else if (scene25seoulButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Hawaii" << std::endl;
        int target = 26;
        is_scene_unlocked(target);
    }
    else if (scene25shanghaiButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Tokyo" << std::endl;
        int target = 27;
        is_scene_unlocked(target);
    }
    else if (scene25singaporeButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Seoul" << std::endl;
        int target = 28;
        is_scene_unlocked(target);
    }
    else if (scene25tokyoButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Shanghai" << std::endl;
        int target = 29;
        is_scene_unlocked(target);
    }
    else if (scene25romeButton.isClicked(mousePosition))
    {
        std::cout << "You clicked Rome" << std::endl;
        int target = 30;
        is_scene_unlocked(target);
    }
}
