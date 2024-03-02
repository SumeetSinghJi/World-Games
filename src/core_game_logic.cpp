/*
    Author: Sumeet Singh
    Dated: 26/09/2023
    Minimum C++ Standard: C++11
    Purpose: Definition file (Declaration file is: "headers/global_variables.hpp")
    License: MIT License
    Description: read the attached help.txt file
*/

#include "headers/global_variables.hpp" // Declarations for all headers, variables and functions

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

// Splash screen
SDL_Texture *splashScreenTexture = nullptr;

// for Font
TTF_Font *font_24 = nullptr;
TTF_Font *font_36 = nullptr;
TTF_Font *font_48 = nullptr;
SDL_Texture *textTexture = nullptr;
SDL_Texture *texture = nullptr;

// Main Menu buttons
SDL_Texture *menuBackgroundTexture = nullptr;
SDL_Texture *menuNewGameTexture = nullptr;
SDL_Texture *menuLoadGameTexture = nullptr;
SDL_Texture *menuSettingsTexture = nullptr;
SDL_Texture *menuAchievementsTexture = nullptr;
SDL_Texture *menuHelpTexture = nullptr;
SDL_Texture *menuUpdateGameTexture = nullptr;
SDL_Texture *menuQuitTexture = nullptr;
SDL_Texture *AgniSamoohLogoTexture = nullptr;

// Settings buttons
SDL_Texture *settingsTexture = nullptr;
SDL_Texture *settingsResetTexture = nullptr;
SDL_Texture *settingsSaveTexture = nullptr;
SDL_Texture *fontTexture = nullptr;
SDL_Texture *soundOnTexture = nullptr;
SDL_Texture *soundOffTexture = nullptr;
SDL_Texture *languageTexture = nullptr;
SDL_Texture *fpsTexture = nullptr;
SDL_Texture *keyRemapTexture = nullptr;
SDL_Texture *resolution800x600Texture = nullptr;
SDL_Texture *resolution1366x768Texture = nullptr;
SDL_Texture *resolutionFullScreenTexture = nullptr;
SDL_Texture *returnGameTexture = nullptr;
SDL_Texture *returnTitleTexture = nullptr;

// Keyboard remapping texture
SDL_Texture *keyboardRealisticTexture = nullptr;
SDL_Texture *keyboardCartoonTexture = nullptr;
SDL_Texture *gameControllerTexture = nullptr;
SDL_Texture *computerMouseTexture = nullptr;

// Uses return to title button from settings
SDL_Texture *forwardTexture = nullptr;
SDL_Texture *backwardTexture = nullptr;

// Popup textures
SDL_Texture *humanTexture = nullptr;
SDL_Texture *computerTexture = nullptr;
SDL_Texture *buttonTexture = nullptr; // Popup - button texture

// animations
SDL_Texture *fireworksAnimationTexture = nullptr;
SDL_Surface *fireworksAnimationSurface = nullptr;

// for music
Mix_Music *music = nullptr;

// for Sound effects (SFX)
Mix_Chunk *winRoundSound = nullptr;
Mix_Chunk *loseRoundSound = nullptr;
Mix_Chunk *winGameSound = nullptr;
Mix_Chunk *loseGameSound = nullptr;
Mix_Chunk *drawGameSound = nullptr;

// scene 6 - world map
SDL_Texture *worldMapTexture = nullptr;  // scene 6
SDL_Texture *saveTexture = nullptr;      // save button on world map
SDL_Texture *beijingTexture = nullptr;   // scene 20
SDL_Texture *berlinTexture = nullptr;    // scene 23
SDL_Texture *delhiTexture = nullptr;     // scene 24
SDL_Texture *hawaiiTexture = nullptr;    // scene 26
SDL_Texture *londonTexture = nullptr;    // scene 21
SDL_Texture *parisTexture = nullptr;     // scene 22
SDL_Texture *seoulTexture = nullptr;     // scene 28
SDL_Texture *shanghaiTexture = nullptr;  // scene 29
SDL_Texture *singaporeTexture = nullptr; // scene 25
SDL_Texture *tokyoTexture = nullptr;     // scene 27

SDL_Texture *romeTexture = nullptr; // scene 32

// scene 8 - multiplayer
SDL_Texture *joinAvailableGameTexture = nullptr;           // Multiplayer buttons
SDL_Texture *createAvailableGameTexture = nullptr;         // Multiplayer buttons
SDL_Texture *inviteFriendToAvailableGameTexture = nullptr; // Multiplayer buttons
SDL_Texture *refreshAvailableGamesTexture = nullptr;       // Multiplayer buttons
SDL_Texture *returnToAvailableGamesTexture = nullptr;      // Multiplayer buttons

// HUD buttons
SDL_Texture *helpTexture = nullptr;      // In game - view rules from help
SDL_Texture *restartTexture = nullptr;   // In game - swap icons from hands to abstract images
SDL_Texture *skipTexture = nullptr;      // In game - skips Mentor explaining rules
SDL_Texture *heartTexture = nullptr;     // In game - Rounds
SDL_Texture *hearts2Texture = nullptr;   // In game - Rounds
SDL_Texture *hearts3Texture = nullptr;   // In game - Rounds
SDL_Texture *hearts4Texture = nullptr;   // In game - Rounds
SDL_Texture *hearts5Texture = nullptr;   // In game - Rounds
SDL_Texture *hearts10Texture = nullptr;  // In game - Rounds
SDL_Texture *timerTexture = nullptr;     // In game - timer box
SDL_Texture *frequencyTexture = nullptr; // In game - frequency box

// backgrounds
SDL_Texture *tutorialBackgroundTexture = nullptr;       // scene 7
SDL_Texture *beijingDayBackgroundTexture = nullptr;     // scene 20
SDL_Texture *beijingNightBackgroundTexture = nullptr;   // scene 20
SDL_Texture *berlinDayBackgroundTexture = nullptr;      // scene 23
SDL_Texture *berlinNightBackgroundTexture = nullptr;    // scene 23
SDL_Texture *delhiDayBackgroundTexture = nullptr;       // scene 24
SDL_Texture *delhiNightBackgroundTexture = nullptr;     // scene 24
SDL_Texture *hawaiiDayBackgroundTexture = nullptr;      // scene 26
SDL_Texture *hawaiiNightBackgroundTexture = nullptr;    // scene 26
SDL_Texture *londonDayBackgroundTexture = nullptr;      // scene 21
SDL_Texture *londonNightBackgroundTexture = nullptr;    // scene 21
SDL_Texture *parisDayBackgroundTexture = nullptr;       // scene 22
SDL_Texture *parisNightBackgroundTexture = nullptr;     // scene 22
SDL_Texture *seoulDayBackgroundTexture = nullptr;       // scene 28
SDL_Texture *seoulNightBackgroundTexture = nullptr;     // scene 28
SDL_Texture *shanghaiDayBackgroundTexture = nullptr;    // scene 29
SDL_Texture *shanghaiNightBackgroundTexture = nullptr;  // scene 29
SDL_Texture *singaporeDayBackgroundTexture = nullptr;   // scene 25
SDL_Texture *singaporeNightBackgroundTexture = nullptr; // scene 25
SDL_Texture *tokyoDayBackgroundTexture = nullptr;       // scene 27
SDL_Texture *tokyoNightBackgroundTexture = nullptr;     // scene 27

// scenes 30 - 39
SDL_Texture *capetownDayBackgroundTexture = nullptr;      // scene 30
SDL_Texture *capetownNightBackgroundTexture = nullptr;    // scene 30
SDL_Texture *riodejaneroDayBackgroundTexture = nullptr;   // scene 31
SDL_Texture *riodejaneroNightBackgroundTexture = nullptr; // scene 31
SDL_Texture *romeDayBackgroundTexture = nullptr;          // scene 32
SDL_Texture *romeNightBackgroundTexture = nullptr;        // scene 32
SDL_Texture *hanoiDayBackgroundTexture = nullptr;         // scene 33
SDL_Texture *hanoiNightBackgroundTexture = nullptr;       // scene 33
SDL_Texture *barcelonaDayBackgroundTexture = nullptr;     // scene 34
SDL_Texture *barcelonaNightBackgroundTexture = nullptr;   // scene 34
SDL_Texture *budapestDayBackgroundTexture = nullptr;      // scene 35
SDL_Texture *budapestNightBackgroundTexture = nullptr;    // scene 35
SDL_Texture *moscowDayBackgroundTexture = nullptr;        // scene 36
SDL_Texture *moscowNightBackgroundTexture = nullptr;      // scene 36
SDL_Texture *athensDayBackgroundTexture = nullptr;        // scene 37
SDL_Texture *athensNightBackgroundTexture = nullptr;      // scene 37
SDL_Texture *manillaDayBackgroundTexture = nullptr;       // scene 38
SDL_Texture *manillaNightBackgroundTexture = nullptr;     // scene 38
SDL_Texture *tehranDayBackgroundTexture = nullptr;        // scene 39
SDL_Texture *tehranNightBackgroundTexture = nullptr;      // scene 39

// scenes 40 - 49
SDL_Texture *telavivDayBackgroundTexture = nullptr;      // scene 40
SDL_Texture *telavivNightBackgroundTexture = nullptr;    // scene 40
SDL_Texture *cairoDayBackgroundTexture = nullptr;        // scene 41
SDL_Texture *cairoNightBackgroundTexture = nullptr;      // scene 41
SDL_Texture *bogotaDayBackgroundTexture = nullptr;       // scene 42
SDL_Texture *bogotaNightBackgroundTexture = nullptr;     // scene 42
SDL_Texture *istanbulDayBackgroundTexture = nullptr;     // scene 43
SDL_Texture *istanbulNightBackgroundTexture = nullptr;   // scene 43
SDL_Texture *stolkholmDayBackgroundTexture = nullptr;    // scene 44
SDL_Texture *stolkholmNightBackgroundTexture = nullptr;  // scene 44
SDL_Texture *mexicocityDayBackgroundTexture = nullptr;   // scene 45
SDL_Texture *mexicocityNightBackgroundTexture = nullptr; // scene 45
SDL_Texture *bangkokDayBackgroundTexture = nullptr;      // scene 46
SDL_Texture *bangkokNightBackgroundTexture = nullptr;    // scene 46
SDL_Texture *kathmanduDayBackgroundTexture = nullptr;    // scene 47
SDL_Texture *kathmanduNightBackgroundTexture = nullptr;  // scene 47
SDL_Texture *vancouverDayBackgroundTexture = nullptr;    // scene 48
SDL_Texture *vancouverNightBackgroundTexture = nullptr;  // scene 48
SDL_Texture *newyorkDayBackgroundTexture = nullptr;      // scene 49
SDL_Texture *newyorkNightBackgroundTexture = nullptr;    // scene 49

SDL_GameController *controller = nullptr; // gamepad object initialise
SDL_Event event;                          // event loop object initialise

// Buttons
// Scene 1
Custom_SDL_Button scene1LoadGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1newGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1settingsButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1AchievementsButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1HelpButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1multiplayerButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1QuitButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1DeveloperLogoLinkButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1overwriteGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene1continueButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// scene 2
Custom_SDL_Button fontButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button soundButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button languageButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button fpsButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

Custom_SDL_Button resolution800x600Button(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button resolution1366x768Button(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button resolutionFullScreenButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button keyRemapButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

Custom_SDL_Button returnGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button returnTitleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button settingsResetButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button settingsSaveButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// scene 3
Custom_SDL_Button scene3returnTitleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// scene 4
Custom_SDL_Button scene4returnTitleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// scene 5
Custom_SDL_Button scene5backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene5forwardButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene5continueButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene5returnTitleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// scene 6
Custom_SDL_Button scene6returnTitleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// scene 7
Custom_SDL_Button scene7returnTitleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// scene 10
Custom_SDL_Button scene10acceptButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene10denyButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// Scene 11

Custom_SDL_Button scene11submitUsernameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11registerButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11acceptButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11denyButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// Scene 12
Custom_SDL_Button scene12submitEmailPasswordButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene12backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// Scene 13
Custom_SDL_Button scene13hostGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene13joinGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene13searchGamesButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene13searchFriendsGamesButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene13refreshButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene13backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// Scene 25
Custom_SDL_Button scene25helpButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25settingsButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25returnTitleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

Custom_SDL_Button scene25beijingButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25berlinButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25delhiButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25hawaiiButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25londonButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

Custom_SDL_Button scene25parisButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25seoulButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25shanghaiButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25singaporeButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene25tokyoButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

Custom_SDL_Button scene25romeButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// For SDL_Custom_button find_nearest() to find nearest button through kb handle arrow direction keys for GUI navigation
std::vector<Custom_SDL_Button *> scene1buttons;
std::vector<Custom_SDL_Button *> scene2buttons;
std::vector<Custom_SDL_Button *> scene3buttons;
std::vector<Custom_SDL_Button *> scene4buttons;
std::vector<Custom_SDL_Button *> scene5buttons;
std::vector<Custom_SDL_Button *> scene6buttons;
std::vector<Custom_SDL_Button *> scene7buttons;
std::vector<Custom_SDL_Button *> scene8buttons;
std::vector<Custom_SDL_Button *> scene9buttons;
std::vector<Custom_SDL_Button *> scene10buttons;
std::vector<Custom_SDL_Button *> scene11buttons;
std::vector<Custom_SDL_Button *> scene12buttons;
std::vector<Custom_SDL_Button *> scene13buttons;
std::vector<Custom_SDL_Button *> scene14buttons;
std::vector<Custom_SDL_Button *> scene15buttons;
std::vector<Custom_SDL_Button *> scene16buttons;
std::vector<Custom_SDL_Button *> scene17buttons;
std::vector<Custom_SDL_Button *> scene18buttons;
std::vector<Custom_SDL_Button *> scene19buttons;
std::vector<Custom_SDL_Button *> scene20buttons;
std::vector<Custom_SDL_Button *> scene21buttons;
std::vector<Custom_SDL_Button *> scene22buttons;
std::vector<Custom_SDL_Button *> scene23buttons;
std::vector<Custom_SDL_Button *> scene24buttons;
std::vector<Custom_SDL_Button *> scene25buttons;
std::vector<Custom_SDL_Button *> scene26buttons;
std::vector<Custom_SDL_Button *> scene27buttons;
std::vector<Custom_SDL_Button *> scene28buttons;
std::vector<Custom_SDL_Button *> scene29buttons;
std::vector<Custom_SDL_Button *> scene30buttons;

std::vector<Custom_SDL_Button *> allButtons;
Custom_SDL_Button *Custom_SDL_Button::selectedButton = nullptr;

// GLOBAL VARIABLES
bool quitEventLoop = NULL;                     // for run_SDL Event loop
int windowWidth = 1366;                        // for Window resolution
int windowHeight = 768;                        // for Window resolution
int rectWidth = (windowWidth / 22);            // Button - The image width inside button itself
int rectHeight = (windowHeight / 22);          // Button - The image height inside button itself
int buttonWidth = ((windowWidth / 10));        // Button - The literal button width
int buttonHeight = ((windowHeight / 12));      // Button - The literal button height
int buttonXOffset = 25;                        // Button - X Offset e.g. (windowWidth / 10) - 10) = ((windowWidth / 10) - buttonXOffset) - higher number box goes left
int buttonYOffset = 14;                        // Button - Y Offset e.g. (windowWidth / 10) - 15) = ((windowWidth / 10) - buttonXOffset) - higher number box goes up
int worldmapRegionWidth = (windowWidth / 18);  // World Map scenes button size
int worldmapRegionHeight = (windowWidth / 18); // World Map scenes button size
int textWidth = 0;                             // for font
int textHeight = 0;                            // for font
int fontSize = 36;                             // for font
int scene = 1;                                 // for scene to display

// PLAYER VARIABLES
std::string username = ""; // Multiplayer - Multiplayer players username
std::string email = "";    // Multiplayer - Multiplayer players email address
std::string password = ""; // Multiplayer - Multiplayer players account password

// SETTINGS VARIABLES
bool isMusicPlaying = NULL;                                           // for music
std::string currentSong = "";                                         // for music
std::string songTitle = "assets/sounds/music/Time - AlexiAction.mp3"; // for music
std::string language = "English";                                     // for changing language
std::string osVersion = "";                                           // Custom Multiplatform social media link
int lastScene = 1;                                                    // Settings - return to last game scene
bool isNight = NULL;                                                  // for background cosmetics
bool fpsRendering = false;

// README MOUSE SCROLL VARIABLES
int scrollY = 0;       // Current scroll position
int scrollSpeed = 100; // Speed of mouse wheel and forward and back button page scrolling e.g. in help scene 5

// HUD VARIABLES
int frameCount = 0;            // for FPS HUD display toggle
int timerFPS, lastFrame, fps;  // for FPS HUD display toggle
bool fpsCondition = NULL;      // for FPS HUD display toggle
int lastTime = SDL_GetTicks(); // for FPS HUD display toggle

// HUD - Timer variables
bool timerRunning = false;
bool countdownStarted = false;
int countdownSeconds = 300; // Initial countdown time

// GAME VARIABLES
bool gameStarted = NULL;                      // Toggle to prevent "continuing to game" if game hasn't begun
bool gameWon = NULL;                          // Game variable - display credits on game completion
std::vector<int> unlockedScenes(30, 0);       // unlocked scenes if in game mode
std::vector<int> unlockedAchievements(10, 0); // unlocked scenes if in game mode
int selectedOption = 0;                       // For Keyboard arrow key or Gamepad d-pad selection
int menuTotalOptions = 6;                     // For Keyboard arrow key or Gamepad d-pad selection
int SettingsTotalOptions = 10;                // For Keyboard arrow key or Gamepad d-pad selection
int GameTotalOptions = 10;                    // For Keyboard arrow key or Gamepad d-pad selection

// Multiplayer variables
std::string playerUsername = "";
std::string playerEmail = "";
std::string playerPassword = "";
bool submitUsername = false;
bool showPrivacyPolicyPopup = false;
bool acceptedPrivacyPolicy = false;
bool acceptedTermsAndConditions = false;

// Keyboard Remapping
std::unordered_map<std::string, SDL_Keycode> keyMap = {
    {"w", SDLK_UP},
    {"s", SDLK_DOWN},
    {"a", SDLK_LEFT},
    {"d", SDLK_RIGHT},
    {"d", SDLK_ESCAPE},
    {"d", SDLK_SPACE},
    {"d", SDLK_RETURN},
};

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
void render_text(const std::string &text, int x, int y, Uint8 alpha, int customFontSize)
{
    /* Example
     1. Parameter definitions
     const std::string &text: The text to render to screen
     int x, x position e.g. static_cast<int>(windowWidth * 0.1) = if there are 10 columns it will appear in 1st column from left
     int y: y position e.g. static_cast<int>(windowHeight * 0.3) = if there are 10 rows it will appear in 3rd row from top
     Uint8 alpha: transperancy, leave at 255 per default unless you want particular text transparent scale 0 - 255
     int customFontSize = leave as 0 to scale with all global fontsize functions, however can statically
     set to values equal to fonts on loop below e.g. 24, 36, 48 for fixed heading sizes

     2. Populate parameters
     render_text("Enter Username: ", static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.2), 255, 0);
    */
    TTF_Font *font = nullptr;
    if (customFontSize == 0)
    {
        if (fontSize == 24)
        {
            font = font_24;
        }
        else if (fontSize == 36)
        {
            font = font_36;
        }
        else if (fontSize == 48)
        {
            font = font_48;
        }
    }
    else if (!customFontSize == 0)
    {
        if (customFontSize == 24)
        {
            font = font_24;
        }
        else if (customFontSize == 36)
        {
            font = font_36;
        }
        else if (customFontSize == 48)
        {
            font = font_48;
        }
    }

    if (font)
    {
        SDL_Color textColor = {0, 0, 0, alpha};
        SDL_Surface *textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), textColor);

        if (textSurface)
        {
            // Calculate textWidth and textHeight using TTF_SizeText
            int textWidth, textHeight;
            TTF_SizeText(font, text.c_str(), &textWidth, &textHeight);

            SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_FreeSurface(textSurface);

            if (textTexture)
            {
                SDL_Rect textRect = {x, y, textWidth, textHeight};
                SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            }
        }
    }
}

void is_scene_unlocked(int target)
{
    std::cout << "target to find in unlocked scenes is " << target << std::endl;
    std::cout << "Unlocked scenes: " << std::endl;
    for (int y : unlockedScenes)
    {
        std::cout << y << ", ";
    }

    bool found = false;
    for (int i : unlockedScenes)
    {
        if (i == target)
        {
            found = true;
        }
    }
    if (found == true)
    {
        render_text("You already defeated the grandmaster", (windowWidth * 0.3), (windowHeight * 0.8), 255, 0);
    }
    else
    {
        scene = target;
    }
}
bool is_achievement_unlocked(int target)
{
    for (int y : unlockedAchievements)
    {
        std::cout << y << ", ";
    }

    bool found = false;
    for (int i : unlockedAchievements)
    {
        if (i == target)
        {
            found = true;
        }
    }
    if (found == true)
    {
        return true;
    }
    return false;
}
void render_fps()
{
    if (!fpsCondition)
    {
        fpsCondition = true;
    }
    else
    {
        fpsCondition = false;
    }
}

// MAIN MENU & SETTINGS FUNCTIONS
void play_developer_splash_screen()
{
    // Display the splash screen for 2 seconds
    SDL_RenderCopy(renderer, splashScreenTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}
void change_resolution(int newWindowWidth, int newWindowHeight)
{
    // Update the window size
    windowWidth = newWindowWidth;
    windowHeight = newWindowHeight;
    SDL_SetWindowSize(window, windowWidth, windowHeight);
}
void new_game()
{
    gameStarted = true; // This is flagged as on, so that in Settings screen you can "Continue" to game, if started else not.
    gameWon = NULL;
    unlockedScenes.clear();
    unlockedAchievements.clear();
}
std::string find_os()
{
    const char *char_osVersion = SDL_GetPlatform();
    std::string osVersion = char_osVersion;
    if (char_osVersion != NULL)
    {
        std::cout << "Host operating system: " << char_osVersion << std::endl;
    }
    else
    {
        std::cerr << "Failed to detect the host operating system." << std::endl;
    }
    return osVersion;
}
void manual_file_read()
{
    std::cout << "Reading contents from: MANUAL.txt" << std::endl;

    // Read contents from the MANUAL.txt file
    std::ifstream sentence_file("MANUAL.txt");
    if (!sentence_file.is_open())
    {
        std::cerr << "Error: Failed to open MANUAL.txt" << std::endl;
        return;
    }

    // Render position for the first line of text
    int renderY = static_cast<int>(windowHeight * 0.2) + scrollY;

    // Read lines from the file and render them to the window
    std::string line;
    while (std::getline(sentence_file, line))
    {
        if (renderY >= 0 && renderY < windowHeight)
        {
            // Render only if the text is within the visible area of the window
            if (line.size() > 80) // Check if the line is too long
            {
                // Split the line into two parts
                std::string firstHalf = line.substr(0, 60); // assuming you want to split at 40 characters
                std::string secondHalf = line.substr(40);

                // Render the first half
                render_text(firstHalf, static_cast<int>(windowWidth * 0.1), renderY, 255, 0);
                renderY += 30; // Vertical spacing between lines

                // Render the second half
                render_text(secondHalf, static_cast<int>(windowWidth * 0.1), renderY, 255, 0);
                renderY += 30; // Vertical spacing between lines
            }
            else
            {
                render_text(line, static_cast<int>(windowWidth * 0.1), renderY, 255, 0);
                // Update render position for the next line of text
                renderY += 30; // Vertical spacing between lines
            }
        }
    }
    // Close the file
    sentence_file.close();
}
void credits_file_read()
{
    std::cout << "Reading contents from: credits.txt" << std::endl;

    // Read contents from the CREDITS.txt file
    std::ifstream sentence_file("CREDITS.txt");
    if (!sentence_file.is_open())
    {
        std::cerr << "Error: Failed to open credits.txt" << std::endl;
        return;
    }

    // Render position for the first line of text
    int renderY = static_cast<int>(windowHeight * 0.2) + scrollY;

    // Read lines from the file and render them to the window
    std::string line;
    while (std::getline(sentence_file, line))
    {
        // Render only if the text is within the visible area of the window
        if (renderY >= 0 && renderY < windowHeight)
            render_text(line, static_cast<int>(windowWidth * 0.1), renderY, 255, 0);

        // Update render position for the next line of text
        renderY += 30; // Vertical spacing between lines
    }

    // Close the file
    sentence_file.close();
}
void privacy_policy_file_read()
{
    std::cout << "Reading contents from: PRIVACY_POLICY.txt" << std::endl;

    // Read contents from the PRIVACY_POLICY.txt file
    std::ifstream sentence_file("PRIVACY_POLICY.txt");
    if (!sentence_file.is_open())
    {
        std::cerr << "Error: Failed to open PRIVACY_POLICY.txt" << std::endl;
        return;
    }

    // Render position for the first line of text
    int renderY = static_cast<int>(windowHeight * 0.2) + scrollY;

    // Read lines from the file and render them to the window
    std::string line;
    while (std::getline(sentence_file, line))
    {
        // Render only if the text is within the visible area of the window
        if (renderY >= 0 && renderY < windowHeight)
            render_text(line, static_cast<int>(windowWidth * 0.1), renderY, 255, 0);

        // Update render position for the next line of text
        renderY += 30; // Vertical spacing between lines
    }

    // Close the file
    sentence_file.close();
}
void terms_and_conditions_file_read()
{
    std::cout << "Reading contents from: TERMS_AND_CONDITIONS.txt" << std::endl;

    // Read contents from the TERMS_AND_CONDITIONS.txt file
    std::ifstream sentence_file("TERMS_AND_CONDITIONS.txt");
    if (!sentence_file.is_open())
    {
        std::cerr << "Error: Failed to open TERMS_AND_CONDITIONS.txt" << std::endl;
        return;
    }

    // Render position for the first line of text
    int renderY = static_cast<int>(windowHeight * 0.2) + scrollY;

    // Read lines from the file and render them to the window
    std::string line;
    while (std::getline(sentence_file, line))
    {
        // Render only if the text is within the visible area of the window
        if (renderY >= 0 && renderY < windowHeight)
            render_text(line, static_cast<int>(windowWidth * 0.1), renderY, 255, 0);

        // Update render position for the next line of text
        renderY += 30; // Vertical spacing between lines
    }

    // Close the file
    sentence_file.close();
}

void key_remap_SDL(const std::string &newKey, SDL_Keycode &oldKey)
{
    auto it = keyMap.find(newKey);
    if (it != keyMap.end())
    {
        oldKey = it->second;
        std::cout << "Key remapped successfully!" << std::endl;
    }
    else
    {
        std::cout << "Invalid key mapping: " << newKey << std::endl;
    }
}

// HUD Functions
void toggle_countdown(bool &subGameSettingsShowPopup, bool &subGameOver, int &subGameWinner)
{
    // toggle_countdown() started whenever the popup for game start variable is closed
    if (!countdownStarted)
    {
        countdownStarted = true;
        std::thread countdownThread([&]()
                                    {
            timerRunning = true;
            for (; countdownSeconds > 0 && timerRunning; --countdownSeconds) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            timerRunning = false;
            if (countdownSeconds <= 0) {
                if(!subGameSettingsShowPopup) {
                    subGameOver = true;
                    subGameWinner = 3; // draw

                    /*                    
                    */
                }
                
            } });
        countdownThread.detach(); // Detach the thread to let it run independently
    }
    else
    {
        countdownStarted = false;
        timerRunning = false; // Stop the countdown when toggled off
    }
}

void draw_timer()
{
    /* draw_timer() is placed in standard draw()
    countdownSeconds can be any value from rect, but default value is global variable, countdownSeconds = 120;

    Calculate minutes and seconds
        if countdownSeconds = 75;
            75 seconds / 60 = 1 minute
            75 seconds / 60 = remainder 15 seconds
        render_text(1:15)
    */
    SDL_Rect timerRect = {static_cast<int>(windowWidth * 0.05), static_cast<int>(windowHeight * 0.05), (windowWidth / 4), (windowHeight / 8)};
    SDL_RenderCopy(renderer, timerTexture, nullptr, &timerRect);

    int minutes = countdownSeconds / 60;
    int seconds = countdownSeconds % 60;

    // If minutes or seconds < 10, it will add an 0 e.g. 120 seconds = 2. As 2 < 10, final output: 02:00
    std::string timerText = (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

    render_text(timerText, timerRect.x + 150, timerRect.y + 30, 255, 0);
}
void draw_win_frequency(const std::vector<int> &winners, const std::vector<int> &winnersChoice)
{
    SDL_Rect frequencyRect = {static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.3), (windowWidth / 6), (windowHeight / 6)};
    SDL_RenderCopy(renderer, frequencyTexture, nullptr, &frequencyRect);

    int frequencyRectyOffSet = 0; // Initialize offset for vertical spacing

    for (size_t i = 0; i < winners.size(); ++i)
    {
        std::string winnerString = "";
        std::string winnerChoiceString = "";

        int winner = winners[i];
        int winnerChoice = winnersChoice[i];

        if (winner == 1)
        {
            winnerString = "Player";
        }
        else if (winner == 2)
        {
            winnerString = "Opponent";
        }
        else if (winner == 3)
        {
            winnerString = "Draw";
        }

        if (winnerChoice == 0)
        {
            winnerChoiceString = "O";
        }
        else if (winnerChoice == 1)
        {
            winnerChoiceString = "X";
        }
        else if (winnerChoice == 2)
        {
            winnerChoiceString = "";
        }

        // Render winner and their choice at appropriate positions
        render_text(winnerString, static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.15) + frequencyRect.y + frequencyRectyOffSet, 255, 0);
        render_text(winnerChoiceString, static_cast<int>(windowWidth * 0.92), static_cast<int>(windowHeight * 0.15) + frequencyRect.y + frequencyRectyOffSet, 255, 0);

        frequencyRectyOffSet += 40; // Move to the next vertical position for next winner
    }
}
void draw_lives(int lives)
{
    int initialHeartX = static_cast<int>(windowWidth * 0.37); // Initial x-position for the first heart
    int heartWidth = windowWidth / 26;                        // Width of each heart
    int xHeartSpacing = 5;                                    // Adjust this value for spacing between hearts

    SDL_Rect heartRect = {initialHeartX, static_cast<int>(windowHeight * 0.15), heartWidth, heartWidth};

    for (int i = 0; i < lives; i++)
    {
        heartRect.x = initialHeartX + (heartWidth + xHeartSpacing) * i;
        SDL_RenderCopy(renderer, heartTexture, nullptr, &heartRect);
    }
}

void load_buttons_to_scene_vectors()
{
    // scene 1
    scene1buttons.push_back(&scene1LoadGameButton);
    scene1buttons.push_back(&scene1newGameButton);
    scene1buttons.push_back(&scene1settingsButton);
    scene1buttons.push_back(&scene1AchievementsButton);
    scene1buttons.push_back(&scene1HelpButton);
    scene1buttons.push_back(&scene1multiplayerButton);
    scene1buttons.push_back(&scene1QuitButton);
    scene1buttons.push_back(&scene1DeveloperLogoLinkButton);
    // scene 2
    scene2buttons.push_back(&fontButton);
    scene2buttons.push_back(&soundButton);
    scene2buttons.push_back(&languageButton);
    scene2buttons.push_back(&fpsButton);

    scene2buttons.push_back(&resolution800x600Button);
    scene2buttons.push_back(&resolution1366x768Button);
    scene2buttons.push_back(&resolutionFullScreenButton);
    scene2buttons.push_back(&keyRemapButton);

    scene2buttons.push_back(&returnGameButton);
    scene2buttons.push_back(&returnTitleButton);
    scene2buttons.push_back(&settingsResetButton);
    scene2buttons.push_back(&settingsSaveButton);
    
    // scene 3
    scene3buttons.push_back(&scene3returnTitleButton);
    // scene 4
    scene4buttons.push_back(&scene4returnTitleButton);
    // scene 5
    scene5buttons.push_back(&scene5backButton);
    scene5buttons.push_back(&scene5forwardButton);
    scene5buttons.push_back(&scene5continueButton);
    scene5buttons.push_back(&scene5returnTitleButton);
    // scene 6
    scene7buttons.push_back(&scene6returnTitleButton);
    // scene 7
    scene7buttons.push_back(&scene7returnTitleButton);
    // scene 10
    scene10buttons.push_back(&scene10acceptButton);
    scene10buttons.push_back(&scene10denyButton);
    // scene 11
    scene11buttons.push_back(&scene11submitUsernameButton);
    scene11buttons.push_back(&scene11registerButton);
    scene11buttons.push_back(&scene11acceptButton);
    scene11buttons.push_back(&scene11denyButton);
    // scene 12
    scene12buttons.push_back(&scene12submitEmailPasswordButton);
    scene12buttons.push_back(&scene12backButton);
    // scene 13
    scene13buttons.push_back(&scene13hostGameButton);
    scene13buttons.push_back(&scene13joinGameButton);
    scene13buttons.push_back(&scene13searchGamesButton);
    scene13buttons.push_back(&scene13searchFriendsGamesButton);
    scene13buttons.push_back(&scene13refreshButton);
    scene13buttons.push_back(&scene13backButton);
    // scene 25
    scene25buttons.push_back(&scene25helpButton);
    scene25buttons.push_back(&scene25settingsButton);
    scene25buttons.push_back(&scene25returnTitleButton);

    scene25buttons.push_back(&scene25beijingButton);
    scene25buttons.push_back(&scene25berlinButton);
    scene25buttons.push_back(&scene25delhiButton);
    scene25buttons.push_back(&scene25hawaiiButton);
    scene25buttons.push_back(&scene25londonButton);

    scene25buttons.push_back(&scene25parisButton);
    scene25buttons.push_back(&scene25seoulButton);
    scene25buttons.push_back(&scene25shanghaiButton);
    scene25buttons.push_back(&scene25singaporeButton);
    scene25buttons.push_back(&scene25tokyoButton);

    scene25buttons.push_back(&scene25romeButton);

}
void load_buttons_to_allButtons_vector()
{
    allButtons.insert(allButtons.end(), scene1buttons.begin(), scene1buttons.end());
    allButtons.insert(allButtons.end(), scene2buttons.begin(), scene2buttons.end());
    allButtons.insert(allButtons.end(), scene3buttons.begin(), scene3buttons.end());
    allButtons.insert(allButtons.end(), scene4buttons.begin(), scene4buttons.end());
    allButtons.insert(allButtons.end(), scene5buttons.begin(), scene5buttons.end());
    allButtons.insert(allButtons.end(), scene6buttons.begin(), scene6buttons.end());
    allButtons.insert(allButtons.end(), scene7buttons.begin(), scene7buttons.end());
    allButtons.insert(allButtons.end(), scene8buttons.begin(), scene8buttons.end());
    allButtons.insert(allButtons.end(), scene9buttons.begin(), scene9buttons.end());
    allButtons.insert(allButtons.end(), scene10buttons.begin(), scene10buttons.end());
    allButtons.insert(allButtons.end(), scene11buttons.begin(), scene11buttons.end());
    allButtons.insert(allButtons.end(), scene12buttons.begin(), scene12buttons.end());
    allButtons.insert(allButtons.end(), scene13buttons.begin(), scene13buttons.end());
    allButtons.insert(allButtons.end(), scene14buttons.begin(), scene14buttons.end());
    allButtons.insert(allButtons.end(), scene15buttons.begin(), scene15buttons.end());
    allButtons.insert(allButtons.end(), scene16buttons.begin(), scene16buttons.end());
    allButtons.insert(allButtons.end(), scene17buttons.begin(), scene17buttons.end());
    allButtons.insert(allButtons.end(), scene18buttons.begin(), scene18buttons.end());
    allButtons.insert(allButtons.end(), scene19buttons.begin(), scene19buttons.end());
    allButtons.insert(allButtons.end(), scene20buttons.begin(), scene20buttons.end());
    allButtons.insert(allButtons.end(), scene21buttons.begin(), scene21buttons.end());
    allButtons.insert(allButtons.end(), scene22buttons.begin(), scene22buttons.end());
    allButtons.insert(allButtons.end(), scene23buttons.begin(), scene23buttons.end());
    allButtons.insert(allButtons.end(), scene24buttons.begin(), scene24buttons.end());
    allButtons.insert(allButtons.end(), scene25buttons.begin(), scene25buttons.end());
    allButtons.insert(allButtons.end(), scene26buttons.begin(), scene26buttons.end());
    allButtons.insert(allButtons.end(), scene27buttons.begin(), scene27buttons.end());
    allButtons.insert(allButtons.end(), scene28buttons.begin(), scene28buttons.end());
    allButtons.insert(allButtons.end(), scene29buttons.begin(), scene29buttons.end());
    allButtons.insert(allButtons.end(), scene30buttons.begin(), scene30buttons.end());
}

void load_buttons_1()
{
    scene1LoadGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.15),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/load-button.png", false); // RGB: Light green
    scene1newGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25),
                                            rectWidth, rectHeight,
                                            "", 144, 238, 144, 255, "assets/graphics/buttons/settings/newgame-button.png", false); // RGB: Light green
    scene1settingsButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.35),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/settings-button.png", false); // RGB: Light green
    scene1AchievementsButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.45),
                                                 rectWidth, rectHeight,
                                                 "", 144, 238, 144, 255, "assets/graphics/buttons/settings/achievement-button.png", false); // RGB: Light green
    scene1HelpButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.55),
                                         rectWidth, rectHeight,
                                         "", 144, 238, 144, 255, "assets/graphics/buttons/settings/internet-button.png", false); // RGB: Light green
    scene1multiplayerButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.65),
                                                rectWidth, rectHeight,
                                                "", 144, 238, 144, 255, "assets/graphics/buttons/settings/help-button.png", false); // RGB: Light green
    scene1QuitButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.75),
                                         rectWidth, rectHeight,
                                         "", 144, 238, 144, 255, "assets/graphics/buttons/settings/quit-button.png", false); // RGB: Light green
    scene1DeveloperLogoLinkButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.73), static_cast<int>(windowHeight * 0.73),
                                                      (windowWidth) / 6, (windowHeight) / 6,
                                                      "", 144, 238, 144, 255, "assets/graphics/developer_images/AgniSamooh-4k-logo.png", false);
    scene1overwriteGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.3), static_cast<int>(windowHeight * 0.6),
                                                      (static_cast<int>(windowWidth * 0.2)), (static_cast<int>(windowHeight * 0.1)),
                                                      "OVERWRITE", 144, 238, 144, 255, "", false);
    scene1continueButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.6),
                                                      (static_cast<int>(windowWidth * 0.2)), (static_cast<int>(windowHeight * 0.1)),
                                                      "LOAD GAME", 144, 238, 144, 255, "", false);
    
    scene1overwriteGameButton.set_button_texture(renderer, "");
    scene1continueButton.set_button_texture(renderer, "");
    scene1LoadGameButton.set_button_texture(renderer, "");
    scene1newGameButton.set_button_texture(renderer, "");
    scene1settingsButton.set_button_texture(renderer, "");
    scene1AchievementsButton.set_button_texture(renderer, "");
    scene1HelpButton.set_button_texture(renderer, "");
    scene1multiplayerButton.set_button_texture(renderer, "");
    scene1QuitButton.set_button_texture(renderer, "");
    scene1DeveloperLogoLinkButton.set_button_texture(renderer, "");
}
void load_buttons_2()
{
        fontButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.2),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/font-button.png", false); // RGB: Light green
        soundButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.4),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/sound-on-button.png", false); // RGB: Light green
        languageButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.6),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/language-button.png", false); // RGB: Light green
        fpsButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.8),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/Business-target-Icon-button.png", false); // RGB: Light green
        resolution800x600Button = Custom_SDL_Button(static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/resolution-800x600-button.png", false); // RGB: Light green
        resolution1366x768Button = Custom_SDL_Button(static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.4),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/resolution-1300x768-button.png", false); // RGB: Light green
        resolutionFullScreenButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/resolution-Full-Screen-button.png", false); // RGB: Light green
        keyRemapButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.8),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/keyboard-button.png", false); // RGB: Light green
        returnGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.2),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/return-button.png", false); // RGB: Light green
        returnTitleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.4),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green
        settingsResetButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.6),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/load-button.png", false); // RGB: Light green
        settingsSaveButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                             rectWidth, rectHeight,
                                             "", 144, 238, 144, 255, "assets/graphics/buttons/settings/save-button.png", false); // RGB: Light green
        fontButton.set_button_texture(renderer, "");
        soundButton.set_button_texture(renderer, "");
        languageButton.set_button_texture(renderer, "");
        fpsButton.set_button_texture(renderer, "");
        resolution800x600Button.set_button_texture(renderer, "");
        resolution1366x768Button.set_button_texture(renderer, "");
        resolutionFullScreenButton.set_button_texture(renderer, "");
        keyRemapButton.set_button_texture(renderer, "");
        returnGameButton.set_button_texture(renderer, "");
        returnTitleButton.set_button_texture(renderer, "");
        settingsResetButton.set_button_texture(renderer, "");
        settingsSaveButton.set_button_texture(renderer, "");
}
void load_buttons_3()
{
    scene3returnTitleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.25),
                                           rectWidth, rectHeight,
                                           "", 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green
    scene3returnTitleButton.set_button_texture(renderer, "");
}
void load_buttons_4()
{
    scene4returnTitleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                           rectWidth, rectHeight,
                                           "", 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green
    scene4returnTitleButton.set_button_texture(renderer, "");
}
void load_buttons_5()
{
    scene5backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.8),
                                           rectWidth, rectHeight,
                                           "", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene5forwardButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.8),
                                           rectWidth, rectHeight,
                                           "", 144, 238, 144, 255, "assets/graphics/buttons/settings/forward-button.png", false); // RGB: Light green
    scene5continueButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.8),
                                           rectWidth, rectHeight,
                                           "", 144, 238, 144, 255, "assets/graphics/buttons/settings/continue-button.png", false); // RGB: Light green
    scene5returnTitleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.8), static_cast<int>(windowHeight * 0.8),
                                           rectWidth, rectHeight,
                                           "", 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green
    scene5backButton.set_button_texture(renderer, "");
    scene5forwardButton.set_button_texture(renderer, "");
    scene5continueButton.set_button_texture(renderer, "");
    scene5returnTitleButton.set_button_texture(renderer, "");
}
void load_buttons_6()
{
    scene6returnTitleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                           rectWidth, rectHeight,
                                           accept_txt, 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green
    scene6returnTitleButton.set_button_texture(renderer, "");
}
void load_buttons_7()
{
    scene7returnTitleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                           rectWidth, rectHeight,
                                           accept_txt, 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green
    scene7returnTitleButton.set_button_texture(renderer, "");
}
void load_buttons_8()
{
}
void load_buttons_10()
{
    scene10acceptButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.7),
                                           rectWidth, rectHeight,
                                           accept_txt, 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green

    scene10denyButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.7),
                                           rectWidth, rectHeight,
                                           accept_txt, 144, 238, 144, 255, "assets/graphics/buttons/settings/home-button.png", false); // RGB: Light green
    
    scene10acceptButton.set_button_texture(renderer, "");
    scene10denyButton.set_button_texture(renderer, "");
}

void load_buttons_11()
{
    scene11submitUsernameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                    static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                    "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene11registerButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "REGISTER", 144, 238, 144, 255, "", false); // RGB: Light green
    scene11acceptButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.6),
                                            static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                            "ACCEPT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene11denyButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.6),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "DENY", 144, 238, 144, 255, "", false); // RGB: Light green
}
void load_buttons_12()
{
    scene12submitEmailPasswordButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                         static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                         "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene12backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene12backButton.set_button_texture(renderer, "");
}
void load_buttons_13()
{
    scene13hostGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene13joinGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene13searchGamesButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                 static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                 "SUBMIT", 144, 238, 144, 255, "assets/graphics/buttons/settings/zoom-button.png", false); // RGB: Light green
    scene13searchFriendsGamesButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                        static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                        "SUBMIT", 144, 238, 144, 255, "assets/graphics/buttons/settings/zoom-button.png", false); // RGB: Light green
    scene13refreshButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                             static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                             "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/refresh-button.png", false); // RGB: Light green
    scene13backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene13backButton.set_button_texture(renderer, "");
}
void load_buttons_25()
{
    scene25helpButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.7),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/settings/help-button.png", false); // RGB: Light green
    scene25settingsButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.7),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/settings/settings-button.png", false); // RGB: Light green    
    scene25returnTitleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.55), static_cast<int>(windowHeight * 0.7),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/settings/return-button.png", false); // RGB: Light green

    scene25beijingButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.49),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/beijing-button.png", false); // RGB: Light green
    scene25berlinButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.48), static_cast<int>(windowHeight * 0.36),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/berlin-button.png", false); // RGB: Light green    
    scene25delhiButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.63), static_cast<int>(windowHeight * 0.46),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/delhi-button.png", false); // RGB: Light green
    scene25hawaiiButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.01), static_cast<int>(windowHeight * 0.5),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/hawaii-button.png", false); // RGB: Light green                                                  
    scene25londonButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.43), static_cast<int>(windowHeight * 0.3),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/london-button.png", false); // RGB: Light green
    
    scene25parisButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.4),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/paris-button.png", false); // RGB: Light green    
    scene25seoulButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.78), static_cast<int>(windowHeight * 0.4),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/seoul-button.png", false); // RGB: Light green
    scene25shanghaiButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.4),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/shanghai-button.png", false); // RGB: Light green    
    scene25singaporeButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.57),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/singapore-button.png", false); // RGB: Light green
    scene25tokyoButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.83), static_cast<int>(windowHeight * 0.43),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/tokyo-button.png", false); // RGB: Light green    
    
    scene25romeButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.50), static_cast<int>(windowHeight * 0.45),
                                                  rectWidth, rectHeight,
                                                  "", 144, 238, 144, 255, "assets/graphics/buttons/countries/rome-button.png", false); // RGB: Light green
    
    scene25helpButton.set_button_texture(renderer, "");
    scene25settingsButton.set_button_texture(renderer, "");
    scene25returnTitleButton.set_button_texture(renderer, "");

    scene25beijingButton.set_button_texture(renderer, "");
    scene25berlinButton.set_button_texture(renderer, "");
    scene25delhiButton.set_button_texture(renderer, "");
    scene25hawaiiButton.set_button_texture(renderer, "");
    scene25londonButton.set_button_texture(renderer, "");

    scene25parisButton.set_button_texture(renderer, "");
    scene25seoulButton.set_button_texture(renderer, "");
    scene25shanghaiButton.set_button_texture(renderer, "");
    scene25singaporeButton.set_button_texture(renderer, "");
    scene25tokyoButton.set_button_texture(renderer, "");
    
    scene25romeButton.set_button_texture(renderer, "");
}

// SDL CODE FUNCTIONS
void start_SDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error: Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "Successfully initialised: SDL2" << std::endl;
    }

    if (TTF_Init() != 0)
    {
        std::cerr << "Error: Failed to initialize SDL Font: " << TTF_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    else
    {
        std::cout << "Successfully initialised: SDL2 TTF" << std::endl;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::cerr << "Error: Failed to initialize SDL IMG: " << IMG_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    else
    {
        std::cout << "Successfully initialised: SDL2 Image" << std::endl;
    }

    if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
    {
        std::cerr << "Error: Failed to initialize Audio: " << Mix_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    else
    {
        std::cout << "Successfully initialised: SDL2 Mixer" << std::endl;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        std::cerr << "Error: Failed to open audio channel: " << Mix_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("Shoushiling 手勢令", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Error: Failed to create SDL Window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Error: Failed to create SDL Renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
    load_fonts(); // Load fonts here
    load_textures();
    ttt_load_textures();
    load_animations();
    std::string currentSong = "";
    std::string songTitle = "assets/sounds/music/Time - AlexiAction.mp3";
    load_music(songTitle);
    load_sound();
    load_controller();
    localisation("English");
    load_buttons_1();
    load_buttons_2();
    load_buttons_3();
    load_buttons_4();
    load_buttons_5();
    load_buttons_6();
    load_buttons_7();
    load_buttons_8();
    load_buttons_11();
    load_buttons_12();
    load_buttons_13();
    load_buttons_25();
    load_buttons_to_scene_vectors();
    load_buttons_to_allButtons_vector();
}

void handle_events()
{
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            // save_game();
            std::cout << "Game Quiting. Goodbye" << std::endl;
            quitEventLoop = true;
        }
        else if (event.type == SDL_MOUSEWHEEL)
        {
            if (event.wheel.y > 0)
            {
                std::cout << "Mouse wheel moved UP" << std::endl;
                scrollY -= scrollSpeed; // Scroll up
            }
            else if (event.wheel.y < 0)
            {
                std::cout << "Mouse wheel moved DOWN" << std::endl;
                scrollY += scrollSpeed; // Scroll down
            }
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_FINGERDOWN) // For Mouse and Touch key input
        {
            int mouseX, mouseY;
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&mouseX, &mouseY);
            }

            else if (event.type == SDL_FINGERDOWN)
            {
                mouseX = static_cast<int>(event.tfinger.x * windowWidth);
                mouseY = static_cast<int>(event.tfinger.y * windowHeight);
            }

            if (scene == 1)
            {
                handle_click_scene_1(mouseX, mouseY);
            }
            else if (scene == 2)
            {
                handle_click_scene_2(mouseX, mouseY);
            }
            else if (scene == 3)
            {
                handle_click_scene_3(mouseX, mouseY);
            }
            else if (scene == 4)
            {
                handle_click_scene_4(mouseX, mouseY);
            }
            else if (scene == 5)
            {
                handle_click_scene_5(mouseX, mouseY);
            }
            else if (scene == 25)
            {
                handle_click_scene_25(mouseX, mouseY);
            }
            else if (scene == 32)
            {
                ttt_mouse_handle(mouseX, mouseY);
            }
        }
        else if (event.type == SDL_KEYDOWN) // for keyboard input
        {
            if (scene == 1)
            {
                handle_keyboard_scene_1(event);
            }
            else if (scene == 5)
            {
                handle_keyboard_scene_5(event);
            }
        }
        else if (event.type == SDL_CONTROLLERBUTTONDOWN) // for gamepad input
        {
            SDL_ControllerButtonEvent controllerButtonEvent = event.cbutton;
            int button = controllerButtonEvent.button;
            {
                if (scene == 1)
                {
                    handle_gamepad_scene_1(button);
                }
                else if (scene == 5)
                {
                    handle_gamepad_scene_5(button);
                }
            }
        }
    }
}
void update()
{
    // Render FPS if toggled from Settings button, which renders in sdl_texts.hpp
    frameCount++;
    int currentTime = SDL_GetTicks();
    if (currentTime - lastTime >= 1000)
    {
        fps = frameCount;
        frameCount = 0;
        lastTime = currentTime;
    }

    if (scene == 1) // menu
    {
        songTitle = "assets/sounds/music/Time - AlexiAction.mp3";
        load_music(songTitle);
    }
    else if (scene == 2) // settings
    {
    }
    else if (gameWon == true) // Credits (after winning game)
    {
        songTitle = "assets/sounds/music/Out Of Time - AlexiAction.mp3";
        load_music(songTitle);
        scene = 3;
    }
    else if (scene == 4) // achievements
    {
        songTitle = "assets/sounds/music/Out Of Time - AlexiAction.mp3";
        load_music(songTitle);
    }
    else if (scene == 5) // help
    {
    }
    else if (scene == 25) // world map
    {
    }
    else if (scene == 8) // multiplayer
    {
    }
    else if (scene == 9) // leaderboard
    {
    }
    else if (scene == 32)
    {
        ttt_SDL_update();
    }
}
void draw()
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Set the blend mode to enable transparency
    SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255);      // set default background colour to lime green
    SDL_RenderClear(renderer);

    // Rendering text, buttons and backgrounds to screen
    if (scene == 1) // menu
    {
        SDL_RenderCopy(renderer, menuBackgroundTexture, NULL, NULL);
        
        if (savefileExists) {
            draw_does_save_file_exist();
        } else {
            draw_buttons_scene_1();
        }
        draw_text_for_HUD_scene_1();
    }
    else if (scene == 2) // settings
    {
        draw_text_for_HUD_scene_2();
        draw_buttons_scene_2();
    }
    else if (gameWon == true) // credits
    {
        std::cout << "You won the game!" << std::endl;
        draw_buttons_scene_3();
        credits_file_read(); // render txt output of CREDITS.txt to screen
    }
    else if (scene == 4) // achievements
    {
        draw_text_for_HUD_scene_4();
        draw_buttons_scene_4();
    }
    else if (scene == 5) // help
    {
        draw_buttons_scene_5();
        manual_file_read(); // render txt output of MANUAL.txt to screen
    }
    else if (scene == 25) // world map
    {
        SDL_RenderCopy(renderer, worldMapTexture, NULL, NULL);
        draw_text_for_HUD_scene_25();
        draw_buttons_scene_25();
    }
    else if (scene == 8) // tutorial
    {
        draw_text_for_HUD_scene_8();
    }
    else if (scene == 9) // leaderboard
    {
        draw_text_for_HUD_scene_9();
        draw_buttons_scene_9();
    }
    else if (scene == 11) // Profile
    {
        draw_text_for_HUD_scene_11();
        draw_buttons_scene_11();
    }

    else if (scene == 32) // Game Map - Rome - Tic Tac Toe
    {
        ttt_SDL_draw();
    }

    SDL_RenderPresent(renderer);
}

void run_SDL()
{
    while (!quitEventLoop)
    {
        handle_events();
        update();
        draw();
    }
}
void exit_SDL()
{

    std::cout << "STARTING: Destroy Textures." << std::endl;
    // Splash screen
    SDL_DestroyTexture(splashScreenTexture);

    // sdl_loads.hpp load_texture texture
    SDL_DestroyTexture(texture);

    // Scene 1 destroy - Main menu
    SDL_DestroyTexture(menuBackgroundTexture);
    SDL_DestroyTexture(menuNewGameTexture);
    SDL_DestroyTexture(menuLoadGameTexture);
    SDL_DestroyTexture(menuSettingsTexture);
    SDL_DestroyTexture(menuAchievementsTexture);
    SDL_DestroyTexture(menuHelpTexture);
    SDL_DestroyTexture(menuUpdateGameTexture);
    SDL_DestroyTexture(menuQuitTexture);
    SDL_DestroyTexture(AgniSamoohLogoTexture);

    // Scene 2 destroy - Settings options
    SDL_DestroyTexture(settingsTexture);
    SDL_DestroyTexture(settingsResetTexture);
    SDL_DestroyTexture(settingsSaveTexture);
    SDL_DestroyTexture(fontTexture);
    SDL_DestroyTexture(soundOnTexture);
    SDL_DestroyTexture(soundOffTexture);
    SDL_DestroyTexture(languageTexture);
    SDL_DestroyTexture(fpsTexture);
    SDL_DestroyTexture(keyRemapTexture);
    SDL_DestroyTexture(resolution800x600Texture);
    SDL_DestroyTexture(resolution1366x768Texture);
    SDL_DestroyTexture(resolutionFullScreenTexture);
    SDL_DestroyTexture(returnGameTexture);
    SDL_DestroyTexture(returnTitleTexture);

    // Scene 4 destroy - Achievements

    // Secene 5 destroy - Help
    SDL_DestroyTexture(forwardTexture);
    SDL_DestroyTexture(backwardTexture);

    // scene 6 - world map
    SDL_DestroyTexture(worldMapTexture);
    SDL_DestroyTexture(saveTexture);
    SDL_DestroyTexture(beijingTexture);   // scene 20
    SDL_DestroyTexture(berlinTexture);    // scene 23
    SDL_DestroyTexture(delhiTexture);     // scene 24
    SDL_DestroyTexture(hawaiiTexture);    // scene 26
    SDL_DestroyTexture(londonTexture);    // scene 21
    SDL_DestroyTexture(parisTexture);     // scene 22
    SDL_DestroyTexture(seoulTexture);     // scene 28
    SDL_DestroyTexture(shanghaiTexture);  // scne 29
    SDL_DestroyTexture(singaporeTexture); // scene 25
    SDL_DestroyTexture(tokyoTexture);     // scene 27

    SDL_DestroyTexture(romeTexture); // scene 32

    // scene 8 - multiplayer
    SDL_DestroyTexture(joinAvailableGameTexture);
    SDL_DestroyTexture(createAvailableGameTexture);
    SDL_DestroyTexture(inviteFriendToAvailableGameTexture);
    SDL_DestroyTexture(refreshAvailableGamesTexture);
    SDL_DestroyTexture(returnToAvailableGamesTexture);

    // HUD buttons
    SDL_DestroyTexture(helpTexture);
    SDL_DestroyTexture(restartTexture);
    SDL_DestroyTexture(skipTexture);
    SDL_DestroyTexture(heartTexture);
    SDL_DestroyTexture(hearts2Texture);
    SDL_DestroyTexture(hearts3Texture);
    SDL_DestroyTexture(hearts4Texture);
    SDL_DestroyTexture(hearts5Texture);
    SDL_DestroyTexture(hearts10Texture);
    SDL_DestroyTexture(timerTexture);
    SDL_DestroyTexture(frequencyTexture);

    // Popup textures
    SDL_DestroyTexture(humanTexture);
    SDL_DestroyTexture(computerTexture);
    SDL_DestroyTexture(buttonTexture);

    // backgrounds
    SDL_DestroyTexture(tutorialBackgroundTexture);
    SDL_DestroyTexture(beijingDayBackgroundTexture);
    SDL_DestroyTexture(beijingNightBackgroundTexture);
    SDL_DestroyTexture(berlinDayBackgroundTexture);
    SDL_DestroyTexture(berlinNightBackgroundTexture);
    SDL_DestroyTexture(delhiDayBackgroundTexture);
    SDL_DestroyTexture(delhiNightBackgroundTexture);
    SDL_DestroyTexture(hawaiiDayBackgroundTexture);
    SDL_DestroyTexture(hawaiiNightBackgroundTexture);
    SDL_DestroyTexture(londonDayBackgroundTexture);
    SDL_DestroyTexture(londonNightBackgroundTexture);
    SDL_DestroyTexture(parisDayBackgroundTexture);
    SDL_DestroyTexture(parisNightBackgroundTexture);
    SDL_DestroyTexture(seoulDayBackgroundTexture);
    SDL_DestroyTexture(seoulNightBackgroundTexture);
    SDL_DestroyTexture(shanghaiDayBackgroundTexture);
    SDL_DestroyTexture(shanghaiNightBackgroundTexture);
    SDL_DestroyTexture(singaporeDayBackgroundTexture);
    SDL_DestroyTexture(singaporeNightBackgroundTexture);
    SDL_DestroyTexture(tokyoDayBackgroundTexture);
    SDL_DestroyTexture(tokyoNightBackgroundTexture);

    // scenes 30 - 39
    SDL_DestroyTexture(capetownDayBackgroundTexture);      // scene 30
    SDL_DestroyTexture(capetownNightBackgroundTexture);    // scene 30
    SDL_DestroyTexture(riodejaneroDayBackgroundTexture);   // scene 31
    SDL_DestroyTexture(riodejaneroNightBackgroundTexture); // scene 31
    SDL_DestroyTexture(romeDayBackgroundTexture);          // scene 32
    SDL_DestroyTexture(romeNightBackgroundTexture);        // scene 32
    SDL_DestroyTexture(hanoiDayBackgroundTexture);         // scene 33
    SDL_DestroyTexture(hanoiNightBackgroundTexture);       // scene 33
    SDL_DestroyTexture(barcelonaDayBackgroundTexture);     // scene 34
    SDL_DestroyTexture(barcelonaNightBackgroundTexture);   // scene 34
    SDL_DestroyTexture(budapestDayBackgroundTexture);      // scene 35
    SDL_DestroyTexture(budapestNightBackgroundTexture);    // scene 35
    SDL_DestroyTexture(moscowDayBackgroundTexture);        // scene 36
    SDL_DestroyTexture(moscowNightBackgroundTexture);      // scene 36
    SDL_DestroyTexture(athensDayBackgroundTexture);        // scene 37
    SDL_DestroyTexture(athensNightBackgroundTexture);      // scene 37
    SDL_DestroyTexture(manillaDayBackgroundTexture);       // scene 38
    SDL_DestroyTexture(manillaNightBackgroundTexture);     // scene 38
    SDL_DestroyTexture(tehranDayBackgroundTexture);        // scene 39
    SDL_DestroyTexture(tehranNightBackgroundTexture);      // scene 39

    // scenes 40 - 49
    SDL_DestroyTexture(telavivDayBackgroundTexture);      // scene 40
    SDL_DestroyTexture(telavivNightBackgroundTexture);    // scene 40
    SDL_DestroyTexture(cairoDayBackgroundTexture);        // scene 41
    SDL_DestroyTexture(cairoNightBackgroundTexture);      // scene 41
    SDL_DestroyTexture(bogotaDayBackgroundTexture);       // scene 42
    SDL_DestroyTexture(bogotaNightBackgroundTexture);     // scene 42
    SDL_DestroyTexture(istanbulDayBackgroundTexture);     // scene 43
    SDL_DestroyTexture(istanbulNightBackgroundTexture);   // scene 43
    SDL_DestroyTexture(stolkholmDayBackgroundTexture);    // scene 44
    SDL_DestroyTexture(stolkholmNightBackgroundTexture);  // scene 44
    SDL_DestroyTexture(mexicocityDayBackgroundTexture);   // scene 45
    SDL_DestroyTexture(mexicocityNightBackgroundTexture); // scene 45
    SDL_DestroyTexture(bangkokDayBackgroundTexture);      // scene 46
    SDL_DestroyTexture(bangkokNightBackgroundTexture);    // scene 46
    SDL_DestroyTexture(kathmanduDayBackgroundTexture);    // scene 47
    SDL_DestroyTexture(kathmanduNightBackgroundTexture);  // scene 47
    SDL_DestroyTexture(vancouverDayBackgroundTexture);    // scene 48
    SDL_DestroyTexture(vancouverNightBackgroundTexture);  // scene 48
    SDL_DestroyTexture(newyorkDayBackgroundTexture);      // scene 49
    SDL_DestroyTexture(newyorkNightBackgroundTexture);    // scene 49

    // Animations
    SDL_DestroyTexture(fireworksAnimationTexture);
    SDL_FreeSurface(fireworksAnimationSurface);

    // Keyboard remapping texture
    SDL_DestroyTexture(keyboardRealisticTexture);
    SDL_DestroyTexture(keyboardCartoonTexture);
    SDL_DestroyTexture(gameControllerTexture);
    SDL_DestroyTexture(computerMouseTexture);

    // clearing fonts
    SDL_DestroyTexture(textTexture);
    font_24 = nullptr;
    font_36 = nullptr;
    font_48 = nullptr;
    texture = nullptr;

    std::cout << "STARTING: Destroy SDL_Mixer" << std::endl;
    // clear Sound
    Mix_FreeChunk(winRoundSound);
    Mix_FreeChunk(loseRoundSound);
    Mix_FreeChunk(winGameSound);
    Mix_FreeChunk(loseGameSound);
    Mix_FreeChunk(drawGameSound);

    // Stop the music
    Mix_HaltMusic();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();

    std::cout << "STARTING: Destroy controller" << std::endl;
    // Close game controller
    if (controller)
    {
        SDL_GameControllerClose(controller);
    }

    std::cout << "STARTING: Destroy renderer" << std::endl;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    std::cout << "STARTING: Destroy window" << std::endl;
    SDL_DestroyWindow(window);

    std::cout << "STARTING: Destroy Tic Tae Toe" << std::endl;
    // Games
    ttt_SDL_cleanup();

    // Quit SDL subsystems
    std::cout << "STARTING: Quit SDL libraries." << std::endl;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    SDL_GetNumAllocations(); // Included to see if any SDL object hasn't cleared memory allocation.
}
