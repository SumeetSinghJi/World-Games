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

void render_fireworks_animation()
{
    SDL_Rect fireworksAnimationRect = {static_cast<int>(windowWidth * 0.3), static_cast<int>(windowWidth * 0.4), 400, 400};
    SDL_RenderCopy(renderer, fireworksAnimationTexture, nullptr, &fireworksAnimationRect);
    std::cout << "Animation is playing" << std::endl;
}

void draw_does_save_file_exist()
{
    // Draw text input rect black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect borderRect = {static_cast<int>(windowWidth * 0.2) - 2, static_cast<int>(windowHeight * 0.1) - 2, static_cast<int>(windowWidth * 0.7) + 4, static_cast<int>(windowHeight * 0.7) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw text input rect
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect textInputRect = {static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1), static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7)};
    SDL_RenderFillRect(renderer, &textInputRect);

    scene1overwriteGameButton.render_button_rect(renderer);
    scene1continueButton.render_button_rect(renderer);
}

void draw_username_textbox()
{
    // Draw text input rect black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect borderRect = {static_cast<int>(windowWidth * 0.4) - 2, static_cast<int>(windowHeight * 0.2) - 2, static_cast<int>(windowWidth * 0.4) + 4, static_cast<int>(windowHeight * 0.1) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw text input rect
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect textInputRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2), static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.1)};
    SDL_RenderFillRect(renderer, &textInputRect);
}
void draw_email_textbox()
{
    // Draw text input rect black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect borderRect = {static_cast<int>(windowWidth * 0.4) - 2, static_cast<int>(windowHeight * 0.3) - 2, static_cast<int>(windowWidth * 0.4) + 4, static_cast<int>(windowHeight * 0.1) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw text input rect
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect textInputRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.3), static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.1)};
    SDL_RenderFillRect(renderer, &textInputRect);
}
void draw_password_textbox()
{
    // Draw text input rect black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect borderRect = {static_cast<int>(windowWidth * 0.4) - 2, static_cast<int>(windowHeight * 0.4) - 2, static_cast<int>(windowWidth * 0.4) + 4, static_cast<int>(windowHeight * 0.1) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw text input rect
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect textInputRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.4), static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.1)};
    SDL_RenderFillRect(renderer, &textInputRect);
}

void draw_policies_popup_window()
{
    // Draw privacy policy popup black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect privacypolicyPopupBorderRect = {static_cast<int>(windowWidth * 0.1) - 2, static_cast<int>(windowHeight * 0.1) - 2, static_cast<int>(windowWidth * 0.7) + 4, static_cast<int>(windowHeight * 0.7) + 4};
    SDL_RenderFillRect(renderer, &privacypolicyPopupBorderRect);

    // draw privacy policy popup
    SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255); // RGB: Light green
    SDL_Rect privacypolicyPopupRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1), static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7)};
    SDL_RenderFillRect(renderer, &privacypolicyPopupRect);

    if (showPrivacyPolicyPopup)
    {
        render_text("Read Privacy Policy below then accept or deny for online access",
                    static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1), 255, 0);
                    if (!acceptedPrivacyPolicy) {
                        privacy_policy_file_read();
                    } else {
                        terms_and_conditions_file_read();
                    }
        
        scene11acceptButton.render_button_rect(renderer);
        scene11denyButton.render_button_rect(renderer);
    }
}

void draw_buttons_scene_1()
{
    scene1LoadGameButton.render_button_rect(renderer);
    scene1newGameButton.render_button_rect(renderer);
    scene1settingsButton.render_button_rect(renderer);
    scene1AchievementsButton.render_button_rect(renderer);
    scene1HelpButton.render_button_rect(renderer);
    scene1multiplayerButton.render_button_rect(renderer);
    scene1QuitButton.render_button_rect(renderer);
    scene1DeveloperLogoLinkButton.render_button_rect(renderer);
}

void draw_buttons_scene_2() // Settings
{

    fontButton.render_button_rect(renderer);
    soundButton.render_button_rect(renderer);
    languageButton.render_button_rect(renderer);
    fpsButton.render_button_rect(renderer);

    resolution800x600Button.render_button_rect(renderer);
    resolution1366x768Button.render_button_rect(renderer);
    resolutionFullScreenButton.render_button_rect(renderer);
    keyRemapButton.render_button_rect(renderer);

    returnGameButton.render_button_rect(renderer);
    returnTitleButton.render_button_rect(renderer);
    settingsResetButton.render_button_rect(renderer);
    settingsSaveButton.render_button_rect(renderer);

    if (isMusicPlaying)
    {
        soundButton.set_button_texture(renderer, "assets/graphics/buttons/settings/sound-on-button.png");
    }
    else
    {
        soundButton.set_button_texture(renderer, "assets/graphics/buttons/settings/sound-off-button.png");
    }

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

    if (is_achievement_unlocked(1))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement1Rect);
    }
    else if (is_achievement_unlocked(2))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement2Rect);
    }
    else if (is_achievement_unlocked(3))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement3Rect);
    }
    else if (is_achievement_unlocked(4))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement4Rect);
    }
    else if (is_achievement_unlocked(5))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement5Rect);
    }
    else if (is_achievement_unlocked(6))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement6Rect);
    }
    else if (is_achievement_unlocked(7))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement7Rect);
    }
    else if (is_achievement_unlocked(8))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement8Rect);
    }
    else if (is_achievement_unlocked(9))
    {
        SDL_RenderCopy(renderer, menuAchievementsTexture, nullptr, &achievement9Rect);
    }
    else if (is_achievement_unlocked(10))
    {
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
void draw_buttons_scene_7() // Update Software
{
    scene7acceptButton.render_button_rect(renderer);
    scene7denyButton.render_button_rect(renderer);
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
void draw_buttons_scene_11() // Online login
{
    if (showPrivacyPolicyPopup)
    {
        draw_policies_popup_window();
    }
    else if (!showPrivacyPolicyPopup)
    {
        draw_username_textbox();
        draw_password_textbox();
        scene11submitUsernameButton.render_button_rect(renderer);
        scene11registerButton.render_button_rect(renderer);
    }
}
void draw_buttons_scene_12() // Create account
{
    draw_username_textbox();
    draw_email_textbox();
    draw_password_textbox();
    scene12submitEmailPasswordButton.render_button_rect(renderer);
    scene12backButton.render_button_rect(renderer);
}
void draw_buttons_scene_13() // Multiplayer lobby
{
    scene13hostGameButton.render_button_rect(renderer);
    scene13joinGameButton.render_button_rect(renderer);
    scene13searchGamesButton.render_button_rect(renderer);
    scene13searchFriendsGamesButton.render_button_rect(renderer);
    scene13refreshButton.render_button_rect(renderer);
    scene13backButton.render_button_rect(renderer);
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

