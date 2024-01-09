#ifndef sdl_texts
#define sdl_texts

#include <iostream>

extern std::string language;
extern int windowWidth;
extern int windowHeight;
extern int fps;
extern int scene;
extern bool fps_condition;

void render_text(const std::string &text, int x, int y);

void text_for_HUD_scene_1() // Main menu
{
    if (language == "English")
    {
        render_text("WORLD GAMES", (windowWidth * 0.35), (windowHeight * 0.05));

        // render_text("Continue", (windowWidth * 0.45), (windowHeight * 0.25));
        render_text("Start game", (windowWidth * 0.45), (windowHeight * 0.25));
        render_text("Settings", (windowWidth * 0.45), (windowHeight * 0.35));
        render_text("Achievements", (windowWidth * 0.45), (windowHeight * 0.45));
        render_text("Help", (windowWidth * 0.45), (windowHeight * 0.55));
        render_text("Update", (windowWidth * 0.45), (windowHeight * 0.65));
        render_text("Exit", (windowWidth * 0.45), (windowHeight * 0.75));

        render_text("version: 0.1", (windowWidth * 0.05), (windowHeight * 0.9));
        render_text("@AgniSamooh.com", (windowWidth * 0.7), (windowHeight * 0.9));
    }
    else if (language == "日本語")
    {
        render_text("WORLD GAMES", (windowWidth * 0.35), (windowHeight * 0.05));

        // render_text("続く", (windowWidth * 0.45), (windowHeight * 0.25));
        render_text("新しいゲーム", (windowWidth * 0.45), (windowHeight * 0.25));
        render_text("設定", (windowWidth * 0.45), (windowHeight * 0.35));
        render_text("業績", (windowWidth * 0.45), (windowHeight * 0.45));
        render_text("助け", (windowWidth * 0.45), (windowHeight * 0.55));
        render_text("更新", (windowWidth * 0.45), (windowHeight * 0.65));
        render_text("出口", (windowWidth * 0.45), (windowHeight * 0.75));

        render_text("バージョン: 1.0", (windowWidth * 0.05), (windowHeight * 0.9));
        render_text("@AgniSamooh.com", (windowWidth * 0.7), (windowHeight * 0.9));
    }
}
void text_for_HUD_scene_2() // Settings
{
    if (language == "English")
    {
        render_text("Settings", (windowWidth * 0.45), (windowHeight * 0.1));

        render_text("Font size", (windowWidth * 0.2), (windowHeight * 0.2));
        render_text("Sound", (windowWidth * 0.2), (windowHeight * 0.4));
        render_text("Language", (windowWidth * 0.2), (windowHeight * 0.6));
        render_text("FPS", (windowWidth * 0.2), (windowHeight * 0.8));

        render_text("800 x 600", (windowWidth * 0.5), (windowHeight * 0.2));
        render_text("Resolution", (windowWidth * 0.5), (windowHeight * 0.3));
        render_text("1366 x 768", (windowWidth * 0.5), (windowHeight * 0.4));
        render_text("Resolution", (windowWidth * 0.5), (windowHeight * 0.5));
        render_text("Fullscreen", (windowWidth * 0.5), (windowHeight * 0.6));
        render_text("Resolution", (windowWidth * 0.5), (windowHeight * 0.7));

        render_text("Continue", (windowWidth * 0.8), (windowHeight * 0.2));
        render_text("Main Menu", (windowWidth * 0.8), (windowHeight * 0.4));
    }
    else if (language == "日本語")
    {
        render_text("設定", (windowWidth * 0.4), (windowHeight * 0.1));

        render_text("字体大小", (windowWidth * 0.2), (windowHeight * 0.2));
        render_text("音", (windowWidth * 0.2), (windowHeight * 0.4));
        render_text("言語", (windowWidth * 0.2), (windowHeight * 0.6));
        render_text("FPS", (windowWidth * 0.2), (windowHeight * 0.8));

        render_text("800 x 600", (windowWidth * 0.5), (windowHeight * 0.2));
        render_text("解像度", (windowWidth * 0.5), (windowHeight * 0.3));
        render_text("1366 x 768", (windowWidth * 0.5), (windowHeight * 0.4));
        render_text("解像度", (windowWidth * 0.5), (windowHeight * 0.5));
        render_text("全画面表示", (windowWidth * 0.5), (windowHeight * 0.6));
        render_text("解像度", (windowWidth * 0.5), (windowHeight * 0.7));

        render_text("続く", (windowWidth * 0.8), (windowHeight * 0.2));
        render_text("メインメニュー", (windowWidth * 0.8), (windowHeight * 0.4));
    }
}
void text_for_HUD_scene_4() // Achievements
{
    if (language == "English")
    {
        render_text("Achievements", (windowWidth * 0.4), (windowHeight * 0.1));

        render_text("1. Won first game", (windowWidth * 0.1), (windowHeight * 0.2));
        render_text("2. Lost a game", (windowWidth * 0.1), (windowHeight * 0.3));
        render_text("3. Won with same hand", (windowWidth * 0.1), (windowHeight * 0.4));
        render_text("4. Called out a bluff", (windowWidth * 0.1), (windowHeight * 0.5));
        render_text("5. Cheated a round", (windowWidth * 0.1), (windowHeight * 0.6));

        render_text("6. Learnt secret of kitsune-ken", (windowWidth * 0.5), (windowHeight * 0.2));
        render_text("7. Visited the Han Palace", (windowWidth * 0.5), (windowHeight * 0.3));
        render_text("8. Won the game", (windowWidth * 0.5), (windowHeight * 0.4));
        render_text("9. Found the hidden level", (windowWidth * 0.5), (windowHeight * 0.5));
        render_text("10. Never lost a game!", (windowWidth * 0.5), (windowHeight * 0.6));
    }
    else if (language == "日本語")
    {
        render_text("業績", (windowWidth * 0.3), (windowHeight * 0.0));

        render_text("1. 最初の試合に勝利した", (windowWidth * 0.1), (windowHeight * 0.2));
        render_text("2. 試合に負けた", (windowWidth * 0.1), (windowHeight * 0.3));
        render_text("3. 同じハンドで勝ちました", (windowWidth * 0.1), (windowHeight * 0.4));
        render_text("4. ブラフを発動した", (windowWidth * 0.1), (windowHeight * 0.5));
        render_text("5. ラウンドで不正行為をした", (windowWidth * 0.1), (windowHeight * 0.6));

        render_text("6. きつね剣の秘密を知る", (windowWidth * 0.5), (windowHeight * 0.2));
        render_text("7. 漢宮殿を訪問", (windowWidth * 0.5), (windowHeight * 0.3));
        render_text("8. 試合に勝った", (windowWidth * 0.5), (windowHeight * 0.4));
        render_text("9. 隠しレベルを発見", (windowWidth * 0.5), (windowHeight * 0.5));
        render_text("10. 試合に負けることはありません", (windowWidth * 0.5), (windowHeight * 0.6));
    }
}
void text_for_HUD_scene_6() // World map
{
    if (language == "English")
    {
        render_text("World map", (windowWidth * 0.45), (windowHeight * 0.1));
    }
    else if (language == "日本語")
    {
        render_text("手伝う", (windowWidth * 0.4), (windowHeight * 0.1));
    }
}
void text_for_HUD_scene_8() // Multiplayer lobby
{
    if (language == "English")
    {
        render_text("Multiplayer lobby", (windowWidth * 0.45), (windowHeight * 0.1));
    }
    else if (language == "日本語")
    {
        render_text("マルチプレイヤーロビー", (windowWidth * 0.4), (windowHeight * 0.1));
    }
}
void text_for_HUD_scene_9() // Leaderboard
{
    if (language == "English")
    {
        render_text("Leaderboard", (windowWidth * 0.45), (windowHeight * 0.1));
    }
    else if (language == "日本語")
    {
        render_text("リーダーボード", (windowWidth * 0.4), (windowHeight * 0.1));
    }
}
void text_for_HUD_scene_11() // Profile
{
    if (language == "English")
    {
        render_text("Profile", (windowWidth * 0.45), (windowHeight * 0.1));
        render_text("Enter your name:", (windowWidth * 0.3), (windowHeight * 0.3));
    }
    else if (language == "日本語")
    {
        render_text("プロフィール", (windowWidth * 0.4), (windowHeight * 0.1));
        render_text("あなたの名前を入力してください", (windowWidth * 0.3), (windowHeight * 0.3));
    }
}


#endif