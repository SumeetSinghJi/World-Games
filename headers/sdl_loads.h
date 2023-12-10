#ifndef sdl_loads
#define sdl_loads

#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

extern TTF_Font *font_24;
extern TTF_Font *font_36;
extern TTF_Font *font_48;

extern Mix_Music *music;
extern bool isMusicPlaying;
extern std::string songTitle;
extern std::string currentSong;

// for Sound effects (SFX)
// In Game
extern Mix_Chunk *winRoundSound;
extern Mix_Chunk *loseRoundSound;
extern Mix_Chunk *winGameSound;
extern Mix_Chunk *loseGameSound;
extern Mix_Chunk *drawGameSound;

// buttons
extern SDL_Texture *splashScreenTexture;
extern SDL_Renderer *renderer;

extern SDL_Texture *texture;

// main menu buttons
extern SDL_Texture *menuBackgroundTexture;
extern SDL_Texture *menuNewGameTexture;
extern SDL_Texture *menuLoadGameTexture;
extern SDL_Texture *menuSettingsTexture;
extern SDL_Texture *menuAchievementsTexture;
extern SDL_Texture *menuHelpTexture;
extern SDL_Texture *menuUpdateGameTexture;
extern SDL_Texture *menuQuitTexture;
extern SDL_Texture *AgniSamoohLogoTexture;

// settings buttons
extern SDL_Texture *settingsTexture;
extern SDL_Texture *fontTexture;
extern SDL_Texture *soundOnTexture;
extern SDL_Texture *soundOffTexture;
extern SDL_Texture *languageTexture;
extern SDL_Texture *fpsTexture;
extern SDL_Texture *resolution800x600Texture;
extern SDL_Texture *resolution1366x768Texture;
extern SDL_Texture *resolutionFullScreenTexture;
extern SDL_Texture *returnGameTexture;
extern SDL_Texture *returnTitleTexture;

// help buttons
// Uses return to title button from settings
extern SDL_Texture *forwardTexture;
extern SDL_Texture *backwardTexture;

// scene 6 - world map
extern SDL_Texture *worldMapTexture;  // scene 6
extern SDL_Texture *saveTexture;      // save button on world map
extern SDL_Texture *beijingTexture;   // scene 20
extern SDL_Texture *berlinTexture;    // scene 23
extern SDL_Texture *delhiTexture;     // scene 24
extern SDL_Texture *hawaiiTexture;    // scene 26
extern SDL_Texture *londonTexture;    // scene 21
extern SDL_Texture *parisTexture;     // scene 22
extern SDL_Texture *seoulTexture;     // scene 28
extern SDL_Texture *shanghaiTexture;  // scene 29
extern SDL_Texture *singaporeTexture; // scene 25
extern SDL_Texture *tokyoTexture;     // scene 27

extern SDL_Texture *romeTexture;     // scene 32

// scene 8 - multiplayer
extern SDL_Texture *joinAvailableGameTexture;           // Multiplayer buttons
extern SDL_Texture *createAvailableGameTexture;         // Multiplayer buttons
extern SDL_Texture *inviteFriendToAvailableGameTexture; // Multiplayer buttons
extern SDL_Texture *refreshAvailableGamesTexture;       // Multiplayer buttons
extern SDL_Texture *returnToAvailableGamesTexture;      // Multiplayer buttons

// scene 8 - multiplayer
extern SDL_Texture *joinAvailableGameTexture;           // Multiplayer buttons
extern SDL_Texture *createAvailableGameTexture;         // Multiplayer buttons
extern SDL_Texture *inviteFriendToAvailableGameTexture; // Multiplayer buttons
extern SDL_Texture *refreshAvailableGamesTexture;       // Multiplayer buttons
extern SDL_Texture *returnToAvailableGamesTexture;      // Multiplayer buttons

// HUD buttons
extern SDL_Texture *helpTexture;      // In game - view rules from help
extern SDL_Texture *restartTexture;      // In game - swap icons from hands to abstract images
extern SDL_Texture *skipTexture;      // In game - skips Mentor explaining rules
extern SDL_Texture *heartTexture;     // In game - lives
extern SDL_Texture *timerTexture;     // In game - timer box
extern SDL_Texture *frequencyTexture; // In game - frequency box

// backgrounds
extern SDL_Texture *tutorialBackgroundTexture;       // scene 7
extern SDL_Texture *beijingDayBackgroundTexture;     // scene 20
extern SDL_Texture *beijingNightBackgroundTexture;   // scene 20
extern SDL_Texture *berlinDayBackgroundTexture;      // scene 23
extern SDL_Texture *berlinNightBackgroundTexture;    // scene 23
extern SDL_Texture *delhiDayBackgroundTexture;       // scene 24
extern SDL_Texture *delhiNightBackgroundTexture;     // scene 24
extern SDL_Texture *hawaiiDayBackgroundTexture;      // scene 26
extern SDL_Texture *hawaiiNightBackgroundTexture;    // scene 26
extern SDL_Texture *londonDayBackgroundTexture;      // scene 21
extern SDL_Texture *londonNightBackgroundTexture;    // scene 21
extern SDL_Texture *parisDayBackgroundTexture;       // scene 22
extern SDL_Texture *parisNightBackgroundTexture;     // scene 22
extern SDL_Texture *seoulDayBackgroundTexture;       // scene 28
extern SDL_Texture *seoulNightBackgroundTexture;     // scene 28
extern SDL_Texture *shanghaiDayBackgroundTexture;    // scene 29
extern SDL_Texture *shanghaiNightBackgroundTexture;  // scene 29
extern SDL_Texture *singaporeDayBackgroundTexture;   // scene 25
extern SDL_Texture *singaporeNightBackgroundTexture; // scene 25
extern SDL_Texture *tokyoDayBackgroundTexture;       // scene 27
extern SDL_Texture *tokyoNightBackgroundTexture;     // scene 27

// scenes 30 - 39
extern SDL_Texture *capetownDayBackgroundTexture;      // scene 30
extern SDL_Texture *capetownNightBackgroundTexture;    // scene 30
extern SDL_Texture *riodejaneroDayBackgroundTexture;   // scene 31
extern SDL_Texture *riodejaneroNightBackgroundTexture; // scene 31
extern SDL_Texture *romeDayBackgroundTexture;          // scene 32
extern SDL_Texture *romeNightBackgroundTexture;        // scene 32
extern SDL_Texture *hanoiDayBackgroundTexture;         // scene 33
extern SDL_Texture *hanoiNightBackgroundTexture;       // scene 33
extern SDL_Texture *barcelonaDayBackgroundTexture;     // scene 34
extern SDL_Texture *barcelonaNightBackgroundTexture;   // scene 34
extern SDL_Texture *budapestDayBackgroundTexture;      // scene 35
extern SDL_Texture *budapestNightBackgroundTexture;    // scene 35
extern SDL_Texture *moscowDayBackgroundTexture;        // scene 36
extern SDL_Texture *moscowNightBackgroundTexture;      // scene 36
extern SDL_Texture *athensDayBackgroundTexture;        // scene 37
extern SDL_Texture *athensNightBackgroundTexture;      // scene 37
extern SDL_Texture *manillaDayBackgroundTexture;       // scene 38
extern SDL_Texture *manillaNightBackgroundTexture;     // scene 38
extern SDL_Texture *tehranDayBackgroundTexture;        // scene 39
extern SDL_Texture *tehranNightBackgroundTexture;      // scene 39

// scenes 40 - 49
extern SDL_Texture *telavivDayBackgroundTexture;      // scene 40
extern SDL_Texture *telavivNightBackgroundTexture;    // scene 40
extern SDL_Texture *cairoDayBackgroundTexture;        // scene 41
extern SDL_Texture *cairoNightBackgroundTexture;      // scene 41
extern SDL_Texture *bogotaDayBackgroundTexture;       // scene 42
extern SDL_Texture *bogotaNightBackgroundTexture;     // scene 42
extern SDL_Texture *istanbulDayBackgroundTexture;     // scene 43
extern SDL_Texture *istanbulNightBackgroundTexture;   // scene 43
extern SDL_Texture *stolkholmDayBackgroundTexture;    // scene 44
extern SDL_Texture *stolkholmNightBackgroundTexture;  // scene 44
extern SDL_Texture *mexicocityDayBackgroundTexture;   // scene 45
extern SDL_Texture *mexicocityNightBackgroundTexture; // scene 45
extern SDL_Texture *bangkokDayBackgroundTexture;      // scene 46
extern SDL_Texture *bangkokNightBackgroundTexture;    // scene 46
extern SDL_Texture *kathmanduDayBackgroundTexture;    // scene 47
extern SDL_Texture *kathmanduNightBackgroundTexture;  // scene 47
extern SDL_Texture *vancouverDayBackgroundTexture;    // scene 48
extern SDL_Texture *vancouverNightBackgroundTexture;  // scene 48
extern SDL_Texture *newyorkDayBackgroundTexture;      // scene 49
extern SDL_Texture *newyorkNightBackgroundTexture;    // scene 49

extern SDL_Texture *moonBackgroundTexture; // scene 50

// animations
extern SDL_Texture *fireworksAnimationTexture;
extern SDL_Surface *fireworksAnimationSurface;

extern SDL_GameController *controller;

SDL_Texture *load_texture(const char *path, const char *name)
{
    texture = IMG_LoadTexture(renderer, path);
    if (!texture)
    {
        std::cerr << "Error: Failed to load " << name << ": " << IMG_GetError() << std::endl;
    }
    else
    {
        std::cout << "Successfully loaded " << name << std::endl;
    }
    return texture;
}

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

void load_music(std::string songTitle)
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
        std::cerr << "Error: Failed to load vicotry/loss sound effects: " << Mix_GetError() << std::endl;
    }

}

void load_textures()
{
    // Splash screen
    splashScreenTexture = load_texture("assets/graphics/AgniSamooh/AgniSamooh-HD-logo.png", "Developer Splash screen");

    // Backgrounds
    menuBackgroundTexture = load_texture("assets/graphics/backgrounds/title_background.jpg", "Menu Background");
    worldMapTexture = load_texture("assets/graphics/backgrounds/world-map.jpg", "World Map");

    // Main menu buttons
    menuNewGameTexture = load_texture("assets/graphics/buttons/settings/newgame-button.png", "New Game Button");
    menuLoadGameTexture = load_texture("assets/graphics/buttons/settings/save-button.png", "Load Game Button");
    menuSettingsTexture = load_texture("assets/graphics/buttons/settings/settings-button.png", "Settings Button");
    menuAchievementsTexture = load_texture("assets/graphics/buttons/settings/achievement-button.png", "Achievements Button");
    menuHelpTexture = load_texture("assets/graphics/buttons/settings/help-button.png", "Help Button");
    menuUpdateGameTexture = load_texture("assets/graphics/buttons/settings/update-button.png", "Update Button");
    menuQuitTexture = load_texture("assets/graphics/buttons/settings/quit-button.png", "Quit Button");
    AgniSamoohLogoTexture = load_texture("assets/graphics/AgniSamooh/AgniSamooh-4k-logo.png", "AgniSamooh Logo");

    // Settings buttons
    settingsTexture = load_texture("assets/graphics/buttons/settings/settings-button.png", "Settings Button");
    fontTexture = load_texture("assets/graphics/buttons/settings/font-button.png", "Font Button");
    soundOnTexture = load_texture("assets/graphics/buttons/settings/sound-on-button.png", "Sound On Button");
    soundOffTexture = load_texture("assets/graphics/buttons/settings/sound-off-button.png", "Sound Off Button");
    languageTexture = load_texture("assets/graphics/buttons/settings/language-button.png", "Language Button");
    fpsTexture = load_texture("assets/graphics/buttons/settings/fps-button.png", "FPS Button");
    resolution800x600Texture = load_texture("assets/graphics/buttons/settings/resolution-800x600-button.png", "Resolution 800x600 Button");
    resolution1366x768Texture = load_texture("assets/graphics/buttons/settings/resolution-1300x768-button.png", "Resolution 1366x768 Button");
    resolutionFullScreenTexture = load_texture("assets/graphics/buttons/settings/resolution-Full-Screen-button.png", "Resolution Full Screen Button");
    returnGameTexture = load_texture("assets/graphics/buttons/settings/return-button.png", "Return Button");
    returnTitleTexture = load_texture("assets/graphics/buttons/settings/home-button.png", "Return to Title Button");

    // Help buttons
    forwardTexture = load_texture("assets/graphics/buttons/settings/forward-button.png", "Forward Button");
    backwardTexture = load_texture("assets/graphics/buttons/settings/back-button.png", "Back Button");

    // Scene 6 buttons
    beijingTexture = load_texture("assets/graphics/buttons/scenes/beijing-button.png", "Beijing Button");
    berlinTexture = load_texture("assets/graphics/buttons/scenes/berlin-button.png", "Berlin Button");
    delhiTexture = load_texture("assets/graphics/buttons/scenes/delhi-button.png", "Delhi Button");
    hawaiiTexture = load_texture("assets/graphics/buttons/scenes/hawaii-button.png", "Hawaii Button");
    singaporeTexture = load_texture("assets/graphics/buttons/scenes/singapore-button.png", "Singapore Button");
    londonTexture = load_texture("assets/graphics/buttons/scenes/london-button.png", "London Button");
    parisTexture = load_texture("assets/graphics/buttons/scenes/paris-button.png", "Paris Button");
    seoulTexture = load_texture("assets/graphics/buttons/scenes/seoul-button.png", "Seoul Button");
    shanghaiTexture = load_texture("assets/graphics/buttons/scenes/shanghai-button.png", "Shanghai Button");
    tokyoTexture = load_texture("assets/graphics/buttons/scenes/tokyo-button.png", "Tokyo Button");

    romeTexture = load_texture("assets/graphics/buttons/scenes/rome-button.png", "Rome Button");

    // Scene 8 - Multiplayer
    joinAvailableGameTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Join Available Game");
    createAvailableGameTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Create Available Game");
    inviteFriendToAvailableGameTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Invite Friend to Available Game");
    refreshAvailableGamesTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Refresh Available Games");
    returnToAvailableGamesTexture = load_texture("assets/graphics/models/opponents/scene_7_opponent_plain_pose.png", "Return to Available Games");

    // HUD buttons
    helpTexture = load_texture("assets/graphics/buttons/settings/book-button.png", "Help Button");
    restartTexture = load_texture("assets/graphics/buttons/settings/restart-button.png", "Restart Button");
    skipTexture = load_texture("assets/graphics/buttons/settings/skip-button.png", "Skip Button");

    // HUD textures
    heartTexture = load_texture("assets/graphics/HUD/settings/heart.png", "Heart");
    timerTexture = load_texture("assets/graphics/HUD/settings/timer.png", "Timer");
    frequencyTexture = load_texture("assets/graphics/HUD/settings/frequency.png", "Frequency");

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


#endif
