/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++11
    Purpose: Declaration file (declaration file is: global_variables.hpp)
    License: MIT License
    Description: read the attached help.txt file
*/

#pragma once

#include <chrono> // Core logic - for timer
#include <cstdio>
#include <cstdlib> // Core logic
#include <cmath>
#include <ctime>    // Core logic - for srand
#include <fstream>  // multiplatform method for for file open read write objects
#include <iostream> // Core logic
#include <limits>   // For SDL_Button_class largest number limit to compare button distance or srand()
#include <memory>
#include <sstream>
#include <string>        // Core logic
#include <thread>        // Core logic - for timer
#include <vector>        // Core logic
#include <unordered_map> // For key mapping
#include "../src/SDL2/x86_64-w64-mingw32/include/SDL2/SDL.h"
#include "../src/SDL2_image/x86_64-w64-mingw32/include/SDL2/SDL_image.h"
#include "../src/SDL2_TTF/x86_64-w64-mingw32/include/SDL2/SDL_ttf.h"
#include "../src/SDL2_Mixer/x86_64-w64-mingw32/include/SDL2/SDL_mixer.h"
#include "./headers/custom_SDL_button.hpp"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Splash screen
extern SDL_Texture *splashScreenTexture;

// for Font
extern TTF_Font *font_24;
extern TTF_Font *font_36;
extern TTF_Font *font_48;
extern SDL_Texture *textTexture;
extern SDL_Texture *texture;

// Main Menu buttons
extern SDL_Texture *menuBackgroundTexture;
extern SDL_Texture *menuNewGameTexture;
extern SDL_Texture *menuLoadGameTexture;
extern SDL_Texture *menuSettingsTexture;
extern SDL_Texture *menuAchievementsTexture;
extern SDL_Texture *menuHelpTexture;
extern SDL_Texture *menuUpdateGameTexture;
extern SDL_Texture *menuQuitTexture;
extern SDL_Texture *AgniSamoohLogoTexture;

// Settings buttons
extern SDL_Texture *settingsTexture;
extern SDL_Texture *settingsResetTexture;
extern SDL_Texture *settingsSaveTexture;
extern SDL_Texture *fontTexture;
extern SDL_Texture *soundOnTexture;
extern SDL_Texture *soundOffTexture;
extern SDL_Texture *languageTexture;
extern SDL_Texture *fpsTexture;
extern SDL_Texture *keyRemapTexture;
extern SDL_Texture *resolution800x600Texture;
extern SDL_Texture *resolution1366x768Texture;
extern SDL_Texture *resolutionFullScreenTexture;
extern SDL_Texture *returnGameTexture;
extern SDL_Texture *returnTitleTexture;

// Keyboard remapping texture
extern SDL_Texture *keyboardRealisticTexture;
extern SDL_Texture *keyboardCartoonTexture;
extern SDL_Texture *gameControllerTexture;
extern SDL_Texture *computerMouseTexture;

// Uses return to title button from settings
extern SDL_Texture *forwardTexture;
extern SDL_Texture *backwardTexture;

// Popup textures
extern SDL_Texture *humanTexture;
extern SDL_Texture *computerTexture;
extern SDL_Texture *buttonTexture; // Popup - button texture

// animations
extern SDL_Texture *fireworksAnimationTexture;
extern SDL_Surface *fireworksAnimationSurface;

// for music
extern Mix_Music *music;

// for Sound effects (SFX)
extern Mix_Chunk *winRoundSound;
extern Mix_Chunk *loseRoundSound;
extern Mix_Chunk *winGameSound;
extern Mix_Chunk *loseGameSound;
extern Mix_Chunk *drawGameSound;

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

extern SDL_Texture *romeTexture; // scene 32

// scene 8 - multiplayer
extern SDL_Texture *joinAvailableGameTexture;           // Multiplayer buttons
extern SDL_Texture *createAvailableGameTexture;         // Multiplayer buttons
extern SDL_Texture *inviteFriendToAvailableGameTexture; // Multiplayer buttons
extern SDL_Texture *refreshAvailableGamesTexture;       // Multiplayer buttons
extern SDL_Texture *returnToAvailableGamesTexture;      // Multiplayer buttons

// HUD buttons
extern SDL_Texture *helpTexture;      // In game - view rules from help
extern SDL_Texture *restartTexture;   // In game - swap icons from hands to abstract images
extern SDL_Texture *skipTexture;      // In game - skips Mentor explaining rules
extern SDL_Texture *heartTexture;     // In game - Rounds
extern SDL_Texture *hearts2Texture;   // In game - Rounds
extern SDL_Texture *hearts3Texture;   // In game - Rounds
extern SDL_Texture *hearts4Texture;   // In game - Rounds
extern SDL_Texture *hearts5Texture;   // In game - Rounds
extern SDL_Texture *hearts10Texture;  // In game - Rounds
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

extern SDL_GameController *controller; // gamepad object initialise
extern SDL_Event event;                // event loop object initialise

// Scene 11
extern Custom_SDL_Button scene11submitUsernameButton;
extern Custom_SDL_Button scene11registerButton;
extern Custom_SDL_Button scene11acceptButton;
extern Custom_SDL_Button scene11denyButton;
extern Custom_SDL_Button scene11fontScaleButton;
// Scene 12
extern Custom_SDL_Button scene12submitEmailPasswordButton;
extern Custom_SDL_Button scene12backButton;
// Scene 13
extern Custom_SDL_Button scene13submitLoginButton;
extern Custom_SDL_Button scene13backButton;
// Scene 14
extern Custom_SDL_Button scene14hostGameButton;
extern Custom_SDL_Button scene14joinGameButton;
extern Custom_SDL_Button scene14searchGamesButton;
extern Custom_SDL_Button scene14searchFriendsGamesButton;
extern Custom_SDL_Button scene14refreshButton;
extern Custom_SDL_Button scene14backButton;
// Scene 25
extern Custom_SDL_Button scene25backusernameButton;

// For SDL_Custom_button find_nearest() to find nearest button through kb handle arrow direction keys for GUI navigation
extern std::vector<Custom_SDL_Button *> scene1buttons;
extern std::vector<Custom_SDL_Button *> scene2buttons;
extern std::vector<Custom_SDL_Button *> scene3buttons;
extern std::vector<Custom_SDL_Button *> scene4buttons;
extern std::vector<Custom_SDL_Button *> scene5buttons;
extern std::vector<Custom_SDL_Button *> scene6buttons;
extern std::vector<Custom_SDL_Button *> scene7buttons;
extern std::vector<Custom_SDL_Button *> scene8buttons;
extern std::vector<Custom_SDL_Button *> scene9buttons;
extern std::vector<Custom_SDL_Button *> scene10buttons;
extern std::vector<Custom_SDL_Button *> scene11buttons;
extern std::vector<Custom_SDL_Button *> scene12buttons;
extern std::vector<Custom_SDL_Button *> scene13buttons;
extern std::vector<Custom_SDL_Button *> scene14buttons;
extern std::vector<Custom_SDL_Button *> scene15buttons;
extern std::vector<Custom_SDL_Button *> scene16buttons;
extern std::vector<Custom_SDL_Button *> scene17buttons;
extern std::vector<Custom_SDL_Button *> scene18buttons;
extern std::vector<Custom_SDL_Button *> scene19buttons;
extern std::vector<Custom_SDL_Button *> scene20buttons;
extern std::vector<Custom_SDL_Button *> scene21buttons;
extern std::vector<Custom_SDL_Button *> scene22buttons;
extern std::vector<Custom_SDL_Button *> scene23buttons;
extern std::vector<Custom_SDL_Button *> scene24buttons;
extern std::vector<Custom_SDL_Button *> scene25buttons;
extern std::vector<Custom_SDL_Button *> scene26buttons;
extern std::vector<Custom_SDL_Button *> scene27buttons;
extern std::vector<Custom_SDL_Button *> scene28buttons;
extern std::vector<Custom_SDL_Button *> scene29buttons;
extern std::vector<Custom_SDL_Button *> scene30buttons;

extern std::vector<Custom_SDL_Button *> allButtons;

// GLOBAL VARIABLES
extern bool quitEventLoop;       // for run_SDL Event loop
extern int windowWidth;          // for Window resolution
extern int windowHeight;         // for Window resolution
extern int rectWidth;            // Button - The image width inside button itself
extern int rectHeight;           // Button - The image height inside button itself
extern int buttonWidth;          // Button - The literal button width
extern int buttonHeight;         // Button - The literal button height
extern int buttonXOffset;        // Button - X Offset e.g. (windowWidth / 10) - 10) = ((windowWidth / 10) - buttonXOffset) - higher number box goes left
extern int buttonYOffset;        // Button - Y Offset e.g. (windowWidth / 10) - 15) = ((windowWidth / 10) - buttonXOffset) - higher number box goes up
extern int worldmapRegionWidth;  // World Map scenes button size
extern int worldmapRegionHeight; // World Map scenes button size
extern int textWidth;            // for font
extern int textHeight;           // for font
extern int fontSize;             // for font
extern int scene;                // for scene to display
extern std::string currentVersionTextRender; // for rendering text version on main menu when game starts

// PLAYER VARIABLES
extern std::string username; // Multiplayer - Multiplayer players username
extern std::string email;    // Multiplayer - Multiplayer players email address
extern std::string password; // Multiplayer - Multiplayer players account password

// SETTINGS VARIABLES
extern bool isMusicPlaying;     // for music
extern std::string currentSong; // for music
extern std::string songTitle;   // for music
extern std::string language;    // for changing language
extern std::string osVersion;   // Custom Multiplatform social media link
extern int lastScene;           // Settings - return to last game scene
extern bool isNight;            // for background cosmetics
extern bool fpsRendering;

// GAME UPDATE
extern std::string zipFilePath;
extern std::string currentVersion;

// README MOUSE SCROLL VARIABLES
extern int scrollY;     // Current scroll position
extern int scrollSpeed; // Speed of scrollin

// HUD VARIABLES
extern int frameCount;               // for FPS HUD display toggle
extern int timerFPS, lastFrame, fps; // for FPS HUD display toggle
extern bool fpsCondition;            // for FPS HUD display toggle
extern int lastTime;                 // for FPS HUD display toggle

// HUD - Timer variables
extern bool timerRunning;
extern bool countdownStarted;
extern int countdownSeconds; // Initial countdown time

// GAME VARIABLES
extern bool gameStarted;                      // Toggle to prevent "continuing to game" if game hasn't begun
extern bool gameWon;                          // Game variable - display credits on game completion
extern std::vector<int> unlockedScenes;       // unlocked scenes if in game mode
extern std::vector<int> unlockedAchievements; // unlocked scenes if in game mode
extern int selectedOption;                    // For Keyboard arrow key or Gamepad d-pad selection
extern int menuTotalOptions;                  // For Keyboard arrow key or Gamepad d-pad selection
extern int SettingsTotalOptions;              // For Keyboard arrow key or Gamepad d-pad selection
extern int GameTotalOptions;                  // For Keyboard arrow key or Gamepad d-pad selection

extern std::unordered_map<std::string, SDL_Keycode> keyMap;

/* Function Prototypes */
void render_text(const std::string &text, int x, int y, Uint8 alpha, int customFontSize); // For SDL texts
SDL_Texture *load_texture(const char *path, const char *name); // For SDL loads

// For the handles
void change_resolution(int newWindowWidth, int newWindowHeight);
void is_scene_unlocked(int target);
void new_game();
void exit_SDL();
std::string find_os();
void render_fps();
void start_game_update();

// for SDL_renders
bool is_achievement_unlocked(int target); // For rendering Trophy icon if achievement unlocked