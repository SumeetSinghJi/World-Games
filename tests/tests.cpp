/*
    Author: Sumeet Singh
    Dated: 22/02/2024
    Minimum C++ Standard: C++11
    Purpose: Test adding.cpp file
    License: MIT License
    Description: Read README.md for more details
*/
#include "../headers/global_variables.hpp"     // Declarations for all ../headers, variables and functions
#include "../headers/multiplayer.hpp"          // For Multiplayer logic code
#include "../headers/save_and_continue.hpp"    // For save/continue functions
#include "../headers/sdl_loads.hpp"            // SDL Textures, Sounds, Animations to load
#include "../headers/sdl_renders.hpp"          // SDL Rect/Buttons to render to screen/scene/GUI
#include "../headers/sdl_texts.hpp"            // SDL Text to Render to screen/scene/GUI
#include "../headers/sdl_mouse_handles.hpp"    // SDL Mouse and Touch keypresses
#include "../headers/sdl_keyboard_handles.hpp" // SDL Keyboard keypresses
#include "../headers/sdl_gamepad_handles.hpp"  // SDL Gamepad controller keypresses
#include "../headers/update_app.hpp"           // For downloading and installing latest game update
#include "../headers/tic_tac_toe.hpp"          // Scene 32 - Rome - Tic Tac Toe
#include "../headers/custom_SDL_button.hpp"    // Custom SDL Button class for creating buttons for handles
#include <gtest/gtest.h>

class mainTest : public ::testing::Test { 
    protected: // replicate the main.cpp int main() code
        void SetUp() override {
            /*
            srand(static_cast<unsigned int>(time(0)));
            find_os();
            update_version_string_from_readme_file("../README.md");
            start_SDL();
            play_developer_splash_screen();
            run_SDL();
            */
        }
        void TearDown() override {
            // exit_SDL();
        }
};

// Default Google test working test

TEST_F(mainTest, adds_two_numbers_correctly) {
    int a = 1;
    int b = 2;
    EXPECT_EQ(a + b, 3);
}

// Game logic tests



// Settings options tests

TEST_F(mainTest, core_game_logic_cpp_change_resolution_test) {
    int newWindowWidth = 1200;
    int newWindowHeight = 800;
    int currentWindowWidth = 0;
    int currentWindowHeight = 0;
    change_resolution(newWindowWidth, newWindowHeight);
    SDL_GetWindowSize(window, &currentWindowWidth, &currentWindowHeight);
    EXPECT_EQ(currentWindowWidth, newWindowWidth);
    EXPECT_EQ(currentWindowHeight, newWindowHeight);
}



int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}