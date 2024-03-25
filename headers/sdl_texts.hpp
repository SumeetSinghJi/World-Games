/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached MANUAL.txt file
*/

#pragma once

#include "global_variables.hpp"

/*  SUPPORTED LANGUAGES
    English
    Japanese: 日本語
    Thai: ภาษาไทย
    Sanskrit: संस्कृतम्
    Traditional Chinese: 中文
    Arabic: العربية
    Ge'ez: ግዕዝ
    Greek: Ελληνικά
    Latin: Latina
*/

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
std::string load_game_txt;
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
std::string sentence_overwrite_or_load_game_1_txt;
std::string sentence_overwrite_or_load_game_2_txt;
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

        // D
        deny_txt = "DENY";

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
        // I
        // J
        // K
        key_mapping_txt = "Key Mapping";
        // L
        language_txt = "Language";
        leaderboard_txt = "Leaderboard";
        learnt_kitsune_ken_txt = "6. Learnt secret of kitsune-ken";
        load_game_txt = "Load Game";
        lost_a_game_txt = "2. Lost a game";

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
        sentence_overwrite_or_load_game_1_txt = "Existing save file exists, do you want to";
        sentence_overwrite_or_load_game_2_txt = "load it, or delete and start a new game?";
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
        // D
        deny_txt = "拒否";
        // E
        enter_name_txt = "あなたの名前を入力してください";
        exit_txt = "出口";
        // F
        font_size_txt = "字体大小";
        found_hidden_level_txt = "9. 隠しレベルを発見";
        fullscreen_txt = "全画面表示";
        // H
        help_txt = "助け";
        // I
        // J
        // K
        key_mapping_txt = "キーマッピング";
        // L
        language_txt = "言語";
        leaderboard_txt = "リーダーボード";
        learnt_kitsune_ken_txt = "6. きつね剣の秘密を知る";
        load_game_txt = "ゲームを読み込む";
        lost_a_game_txt = "2. 試合に負けた";

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
        sentence_overwrite_or_load_game_1_txt = "既存のセーブファイルが存在します。それをロードしますか、";
        sentence_overwrite_or_load_game_2_txt = "それとも削除して新しいゲームを開始しますか。";
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
    else if (language == "ภาษาไทย")
    {
        accept_txt = "ยอมรับ";
        achievements_txt = "ความสำเร็จ";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. กล่าวออกมาโดนเฉพาะ";
        cheated_round_txt = "5. โกงรอบ";
        continue_txt = "ดำเนินการต่อ";

        // D
        deny_txt = "ปฏิเสธ";

        // E
        enter_name_txt = "กรุณาใส่ชื่อของคุณ:";
        exit_txt = "ออก";
        // F
        font_size_txt = "ขนาดตัวอักษร";
        found_hidden_level_txt = "9. พบระดับที่ซ่อนอยู่";
        fps_text = "FPS";
        fullscreen_txt = "เต็มหน้าจอ";
        // H
        help_txt = "ช่วยเหลือ";
        // I
        // J
        // K
        key_mapping_txt = "การกำหนดคีย์";
        // L
        language_txt = "ภาษา";
        leaderboard_txt = "ตารางเกม";
        learnt_kitsune_ken_txt = "6. เรียนรู้ความลับของ kitsune-ken";
        load_game_txt = "โหลดเกม";
        lost_a_game_txt = "2. แพ้เกม";
        // M
        main_menu_txt = "เมนูหลัก";
        multiplayer_lobby_txt = "ห้องโหลดเกมหลายคน";
        // N
        never_lost_game_txt = "10. ไม่เคยแพ้เกม!";
        // O
        online_multiplayer_txt = "โหมดเล่นหลายคนออนไลน์";
        // R
        reset_settings_txt = "รีเซ็ตการตั้งค่า";
        resolution_txt = "ความละเอียด";
        // S
        save_settings_txt = "บันทึกการตั้งค่า";
        sentence_overwrite_or_load_game_1_txt = "มีไฟล์เซฟที่มีอยู่แล้ว ";
        sentence_overwrite_or_load_game_2_txt = "คุณต้องการโหลดหรือลบและเริ่มเกมใหม่";
        settings_txt = "การตั้งค่า";
        sound_txt = "เสียง";
        start_game_txt = "เริ่มเกม";
        // V
        version_txt = "เวอร์ชัน: ";
        // W
        world_games_txt = "เกมโลก";
        won_first_game_txt = "1. ชนะเกมแรก";
        won_same_hand_txt = "3. ชนะด้วยมือเดียวกัน";
        won_game_txt = "8. ชนะเกม";
        visited_han_palace_txt = "7. เยี่ยมพระราชวังฮัน";
        world_map_txt = "แผนที่โลก";
    }
    else if (language == "संस्कृतम्")
    {
        accept_txt = "स्वीकार्यम्";
        achievements_txt = "यशः";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. छल का उद्घाटन";
        cheated_round_txt = "5. धोखेबाजी राउंड";
        continue_txt = "प्रस्तुति";

        // D
        deny_txt = "अस्वीकार्यम्";

        // E
        enter_name_txt = "तव नाम प्रविष्टम्:";
        exit_txt = "निर्गम";
        // F
        font_size_txt = "लिपिमान";
        found_hidden_level_txt = "9. छिपे स्तर का पता लगाया";
        fps_text = "फ्रेम प्रति सेकेण्ड";
        fullscreen_txt = "पूर्ण आयाम";
        // H
        help_txt = "सहायता";
        // I
        // J
        // K
        key_mapping_txt = "की मानचित्रणं";
        // L
        language_txt = "भाषा";
        leaderboard_txt = "शिखरपट्टिका";
        learnt_kitsune_ken_txt = "6. कित्सुने-केन का गुप्त रहस्य सीखा";
        load_game_txt = "खेलं लोड्";
        lost_a_game_txt = "2. खेल हारा";
        // M
        main_menu_txt = "मुख्य मेनू";
        multiplayer_lobby_txt = "बहुप्रयोक्ता लॉबी";
        // N
        never_lost_game_txt = "10. कदापि खेल न हारा!";
        // O
        online_multiplayer_txt = "ऑनलाइन बहुप्रयोक्ता";
        // R
        reset_settings_txt = "सेटिंग्स पुनः सेट करें";
        resolution_txt = "संकल्प";
        // S
        save_settings_txt = "सेटिंग्स सहेजें";
        sentence_overwrite_or_load_game_1_txt = "अस्तित्वान्तरं सुरक्षणफाइलः अस्ति, तदानीं अन्वेषयसि";
        sentence_overwrite_or_load_game_2_txt = "वा, अथवा हन्तुमुद्यमः प्रारंभ्यताम् इति च प्रश्नः";
        settings_txt = "सेटिंग्स";
        sound_txt = "ध्वनि";
        start_game_txt = "खेल प्रारंभ करें";
        // V
        version_txt = "संस्करण: ";
        // W
        world_games_txt = "विश्व खेल";
        won_first_game_txt = "1. पहला खेल जीता";
        won_same_hand_txt = "3. एक ही हाथ से जीता";
        won_game_txt = "8. खेल जीता";
        visited_han_palace_txt = "7. हान उपासना स्थल पर गया";
        world_map_txt = "विश्व मानचित्र";
    }
    else if (language == "中文")
    {
        accept_txt = "接受";
        achievements_txt = "成就";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. 揭穿虛張聲勢";
        cheated_round_txt = "5. 作弊一輪";
        continue_txt = "繼續";

        // D
        deny_txt = "否認";

        // E
        enter_name_txt = "輸入你的名字：";
        exit_txt = "退出";
        // F
        font_size_txt = "字體大小";
        found_hidden_level_txt = "9. 發現隱藏關卡";
        fps_text = "FPS";
        fullscreen_txt = "全屏";
        // H
        help_txt = "幫助";
        // I
        // J
        // K
        key_mapping_txt = "鍵盤映射";
        // L
        language_txt = "語言";
        leaderboard_txt = "排行榜";
        learnt_kitsune_ken_txt = "6. 學會狐拳的秘密";
        load_game_txt = "載入遊戲";
        lost_a_game_txt = "2. 輸了一局";

        // M
        main_menu_txt = "主菜單";
        multiplayer_lobby_txt = "多人遊戲大廳";
        // N
        never_lost_game_txt = "10. 從未輸過遊戲！";
        // O
        online_multiplayer_txt = "在線多人遊戲";
        // R
        reset_settings_txt = "重置設置";
        resolution_txt = "解析度";
        // S
        save_settings_txt = "保存設置";
        sentence_overwrite_or_load_game_1_txt = "現有的存檔存在，你要載入它";
        sentence_overwrite_or_load_game_2_txt = "還是刪除並開始一個新遊戲";
        settings_txt = "設置";
        sound_txt = "音效";
        start_game_txt = "開始遊戲";
        // V
        version_txt = "版本：";
        // W
        world_games_txt = "世界遊戲";
        won_first_game_txt = "1. 贏得第一場比賽";
        won_same_hand_txt = "3. 用同一手贏得";
        won_game_txt = "8. 贏得比賽";
        visited_han_palace_txt = "7. 參觀漢宮";
        world_map_txt = "世界地圖";
    }
    else if (language == "العربية")
    {
        accept_txt = "قبول";
        achievements_txt = "الإنجازات";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. كشف الكذب";
        cheated_round_txt = "5. خدع جولة";
        continue_txt = "متابعة";

        // D
        deny_txt = "رفض";

        // E
        enter_name_txt = "أدخل اسمك:";
        exit_txt = "خروج";
        // F
        font_size_txt = "حجم الخط";
        found_hidden_level_txt = "9. اكتشف المستوى الخفي";
        fps_text = "إطارات في الثانية";
        fullscreen_txt = "شاشة كاملة";
        // H
        help_txt = "مساعدة";
        // I
        // J
        // K
        key_mapping_txt = " تعيين المفاتيح";
        // L
        language_txt = "اللغة";
        leaderboard_txt = "لوحة القيادة";
        learnt_kitsune_ken_txt = "6. تعلم سر كيتسوني-كين";
        load_game_txt = "تحميل اللعبة";
        lost_a_game_txt = "2. خسر لعبة";
        // M
        main_menu_txt = "القائمة الرئيسية";
        multiplayer_lobby_txt = "غرفة اللعب الجماعي";
        // N
        never_lost_game_txt = "10. لم يخسر أبدًا لعبة!";
        // O
        online_multiplayer_txt = "لعب جماعي عبر الإنترنت";
        // R
        reset_settings_txt = "إعادة تعيين الإعدادات";
        resolution_txt = "الدقة";
        // S
        save_settings_txt = "حفظ الإعدادات";
        sentence_overwrite_or_load_game_1_txt = "تحميله، أم حذفه وبدء لعبة جديدة؟";
        sentence_overwrite_or_load_game_2_txt = "يوجد ملف حفظ قائم، هل تريد";
        settings_txt = "الإعدادات";
        sound_txt = "الصوت";
        start_game_txt = "بدء اللعبة";
        // V
        version_txt = "النسخة: ";
        // W
        world_games_txt = "ألعاب العالم";
        won_first_game_txt = "1. فاز باللعبة الأولى";
        won_same_hand_txt = "3. فاز بنفس اليد";
        won_game_txt = "8. فاز باللعبة";
        visited_han_palace_txt = "7. زار القصر هان";
        world_map_txt = "خريطة العالم";
    }
    else if (language == "ግዕዝ")
    {
        accept_txt = "ተቀበል";
        achievements_txt = "ተሳኝ";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. በርቀት ተገኝቷል";
        cheated_round_txt = "5. መርጋገጥ እቅል";
        continue_txt = "ተጨማሪ ይሆን";

        // D
        deny_txt = "አይሰሙም";

        // E
        enter_name_txt = "ስምዎን ያስገቡ:";
        exit_txt = "ውጣ";
        // F
        font_size_txt = "ፎንት መጠን";
        found_hidden_level_txt = "9. የምርጫ ሁኔታ ተገኝቷል";
        fps_text = "መነጽሮች በሳእንት";
        fullscreen_txt = "መረጃ ለማንበብ";
        // H
        help_txt = "እገዛ";
        // I
        // J
        // K
        key_mapping_txt = "የቁልፍ ምልክት";
        // L
        language_txt = "ቋንቋ";
        leaderboard_txt = "መረጃ ምርጫ";
        learnt_kitsune_ken_txt = "6. ከኪቱንዝነት ጥቅም ተማርለት";
        load_game_txt = "ግዕዝ ጨዋታ";
        lost_a_game_txt = "2. ጨዋታ ተወፍረዋል";
        // M
        main_menu_txt = "መምሪያ ስምምነት";
        multiplayer_lobby_txt = "የሚከተለው ሌቦች";
        // N
        never_lost_game_txt = "10. ጨዋታ አልተማረውም!";
        // O
        online_multiplayer_txt = "እችዋኖች ተጠቃሚ መጫወቻ";
        // R
        reset_settings_txt = "ማስተካከል አስጀምሪ";
        resolution_txt = "ምሳሌ";
        // S
        save_settings_txt = "ማስታወሻ አስገባ";
        sentence_overwrite_or_load_game_1_txt = "አንደኛ የታቀደ ወደ እርስዎ ይጠቀሙታል፣ ወይም";
        sentence_overwrite_or_load_game_2_txt = "አንድ ነገር የሚከተሉትን ስሌት እና አድርጉት የሚጀምሩትን እርስዎ ይጠቀሙታል።";
        settings_txt = "ቅንብሮች";
        sound_txt = "ድምፅ";
        start_game_txt = "ጨዋታ ጀምር";
        // V
        version_txt = "እትም: ";
        // W
        world_games_txt = "ዓለም ጨዋታዎች";
        won_first_game_txt = "1. መጀመሪያ ጨዋታ ተለዋጭ";
        won_same_hand_txt = "3. በአንድ ታንክ ተለዋጭ";
        won_game_txt = "8. ጨዋታ ተለዋጭ";
        visited_han_palace_txt = "7. የሐን ቦርነት ተገኝቷል";
        world_map_txt = "ዓለም ካርታ";
    }
    else if (language == "Ελληνικά")
    {
        accept_txt = "Αποδοχή";
        achievements_txt = "Επιτεύγματα";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. Αποκάλυψη ψεύδους";
        cheated_round_txt = "5. Απάτη γύρου";
        continue_txt = "Συνέχεια";

        // D
        deny_txt = "Άρνηση";

        // E
        enter_name_txt = "Εισαγωγή ονόματος:";
        exit_txt = "Έξοδος";
        // F
        font_size_txt = "Μέγεθος γραμματοσειράς";
        found_hidden_level_txt = "9. Εύρεση κρυμμένου επιπέδου";
        fps_text = "FPS";
        fullscreen_txt = "Πλήρης οθόνη";
        // H
        help_txt = "Βοήθεια";
        // I
        // J
        // K
        key_mapping_txt = "Χαρτογράφηση πλήκτρων";
        // L
        language_txt = "Γλώσσα";
        leaderboard_txt = "Πίνακας κατάταξης";
        learnt_kitsune_ken_txt = "6. Μάθηση μυστικού του kitsune-ken";
        load_game_txt = "Φόρτωση παιχνιδιού";
        lost_a_game_txt = "2. Έχασε ένα παιχνίδι";
        // M
        main_menu_txt = "Κύριο μενού";
        multiplayer_lobby_txt = "Προθάλαμος πολλαπλών παικτών";
        // N
        never_lost_game_txt = "10. Ποτέ δεν έχασε παιχνίδι!";
        // O
        online_multiplayer_txt = "Διαδικτυακό πολλαπλών παικτών";
        // R
        reset_settings_txt = "Επαναφορά ρυθμίσεων";
        resolution_txt = "Ανάλυση";
        // S
        save_settings_txt = "Αποθήκευση ρυθμίσεων";
        sentence_overwrite_or_load_game_1_txt = "Υπάρχει υπάρχει αρχείο αποθήκευσης, θέλετε να το";
        sentence_overwrite_or_load_game_2_txt = "φορτώσετε, ή να το διαγράψετε και να ξεκινήσετε ένα νέο παιχνίδι;";
        settings_txt = "Ρυθμίσεις";
        sound_txt = "Ήχος";
        start_game_txt = "Έναρξη παιχνιδιού";
        // V
        version_txt = "Έκδοση: ";
        // W
        world_games_txt = "Παγκόσμια παιχνίδια";
        won_first_game_txt = "1. Κέρδισε το πρώτο παιχνίδι";
        won_same_hand_txt = "3. Κέρδισε με το ίδιο χέρι";
        won_game_txt = "8. Κέρδισε το παιχνίδι";
        visited_han_palace_txt = "7. Επισκέφθηκε το παλάτι της Χαν";
        world_map_txt = "Παγκόσμιος χάρτης";
    }
    else if (language == "Latina")
    {
        accept_txt = "Accepta";
        achievements_txt = "Perfectiones";
        agnisamooh_txt = "@AgniSamooh.com";
        // C
        called_out_bluff_txt = "4. Detectum mendacium";
        cheated_round_txt = "5. Fraus circuli";
        continue_txt = "Continua";
        // D
        deny_txt = "Negare";
        // E
        enter_name_txt = "Nomine inserito:";
        exit_txt = "Exitus";
        // F
        font_size_txt = "Magnitudo fontis";
        found_hidden_level_txt = "9. Nivelem occultum inventum";
        fps_text = "FPS";
        fullscreen_txt = "Totus pagina";
        // H
        help_txt = "Auxilium";
        // I
        // J
        // K
        key_mapping_txt = "Clavis Mapping";
        // L
        language_txt = "Lingua";
        leaderboard_txt = "Tabula ducum";
        learnt_kitsune_ken_txt = "6. Arcanum Kitsune-ken didicit";
        load_game_txt = "Lusum onerare";
        lost_a_game_txt = "2. Ludum perditum";
        // M
        main_menu_txt = "Menu principalis";
        multiplayer_lobby_txt = "Conventus multiplex";
        // N
        never_lost_game_txt = "10. Nunquam ludum amisit!";
        // O
        online_multiplayer_txt = "Ludum multiplayer online";
        // R
        reset_settings_txt = "Resete configurationes";
        resolution_txt = "Resolutio";
        // S
        save_settings_txt = "Configurationes serva";
        sentence_overwrite_or_load_game_1_txt = "Est fasciculus conservationis, vis eum adfari";
        sentence_overwrite_or_load_game_2_txt = "an deleantur et ludum novum incipiant?";
        settings_txt = "Configurationes";
        sound_txt = "Sonus";
        start_game_txt = "Ludum incipe";
        // V
        version_txt = "Versio: ";
        // W
        world_games_txt = "Ludi mundi";
        won_first_game_txt = "1. Primum ludum vicum";
        won_same_hand_txt = "3. Eadem manu victum";
        won_game_txt = "8. Ludum vicum";
        visited_han_palace_txt = "7. Palatium Han visitavit";
        world_map_txt = "Tabula mundi";
    }
}

void draw_text_for_HUD_scene_1() // Main menu
{
    if (displaySavefileExistsPopup)
    {
        render_text(sentence_overwrite_or_load_game_1_txt, (windowWidth * 0.30), (windowHeight * 0.1), 255, 0);
        render_text(sentence_overwrite_or_load_game_2_txt, (windowWidth * 0.30), (windowHeight * 0.2), 255, 0);
    }
    else
    {
        render_text(world_games_txt, (windowWidth * 0.35), (windowHeight * 0.05), 255, 0);

        render_text(load_game_txt, (windowWidth * 0.45), (windowHeight * 0.15), 255, 0);
        render_text(start_game_txt, (windowWidth * 0.45), (windowHeight * 0.25), 255, 0);
        render_text(settings_txt, (windowWidth * 0.45), (windowHeight * 0.35), 255, 0);
        render_text(achievements_txt, (windowWidth * 0.45), (windowHeight * 0.45), 255, 0);
        render_text(help_txt, (windowWidth * 0.45), (windowHeight * 0.55), 255, 0);
        render_text(online_multiplayer_txt, (windowWidth * 0.45), (windowHeight * 0.65), 255, 0);
        render_text(exit_txt, (windowWidth * 0.45), (windowHeight * 0.75), 255, 0);

        render_text(version_txt + updateApp_currentVersion, (windowWidth * 0.05), (windowHeight * 0.9), 255, 0);
        render_text(agnisamooh_txt, (windowWidth * 0.7), (windowHeight * 0.9), 255, 0);
    }
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
void draw_text_for_HUD_scene_3() // Credits
{
    render_text(help_txt, (windowWidth * 0.4), (windowHeight * 0.1), 255, 0);
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
void draw_text_for_HUD_scene_5() // Help
{

    render_text(leaderboard_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
void draw_text_for_HUD_scene_6() // Leaderboard
{

    render_text(leaderboard_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
void draw_text_for_HUD_scene_7() // 
{
    render_text(update_txt, (windowWidth * 0.4), (windowHeight * 0.1), 255, 0);
}
void draw_text_for_HUD_scene_8() // 
{
    render_text(multiplayer_lobby_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
void draw_text_for_HUD_scene_9() // 
{

    render_text(leaderboard_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
void draw_text_for_HUD_scene_10() // Key mappings
{
    render_text(key_mapping_txt, (windowWidth * 0.35), (windowHeight * 0.1), 255, 0);
}

void draw_text_for_HUD_scene_11() // Online login
{

    render_text(profile_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
    render_text(enter_name_txt, (windowWidth * 0.3), (windowHeight * 0.3), 255, 0);
}
void draw_text_for_HUD_scene_12() // Create account
{

    render_text(profile_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
    render_text(enter_name_txt, (windowWidth * 0.3), (windowHeight * 0.3), 255, 0);
}
void draw_text_for_HUD_scene_13() // Multiplayer lobby
{

    render_text(profile_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
    render_text(enter_name_txt, (windowWidth * 0.3), (windowHeight * 0.3), 255, 0);
}

void draw_text_for_HUD_scene_25() // World map
{

    render_text(world_map_txt, (windowWidth * 0.45), (windowHeight * 0.1), 255, 0);
}
