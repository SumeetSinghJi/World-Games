/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++17
    Purpose: Declaration file
    License: MIT License
    Description: read the attached MANUAL.txt file
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
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "custom_SDL_button.hpp"

// For SDL_texts.hpp localisation for use in strings such as render_text(deny_txt)
// A
 extern std::string accept_txt;
 extern std::string achievements_txt;
 extern std::string agnisamooh_txt;

// C
 extern std::string called_out_bluff_txt;
 extern std::string cheated_round_txt;
 extern std::string continue_txt;

// D
 extern std::string deny_txt;

// E
 extern std::string enter_name_txt;
 extern std::string exit_txt;

// F
 extern std::string font_size_txt;
 extern std::string found_hidden_level_txt;
 extern std::string fullscreen_txt;
 extern std::string fps_text;

// H
 extern std::string help_txt;

// K
 extern std::string key_mapping_txt;

// L
 extern std::string language_txt;
 extern std::string leaderboard_txt;
 extern std::string learnt_kitsune_ken_txt;
 extern std::string load_game_txt;
 extern std::string lost_a_game_txt;

// M
 extern std::string main_menu_txt;
 extern std::string multiplayer_lobby_txt;

// N
 extern std::string never_lost_game_txt;

// O
 extern std::string online_multiplayer_txt;

// P
 extern std::string profile_txt;

// R
 extern std::string resolution_txt;
 extern std::string reset_settings_txt;

// S
 extern std::string save_settings_txt;
 extern std::string sentence_overwrite_or_load_game_1_txt;
 extern std::string sentence_overwrite_or_load_game_2_txt;
 extern std::string settings_txt;
 extern std::string sound_txt;
 extern std::string start_game_txt;

// U
 extern std::string update_txt;

// V
 extern std::string version_txt;
 extern std::string visited_han_palace_txt;

// W
 extern std::string won_first_game_txt;
 extern std::string won_game_txt;
 extern std::string won_same_hand_txt;
 extern std::string world_games_txt;
 extern std::string world_map_txt;

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

// Scene 1 - Main Menu buttons
extern SDL_Texture *menuBackgroundTexture;
extern SDL_Texture *menuNewGameTexture;
extern SDL_Texture *menuLoadGameTexture;
extern SDL_Texture *menuSettingsTexture;
extern SDL_Texture *menuAchievementsTexture;
extern SDL_Texture *menuHelpTexture;
extern SDL_Texture *menuUpdateGameTexture;
extern SDL_Texture *menuQuitTexture;
extern SDL_Texture *AgniSamoohLogoTexture;

// Scene 2 - Settings buttons
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

// Scene 4 - Achievements
extern SDL_Texture *achievementsTexture;

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

// Buttoms defined in ./src/core_game_logic.cpp and initialised as global variables
// and member variables populated in load_buttons_xx(), then loaded on game startup during start_SDL()
// Scene 1 - Main menu
extern Custom_SDL_Button scene1LoadGameButton;
extern Custom_SDL_Button scene1newGameButton;
extern Custom_SDL_Button scene1settingsButton;
extern Custom_SDL_Button scene1AchievementsButton;
extern Custom_SDL_Button scene1HelpButton;
extern Custom_SDL_Button scene1multiplayerButton;
extern Custom_SDL_Button scene1QuitButton;
extern Custom_SDL_Button scene1DeveloperLogoLinkButton;
extern Custom_SDL_Button scene1overwriteGameButton;
extern Custom_SDL_Button scene1continueButton;
// scene 2 - settings
extern Custom_SDL_Button fontButton;
extern Custom_SDL_Button soundButton;
extern Custom_SDL_Button languageButton;
extern Custom_SDL_Button fpsButton;

extern Custom_SDL_Button resolution800x600Button;
extern Custom_SDL_Button resolution1366x768Button;
extern Custom_SDL_Button resolutionFullScreenButton;
extern Custom_SDL_Button keyRemapButton;

extern Custom_SDL_Button returnGameButton;
extern Custom_SDL_Button returnTitleButton;
extern Custom_SDL_Button settingsResetButton;
extern Custom_SDL_Button settingsSaveButton;
// scene 3 - credits
extern Custom_SDL_Button scene3returnTitleButton;
// scene 4 - achievements
extern Custom_SDL_Button scene4returnTitleButton;
// scene 5 - help
extern Custom_SDL_Button scene5forwardButton;
extern Custom_SDL_Button scene5backButton;
extern Custom_SDL_Button scene5continueButton;
extern Custom_SDL_Button scene5returnTitleButton;
// scene 6 - leaderboard
extern Custom_SDL_Button scene6returnTitleButton;
// scene 7
extern Custom_SDL_Button scene7returnTitleButton;
// scene 10 - key mapping
extern Custom_SDL_Button scene10acceptButton;
extern Custom_SDL_Button scene10denyButton;
// Scene 11 - online login
extern Custom_SDL_Button scene11submitUsernameButton;
extern Custom_SDL_Button scene11registerButton;
extern Custom_SDL_Button scene11acceptButton;
extern Custom_SDL_Button scene11denyButton;
// Scene 12 - create account
extern Custom_SDL_Button scene12submitEmailPasswordButton;
extern Custom_SDL_Button scene12backButton;
// Scene 13 - multiplayer
extern Custom_SDL_Button scene13hostGameButton;
extern Custom_SDL_Button scene13joinGameButton;
extern Custom_SDL_Button scene13searchGamesButton;
extern Custom_SDL_Button scene13searchFriendsGamesButton;
extern Custom_SDL_Button scene13refreshButton;
extern Custom_SDL_Button scene13backButton;
// Scene 25 - World map
extern Custom_SDL_Button scene25backusernameButton;
extern Custom_SDL_Button scene25helpButton;
extern Custom_SDL_Button scene25settingsButton;
extern Custom_SDL_Button scene25returnTitleButton;

extern Custom_SDL_Button scene25beijingButton;
extern Custom_SDL_Button scene25berlinButton;
extern Custom_SDL_Button scene25delhiButton;
extern Custom_SDL_Button scene25hawaiiButton;
extern Custom_SDL_Button scene25londonButton;

extern Custom_SDL_Button scene25parisButton;
extern Custom_SDL_Button scene25seoulButton;
extern Custom_SDL_Button scene25shanghaiButton;
extern Custom_SDL_Button scene25singaporeButton;
extern Custom_SDL_Button scene25tokyoButton;

extern Custom_SDL_Button scene25romeButton;

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
extern int framerate; /* There are 1000 milliseconds in 1 second. So, if you render 1 frame every 16 milliseconds, you would render approximately 
1000/16 frames per second, which is approximately 62.5 FPS. */ 

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

// GAMES
extern SDL_Texture *xTexture;
extern SDL_Texture *oTexture;

// GAME UPDATE
extern std::string updateApp_currentVersion;

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

// Scene 4 - Achievements
extern bool coutAchievements; // For scene 4 is_achievement_unlocked() to only cout unlocked achievements once to prevent memory leak

// Multiplayer variables
extern std::string playerUsername;
extern std::string playerEmail;
extern std::string playerPassword;
extern bool submitUsername;
extern bool showPrivacyPolicyPopup;
extern bool acceptedPrivacyPolicy;
extern bool acceptedTermsAndConditions;

// sdl_renders.hpp variables
extern bool displaySavefileExistsPopup; // for drawing in scene 1 if you click new game and save game already exists
extern bool overwriteGame; // set in mouse handle if overwrite button, will set to delete existing save game and new game
void draw_does_save_file_exist();

extern std::unordered_map<std::string, SDL_Keycode> keyMap;

/* Function Prototypes */
void render_text(const std::string &text, int x, int y, Uint8 alpha, int customFontSize); // For SDL texts
SDL_Texture *load_texture(const char *path, const char *name); // For SDL loads

// for each individual game win logic,cout the unlocked achievements for debugging the achievement was unlocked
// and for SDL_renders
void show_unlocked_achievements();
void unlocked_achievement(int i);

// For the handles
void change_resolution(int newWindowWidth, int newWindowHeight);
void is_scene_unlocked(int target);
void new_game();
void exit_SDL();
std::string find_os();
void render_fps();
void start_application_update(std::string urlPath, std::string downloadLink);

// for SDL_renders
bool is_achievement_unlocked(int target); // For rendering Trophy icon if achievement unlocked
void privacy_policy_file_read(); // for privacy policy popup in scene 11
void terms_and_conditions_file_read(); // for Terms and conditions policy popup in scene 11

// for main.cpp
std::string find_os();
std::string update_version_string_from_readme_file(std::string fileWithVersionString);
void start_SDL();
void play_developer_splash_screen();
void run_SDL();
void exit_SDL();

// for core_game_logic.cpp - start_sdl()
void load_fonts(); // Load fonts here
void load_textures();
void ttt_load_textures();
void load_animations();
void load_music(std::string songTitle);
void load_sound();
void load_controller();

// for core_game_logic.cpp - run_sdl()
void handle_gamepad_scene_1(int button);
void handle_gamepad_scene_5(int button);

void handle_keyboard_scene_1(SDL_Event event);
void handle_keyboard_scene_5(SDL_Event event);

void handle_click_scene_1(int mouseX, int mouseY);
void handle_click_scene_2(int mouseX, int mouseY);
void handle_click_scene_3(int mouseX, int mouseY);
void handle_click_scene_4(int mouseX, int mouseY);
void handle_click_scene_5(int mouseX, int mouseY);
void handle_click_scene_25(int mouseX, int mouseY);
void handle_click_scene_8(int mouseX, int mouseY);
void handle_click_scene_9(int mouseX, int mouseY);
void handle_click_scene_10(int mouseX, int mouseY);

void draw_buttons_scene_1();
void draw_buttons_scene_2();
void draw_buttons_scene_3();
void draw_buttons_scene_4();
void draw_buttons_scene_5();
void draw_buttons_scene_25();
void draw_buttons_scene_8();
void draw_buttons_scene_9();
void draw_buttons_scene_10();
void draw_buttons_scene_11();

void draw_text_for_HUD_scene_1();
void draw_text_for_HUD_scene_2();
void draw_text_for_HUD_scene_4();
void draw_text_for_HUD_scene_25();
void draw_text_for_HUD_scene_8();
void draw_text_for_HUD_scene_9();
void draw_text_for_HUD_scene_11();

void ttt_mouse_handle(int mouseX, int mouseY);
void ttt_SDL_update();
void ttt_SDL_draw();
void ttt_SDL_cleanup();

// from render_text
void localisation(const std::string& language);
