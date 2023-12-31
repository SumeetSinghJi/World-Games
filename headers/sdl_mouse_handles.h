#ifndef sdl_mouse_handles
#define sdl_mouse_handles

#include <iostream>
#include <string>
#include "headers/game_update_1.h"

/*
Both Mouse and Touch click use the same mousePoint variable
*/

extern SDL_Window *window;

// for Window resolution
extern int windowWidth;
extern int windowHeight;
extern int textWidth, textHeight;
extern bool isFullScreen;
extern int scene;
extern int lastScene;
extern std::string os_version;
extern bool game_started;
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

void handle_click_scene_1(int mouseX, int mouseY) // main menu
{
    // SDL_Rect menuLoadGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25), rectWidth, rectHeight};
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
        new_game();
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
        start_game_update_1();
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
    SDL_Rect soundRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect languageRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect fpsRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    SDL_Rect resolution800x600Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect resolution1366x768Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect resolutionFullScreenRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};

    SDL_Rect returnGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};

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
        std::cout << "You clicked Sound toggle" << std::endl;
        if (isMusicPlaying)
        {
            Mix_PauseMusic();
            isMusicPlaying = false;
            std::cout << "Music is off: " << isMusicPlaying << std::endl;
        }
        else
        {
            load_music(songTitle);
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
        render_fps();
        std::cout << "You clicked FPS toggle" << std::endl;
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
        std::cout << "You clicked set to 800 x 600 resolution" << std::endl;
        change_resolution(800, 600);
    }
    else if (SDL_PointInRect(&mousePosition, &resolution1366x768Rect))
    {
        std::cout << "You clicked set to 1366 x 768 resolution" << std::endl;
        change_resolution(1366, 768);
    }
    else if (SDL_PointInRect(&mousePosition, &resolutionFullScreenRect))
    {
        std::cout << "You clicked set to Full Screen resolution" << std::endl;
        // change to full screen
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        // capture the new window resolution width and height, and update the existing
        // window width and height variables
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);
        // pass the new values of width and height to change_resolution() to then update positioning
        // for rendering of objects
        change_resolution(windowWidth, windowHeight);
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
void handle_click_scene_6(int mouseX, int mouseY) // World map
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
    } else if (SDL_PointInRect(&mousePosition, &createAvailableGameRect))
    {
        std::cout << "You clicked Create multiplayer game" << std::endl;
    } else if (SDL_PointInRect(&mousePosition, &inviteFriendToAvailableGameRect))
    {
        std::cout << "You clicked Invite friend to game" << std::endl;
    } else if (SDL_PointInRect(&mousePosition, &refreshAvailableGamesRect))
    {
        std::cout << "You clicked Refresh available multiplayer games" << std::endl;
    }else if (SDL_PointInRect(&mousePosition, &returnToAvailableGamesRect))
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

#endif