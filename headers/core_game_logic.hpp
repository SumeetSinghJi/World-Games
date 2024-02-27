/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Definition file (declaration file is: global_variables.hpp)
License: MIT License
Description: read the attached help.txt file
*/

#pragma once

#include "global_variables.hpp"

// GAME LOGIC

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
void toggle_countdown(bool& subGameSettingsShowPopup, bool& subGameOver, int& subGameWinner)
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
