/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++11
    Purpose: Declaration/Definition file combined
    License: MIT License
    Description: Declaration and Definition file for using curl to read website i.e, World Games github
    then find the version number from the README.md string "Version: x.x". Compare the version number
    online with local offline version then prompt user if offline software out of date to update.
    curl.h will download the git .zip file, then zip.h will extract. Remainder of code related to
    copying over save file from old directory to new folder, existing the open application, deleting
    the old directory and starting the new folder executable.

    Example:

    1. Populate valuable for variable currentVersion by calling function: update_version_string_from_readme_file();
    2. Populate variable OSversion with value matching "Windows" "linux" or "Mac OS X"
    3. Call function: start_game_update(); to update game, with parameters for URL of website with the string "Version: "
    to match with offline version, and second parameter of local trusted CA certificate proving remote sites authenticity.
    3rd parameter string is the full zip path to download.
    e.g. start_game_update("https://github.com/SumeetSinghJi/world-games", "./src/curl/bin/curl-ca-bundle.crt", "https://github.com/SumeetSinghJi/world-games/archive/refs/heads/master.zip");
*/

#pragma once

#include <iostream>
#include "global_variables.hpp"
#include <curl.h>  // for downloading latest game from Github
#include <cstdio>  // for curl functions
#include <cstring> // for curl functions
#include <cstdlib> // multiplatform e.g. std::system("pkill") to run system commands e.g terminate app,
#ifdef _WIN32
#include <winsock2.h> // For curling on Windows
#endif
#include <zip.h>      // for unzipping downloaded game from GitHub/source repo
#include <fstream>    // multiplatform method for for file open read write objects
#include <filesystem> // multiplatform method for creating and deleting directories (folders)
#include <string>     // For getline()
#include <cstdlib>    // multiplatform e.g. std::system("pkill") to run system commands e.g terminate app,

#ifdef _WIN32
const std::string OSversion = "Windows";
const std::string curl_path = "./src/curl/bin/curl.exe";
const std::string certPath = "./src/curl/bin/curl-ca-bundle.crt";
#elif __APPLE__
const std::string OSversion = "Mac OS X";
const std::string curl_path = "./src/curl/bin/curl.exe";
const std::string certPath = "./src/curl/bin/curl-ca-bundle.crt";
#elif __linux__
const std::string OSversion = "Linux";
const std::string curl_path = "./src/curl/bin/curl";
const std::string certPath = "./src/curl/bin/curl-ca-bundle.crt";
#else
const std::string OSversion = "Unknown";
#endif

// FUNCTION PROTOTYPE
void download_file(std::string downloadLink);

// GLOBAL VARIABLES
std::string currentVersion;
std::string zipFilePath;
double download_progress = 0.0;
bool show_progress = false;
bool clickedStartAppUpdate = false;
bool downloadUpdateSelected = false; // if true render_text(Updating...)

// This function reads the README.md to find the current version, to compare with online repo latest version
std::string update_version_string_from_readme_file(std::string fileWithVersionString)
{
    std::fstream readme_object;
    std::string version = "";
    readme_object.open(fileWithVersionString, std::ios::in);
    if (readme_object.is_open())
    {
        std::string line;
        while (std::getline(readme_object, line))
        {
            if (line.find("Version: ") != std::string::npos)
                currentVersion = line.substr(9);
            std::cout << "Current Version is: " << currentVersion << std::endl;
        }

        readme_object.close();
        readme_object.clear();
    }
    else
    {
        std::cerr << "Error: Unable to open: " << fileWithVersionString << " file to find version number string" << std::endl;
    }
    return currentVersion;
}

/*
// Set curl executable or bin path by OS
std::string set_curl_executable_or_bin_path()
{
    std::string filepath_separator = "";
    std::string curl_path = "";
    const char *home_directory = nullptr;

    if (OSversion == "Windows")
    {
        // filepath_separator = '\\';
        // home_directory = getenv("USERPROFILE"); // Windows uses USERPROFILE for the home directory
        // curl_path = std::string(home_directory) + filepath_separator + "Documents" + filepath_separator + "world-games" + filepath_separator + "src" + filepath_separator + "curl" + filepath_separator + "bin" + filepath_separator + "curl.exe";
        curl_path = ".\\src\\curl\\bin\\curl.exe";
    }
    else if (OSversion == "linux" || OSversion == "Mac OS X")
    {
        // filepath_separator = '/';
        // home_directory = getenv("HOME"); // linux and macOS use HOME for the home directory
        // curl_path = std::string(home_directory) + filepath_separator + "world-games" + filepath_separator + "curl" + filepath_separator + "bin" + filepath_separator + "curl";
        curl_path = "./src/curl/bin/curl.exe";
    }
    else
    {
        std::cout << "Error: Host OS Home directory folder cannot be found" << std::endl;
    }
    std::cout << "Curl binary/executable path set to: " << curl_path << std::endl;
    return curl_path;
}
*/


// Set path to download game updates to
std::string save_path_for_zip()
{
    std::string filepath_separator = "";
    const char *home_directory = nullptr;

    if (OSversion == "Windows")
    {
        filepath_separator = '\\';
        home_directory = getenv("USERPROFILE"); // Windows uses USERPROFILE for the home directory
        std::string zipFilePath = std::string(home_directory) + filepath_separator + "world-games_updates.zip";
    }
    else if (OSversion == "linux" || OSversion == "Mac OS X")
    {
        filepath_separator = '/';
        home_directory = getenv("HOME"); // linux and macOS use HOME for the home directory
        std::string zipFilePath = std::string(home_directory) + filepath_separator + "world-games_updates.zip";
    }
    else
    {
        std::cout << "Error: Host OS Home directory folder cannot be found" << std::endl;
    }
    return zipFilePath;
}

// Callback function to handle the response received from the website
size_t cout_curl_response_to_terminal(void *contents, size_t size, size_t nmemb, std::string *output)
{
    size_t total_size = size * nmemb;
    output->append(static_cast<char *>(contents), total_size);
    return total_size;
}

// Start Curl to world-games Github to check for updates
void start_curl(std::string urlPath, std::string downloadLink)
{
    /* Purpose

    1. Function update_version_string_from_readme_file() called to populate global variable: currentVersion
    from reading existing directory readme.md string version number
    2. This function will connect to a website, and search for string "Version: " and find the trailing
    numbers then update the global variables remoteVersionDouble
    3. If remote version is greater then local version prompt will appear to download zip.
    4. Remainder of steps called in start_game_update()
    */

    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl)
    {
        std::cout << "Success: Curl initialised." << std::endl;
        curl_easy_setopt(curl, CURLOPT_URL, urlPath.c_str());

        // Step 1 - Configure curl with curl.exe path
        curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, 1L); // Set this to avoid converting slashes
        curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, curl_path.c_str());

        // Step 2 - Set CA cert path
        curl_easy_setopt(curl, CURLOPT_CAINFO, certPath.c_str());

        // Store the response in a string
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cout_curl_response_to_terminal);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        std::cout << "Status: Now starting to curl: " << urlPath << std::endl;

        // Perform the request
        res = curl_easy_perform(curl);

        if (res == CURLE_OK)
        {
            std::cout << "Curl successfull" << std::endl;
            // Extract the version number from the response -
            // IMPORTANT - Repo needs to be public
            std::string version_tag = "Version: ";
            size_t version_pos = response.find(version_tag);
            std::cout << "now locating string '" << version_tag << "', in README.md on Github."
                                                                   "Ensure no bullet point in front of word in online page. e.g. Version: 1.0"
                      << std::endl;

            if (version_pos != std::string::npos)
            {
                version_pos += version_tag.length(); // Move past the "Version: " string

                // Find the position of the first non-numeric character in the version number
                size_t non_numeric_pos = response.find_first_not_of("0123456789.", version_pos);

                // Keep only the numeric part of the version number
                std::string versionNumber = response.substr(version_pos, non_numeric_pos - version_pos);

                // Convert version strings to double
                double currentVersionDouble = stod(currentVersion);
                double remoteVersionDouble = stod(versionNumber);

                if (remoteVersionDouble <= currentVersionDouble)
                {
                    std::cout << "Current version: " << currentVersionDouble << " , is already up to date." << std::endl;
                }
                else
                {
                    // 1 - If the game is out of date, prompt to download the latest version
                    std::cout << "Current version is: " << currentVersionDouble << ", New version available is: " << remoteVersionDouble << std::endl;
                    std::cout << "Would you like to update to the latest version? (Enter 'Y' for Yes or 'N' for No.): ";
                    char download_accept_char;
                    std::cin.get() >> download_accept_char;
                    std::cin.ignore(); // Ignore the newline character left in the buffer

                    if (download_accept_char == 'Y' || download_accept_char == 'y')
                    {
                        downloadUpdateSelected = true;
                        show_progress = true; // Enable progress display
                        download_file(downloadLink.c_str());
                        show_progress = false; // Disable progress display after download
                    }
                    else
                    {
                        std::cout << "Stopped check for updates." << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "Couldn't find string 'Version: ' in online repo README.md game update stopping." << std::endl;
            }
        }
        else
        {
            std::cout << "Error: curl failed: " << curl_easy_strerror(res) << std::endl;
            std::cout << "Manually download latest game version from here: " << downloadLink << std::endl;
        }

        curl_easy_cleanup(curl);
    }
    else
    {
        std::cout << "Error: Failed to initialize curl." << std::endl;
        std::cout << "Manually download latest game version from here: https://github.com/SumeetSinghJi/world-games" << std::endl;
    }

    curl_global_cleanup();
}

// Callback function to write the downloaded data to a file
size_t WriteCallback(void *contents, size_t size, size_t nmemb, FILE *file)
{
    return fwrite(contents, size, nmemb, file);
}

// Callback function to display progress
int XferInfoCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    if (show_progress)
    {
        if (dltotal <= 0)
        {
            std::cout << "Download progress: " << dlnow / (1024 * 1024) << " MB downloaded (Unknown total size)" << std::endl;
        }
        else
        {
            double total = static_cast<double>(dltotal) / (1024 * 1024);
            double downloaded = static_cast<double>(dlnow) / (1024 * 1024);
            std::cout << "Download progress: " << static_cast<long long>(downloaded) << " MB / " << static_cast<long long>(total) << " MB ("
                      << (downloaded / total) * 100.0 << "%/100% complete)" << std::endl;
        }
    }
    return 0;
}

// download update file from start_curl() prompt
void download_file(std::string downloadLink)
{
    std::cout << "Attempting to download updates for world-games." << std::endl;

    CURL *curl;
    CURLcode res;
    std::string zipFilePath = save_path_for_zip();
    FILE *file = fopen(zipFilePath.c_str(), "wb");

    if (!file)
    {
        std::cout << "Error: Cannot open file for writing." << std::endl;
        return;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (!curl)
    {
        std::cout << "Error: Cannot initialize curl." << std::endl;
        fclose(file);
        return;
    }
    // Step 1 - Configure curl with curl.exe path
    curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, 1L); // Set this to avoid converting slashes
    curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, curl_path.c_str());

    // Step 2 - Set CA cert path
    curl_easy_setopt(curl, CURLOPT_CAINFO, certPath.c_str());

    curl_easy_setopt(curl, CURLOPT_URL, downloadLink.c_str());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);                                                                                                                 // Pass file pointer to the callback
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);                                                                                                                  // Enable progress meter
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, XferInfoCallback);                                                                                              // Set progress callback
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);                                                                                                              // Allow redirects
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);                                                                                                                 // Fail if HTTP response code >= 400
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"); // Set user-agent

    // Perform the request
    // Download the zip file from url with
    res = curl_easy_perform(curl);

    fclose(file); // Close the file after download

    if (res == CURLE_OK)
    {
        std::cout << "Download successful." << std::endl;
    }
    else
    {
        std::cout << "Download failed: " << curl_easy_strerror(res) << std::endl;
    }

    // Clean up
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

// Extract Zip of downloaded game update from curl of Github repo
bool extract_zip(std::string zipFilePath)
{
    struct zip *zip_archive;
    struct zip_file *zip_file;
    struct zip_stat zip_stat;
    char buf[100];

    // Get the directory path from the zip_file_path
    std::filesystem::path zip_directory = std::filesystem::path(zipFilePath).parent_path();

    std::cout << "Starting Extract Zip function..." << std::endl;

    // Open the zip archive
    zip_archive = zip_open(zipFilePath.c_str(), ZIP_RDONLY, nullptr);
    if (zip_archive == nullptr)
    {
        std::cout << "Error opening zip archive." << std::endl;
        return false;
    }
    else
    {
        std::cout << "Zip archive opened successfully." << std::endl;
    }

    // Get the number of entries in the zip archive
    int num_entries = zip_get_num_entries(zip_archive, 0);
    std::cout << "Number of entries in the zip archive: " << num_entries << std::endl;

    // Extract each entry in the zip archive
    for (int i = 0; i < num_entries; i++)
    {
        // Get information about the current entry
        if (zip_stat_index(zip_archive, i, 0, &zip_stat) == 0)
        {
            // Get the name of the entry
            std::string entry_name = zip_get_name(zip_archive, i, 0);

            // Check if the entry is a directory
            bool is_directory = entry_name.back() == '/';

            // Create full output file path
            std::filesystem::path output_file_path = std::filesystem::path(zip_directory) / entry_name;

            if (!is_directory)
            {
                // If it's a file, open the entry
                zip_file = zip_fopen_index(zip_archive, i, ZIP_FL_UNCHANGED);
                if (zip_file == nullptr)
                {
                    std::cout << "Error opening file in zip archive." << std::endl;
                    zip_close(zip_archive);
                    return false;
                }
                else
                {
                    std::cout << "Opened entry " << i << " in the zip archive." << std::endl;
                }

                // Create directories if needed using filesystem
                std::filesystem::create_directories(output_file_path.parent_path());

                // Open the output file
                FILE *output_file = fopen(output_file_path.string().c_str(), "wb");
                if (output_file == nullptr)
                {
                    std::cout << "Error creating output file." << std::endl;
                    zip_fclose(zip_file);
                    zip_close(zip_archive);
                    return false;
                }
                else
                {
                    std::cout << "Created output file: " << output_file_path.string() << std::endl;
                }

                // Extract the current entry and write it to the output file
                zip_int64_t n;
                while ((n = zip_fread(zip_file, buf, sizeof(buf))) > 0)
                {
                    fwrite(buf, n, 1, output_file);
                }

                // Close the output file and the current entry
                fclose(output_file);
                zip_fclose(zip_file);

                std::cout << "Zip entry extracted successfully." << std::endl;
            }
            else
            {
                // If it's a directory, create the directory
                std::filesystem::create_directories(output_file_path);
                std::cout << "Created directory: " << output_file_path.string() << std::endl;
            }
        }
        else
        {
            std::cout << "Error getting information about zip entry." << std::endl;
            zip_close(zip_archive);
            return false;
        }
    }

    std::cout << "Game updates unzipped successful." << std::endl;

    // Close the zip archive
    zip_close(zip_archive);
    return true;
}

// Getting filepath to existing non updated folder "world-games"
std::string get_existing_game_folder_path()
{
    std::string filepath_separator = "";
    const char *home_directory = nullptr;
    std::string existing_game_directory_path = "";

    if (OSversion == "Windows")
    {
        filepath_separator = '\\';
        home_directory = getenv("USERPROFILE");
        existing_game_directory_path = std::string(home_directory) + filepath_separator + "world-games";
    }
    else if (OSversion == "linux" || OSversion == "Mac OS X")
    {
        filepath_separator = '/';
        home_directory = getenv("HOME");
        existing_game_directory_path = std::string(home_directory) + filepath_separator + "world-games";
    }
    else
    {
        std::cout << "Error: filepath to 'world-games' under users Home directory not found! " << std::endl;
    }
    return existing_game_directory_path;
}

// Getting filepath to unzipped folder "world-games-master"
std::string get_unzipped_game_destination_path()
{
    std::string filepath_separator = "";
    const char *home_directory = nullptr;
    std::string unzipped_game_destination_path = "";

    if (OSversion == "Windows")
    {
        filepath_separator = '\\';
        home_directory = getenv("USERPROFILE");
        unzipped_game_destination_path = std::string(home_directory) + filepath_separator + "world-games-master";
    }
    else if (OSversion == "linux" || OSversion == "Mac OS X")
    {
        filepath_separator = '/';
        home_directory = getenv("HOME");
        unzipped_game_destination_path = std::string(home_directory) + filepath_separator + "world-games-master";
    }
    else
    {
        std::cout << "Error: filepath to 'world-games-master' unzipped updated game folder under users Home directory not found! " << std::endl;
    }
    return unzipped_game_destination_path;
}

// Copy save from original game directory "world-games" to unzipped folder "world-games-master"
void copy_save_to_extracted_folder()
{
    std::cout << "STARTING - copy save from original directory to unzipped new updated game folder" << std::endl;

    std::filesystem::path sourceDirectory = get_existing_game_folder_path();
    std::filesystem::path sourcePath = sourceDirectory / "world-games_save.txt";
    std::filesystem::path destinationDirectory = get_unzipped_game_destination_path();
    std::filesystem::path destinationPath = destinationDirectory / "world-games_save.txt"; // Include the filename

    try
    {
        // Check if the source file exists
        if (std::filesystem::exists(sourcePath))
        {
            // Check if the destination file exists
            if (std::filesystem::exists(destinationPath))
            {
                // Delete the existing destination file
                std::filesystem::remove(destinationPath);
                std::cout << "Existing destination file deleted." << std::endl;
            }

            // Copy the file
            std::filesystem::copy_file(sourcePath, destinationPath, std::filesystem::copy_options::overwrite_existing);

            std::cout << "File copied successfully." << std::endl;
        }
        else
        {
            std::cerr << "Existing save file from non updated game directory not found." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Close existing world-games executable
void exit_game()
{
    std::cout << "STARTING - Close game" << std::endl;
    std::string windows_terrinate_process_command = "taskkill /F /IM main.exe";
    std::string unix_terrinate_process_command = "pkill main";

    if (OSversion == "Windows")
    {
        system(windows_terrinate_process_command.c_str());
    }
    else
    {
        system(unix_terrinate_process_command.c_str());
    }
}

// Function to delete a directory and its contents using the rmdir command
void delete_directory(const std::string &folderPath)
{
    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.is_directory())
        {
            // Check if the directory is hidden by checking its name
            if (!entry.path().filename().string().empty() && entry.path().filename().string()[0] == '.')
            {
                // Delete the hidden folder and its contents using the rmdir command
                std::string command = "rmdir /s /q \"" + entry.path().string() + "\"";
                int result = system(command.c_str());

                if (result == 0)
                {
                    std::cout << "Directory deleted: " << entry.path().string() << std::endl;
                }
                else
                {
                    std::cerr << "Error deleting directory: " << entry.path().string() << std::endl;
                }
            }
            else
            {
                delete_directory(entry.path().string());
            }
        }
        else if (entry.is_regular_file())
        {
            try
            {
                std::filesystem::remove(entry);
            }
            catch (const std::filesystem::filesystem_error &exception)
            {
                std::cerr << "Error deleting file: " << exception.what() << std::endl;
            }
        }
    }

    // Use the rmdir command to delete the current directory

    if (OSversion == "Windows")
    {
        std::string command = "rmdir /s /q \"" + folderPath + "\"";
        int result = system(command.c_str());

        if (result == 0)
        {
            std::cout << "Directory deleted: " << folderPath << std::endl;
        }
        else
        {
            std::cerr << "Error deleting directory: " << folderPath << std::endl;
        }
    }
    else
    {
        std::string command = "rm -r \"" + folderPath + "\"";
        int result = system(command.c_str());

        if (result == 0)
        {
            std::cout << "Directory deleted: " << folderPath << std::endl;
        }
        else
        {
            std::cerr << "Error deleting directory: " << folderPath << std::endl;
        }
    }
}

// Delete original game directory and its subdirectories
void delete_original_game_directory_subdirectories()
{
    std::cout << "STARTING - delete original game directory - subdirectories" << std::endl;
    std::cout << "Existing game folder to be deleted is: " << get_existing_game_folder_path() << std::endl;
    std::string existing_game_folder_path = get_existing_game_folder_path();

    // Call the recursive delete_directory function
    delete_directory(existing_game_folder_path);
}

// Delete original game directory
void delete_original_game_folder()
{
    std::cout << "STARTING - delete original game directory" << std::endl;
    std::cout << "Existing game folder to be deleted is: " << get_existing_game_folder_path() << std::endl;
    std::string existing_game_folder_path = get_existing_game_folder_path();

    if (OSversion == "Windows")
    {
        try
        {
            std::filesystem::remove_all(existing_game_folder_path); // Use remove_all to delete hidden folders as well
            std::cout << "Original game directory deleted." << std::endl;
        }
        catch (const std::filesystem::filesystem_error &exception)
        {
            std::cout << "Error deleting original game directory: " << exception.what() << std::endl;
        }
    }
    else if (OSversion == "linux" || OSversion == "Mac OS X")
    {
        std::cout << "delete original game directory Work in progress" << std::endl;
    }
}

// Rename unzipped new updated game folder "world-games-master" to "world-games"
void rename_extracted_folder()
{
    std::string worldgames_master_folder_path_old_name = get_unzipped_game_destination_path();
    std::string worldgames_master_folder_path_new_name = get_existing_game_folder_path();

    std::cout << "STARTING - rename unzipped folder to world-games" << std::endl;
    try
    {
        rename(worldgames_master_folder_path_old_name.c_str(), worldgames_master_folder_path_new_name.c_str());
        std::cout << "Unzipped folder sucessfully rename from 'world-games-master' to 'world-games'." << std::endl;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error renaming Unzipped folder from 'world-games-master' to 'world-games': " << e.what() << std::endl;
    }
}

// TEST THEN DEPLOY - Run CMAKE, to copy shortcut to desktop
void CMAKE_build()
{
    std::cout << "Running CMAKE build steps to copy shortcuts to desktop" << std::endl;
    if (OSversion == "Windows")
    {
        std::string scriptPath = "windows-add-icon.ps1";
        int result = system(("powershell.exe -ExecutionPolicy Bypass -File " + std::string(scriptPath)).c_str());
        if (result == 0)
        {
            std::cout << "Succesfully copied shortcut to users desktop" << std::endl;
        }
        else
        {
            std::cout << "Error: Failed to copy shortcut to users desktop" << std::endl;
        }
    }
    else if (OSversion == "linux" || OSversion == "Mac OS X")
    {
        std::cout << "CMAKE for Linux/MacOS Work in progress" << std::endl;
    }
}

// TEST THEN DEPLOY - Open new game executable or binary to complete update game step
void game_start()
{
    std::cout << "STARTING - Opening game executable or binary" << std::endl;
    std::string new_game_directory_path = get_existing_game_folder_path();
    std::string start_command;

    if (OSversion == "Windows")
    {
        start_command = "start \"\" \"" + new_game_directory_path + "\\world-games.exe\"";
        system(start_command.c_str());
    }
    else
    {
        start_command = "chmod +x \"" + new_game_directory_path + "/world-games.bin\"";
        system(start_command.c_str());
    }
}

void start_game_update(std::string urlPath, std::string downloadLink)
{
    // start_game_update() -> first called elsewhere e.g. in mouse_handles();
    // update_version_string_from_readme_file("README.md"); -> called in main
    clickedStartAppUpdate = true;
    start_curl(urlPath, downloadLink); // -> will call download_link() if prompted
    if (downloadUpdateSelected)
    {
        // Functions from header install_game.hpp
        extract_zip(zipFilePath);
        copy_save_to_extracted_folder();
        exit_game();
        delete_original_game_directory_subdirectories();
        rename_extracted_folder();
        CMAKE_build();
        game_start();
    }
}
