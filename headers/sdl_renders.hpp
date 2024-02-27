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

void render_fireworks_animation()
{
    SDL_Rect fireworksAnimationRect = {static_cast<int>(windowWidth * 0.3), static_cast<int>(windowWidth * 0.4), 400, 400};
    SDL_RenderCopy(renderer, fireworksAnimationTexture, nullptr, &fireworksAnimationRect);
    std::cout << "Animation is playing" << std::endl;
}

void draw_buttons_scene_1() // Main menu
{
    // SDL_Rect menuLoadGameRect = {static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.15), rectWidth, rectHeight};
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
        static_cast<int>(windowHeight * 0.25) + selectedOption * 75, // Adjust spacing as needed
        rectWidth,
        rectHeight
    };

    // Draw the filled rectangle for the selected option
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow color (adjust as needed)
    SDL_RenderFillRect(renderer, &selectedRect);

    // SDL_RenderCopy(renderer, menuLoadGameTexture, nullptr, &menuLoadGameRect);
    SDL_RenderCopy(renderer, menuNewGameTexture, nullptr, &menuNewGameRect);
    SDL_RenderCopy(renderer, menuSettingsTexture, nullptr, &menuSettingsRect);
    SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &menuAchievementsRect);
    SDL_RenderCopy(renderer, menuHelpTexture, nullptr, &menuHelpRect);
    SDL_RenderCopy(renderer, menuUpdateGameTexture, nullptr, &menuGameUpdateRect);
    SDL_RenderCopy(renderer, menuQuitTexture, nullptr, &menuQuitRect);
    SDL_RenderCopy(renderer, AgniSamoohLogoTexture, nullptr, &AgniSamoohLogoRect); // for social media open browser link
    SDL_RenderDrawRect(renderer, &selectedRect); // for keyboard input

     // Draw the outline of the selected option
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color (adjust as needed)
    SDL_RenderDrawRect(renderer, &selectedRect);
}
void draw_buttons_scene_2() // Settings
{
    SDL_Rect fontRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect soundRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect languageRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect fpsRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    SDL_Rect resolution800x600Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect resolution1366x768Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect resolutionFullScreenRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect keyRemapRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    SDL_Rect returnGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect settingsResetRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect settingsSaveRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    extern SDL_Texture *keyboardRealisticTexture;
    extern SDL_Texture *keyboardCartoonTexture;
    extern SDL_Texture *gameControllerTexture;
    extern SDL_Texture *computerMouseTexture;

    SDL_RenderCopy(renderer, fontTexture, nullptr, &fontRect);
    if (isMusicPlaying)
    {
        SDL_RenderCopy(renderer, soundOnTexture, nullptr, &soundRect);
    }
    else
    {
        SDL_RenderCopy(renderer, soundOffTexture, nullptr, &soundRect);
    }
    SDL_RenderCopy(renderer, languageTexture, nullptr, &languageRect);
    SDL_RenderCopy(renderer, fpsTexture, nullptr, &fpsRect);
    

    SDL_RenderCopy(renderer, resolution800x600Texture, nullptr, &resolution800x600Rect);
    SDL_RenderCopy(renderer, resolution1366x768Texture, nullptr, &resolution1366x768Rect);
    SDL_RenderCopy(renderer, resolutionFullScreenTexture, nullptr, &resolutionFullScreenRect);
    SDL_RenderCopy(renderer, keyRemapTexture, nullptr, &keyRemapRect);

    SDL_RenderCopy(renderer, returnGameTexture, nullptr, &returnGameRect);
    SDL_RenderCopy(renderer, settingsResetTexture, nullptr, &settingsResetRect);
    SDL_RenderCopy(renderer, settingsSaveTexture, nullptr, &settingsSaveRect);
    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
}
void draw_buttons_scene_3() // Credits
{
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
}
void draw_buttons_scene_4() // Achievements
{
    SDL_Rect achievement1Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect achievement2Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.3), rectWidth, rectHeight};
    SDL_Rect achievement3Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect achievement4Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.5), rectWidth, rectHeight};
    SDL_Rect achievement5Rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    
    SDL_Rect achievement6Rect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect achievement7Rect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.3), rectWidth, rectHeight};
    SDL_Rect achievement8Rect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect achievement9Rect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.5), rectWidth, rectHeight};
    SDL_Rect achievement10Rect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};

    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    if (is_achievement_unlocked(1)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement1Rect);
    } else if (is_achievement_unlocked(2)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement2Rect);
    } else if (is_achievement_unlocked(3)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement3Rect);
    } else if (is_achievement_unlocked(4)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement4Rect);
    } else if (is_achievement_unlocked(5)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement5Rect);
    } else if (is_achievement_unlocked(6)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement6Rect);
    } else if (is_achievement_unlocked(7)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement7Rect);
    } else if (is_achievement_unlocked(8)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement8Rect);
    } else if (is_achievement_unlocked(9)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement9Rect);
    } else if (is_achievement_unlocked(10)) {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement10Rect);
    }
    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
}
void draw_buttons_scene_5() // Help
{
    SDL_Rect backwardRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect forwardRect = {static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect returnGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};

    SDL_RenderCopy(renderer, returnGameTexture, nullptr, &returnGameRect);
    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
    SDL_RenderCopy(renderer, forwardTexture, nullptr, &forwardRect);
    SDL_RenderCopy(renderer, backwardTexture, nullptr, &backwardRect);
}
void draw_buttons_scene_25() // World map
{
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


    SDL_RenderCopy(renderer, beijingTexture, nullptr, &beijingRect);
    SDL_RenderCopy(renderer, berlinTexture, nullptr, &berlinRect);
    SDL_RenderCopy(renderer, delhiTexture, nullptr, &delhiRect);
    SDL_RenderCopy(renderer, hawaiiTexture, nullptr, &hawaiiRect);
    SDL_RenderCopy(renderer, londonTexture, nullptr, &londonRect);
    SDL_RenderCopy(renderer, parisTexture, nullptr, &parisRect);
    SDL_RenderCopy(renderer, seoulTexture, nullptr, &seoulRect);
    SDL_RenderCopy(renderer, shanghaiTexture, nullptr, &shanghaiRect);
    SDL_RenderCopy(renderer, singaporeTexture, nullptr, &singaporeRect);
    SDL_RenderCopy(renderer, tokyoTexture, nullptr, &tokyoRect);

    SDL_RenderCopy(renderer, romeTexture, nullptr, &romeRect);

    SDL_RenderCopy(renderer, helpTexture, nullptr, &helpRect);
    SDL_RenderCopy(renderer, settingsTexture, nullptr, &settingsRect);
    // SDL_RenderCopy(renderer, saveTexture, nullptr, &saveRect);
    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
}
void draw_buttons_scene_8() // Multiplayer lobby
{
    SDL_Rect joinAvailableGameRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect createAvailableGameRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    SDL_Rect inviteFriendToAvailableGameRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};
    
    SDL_Rect refreshAvailableGamesRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.7), rectWidth, rectHeight};
    SDL_Rect returnToAvailableGamesRect = {static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7), rectWidth, rectHeight};

    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    
    SDL_RenderCopy(renderer, joinAvailableGameTexture, nullptr, &joinAvailableGameRect);
    SDL_RenderCopy(renderer, createAvailableGameTexture, nullptr, &createAvailableGameRect);
    SDL_RenderCopy(renderer, inviteFriendToAvailableGameTexture, nullptr, &inviteFriendToAvailableGameRect);

    SDL_RenderCopy(renderer, refreshAvailableGamesTexture, nullptr, &refreshAvailableGamesRect);
    SDL_RenderCopy(renderer, returnToAvailableGamesTexture, nullptr, &returnToAvailableGamesRect);

    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
}
void draw_buttons_scene_9() // leaderboard
{
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    
    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
}
void draw_buttons_scene_10() // Keybindings
{
    SDL_Rect returnTitleRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, returnTitleTexture, nullptr, &returnTitleRect);
}
void draw_buttons_scene_11() // Profile
{
    SDL_Rect inputTextRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.4), static_cast<int>(windowWidth * 0.9), (windowHeight / 10)};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &inputTextRect);
}