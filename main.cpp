/*
    Author: Sumeet Singh
    Dated: 26/09/2023
    Minimum C++ Standard: C++11
    Purpose: Implementation file
    License: MIT License
    Description: read the attached help.txt file
*/

#include <iostream>                         // Core logic
#include <cstdlib>                          // Core logic
#include <ctime>                            // Core logic - for srand
#include <vector>                           // Core logic
#include <string>                           // Core logic
#include <thread>                           // Core logic - for timer
#include <chrono>                           // Core logic - for timer
#include <fstream>                          // multiplatform method for for file open read write objects
#include <unordered_map>                    // For key mapping
#include <SDL.h>                            // SDL 2 library
#include <SDL_ttf.h>                        // SDL 2 Font library for rendering text
#include <SDL_image.h>                      // SDL 2 Image library for loading complex images
#include <SDL_mixer.h>                      // SDL 2 Mixer for audio integration
#include "headers/multiplayer.hpp"          // For Multiplayer
#include "headers/save_game.hpp"            // For save/continue functions
#include "headers/sdl_loads.hpp"            // SDL Textures, Sounds, Animations to load
#include "headers/sdl_renders.hpp"          // SDL Rect/Buttons to render to screen/scene/GUI
#include "headers/sdl_texts.hpp"            // SDL Text to Render to screen/scene/GUI
#include "headers/sdl_mouse_handles.hpp"    // SDL Mouse and Touch keypresses
#include "headers/sdl_keyboard_handles.hpp" // SDL Keyboard keypresses
#include "headers/sdl_gamepad_handles.hpp"  // SDL Gamepad controller keypresses
#include "headers/download_game.hpp"        // For downloading latest game update
#include "headers/Install_game.hpp"         // For Installing game from zip
#include "headers/tic_tac_toe.hpp"          // Scene 32 - Rome - Tic Tac Toe
#include "headers/custom_SDL_button.hpp"    // Custom SDL Button class for creating buttons for handles

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

// Global variables automatically destroyed at end of main() no need to manual destroy
// Scene 11
Custom_SDL_Button scene11submitUsernameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11registerButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11acceptButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11denyButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11fontScaleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 12
Custom_SDL_Button scene12submitEmailPasswordButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene12backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 13
Custom_SDL_Button scene13submitLoginButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene13backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 14
Custom_SDL_Button scene14hostGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14joinGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14searchGamesButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14searchFriendsGamesButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14refreshButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 25
Custom_SDL_Button scene25backusernameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

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

// GAME UPDATE
std::string zipFilePath;
std::string currentVersion;

// README MOUSE SCROLL VARIABLES
int scrollY = 0;      // Current scroll position
int scrollSpeed = 20; // Speed of scrollin

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

// GAME LOGIC
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
    scene = 25;
}
std::string find_os()
{
    const char *char_osVersion = SDL_GetPlatform();
    osVersion = char_osVersion;
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
void help_guide_file_read()
{
    std::cout << "Reading contents from: help.txt" << std::endl;

    // Read contents from the help.txt  file
    std::ifstream sentence_file("help.txt");
    if (!sentence_file.is_open())
    {
        std::cerr << "Error: Failed to open help.txt" << std::endl;
        return;
    }
    std::string sentence_line;
    std::string sentence_content;
    while (std::getline(sentence_file, sentence_line))
    {
        sentence_content += sentence_line + "\n";
    }
    sentence_file.close();

    TTF_Font *font = nullptr;
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

    SDL_Color sentence_textColor = {0, 0, 0}; // Black colour

    // Wrap length for each section
    int wrapLength = windowWidth / 2 + 300;

    // Calculate number of sections based on text length and wrap length
    int numSections = sentence_content.length() / wrapLength + 1;

    // Height of each section
    int sectionHeight = textHeight / numSections;

    int startY = 0; // this is same as y position in x, y for rendering buttons/text anything.

    for (int i = 0; i < numSections; ++i)
    {
        // Get a substring for each section
        std::string section = sentence_content.substr(i * wrapLength, wrapLength);

        // Render text to a surface
        SDL_Surface *sentence_textSurface = TTF_RenderText_Blended_Wrapped(font, section.c_str(), sentence_textColor, wrapLength);
        if (sentence_textSurface == nullptr)
        {
            std::cerr << "TTF_RenderText Error: " << TTF_GetError() << std::endl;
            return;
        }

        // Calculate textWidth and textHeight using TTF_SizeText
        int textWidth = sentence_textSurface->w;
        int textHeight = sentence_textSurface->h;

        // Create a texture from the surface
        SDL_Texture *sentence_textTexture = SDL_CreateTextureFromSurface(renderer, sentence_textSurface);
        SDL_FreeSurface(sentence_textSurface);

        if (sentence_textTexture)
        {
            SDL_Rect sentence_textRect = {50, startY, textWidth, textHeight}; // Define the area to render text
            SDL_RenderCopy(renderer, sentence_textTexture, nullptr, &sentence_textRect);
            SDL_DestroyTexture(sentence_textTexture);
        }
        else
        {
            std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
            return;
        }

        // Update the startY coordinate for the next section
        startY += textHeight;
    }
}
void credits_file_read()
{
    std::cout << "Reading contents from: credits.txt" << std::endl;

    // Read contents from the Help Guide file
    std::ifstream sentence_file("credits.txt");
    if (!sentence_file.is_open())
    {
        std::cerr << "Error: Failed to open credits.txt" << std::endl;
        return;
    }
    std::string sentence_line;
    std::string sentence_content;
    while (std::getline(sentence_file, sentence_line))
    {
        sentence_content += sentence_line + "\n";
    }
    sentence_file.close();

    TTF_Font *font = nullptr;
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

    SDL_Color sentence_textColor = {0, 0, 0}; // Black colour

    // Wrap length for each section
    int wrapLength = windowWidth / 2 + 300;

    // Calculate number of sections based on text length and wrap length
    int numSections = sentence_content.length() / wrapLength + 1;

    // Height of each section
    int sectionHeight = textHeight / numSections;

    int startY = 0; // this is same as y position in x, y for rendering buttons/text anything.

    for (int i = 0; i < numSections; ++i)
    {
        // Get a substring for each section
        std::string section = sentence_content.substr(i * wrapLength, wrapLength);

        // Render text to a surface
        SDL_Surface *sentence_textSurface = TTF_RenderText_Blended_Wrapped(font, section.c_str(), sentence_textColor, wrapLength);
        if (sentence_textSurface == nullptr)
        {
            std::cerr << "TTF_RenderText Error: " << TTF_GetError() << std::endl;
            return;
        }

        // Calculate textWidth and textHeight using TTF_SizeText
        int textWidth = sentence_textSurface->w;
        int textHeight = sentence_textSurface->h;

        // Create a texture from the surface
        SDL_Texture *sentence_textTexture = SDL_CreateTextureFromSurface(renderer, sentence_textSurface);
        SDL_FreeSurface(sentence_textSurface);

        if (sentence_textTexture)
        {
            SDL_Rect sentence_textRect = {50, startY, textWidth, textHeight}; // Define the area to render text
            SDL_RenderCopy(renderer, sentence_textTexture, nullptr, &sentence_textRect);
            SDL_DestroyTexture(sentence_textTexture);
        }
        else
        {
            std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
            return;
        }

        // Update the startY coordinate for the next section
        startY += textHeight;
    }
}
void start_game_update()
{
    // Functions from header download_game.hpp
        // called in main() -> update_version_string_from_readme_file();
    save_path_for_zip();
    start_curl();
        // called in start_curl -> download_file();

    if (!remoteVersionDouble <= currentVersionDouble)
    {
        // Functions from header install_game.hpp
        extract_zip();
        copy_save_to_extracted_folder();
        exit_game();
        delete_original_game_directory_subdirectories();
        rename_extracted_folder();
        CMAKE_build();
        game_start();
    }
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

// main.cpp HUD Functions
void toggle_countdown()
{
    // toggle_countdown() started whenever the popup for game start variable is closed
    if (!countdownStarted)
    {
        countdownStarted = true;
        std::thread countdownThread([]()
                                    {
            timerRunning = true;
            for (; countdownSeconds > 0 && timerRunning; --countdownSeconds) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            timerRunning = false;
            if (countdownSeconds <= 0) {
                if(!ttt_showPopup) {
                    ttt_game_over = true;
                    ttt_winner = 3; // draw
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

// MOVE TO LOADS
void load_buttons_to_scene_vectors()
{
    scene11buttons.push_back(&scene11submitUsernameButton);
    scene11buttons.push_back(&scene11registerButton);
    scene11buttons.push_back(&scene11acceptButton);
    scene11buttons.push_back(&scene11denyButton);
    scene11buttons.push_back(&scene11fontScaleButton);

    scene12buttons.push_back(&scene12submitEmailPasswordButton);
    scene12buttons.push_back(&scene12backButton);

    scene13buttons.push_back(&scene13submitLoginButton);
    scene13buttons.push_back(&scene13backButton);

    scene14buttons.push_back(&scene14hostGameButton);
    scene14buttons.push_back(&scene14joinGameButton);
    scene14buttons.push_back(&scene14searchGamesButton);
    scene14buttons.push_back(&scene14searchFriendsGamesButton);
    scene14buttons.push_back(&scene14refreshButton);
    scene14buttons.push_back(&scene14backButton);

    scene25buttons.push_back(&scene25backusernameButton);
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
    scene11fontScaleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                               static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                               "CHANGE FONT", 144, 238, 144, 255, "", false); // RGB: Light green
}
void load_buttons_12()
{
    scene12submitEmailPasswordButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                         static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                         "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene12backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene12backButton.set_button_texture(renderer);
}
void load_buttons_13()
{
    scene13submitLoginButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                 static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                 "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene13backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene13backButton.set_button_texture(renderer);
}
void load_buttons_14()
{
    scene14hostGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene14joinGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene14searchGamesButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                 static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                 "SUBMIT", 144, 238, 144, 255, "assets/graphics/buttons/settings/zoom-button.png", false); // RGB: Light green
    scene14searchFriendsGamesButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                        static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                        "SUBMIT", 144, 238, 144, 255, "assets/graphics/buttons/settings/zoom-button.png", false); // RGB: Light green
    scene14refreshButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                             static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                             "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/refresh-button.png", false); // RGB: Light green
    scene14backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene14backButton.set_button_texture(renderer);
}
void load_buttons_25()
{
    scene25backusernameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                                  static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                                  "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene25backusernameButton.set_button_texture(renderer);
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
    load_buttons_11();
    load_buttons_12();
    load_buttons_13();
    load_buttons_14();
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
        draw_text_for_HUD_scene_1();
        draw_buttons_scene_1();
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
        credits_file_read(); // render txt output of credits.txt to screen
    }
    else if (scene == 4) // achievements
    {
        draw_text_for_HUD_scene_4();
        draw_buttons_scene_4();
    }
    else if (scene == 5) // help
    {
        draw_buttons_scene_5();
        help_guide_file_read(); // render txt output of help.txt to screen
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
        draw_buttons_scene_8();
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
    // Clear each scene button vector
    std::cout << "STARTING: Clear Button Vectors." << std::endl;
    scene1buttons.clear();
    scene2buttons.clear();
    scene3buttons.clear();
    scene4buttons.clear();
    scene5buttons.clear();
    scene6buttons.clear();
    scene7buttons.clear();
    scene8buttons.clear();
    scene9buttons.clear();
    scene10buttons.clear();
    scene11buttons.clear();
    scene12buttons.clear();
    scene13buttons.clear();
    scene14buttons.clear();
    scene15buttons.clear();
    scene16buttons.clear();
    scene17buttons.clear();
    scene18buttons.clear();
    scene19buttons.clear();
    scene20buttons.clear();
    scene21buttons.clear();
    scene22buttons.clear();
    scene23buttons.clear();
    scene24buttons.clear();
    scene25buttons.clear();
    scene26buttons.clear();
    scene27buttons.clear();
    scene28buttons.clear();
    scene29buttons.clear();
    scene30buttons.clear();

    // Clear the allButtons vector
    allButtons.clear();

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
}

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    find_os();
    update_version_string_from_readme_file();

    start_SDL();

    play_developer_splash_screen();

    run_SDL();
    exit_SDL();
    SDL_GetNumAllocations();

    return 0;
}