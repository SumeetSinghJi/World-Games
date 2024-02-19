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
#include "custom_SDL_button.hpp" // Custom SDL Button class for creating buttons for handles

/*
Both Mouse and Touch click use the same mousePoint variable
*/

extern SDL_Window *window;
extern std::vector<Custom_SDL_Button *> allButtons;

// for Window resolution
extern int windowWidth;
extern int windowHeight;
extern int textWidth, textHeight;
extern int scene;
extern int lastScene;
extern std::string os_version;
extern bool game_started;
// README SCROLL VARIABLES
extern int scrollY;
extern int scrollSpeed;
extern bool fpsRendering;

// FUNCTION PROTOTPES
void change_resolution(int newWindowWidth, int newWindowHeight);
void is_scene_unlocked(int target);
void new_game();
void exit_SDL();
std::string find_os();
void render_fps();

void handle_click_scene_1(int mouseX, int mouseY) // main menu
{
    // SDL_Rect menuLoadGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.15), rectWidth, rectHeight};
    SDL_Rect menuNewGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25), rectWidth, rectHeight};
    SDL_Rect menuSettingsRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.35), rectWidth, rectHeight};
    SDL_Rect menuAchievementsRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.45), rectWidth, rectHeight};
    SDL_Rect menuHelpRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.55), rectWidth, rectHeight};
    SDL_Rect menuGameUpdateRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.65), rectWidth, rectHeight};
    SDL_Rect menuQuitRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.75), rectWidth, rectHeight};
    SDL_Rect AgniSamoohLogoRect = {static_cast<int>(windowWidth * 0.73), static_cast<int>(windowHeight * 0.73), (windowWidth) / 6, (windowHeight) / 6};

    SDL_Point mousePosition = {mouseX, mouseY};
    /*
    if (SDL_PointInRect(&mousePosition, &menuLoadGameRect))
    {
        std::cout << "You clicked Load Game" << std::endl;
        load_game();
    }
    */
    if (SDL_PointInRect(&mousePosition, &menuNewGameRect))
    {
        std::cout << "You clicked Start Game" << std::endl;
        // scene = 11;
        new_game(); // uncomment this and remove scene = 11, after testing;
    }
    else if (SDL_PointInRect(&mousePosition, &menuSettingsRect))
    {
        std::cout << "You clicked Settings" << std::endl;
        scene = 2;
    }
    else if (SDL_PointInRect(&mousePosition, &menuAchievementsRect))
    {
        std::cout << "You clicked Achievements" << std::endl;
        scene = 4;
    }
    else if (SDL_PointInRect(&mousePosition, &menuHelpRect))
    {
        std::cout << "You clicked Help" << std::endl;
        scene = 5;
    }
    else if (SDL_PointInRect(&mousePosition, &menuGameUpdateRect))
    {
        std::cout << "You clicked Update game" << std::endl;
        // start_game_update_1();
    }
    else if (SDL_PointInRect(&mousePosition, &menuQuitRect))
    {
        std::cout << "You clicked Quit game" << std::endl;
        // save_game();
        exit_SDL();
        exit(0);
    }
    else if (SDL_PointInRect(&mousePosition, &AgniSamoohLogoRect))
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
}
void handle_click_scene_2(int mouseX, int mouseY) // Settings
{
    SDL_Rect fontRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect soundRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.3), rectWidth, rectHeight};
    SDL_Rect languageRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect fpsRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.5), rectWidth, rectHeight};

    SDL_Rect resolution800x600Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect resolution1366x768Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect resolutionFullScreenRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect keyRemapRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    SDL_Rect returnGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect settingsResetRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect settingsSaveRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    SDL_Point mousePosition = {mouseX, mouseY};

    // Settings Buttons
    if (SDL_PointInRect(&mousePosition, &fontRect))
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
    else if (SDL_PointInRect(&mousePosition, &soundRect))
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
    else if (SDL_PointInRect(&mousePosition, &languageRect))
    {
        std::cout << "You clicked change Language" << std::endl;
        if (language == "English")
        {
            language = "日本語";
            std::cout << "Language is now set to: " << language << std::endl;
        }
        else
        {
            language = "English";
            std::cout << "Language is now set to: " << language << std::endl;
        }
    }
    else if (SDL_PointInRect(&mousePosition, &fpsRect))
    {
        std::cout << "You clicked FPS toggle" << std::endl;
        render_fps();
        fpsRendering = true;
    }
    else if (SDL_PointInRect(&mousePosition, &keyRemapRect))
    {
        std::cout << "You clicked: Key Remap" << std::endl;
    }
    else if (SDL_PointInRect(&mousePosition, &settingsResetRect))
    {
        std::cout << "You clicked: Reset settings" << std::endl;
        change_resolution(1366, 768);
        fontSize = 36;
        for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
        {
            button->set_font_size(36);
        }
        if (!isMusicPlaying) {
            Mix_ResumeMusic();
        }
        if (fpsRendering) {
            render_fps();
        }
        language = "English";
    }
    else if (SDL_PointInRect(&mousePosition, &settingsSaveRect))
    {
        std::cout << "You clicked: Save settings" << std::endl;
    }
    else if (SDL_PointInRect(&mousePosition, &returnGameRect))
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
    else if (SDL_PointInRect(&mousePosition, &returnTitleRect))
    {
        std::cout << "You clicked Return to title toggle" << std::endl;
        scene = 1;
    }
    else if (SDL_PointInRect(&mousePosition, &resolution800x600Rect))
    {
        std::cout << "You clicked: set to 800 x 600 resolution" << std::endl;
        change_resolution(800, 600);
        fontSize = 24;
        for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
        {
            button->set_font_size(24);
        }
    }
    else if (SDL_PointInRect(&mousePosition, &resolution1366x768Rect))
    {
        std::cout << "You clicked: set to 1366 x 768 resolution" << std::endl;
        change_resolution(1366, 768);
        fontSize = 36;
        for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
        {
            button->set_font_size(36);
        }
    }
    else if (SDL_PointInRect(&mousePosition, &resolutionFullScreenRect))
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
}
void handle_click_scene_3(int mouseX, int mouseY) // Credits
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
void handle_click_scene_4(int mouseX, int mouseY) // Achievements
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
void handle_click_scene_5(int mouseX, int mouseY) // Help
{
    SDL_Point mousePosition = {mouseX, mouseY};

    SDL_Rect backwardRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect forwardRect = {static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect returnGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    if (SDL_PointInRect(&mousePosition, &returnTitleRect))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
    else if (SDL_PointInRect(&mousePosition, &forwardRect))
    {
        std::cout << "You clicked Forward" << std::endl;
        scrollY -= scrollSpeed; // Scroll up
    }
    else if (SDL_PointInRect(&mousePosition, &backwardRect))
    {
        std::cout << "You clicked Back" << std::endl;
        scrollY += scrollSpeed; // Scroll down
    }
    else if (SDL_PointInRect(&mousePosition, &returnGameRect))
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
}
void handle_click_scene_25(int mouseX, int mouseY) // World map
{
    SDL_Point mousePosition = {mouseX, mouseY};

    SDL_Rect helpRect = {static_cast<int>(windowWidth * 0.95), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect settingsRect = {static_cast<int>(windowWidth * 0.95), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.95), static_cast<int>(windowHeight * 0.7), rectWidth, rectHeight};

    SDL_Rect beijingRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.49), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect berlinRect = {static_cast<int>(windowWidth * 0.48), static_cast<int>(windowHeight * 0.36), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect delhiRect = {static_cast<int>(windowWidth * 0.63), static_cast<int>(windowHeight * 0.46), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect hawaiiRect = {static_cast<int>(windowWidth * 0.01), static_cast<int>(windowHeight * 0.5), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect londonRect = {static_cast<int>(windowWidth * 0.43), static_cast<int>(windowHeight * 0.3), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect parisRect = {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.4), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect seoulRect = {static_cast<int>(windowWidth * 0.78), static_cast<int>(windowHeight * 0.4), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect shanghaiRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.4), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect singaporeRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.57), worldmapRegionWidth, worldmapRegionHeight};
    SDL_Rect tokyoRect = {static_cast<int>(windowWidth * 0.83), static_cast<int>(windowHeight * 0.43), worldmapRegionWidth, worldmapRegionHeight};

    SDL_Rect romeRect = {static_cast<int>(windowWidth * 0.50), static_cast<int>(windowHeight * 0.45), worldmapRegionWidth, worldmapRegionHeight};

    // Settings Buttons
    if (SDL_PointInRect(&mousePosition, &helpRect))
    {
        lastScene = scene;
        std::cout << "You clicked Help" << std::endl;
        scene = 5;
    }
    else if (SDL_PointInRect(&mousePosition, &settingsRect))
    {
        lastScene = scene;
        std::cout << "You clicked Settings" << std::endl;
        scene = 2;
    }
    else if (SDL_PointInRect(&mousePosition, &returnTitleRect))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
    else if (SDL_PointInRect(&mousePosition, &beijingRect))
    {
        std::cout << "You clicked Beijing" << std::endl;
        int target = 20;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &londonRect))
    {
        std::cout << "You clicked London" << std::endl;
        int target = 21;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &parisRect))
    {
        std::cout << "You clicked Paris" << std::endl;
        int target = 22;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &berlinRect))
    {
        std::cout << "You clicked Berlin" << std::endl;

        int target = 23;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &delhiRect))
    {
        std::cout << "You clicked Dehli" << std::endl;

        int target = 24;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &singaporeRect))
    {
        std::cout << "You clicked Singapore" << std::endl;

        int target = 25;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &hawaiiRect))
    {
        std::cout << "You clicked Hawaii" << std::endl;
        int target = 26;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &tokyoRect))
    {
        std::cout << "You clicked Tokyo" << std::endl;
        int target = 27;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &seoulRect))
    {
        std::cout << "You clicked Seoul" << std::endl;
        int target = 28;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &shanghaiRect))
    {
        std::cout << "You clicked Shanghai" << std::endl;
        int target = 29;
        is_scene_unlocked(target);
    }
    else if (SDL_PointInRect(&mousePosition, &romeRect))
    {
        std::cout << "You clicked Rome" << std::endl;
        int target = 32;
        is_scene_unlocked(target);
    }
}
void handle_click_scene_8(int mouseX, int mouseY) // Multiplayer lobby
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
void handle_click_scene_9(int mouseX, int mouseY) // Leaderboard
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

    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    // Settings Buttons
    if (SDL_PointInRect(&mousePosition, &returnTitleRect))
    {
        std::cout << "You clicked Return to title" << std::endl;
        scene = 1;
    }
}