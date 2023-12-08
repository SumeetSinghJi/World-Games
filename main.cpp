/*
    Name: Shoushiling 手勢令 | World Hand Games | World Hand Sports
    Purpose: main.cpp
    Author: Sumeet Singh
    Website: www.sumeet-singh.com
    Created: 26th September 2023
    Version: 0.1
    Description: Players travel the world playing different traditional hand games.
    License: Main source code is open source excluding the third party libraries which have their own licensing.
    Game and Programming logic: Read in help_scene.h file or view in game help menu.
    Location: https://github.com/SumeetSinghJi/Shoushiling
*/

#include <iostream>                       // Core logic
#include <cstdlib>                        // Core logic
#include <ctime>                          // Core logic - for srand and time for Chrono
#include <vector>                         // Core logic - for variables unlockedscenes/achievements
#include <string>                         // Core logic
#include <fstream>                        // multiplatform method for for file open read write objects
#include <SDL.h>                          // SDL Requirement
#include <SDL_image.h>                    // SDL Requirement
#include <SDL_ttf.h>                      // SDL Requirement
#include <SDL_mixer.h>                    // SDL Requirement
#include "headers/multiplayer.h"          // FUTURE DEVELOPMENT - For Multiplayer
#include "headers/savegame.h"             // For save/continue functions
#include "headers/sdl_loads.h"            // SDL Textures, Sounds, Animations to load
#include "headers/sdl_renders.h"          // SDL Rect/Buttons to render to screen/scene/GUI
#include "headers/sdl_texts.h"            // SDL Text to Render  to screen/scene/GUI
#include "headers/sdl_mouse_handles.h"    // SDL Mouse and Touch keypresses
#include "headers/sdl_keyboard_handles.h" // SDL Keyboard keypresses
#include "headers/sdl_gamepad_handles.h"  // SDL Gamepad controller keypresses
#include "headers/game_update_1.h"        // For downloading latest game update
#include "headers/game_update_2.h"        // For downloading latest game update
#include "headers/tic_tac_toe.h"          // Scene 32 - Rome - Tic Tac Toe

/*
    TO DO

*/

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
SDL_Texture *fontTexture = nullptr;
SDL_Texture *soundOnTexture = nullptr;
SDL_Texture *soundOffTexture = nullptr;
SDL_Texture *languageTexture = nullptr;
SDL_Texture *fpsTexture = nullptr;
SDL_Texture *resolution800x600Texture = nullptr;
SDL_Texture *resolution1366x768Texture = nullptr;
SDL_Texture *resolutionFullScreenTexture = nullptr;
SDL_Texture *returnGameTexture = nullptr;
SDL_Texture *returnTitleTexture = nullptr;

// Uses return to title button from settings
SDL_Texture *forwardTexture = nullptr;
SDL_Texture *backwardTexture = nullptr;

// animations
SDL_Texture *fireworksAnimationTexture = nullptr;
SDL_Surface *fireworksAnimationSurface = nullptr;

// for music
Mix_Music *music = nullptr;

// for Sound effects (SFX)
// In Game
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

SDL_Texture *romeTexture = nullptr;     // scene 32

// scene 8 - multiplayer
SDL_Texture *joinAvailableGameTexture = nullptr;           // Multiplayer buttons
SDL_Texture *createAvailableGameTexture = nullptr;         // Multiplayer buttons
SDL_Texture *inviteFriendToAvailableGameTexture = nullptr; // Multiplayer buttons
SDL_Texture *refreshAvailableGamesTexture = nullptr;       // Multiplayer buttons
SDL_Texture *returnToAvailableGamesTexture = nullptr;      // Multiplayer buttons

// HUD buttons
SDL_Texture *helpTexture = nullptr;      // In game - view rules from help
SDL_Texture *restartTexture = nullptr;      // In game - swap icons from hands to abstract images
SDL_Texture *skipTexture = nullptr;      // In game - skips Mentor explaining rules
SDL_Texture *heartTexture = nullptr;     // In game - lives
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

// GLOBAL VARIABLES
bool quit_event_loop = NULL;    // for run_SDL Event loop
int windowWidth = 1366;         // for Window resolution
int windowHeight = 768;         // for Window resolution
int rectWidth = 50;             // default button Rect width/height
int rectHeight = 50;            // default button width/height
int menulogoWidth = 330;        // Main menu Developer logo button size
int menulogoHeight = 130;       // Main menu Developer logo button size
int handWidth = 150;            // Rock paper scissors button size
int handHeight = 150;           // Rock paper scissors button size
int worldmapRegionWidth = 100;  // World Map scenes button size
int worldmapRegionHeight = 100; // World Map scenes button size
int avatarInGameWidth = 300;    // World Map scenes button size
int avatarInGameHeight = 300;   // World Map scenes button size
int textWidth = 0;              // for font
int textHeight = 0;             // for font
int fontSize = 36;              // for font
int scene = 1;                  // for scene to display

// SETTINGS VARIABLES
bool isMusicPlaying = NULL;                                           // for music
std::string currentSong = "";                                         // for music
std::string songTitle = "assets/sounds/music/Time - AlexiAction.mp3"; // for music
std::string language = "English";                                     // for changing language
std::string os_version = "";                                          // Custom Multiplatform social media link
int lastScene = 1;                                                    // Settings - return to last game scene
bool isNight = NULL;                                                  // for background cosmetics

// README SCROLL VARIABLES
int scrollY = 0;      // Current scroll position
int scrollSpeed = 20; // Speed of scrollin

// HUD VARIABLES
int frameCount = 0;            // for FPS HUD display toggle
int timerFPS, lastFrame, fps;  // for FPS HUD display toggle
bool fps_condition = NULL;     // for FPS HUD display toggle
int lastTime = SDL_GetTicks(); // for FPS HUD display toggle

// GAME VARIABLES
bool game_started = NULL;                     // Toggle to prevent "continuing to game" if game hasn't begun
bool game_won = NULL;                         // Game variable - display credits on game completion
std::vector<int> unlockedScenes(30, 0);       // unlocked scenes if in game mode
std::vector<int> unlockedAchievements(10, 0); // unlocked scenes if in game mode
int selectedOption = 0;                       // For Keyboard arrow key or Gamepad d-pad selection
int menuTotalOptions = 7;                     // For Keyboard arrow key or Gamepad d-pad selection
int SettingsTotalOptions = 10;                // For Keyboard arrow key or Gamepad d-pad selection
int GameTotalOptions = 10;                    // For Keyboard arrow key or Gamepad d-pad selection

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
        render_text("You already defeated the grandmaster", (windowWidth * 0.3), (windowHeight * 0.8));
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
    if (!fps_condition)
    {
        fps_condition = true;
    }
    else
    {
        fps_condition = false;
    }
}

// MAIN MENU & SETTINGS FUNCTIONS
void change_resolution(int newWindowWidth, int newWindowHeight)
{
    // Update the window size
    windowWidth = newWindowWidth;
    windowHeight = newWindowHeight;

    if (windowWidth == 800)
    {
        rectWidth = 50;
        rectHeight = 50;
        menulogoWidth = 200;
        menulogoHeight = 100;
        worldmapRegionWidth = 50;
        worldmapRegionHeight = 50;
        avatarInGameWidth = 150;
        avatarInGameHeight = 150;
        handWidth = 100;
        handHeight = 100;
    }
    else if (windowWidth == 1366)
    {
        rectWidth = 50;
        rectHeight = 50;
        menulogoWidth = 330;
        menulogoHeight = 130;
        worldmapRegionWidth = 100;
        worldmapRegionHeight = 100;
        avatarInGameWidth = 300;
        avatarInGameHeight = 300;
        handWidth = 200;
        handHeight = 200;
    }
    else if (windowWidth == 1920)
    {
        rectWidth = 150;
        rectHeight = 150;
        menulogoWidth = 400;
        menulogoHeight = 200;
        worldmapRegionWidth = 150;
        worldmapRegionHeight = 150;
        avatarInGameWidth = 600;
        avatarInGameHeight = 600;
        handWidth = 300;
        handHeight = 300;
    }
}
void new_game()
{
    game_started = true; // This is flagged as on, so that in Settings screen you can "Continue" to game, if started else not.
    game_won = NULL;
    unlockedScenes.clear();
    unlockedAchievements.clear();
    scene = 6;
}
std::string find_os()
{
    const char *char_osVersion = SDL_GetPlatform();
    os_version = char_osVersion;
    if (char_osVersion != NULL)
    {
        std::cout << "Host operating system: " << char_osVersion << std::endl;
    }
    else
    {
        std::cerr << "Failed to detect the host operating system." << std::endl;
    }
    return os_version;
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
void play_developer_splash_screen() {
    // Display the splash screen for 2 seconds
    SDL_RenderCopy(renderer, splashScreenTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}

// SDL CODE FUNCTIONS
void start_SDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error: Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        std::cerr << "Error: Failed to initialize SDL Font: " << TTF_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::cerr << "Error: Failed to initialize SDL IMG: " << IMG_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
    {
        std::cerr << "Error: Failed to initialize Audio: " << Mix_GetError() << std::endl;
        SDL_Quit();
        exit(1);
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
    tic_tac_toe_load_textures();
    load_animations();
    std::string currentSong = "";
    std::string songTitle = "assets/sounds/music/Time - AlexiAction.mp3";
    load_music(songTitle);
    load_sound();
    load_controller();
}
void handle_events()
{
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            save_game();
            std::cout << "Game Quiting. Goodbye" << std::endl;
            quit_event_loop = true;
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
            else if (scene == 6)
            {
                handle_click_scene_6(mouseX, mouseY);
            }
            else if (scene == 32)
            {
                tic_tac_toe_mouse_handle(mouseX, mouseY);
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
    // Render FPS if toggled from Settings button, which renders in sdl_texts.h
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
    else if (game_won == true) // Credits (after winning game)
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
    else if (scene == 6) // world map
    {
    }
    else if (scene == 8) // multiplayer
    {
    }
    else if (scene == 9) // leaderboard
    {
    }
    else if (scene == 32) {
        tic_tac_toe_SDL_update();
    }

}
void draw()
{
    /*
    While game is running 3 functions are called
    handle_events() - Deals with listening for key press then call header for keyboard/mouse/gamepad input
    update() - Calls logic depending on scene e.g. if scene x, play song x
    draw() - Calls headers for rendering buttons and rendering text
    */
    SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255); // set default background colour to lime green
    SDL_RenderClear(renderer);

    // Rendering text, buttons and backgrounds to screen
    if (scene == 1) // menu
    {
        SDL_RenderCopy(renderer, menuBackgroundTexture, NULL, NULL);
        text_for_HUD_scene_1();
        render_buttons_scene_1();
    }
    else if (scene == 2) // settings
    {
        text_for_HUD_scene_2();
        render_buttons_scene_2();
    }
    else if (game_won == true) // credits
    {
        std::cout << "You won the game!" << std::endl;
        text_for_HUD_scene_3();
        render_buttons_scene_3();
        credits_file_read(); // render txt output of credits.txt to screen
    }
    else if (scene == 4) // achievements
    {
        text_for_HUD_scene_4();
        render_buttons_scene_4();
    }
    else if (scene == 5) // help
    {
        text_for_HUD_scene_5();
        render_buttons_scene_5();
        help_guide_file_read(); // render txt output of help.txt to screen
    }
    else if (scene == 6) // world map
    {
        SDL_RenderCopy(renderer, worldMapTexture, NULL, NULL);
        text_for_HUD_scene_6();
        render_buttons_scene_6();
    }
    else if (scene == 8) // tutorial
    {
        text_for_HUD_scene_8();
        render_buttons_scene_8();
    }
    else if (scene == 9) // leaderboard
    {
        text_for_HUD_scene_9();
        render_buttons_scene_9();
    }
    else if (scene == 32) {
        tic_tac_toe_SDL_draw();
    }

    SDL_RenderPresent(renderer);
}
void run_SDL()
{
    while (!quit_event_loop)
    {
        handle_events();
        update();
        draw();
    }
}
void exit_SDL()
{
    // Splash screen
    SDL_DestroyTexture(splashScreenTexture);

    // sdl_loads.h load_texture texture
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
    SDL_DestroyTexture(fontTexture);
    SDL_DestroyTexture(soundOnTexture);
    SDL_DestroyTexture(soundOffTexture);
    SDL_DestroyTexture(languageTexture);
    SDL_DestroyTexture(fpsTexture);
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

    SDL_DestroyTexture(romeTexture);     // scene 32

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
    SDL_DestroyTexture(timerTexture);
    SDL_DestroyTexture(frequencyTexture);

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

    // clearing fonts
    SDL_DestroyTexture(textTexture);

    // Stop the music
    Mix_HaltMusic();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();

    // clear Sound
    Mix_FreeChunk(winRoundSound);
    Mix_FreeChunk(loseRoundSound);
    Mix_FreeChunk(winGameSound);
    Mix_FreeChunk(loseGameSound);
    Mix_FreeChunk(drawGameSound);

    // Close game controller
    if (controller)
    {
        SDL_GameControllerClose(controller);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Games
    tic_tac_toe_cleanup();

    // Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    find_os();

    start_SDL();

    play_developer_splash_screen();

    run_SDL();
    exit_SDL();

    return 0;
}