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


void load_fonts()
{
    font_24 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Bold.ttf", 24);
    font_36 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Bold.ttf", 36);
    font_48 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Bold.ttf", 48);
    if (!font_24 || !font_36 || !font_48)
    {
        std::cerr << "Error: Failed to load font size: " << TTF_GetError() << std::endl;
    }
}

void load_controller()
{
    for (int i = 0; i < SDL_NumJoysticks(); i++)
    {
        if (SDL_IsGameController(i))
        {
            controller = SDL_GameControllerOpen(i);
            if (controller)
            {
                std::cout << "Controller " << i << " is open." << std::endl;
                break;
            }
            else
            {
                std::cerr << "Could not open controller " << i << ": " << SDL_GetError() << std::endl;
            }
        }
    }
}

void load_music(const std::string& songTitle)
{
    if (currentSong != songTitle)
    {
        music = Mix_LoadMUS(songTitle.c_str());
        if (!music)
        {
            std::cerr << "Error: Failed to load music: " << Mix_GetError() << std::endl;
            music = nullptr;
        }
        else
        {
            Mix_PlayMusic(music, -1); // Set loops to -1 for infinite looping
            isMusicPlaying = true;
            currentSong = songTitle;
            std::cout << "Music playing is: " << songTitle << std::endl;
        }
    }
}
void load_sound()
{
    winRoundSound = Mix_LoadWAV("assets/sounds/sound-effects/wavs/success-1 - Pixabay.wav");
    loseRoundSound = Mix_LoadWAV("assets/sounds/sound-effects/wavs/failure drum sound effect 2 - Pixabay.wav");
    winGameSound = Mix_LoadWAV("assets/sounds/sound-effects/wavs/Success Fanfare Trumpets - Pixabay.wav");
    loseGameSound = Mix_LoadWAV("assets/sounds/sound-effects/wavs/Fail - UNIVERSFIELD.wav");
    drawGameSound = Mix_LoadWAV("assets/sounds/sound-effects/wavs/door open close - Pixabay.wav");

    if (!winRoundSound || !loseRoundSound || !winGameSound || !loseGameSound || !drawGameSound)
    {
        std::cerr << "Error: Failed to load victory & loss sound effects: " << Mix_GetError() << std::endl;
    }

}

void load_textures()
{
    // Splash screen
    splashScreenTexture = load_texture("assets/graphics/developer_images/AgniSamooh-HD-logo.png", "Developer Splash screen");

    // Backgrounds
    menuBackgroundTexture = load_texture("assets/graphics/backgrounds/title_background.jpg", "Menu Background");
    worldMapTexture = load_texture("assets/graphics/backgrounds/world-map.jpg", "World Map");

    // Settings buttons
    settingsTexture = load_texture("assets/graphics/buttons/settings/settings-button.png", "Settings Button");
    fontTexture = load_texture("assets/graphics/buttons/settings/font-button.png", "Font Button");
    soundOnTexture = load_texture("assets/graphics/buttons/settings/sound-on-button.png", "Sound On Button");
    soundOffTexture = load_texture("assets/graphics/buttons/settings/sound-off-button.png", "Sound Off Button");
    languageTexture = load_texture("assets/graphics/buttons/settings/language-button.png", "Language Button");
    settingsResetTexture = load_texture("assets/graphics/buttons/settings/update-button.png", "Reset settings Button");
    settingsSaveTexture = load_texture("assets/graphics/buttons/settings/save-button.png", "Save settings Button");
    fpsTexture = load_texture("assets/graphics/buttons/settings/Business-target-Icon-button.png", "FPS Button");
    keyRemapTexture = load_texture("assets/graphics/buttons/settings/keyboard-button.png", "Keyboard Mapping Button");
    resolution800x600Texture = load_texture("assets/graphics/buttons/settings/resolution-800x600-button.png", "Resolution 800x600 Button");
    resolution1366x768Texture = load_texture("assets/graphics/buttons/settings/resolution-1300x768-button.png", "Resolution 1366x768 Button");
    resolutionFullScreenTexture = load_texture("assets/graphics/buttons/settings/resolution-Full-Screen-button.png", "Resolution Full Screen Button");
    returnGameTexture = load_texture("assets/graphics/buttons/settings/return-button.png", "Return Button");
    returnTitleTexture = load_texture("assets/graphics/buttons/settings/home-button.png", "Return to Title Button");

    // Keyboard remapping texture
    keyboardRealisticTexture = load_texture("assets/graphics/boxes/settings/keyboard_realistic.png", "Realistic Keyboard");
    keyboardCartoonTexture = load_texture("assets/graphics/boxes/settings/keyboard_cartoon.png", "Cartoon Keyboard");
    gameControllerTexture = load_texture("assets/graphics/boxes/settings/game_controller.png", "Game controller");
    computerMouseTexture = load_texture("assets/graphics/boxes/settings/computer_mouse.png", "Computer mouse");

    // Help buttons
    forwardTexture = load_texture("assets/graphics/buttons/settings/forward-button.png", "Forward Button");
    backwardTexture = load_texture("assets/graphics/buttons/settings/back-button.png", "Back Button");

    // Scene 4 textures
    achievementsTexture = load_texture("assets/graphics/buttons/settings/achievement-button.png", "Scene 4 - Achievement texture"); 

    // Scene 6 buttons
    beijingTexture = load_texture("assets/graphics/buttons/countries/beijing-button.png", "Beijing Button");
    berlinTexture = load_texture("assets/graphics/buttons/countries/berlin-button.png", "Berlin Button");
    delhiTexture = load_texture("assets/graphics/buttons/countries/delhi-button.png", "Delhi Button");
    hawaiiTexture = load_texture("assets/graphics/buttons/countries/hawaii-button.png", "Hawaii Button");
    singaporeTexture = load_texture("assets/graphics/buttons/countries/singapore-button.png", "Singapore Button");
    londonTexture = load_texture("assets/graphics/buttons/countries/london-button.png", "London Button");
    parisTexture = load_texture("assets/graphics/buttons/countries/paris-button.png", "Paris Button");
    seoulTexture = load_texture("assets/graphics/buttons/countries/seoul-button.png", "Seoul Button");
    shanghaiTexture = load_texture("assets/graphics/buttons/countries/shanghai-button.png", "Shanghai Button");
    tokyoTexture = load_texture("assets/graphics/buttons/countries/tokyo-button.png", "Tokyo Button");
    romeTexture = load_texture("assets/graphics/buttons/countries/rome-button.png", "Rome Button");

    // Scene 8 - Multiplayer
    joinAvailableGameTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Join Available Game");
    createAvailableGameTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Create Available Game");
    inviteFriendToAvailableGameTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Invite Friend to Available Game");
    refreshAvailableGamesTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Refresh Available Games");
    returnToAvailableGamesTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Return to Available Games");

    // Generic - Shared between Main menu + In Game
    helpTexture = load_texture("assets/graphics/buttons/settings/book-button.png", "Help Button");
    restartTexture = load_texture("assets/graphics/buttons/settings/restart-button.png", "Restart Button");
    skipTexture = load_texture("assets/graphics/buttons/settings/skip-button.png", "Skip Button");

    // HUD textures
    heartTexture = load_texture("assets/graphics/HUD/heart.png", "Heart");
    hearts2Texture = load_texture("assets/graphics/HUD/2hearts.png", "2 Hearts");
    hearts3Texture = load_texture("assets/graphics/HUD/3hearts.png", "3 Hearts");
    hearts4Texture = load_texture("assets/graphics/HUD/4hearts.png", "4 Hearts");
    hearts5Texture = load_texture("assets/graphics/HUD/5hearts.png", "5 Hearts");
    hearts10Texture = load_texture("assets/graphics/HUD/10hearts.png", "10 Hearts");
    timerTexture = load_texture("assets/graphics/HUD/timer.png", "Timer");
    frequencyTexture = load_texture("assets/graphics/HUD/frequency.png", "Frequency");

    // Popup buttons
    humanTexture = load_texture("assets/graphics/buttons/settings/human-button.png", "Human");
    computerTexture = load_texture("assets/graphics/buttons/settings/computer-button.png", "Computer");
    buttonTexture = load_texture("assets/graphics/buttons/boxes/button.png", "Button");

    // Backgrounds
    // scenes 20 - 29
    tutorialBackgroundTexture = load_texture("assets/graphics/backgrounds/tutorial-day.jpg", "Tutorial Background");
    beijingDayBackgroundTexture = load_texture("assets/graphics/backgrounds/beijing-day.jpg", "Beijing Day Background");
    beijingNightBackgroundTexture = load_texture("assets/graphics/backgrounds/beijing-night.jpg", "Beijing Night Background");
    berlinDayBackgroundTexture = load_texture("assets/graphics/backgrounds/berlin-day.jpg", "Berlin Day Background");
    berlinNightBackgroundTexture = load_texture("assets/graphics/backgrounds/berlin-night.jpg", "Berlin Night Background");
    delhiDayBackgroundTexture = load_texture("assets/graphics/backgrounds/delhi-day.jpg", "Delhi Day Background");
    delhiNightBackgroundTexture = load_texture("assets/graphics/backgrounds/delhi-night.jpg", "Delhi Night Background");
    hawaiiDayBackgroundTexture = load_texture("assets/graphics/backgrounds/hawaii-day.jpg", "Hawaii Day Background");
    hawaiiNightBackgroundTexture = load_texture("assets/graphics/backgrounds/hawaii-night.jpg", "Hawaii Night Background");
    londonDayBackgroundTexture = load_texture("assets/graphics/backgrounds/london-day.jpg", "London Day Background");
    londonNightBackgroundTexture = load_texture("assets/graphics/backgrounds/london-night.jpg", "London Night Background");
    parisDayBackgroundTexture = load_texture("assets/graphics/backgrounds/paris-day.jpg", "Paris Day Background");
    parisNightBackgroundTexture = load_texture("assets/graphics/backgrounds/paris-night.jpg", "Paris Night Background");
    seoulDayBackgroundTexture = load_texture("assets/graphics/backgrounds/seoul-day.jpg", "Seoul Day Background");
    seoulNightBackgroundTexture = load_texture("assets/graphics/backgrounds/seoul-night.jpg", "Seoul Night Background");
    shanghaiDayBackgroundTexture = load_texture("assets/graphics/backgrounds/shanghai-day.jpg", "Shanghai Day Background");
    shanghaiNightBackgroundTexture = load_texture("assets/graphics/backgrounds/shanghai-night.jpg", "Shanghai Night Background");
    singaporeDayBackgroundTexture = load_texture("assets/graphics/backgrounds/singapore-day.jpg", "Singapore Day Background");
    singaporeNightBackgroundTexture = load_texture("assets/graphics/backgrounds/singapore-night.jpg", "Singapore Night Background");
    tokyoDayBackgroundTexture = load_texture("assets/graphics/backgrounds/tokyo-day.jpg", "Tokyo Day Background");
    tokyoNightBackgroundTexture = load_texture("assets/graphics/backgrounds/tokyo-night.jpg", "Tokyo Night Background");

    // scenes 30 - 39
    capetownDayBackgroundTexture = load_texture("assets/graphics/backgrounds/capetown-day.jpg", "Cape Town Day Background");
    capetownNightBackgroundTexture = load_texture("assets/graphics/backgrounds/capetown-night.jpg", "Cape Town Night Background");
    riodejaneroDayBackgroundTexture = load_texture("assets/graphics/backgrounds/riodejanero-day.jpg", "Rio De Janero Day Background");
    riodejaneroNightBackgroundTexture = load_texture("assets/graphics/backgrounds/riodejanero-night.jpg", "Rio De Janero Night Background");
    romeDayBackgroundTexture = load_texture("assets/graphics/backgrounds/rome-day.jpg", "Rome Day Background");
    romeNightBackgroundTexture = load_texture("assets/graphics/backgrounds/rome-night.jpg", "Rome Night Background");
    hanoiDayBackgroundTexture = load_texture("assets/graphics/backgrounds/hanoi-day.jpg", "Hanoi Day Background");
    hanoiNightBackgroundTexture = load_texture("assets/graphics/backgrounds/hanoi-night.jpg", "Hanoi Night Background");
    barcelonaDayBackgroundTexture = load_texture("assets/graphics/backgrounds/barcelona-day.jpg", "Barcelona Day Background");
    barcelonaNightBackgroundTexture = load_texture("assets/graphics/backgrounds/barcelona-night.jpg", "Barcelona Night Background");
    budapestDayBackgroundTexture = load_texture("assets/graphics/backgrounds/budapest-day.jpg", "Budapest Day Background");
    budapestNightBackgroundTexture = load_texture("assets/graphics/backgrounds/budapest-night.jpg", "Budapest Night Background");
    moscowDayBackgroundTexture = load_texture("assets/graphics/backgrounds/seoul-day.jpg", "Moscow Day Background");
    moscowNightBackgroundTexture = load_texture("assets/graphics/backgrounds/seoul-night.jpg", "Moscow Night Background");
    athensDayBackgroundTexture = load_texture("assets/graphics/backgrounds/shanghai-day.jpg", "Athens Day Background");
    athensNightBackgroundTexture = load_texture("assets/graphics/backgrounds/shanghai-night.jpg", "Athens Night Background");
    manillaDayBackgroundTexture = load_texture("assets/graphics/backgrounds/singapore-day.jpg", "Manilla Day Background");
    manillaNightBackgroundTexture = load_texture("assets/graphics/backgrounds/singapore-night.jpg", "Manilla Night Background");
    tehranDayBackgroundTexture = load_texture("assets/graphics/backgrounds/tehran-day.jpg", "Tehran Day Background");
    tehranNightBackgroundTexture = load_texture("assets/graphics/backgrounds/tehran-night.jpg", "Tehran Night Background");

    // scenes 40 - 49
    telavivDayBackgroundTexture = load_texture("assets/graphics/backgrounds/telaviv-day.jpg", "Tel Aviv Day Background");
    telavivNightBackgroundTexture = load_texture("assets/graphics/backgrounds/telaviv-night.jpg", "Tel Aviv Night Background");
    cairoDayBackgroundTexture = load_texture("assets/graphics/backgrounds/cairo-day.jpg", "Cairo Day Background");
    cairoNightBackgroundTexture = load_texture("assets/graphics/backgrounds/cairo-night.jpg", "Cairo Night Background");
    bogotaDayBackgroundTexture = load_texture("assets/graphics/backgrounds/bogota-day.jpg", "Bogota Day Background");
    bogotaNightBackgroundTexture = load_texture("assets/graphics/backgrounds/bogota-night.jpg", "Bogota Night Background");
    istanbulDayBackgroundTexture = load_texture("assets/graphics/backgrounds/istanbul-day.jpg", "Istanbul Day Background");
    istanbulNightBackgroundTexture = load_texture("assets/graphics/backgrounds/istanbul-night.jpg", "Istanbul Night Background");
    stolkholmDayBackgroundTexture = load_texture("assets/graphics/backgrounds/stolkholm-day.jpg", "Stolkholm Day Background");
    stolkholmNightBackgroundTexture = load_texture("assets/graphics/backgrounds/stolkholm-night.jpg", "Stolkholm Night Background");
    mexicocityDayBackgroundTexture = load_texture("assets/graphics/backgrounds/mexicocity-day.jpg", "Mexico city Day Background");
    mexicocityNightBackgroundTexture = load_texture("assets/graphics/backgrounds/mexicocity-night.jpg", "Mexico city Night Background");
    bangkokDayBackgroundTexture = load_texture("assets/graphics/backgrounds/bangkok-day.jpg", "Bangkok Day Background");
    bangkokNightBackgroundTexture = load_texture("assets/graphics/backgrounds/bangkok-night.jpg", "Bangkok Night Background");
    kathmanduDayBackgroundTexture = load_texture("assets/graphics/backgrounds/kathmandu-day.jpg", "Kathmandu Day Background");
    kathmanduNightBackgroundTexture = load_texture("assets/graphics/backgrounds/kathmandu-night.jpg", "Kathmandu Night Background");
    vancouverDayBackgroundTexture = load_texture("assets/graphics/backgrounds/vancouver-day.jpg", "Vancouver Day Background");
    vancouverNightBackgroundTexture = load_texture("assets/graphics/backgrounds/vancouver-night.jpg", "Vancouver Night Background");
    newyorkDayBackgroundTexture = load_texture("assets/graphics/backgrounds/newyork-day.jpg", "New York Day Background");
    newyorkNightBackgroundTexture = load_texture("assets/graphics/backgrounds/newyork-night.jpg", "New York Night Background");
}
void load_animations()
{
    fireworksAnimationSurface = IMG_Load("assets/graphics/animations/fireworks - haenaillust.gif");
    if (!fireworksAnimationSurface)
    {
        std::cerr << "Error: Faled to load .gif animations: " << IMG_GetError << std::endl;
    }
    else
    {
        fireworksAnimationTexture = SDL_CreateTextureFromSurface(renderer, fireworksAnimationSurface);
        std::cout << "Animation's are loaded." << std::endl;
    }
}