/*
    Author: Sumeet Singh
    Dated: 26/09/2023
    Minimum C++ Standard: C++11
    Purpose: Implementation file
    License: MIT License
    Description: read the attached MANUAL.txt file
*/

#include "headers/global_variables.hpp"     // Declarations for all headers, variables and functions
#include "headers/multiplayer.hpp"          // For Multiplayer logic code
#include "headers/save_and_continue.hpp"    // For save/continue functions
#include "headers/sdl_loads.hpp"            // SDL Textures, Sounds, Animations to load
#include "headers/sdl_renders.hpp"          // SDL Rect/Buttons to render to screen/scene/GUI
#include "headers/sdl_texts.hpp"            // SDL Text to Render to screen/scene/GUI
#include "headers/sdl_mouse_handles.hpp"    // SDL Mouse and Touch keypresses
#include "headers/sdl_keyboard_handles.hpp" // SDL Keyboard keypresses
#include "headers/sdl_gamepad_handles.hpp"  // SDL Gamepad controller keypresses
#include "headers/update_app.hpp"           // For downloading and installing latest game update
#include "headers/tic_tac_toe.hpp"          // Scene 32 - Rome - Tic Tac Toe
#include "headers/custom_SDL_button.hpp"    // Custom SDL Button class for creating buttons for handles

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0))); // Seed random time function for gameplay randomisation
    find_os(); // Find host OS for OS specific functions
    update_version_string_from_readme_file("README.md"); // populate variable currentVersion in update_app.hpp
    UpdateApp_sourceDirectory = "C:/Users/Sumeet/Documents/World-Games"; // populate variable in update_app.hpp 

    start_SDL(); // Start game

    play_developer_splash_screen(); // Render promotional image of developer before game starts

    run_SDL(); // Run Game
    exit_SDL(); // Quit Game

    return 0;
}