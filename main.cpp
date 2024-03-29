/*
    Author: Sumeet Singh
    Dated: 26/09/2023
    Minimum C++ Standard: C++17
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

#include "headers/games/tic_tac_toe.hpp"      // scene 30 - Tutorial - Tic Tac Toe
#include "headers/games/go.hpp"               // scene 31 - beijing - Go
#include "headers/games/fidhchell.hpp"        // scene 32 = london (Celtic)- Fidhchell
#include "headers/games/mancala.hpp"          // scene 33 = Ethiopia (Yeha) - Mancala
#include "headers/games/senet.hpp"            // scene 34 = Cairo - Senet
#include "headers/games/pachisi.hpp"          // scene 35 = Delhi (Aryavarta) - Pachisi
#include "headers/games/backgammon.hpp"       // scene 36 = Tehran (Persia) - Backgammon
#include "headers/games/patolli.hpp"          // scene 37 = Mexico - Patolli
#include "headers/games/royal_game_of_ur.hpp" // scene 38 = Baghdad (Babylonian) - Royal game of Ur
#include "headers/games/petteia.hpp"          // scene 39 = Greece - Petteia
#include "headers/games/terni_lapilli.hpp"    // scene 40 - Rome - terni lapilli

#include "headers/custom_SDL_button.hpp" // Custom SDL Button class for creating buttons for handles

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));           // Seed random time function for gameplay randomisation
    osVersion = find_os();                               // Find host OS for OS specific functions
    update_version_string_from_readme_file("README.md"); // populate variable currentVersion in update_app.hpp

    create_save_file_if_doesnt_exist(); // If game downloaded with no existing save file this function will create
    load_settings();                    // load settings will call create_save_file_if_missing();

    start_SDL(); // Start game

    play_developer_splash_screen(); // Render promotional image of developer before game starts

    run_SDL();   // Run Game
    save_game(); // Save after quit called in run_SDL() event loop
    exit_SDL();  // Quit Game

    return 0;
}