/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached help.txt file
*/

#pragma once

#include "global_variables.hpp"

// A
std::string accept_txt;
std::string achievements_txt;
std::string agnisamooh_txt;

// C
std::string called_out_bluff_txt;
std::string cheated_round_txt;
std::string continue_txt;

// D
std::string deny_txt;

// E
std::string enter_name_txt;
std::string exit_txt;

// F
std::string font_size_txt;
std::string found_hidden_level_txt;
std::string fullscreen_txt;
std::string fps_text;

// H
std::string help_txt;

// K
std::string key_mapping_txt;

// L
std::string language_txt;
std::string leaderboard_txt;
std::string learnt_kitsune_ken_txt;
std::string lost_a_game_txt;

// M
std::string main_menu_txt;
std::string multiplayer_lobby_txt;

// N
std::string never_lost_game_txt;

// O
std::string online_multiplayer_txt;

// P
std::string profile_txt;

// R
std::string resolution_txt;
std::string reset_settings_txt;

// S
std::string save_settings_txt;
std::string settings_txt;
std::string sound_txt;
std::string start_game_txt;

// U
std::string update_txt;

// V
std::string version_txt;
std::string visited_han_palace_txt;

// W
std::string won_first_game_txt;
std::string won_game_txt;
std::string won_same_hand_txt;
std::string world_games_txt;
std::string world_map_txt;

void localisation(const std::string &language)
{
    if (language == "English")
    {
        // A
        accept_txt = "ACCEPT";
        achievements_txt = "Achievements";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. Called out a bluff";
        cheated_round_txt = "5. Cheated a round";
        continue_txt = "Continue";
        // E
        enter_name_txt = "Enter your name:";
        exit_txt = "Exit";
        // F
        font_size_txt = "Font size";
        found_hidden_level_txt = "9. Found the hidden level";
        fps_text = "FPS";
        fullscreen_txt = "Fullscreen";
        // H
        help_txt = "Help";
        // L
        language_txt = "Language";
        leaderboard_txt = "Leaderboard";
        lost_a_game_txt = "2. Lost a game";
        learnt_kitsune_ken_txt = "6. Learnt secret of kitsune-ken";
        // M
        main_menu_txt = "Main Menu";
        multiplayer_lobby_txt = "Multiplayer lobby";
        // N
        never_lost_game_txt = "10. Never lost a game!";
        // O
        online_multiplayer_txt = "Online Multiplayer";
        // R
        reset_settings_txt = "Reset Settings";
        resolution_txt = "Resolution";
        // S
        save_settings_txt = "Save Settings";
        settings_txt = "Settings";
        sound_txt = "Sound";
        start_game_txt = "Start game";
        // V
        version_txt = "version: ";
        // W
        world_games_txt = "World Games";
        won_first_game_txt = "1. Won first game";
        won_same_hand_txt = "3. Won with same hand";
        won_game_txt = "8. Won the game";
        visited_han_palace_txt = "7. Visited the Han Palace";
        world_map_txt = "World map";
    }
    else if (language == "日本語")
    {
        // A
        accept_txt = "受け入れる";
        achievements_txt = "業績";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. ブラフを発動した";
        cheated_round_txt = "5. ラウンドで不正行為をした";
        continue_txt = "続く";
        // E
        enter_name_txt = "あなたの名前を入力してください";
        exit_txt = "出口";
        // F
        font_size_txt = "字体大小";
        found_hidden_level_txt = "9. 隠しレベルを発見";
        fullscreen_txt = "全画面表示";
        // H
        help_txt = "助け";
        // L
        language_txt = "言語";
        leaderboard_txt = "リーダーボード";
        lost_a_game_txt = "2. 試合に負けた";
        learnt_kitsune_ken_txt = "6. きつね剣の秘密を知る";
        // M
        main_menu_txt = "メインメニュー";
        multiplayer_lobby_txt = "マルチプレイヤーロビー";
        // N
        never_lost_game_txt = "10. 試合に負けることはありません";
        // O
        online_multiplayer_txt = "オンラインマルチプレイヤー";
        // R
        reset_settings_txt = "設定をリセット";
        resolution_txt = "解決";
        // S
        save_settings_txt = "設定を保存する";
        settings_txt = "設定";
        start_game_txt = "始めるゲーム";
        sound_txt = "音";
        // V
        version_txt = "バージョン: ";
        // W
        world_games_txt = "世界 ゲーム";
        won_first_game_txt = "1. 最初の試合に勝利した";
        won_same_hand_txt = "3. 同じハンドで勝ちました";
        won_game_txt = "8. 試合に勝った";
        visited_han_palace_txt = "7. 漢宮殿を訪問";
        world_map_txt = "手伝う";
    }
}

void draw_text_for_HUD_scene_1() // Main menu
{
    render_text(world_games_txt, (windowWidth * 0.35), (windowHeight * 0.05), 255, 0);

    render_text(start_game_txt, (windowWidth * 0.45), (windowHeight * 0.25), 255, 0);
    render_text(settings_txt, (windowWidth * 0.45), (windowHeight * 0.35), 255, 0);
    render_text(achievements_txt, (windowWidth * 0.45), (windowHeight * 0.45), 255, 0);
    render_text(help_txt, (windowWidth * 0.45), (windowHeight * 0.55), 255, 0);
    render_text(online_multiplayer_txt, (windowWidth * 0.45), (windowHeight * 0.65), 255, 0);
    render_text(exit_txt, (windowWidth * 0.45), (windowHeight * 0.75), 255, 0);

    render_text(version_txt + currentVersion, (windowWidth * 0.05), (windowHeight * 0.9), 255, 0);
    render_text(agnisamooh_txt, (windowWidth * 0.7), (windowHeight * 0.9), 255, 0);
}
void draw_text_for_HUD_scene_2() // Settings
{
    render_text(settings_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);

    render_text(font_size_txt, (windowWidth * 0.2), (windowHeight * 0.2), 255, 0);
    render_text(sound_txt, (windowWidth * 0.2), (windowHeight * 0.4), 255, 0);
    render_text(language_txt, (windowWidth * 0.2), (windowHeight * 0.6), 255, 0);
    render_text(fps_text, (windowWidth * 0.2), (windowHeight * 0.8), 255, 0);

    render_text("800 x 600", (windowWidth * 0.5), (windowHeight * 0.2), 255, 0);
    render_text(resolution_txt, (windowWidth * 0.5), (windowHeight * 0.3), 255, 0);
    render_text("1366 x 768", (windowWidth * 0.5), (windowHeight * 0.4), 255, 0);
    render_text(resolution_txt, (windowWidth * 0.5), (windowHeight * 0.5), 255, 0);
    render_text(fullscreen_txt, (windowWidth * 0.5), (windowHeight * 0.6), 255, 0);
    render_text(resolution_txt, (windowWidth * 0.5), (windowHeight * 0.7), 255, 0);
    render_text(key_mapping_txt, (windowWidth * 0.5), (windowHeight * 0.8), 255, 0);

    render_text(continue_txt, (windowWidth * 0.8), (windowHeight * 0.2), 255, 0);
    render_text(main_menu_txt, (windowWidth * 0.8), (windowHeight * 0.4), 255, 0);
    render_text(reset_settings_txt, (windowWidth * 0.8), (windowHeight * 0.6), 255, 0);
    render_text(save_settings_txt, (windowWidth * 0.8), (windowHeight * 0.8), 255, 0);
}
void draw_text_for_HUD_scene_4() // Achievements
{
    render_text(achievements_txt, (windowWidth * 0.4), (windowHeight * 0.1), 255, 0);

    render_text(won_first_game_txt, (windowWidth * 0.1), (windowHeight * 0.2), 255, 0);
    render_text(lost_a_game_txt, (windowWidth * 0.1), (windowHeight * 0.3), 255, 0);
    render_text(won_same_hand_txt, (windowWidth * 0.1), (windowHeight * 0.4), 255, 0);
    render_text(called_out_bluff_txt, (windowWidth * 0.1), (windowHeight * 0.5), 255, 0);
    render_text(cheated_round_txt, (windowWidth * 0.1), (windowHeight * 0.6), 255, 0);

    render_text(learnt_kitsune_ken_txt, (windowWidth * 0.5), (windowHeight * 0.2), 255, 0);
    render_text(visited_han_palace_txt, (windowWidth * 0.5), (windowHeight * 0.3), 255, 0);
    render_text(won_game_txt, (windowWidth * 0.5), (windowHeight * 0.4), 255, 0);
    render_text(found_hidden_level_txt, (windowWidth * 0.5), (windowHeight * 0.5), 255, 0);
    render_text(never_lost_game_txt, (windowWidth * 0.5), (windowHeight * 0.6), 255, 0);
}

void draw_text_for_HUD_scene_7() // Update Software
{
    render_text(update_txt, (windowWidth * 0.4), (windowHeight * 0.1), 255, 0);
}

void draw_text_for_HUD_scene_8() // Multiplayer lobby
{
    render_text(multiplayer_lobby_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
void draw_text_for_HUD_scene_9() // Leaderboard
{

    render_text(leaderboard_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
void draw_text_for_HUD_scene_11() // Profile
{

    render_text(profile_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
    render_text(enter_name_txt, (windowWidth * 0.3), (windowHeight * 0.3), 255, 0);
}

void draw_text_for_HUD_scene_25() // World map
{

    render_text(world_map_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
