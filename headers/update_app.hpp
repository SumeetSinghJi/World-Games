/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++11
    Purpose: Declaration/Definition file combined
    License: MIT License
    Description: Declaration and Definition file for using curl to read website i.e, World games github
    then find the version number from the README.md string "Version: x.x". Compare the version number
    online with local offline version then prompt user if offline software out of date to update.
    curl.h will download the git .zip file, then zip.h will extract. Remainder of code related to
    copying over save file from old directory to new folder, existing the open application, deleting
    the old directory and starting the new folder executable.

    Example:
    1. Set variable UpdateApp_sourceDirectory to existing game directory e.g. UpdateApp_sourceDirectory = "C:/Users/Sumeet/Documents/World-Games";
    2. call function: update_version_string_from_readme_file(std::string fileWithVersionString); with parameters below
    fileWithVersionString = local file e.g. .txt/.md with string "Version: " to populate return variable currenVersion;
    3. call function: start_application_update(std::string urlPath, std::string downloadLink); with 2 parameters;
    urlPath = remote file e.g. .txt/.md with string "Version: " to curl and compare remoteVersion with updateApp_currentVersion;
    downloadLink = full .zip file URL of app
    e.g. start_application_update("https://github.com/SumeetSinghJi/world-games", "./src/curl/bin/curl-ca-bundle.crt", "https://github.com/SumeetSinghJi/world-games/archive/refs/heads/master.zip");
    4. variable/API updateApp_newVersionAvailable will trigger true during start_application_update() if new update available
    5. Manually setting variable updateApp_startUpdate to true will continue remainder of update process, closing app, copying save, and restarting
*/

#pragma once

#include <iostream>
#include <curl.h>  // for downloading latest application from Github
#include <cstdio>  // for curl functions
#include <cstring> // for curl functions
#include <cstdlib> // multiplatform e.g. std::system("pkill") to run system commands e.g terminate app,
#ifdef _WIN32
#include <winsock2.h> // For curling on Windows
#endif
#include <zip.h>      // for unzipping downloaded application from GitHub/source repo
#include <fstream>    // multiplatform method for for file open read write objects
#include <filesystem> // multiplatform method for creating and deleting directories (folders)
#include <string>     // For getline()
#include <cstdlib>    // multiplatform e.g. std::system("pkill") to run system commands e.g terminate app,

#ifdef _WIN32
const std::string updateApp_OSversion = "Windows";
const std::string updateApp_curl_bin_path = "./src/curl/bin/curl.exe";
#elif __APPLE__
const std::string updateApp_OSversion = "Mac OS X";
const std::string updateApp_curl_bin_path = "./src/curl/bin/curl.bin";
#elif __linux__
const std::string updateApp_OSversion = "Linux";
const std::string updateApp_curl_bin_path = "./src/curl/bin/curl";
#else
const std::string updateApp_OSversion = "Unknown";
const std::string updateApp_curl_bin_path = "./src/curl/bin/curl.exe";
#endif

// GLOBAL VARIABLES
const std::string updateApp_certPath = "./src/curl/bin/curl-ca-bundle.crt";
std::string UpdateApp_sourceDirectory  = ""; // Game installation path set in main code
std::string updateApp_zipFilePath = ""; // set by set_zip_file_name();
std::string UpdateApp_sourceParentDirectory = ""; // set by set_parent_directory_file_path();
std::string UpdateApp_downloadLink = "";
std::string updateApp_currentVersion; // API for rendering current version of app to console/screen
bool updateApp_newVersionAvailable = false; // API to render to console/screen "new version available" then set "updateApp_startUpdate = true" to start update.
bool updateApp_startUpdate = false; // API that works together with variable above "updateApp_newVersionAvailable"
double updateApp_downloadProgress = 0.0;
bool updateApp_showProgress = false;

// Callback function to handle the response received from the website
size_t cout_curl_response_to_terminal(void *contents, size_t size, size_t nmemb, std::string *output)
{
    size_t total_size = size * nmemb;
    output->append(static_cast<char *>(contents), total_size);
    return total_size;
}

// Callback function to write the downloaded data to a file
size_t WriteCallback(void *contents, size_t size, size_t nmemb, FILE *file)
{
    return fwrite(contents, size, nmemb, file);
}

// Callback function to display progress
int XferInfoCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    if (updateApp_showProgress)
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
                updateApp_currentVersion = line.substr(9);
            std::cout << "Current Version is: " << updateApp_currentVersion << std::endl;
        }

        readme_object.close();
        readme_object.clear();
    }
    else
    {
        std::cerr << "Error: Unable to open: " << fileWithVersionString << " file to find version number string" << std::endl;
    }
    return updateApp_currentVersion;
}

// Start Curl to world-games Github to check for updates
bool start_curl(std::string urlPath)
{
    /* Purpose

    1. Function update_version_string_from_readme_file() called to populate global variable: updateApp_currentVersion
    from reading existing directory readme.md string version number
    2. This function will connect to a website, and search for string "Version: " and find the trailing
    numbers then update the global variables remoteVersionDouble
    3. If remote version is greater then local version prompt will appear to download zip.
    4. Remainder of steps called in start_application_update()
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
        curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, updateApp_curl_bin_path.c_str());

        // Step 2 - Set CA cert path
        curl_easy_setopt(curl, CURLOPT_CAINFO, updateApp_certPath.c_str());

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
                double updateApp_currentVersionDouble = stod(updateApp_currentVersion);
                double remoteVersionDouble = stod(versionNumber);

                if (remoteVersionDouble <= updateApp_currentVersionDouble)
                {
                    std::cout << "Current version: " << updateApp_currentVersionDouble << " , is already up to date." << std::endl;
                    updateApp_newVersionAvailable = false;
                }
                else
                {
                    // 1 - If the application is out of date, prompt to download the latest version
                    std::cout << "Current version is: " << updateApp_currentVersionDouble << ", New version available is: " << remoteVersionDouble << std::endl;
                    updateApp_newVersionAvailable = true;
                }
                curl_easy_cleanup(curl);
                curl_global_cleanup();
                return true;
            }
            else
            {
                std::cout << "Couldn't find string 'Version: ' in online repo README.md application update stopping." << std::endl;
            }
        }
        else
        {
            std::cout << "Error: curl failed: " << curl_easy_strerror(res) << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Failed to initialize curl." << std::endl;
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return false;
}

// download update file from start_curl() prompt
bool download_file(std::string downloadLink)
{
    std::cout << "Attempting to download updates for world-games." << std::endl;

    CURL *curl;
    CURLcode res;
    FILE *file = fopen(updateApp_zipFilePath.c_str(), "wb");

    if (!file)
    {
        std::cout << "Error: Cannot open file for writing." << std::endl;
        return false;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (!curl)
    {
        std::cout << "Error: Cannot initialize curl." << std::endl;
        fclose(file);
        return false;
    }
    // Step 1 - Configure curl with curl.exe path
    curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, 1L); // Set this to avoid converting slashes
    curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, updateApp_curl_bin_path.c_str());

    // Step 2 - Set CA cert path
    curl_easy_setopt(curl, CURLOPT_CAINFO, updateApp_certPath.c_str());

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
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return true;
    }
    else
    {
        std::cout << "Download failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return false;
    }

    // Clean up
    // curl_easy_cleanup(curl);
    // curl_global_cleanup();
}

// Extract Zip of downloaded application update from curl of Github repo
bool extract_zip()
{
    struct zip *zip_archive;
    struct zip_file *zip_file;
    struct zip_stat zip_stat;
    char buf[100];

    // Construct the full path to the zip file
    std::string full_zip_file_path = UpdateApp_sourceParentDirectory + updateApp_zipFilePath;

    // Get the directory path from the zip_file_path
    std::filesystem::path zip_directory = std::filesystem::path(full_zip_file_path).parent_path();

    std::cout << "Starting Extract Zip function..." << std::endl;

    // Open the zip archive
    zip_archive = zip_open(full_zip_file_path.c_str(), ZIP_RDONLY, nullptr);
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

    std::cout << "application updates unzipped successful." << std::endl;

    // Close the zip archive
    zip_close(zip_archive);
    return true;
}

// Get parent directory from sourceDirectory
bool set_parent_directory_file_path() {
    // Assuming UpdateApp_sourceDirectory is "C:/Users/Sumeet/Documents/World-Games"
    size_t lastSeparatorPos = UpdateApp_sourceDirectory.find_last_of("/\\");

    // Check if the separator was found
    if (lastSeparatorPos != std::string::npos) {
        // Remove everything after the last separator (including the separator itself)
        UpdateApp_sourceParentDirectory = UpdateApp_sourceDirectory.substr(0, lastSeparatorPos);
    }
    return true;
}

// Get zip file name from downloadLink
bool set_zip_file_name(std::string downloadLink) {
    // Assuming UpdateApp_sourceDirectory is "C:/Users/Sumeet/Documents/World-Games"
    size_t lastSeparatorPos = downloadLink.find_last_of("/\\");

    // Check if the separator was found
    if (lastSeparatorPos != std::string::npos) {
        // Remove everything after the last separator (including the separator itself)
        updateApp_zipFilePath = UpdateApp_sourceDirectory.substr(0, lastSeparatorPos);
    }
    return true;
}

// from UpdateApp_sourceDirectory set UpdateApp_destinationDirectory
std::string get_unzipped_application_file_path()
{
    // Assuming UpdateApp_sourceDirectory is "C:/Users/Sumeet/Documents/World-Games"
    std::string UpdateApp_destinationDirectory = UpdateApp_sourceDirectory;

    // Find the last occurrence of the directory separator
    size_t lastSeparatorPos = UpdateApp_destinationDirectory.find_last_of("/\\");
    
    // Check if the separator was found
    if (lastSeparatorPos != std::string::npos) {
        // Remove everything after the last separator (including the separator itself)
        UpdateApp_destinationDirectory = UpdateApp_destinationDirectory.substr(0, lastSeparatorPos);
    }
    // Append "world-games-master" to the destination directory
    UpdateApp_destinationDirectory += "/world-games-master";

    return UpdateApp_destinationDirectory;
}

// Copy save from original application directory "world-games" to unzipped folder "world-games-master"
bool copy_save_to_extracted_folder()
{
    std::cout << "STARTING - copy save from original directory to unzipped new updated application folder" << std::endl;

    std::filesystem::path sourcePath = std::filesystem::path(UpdateApp_sourceDirectory) / "world-games_save.txt";
    std::filesystem::path destinationDirectory = get_unzipped_application_file_path();
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
            return true;
        }
        else
        {
            std::cerr << "Existing save file from non updated application directory not found." << std::endl;
            return false;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

// Close existing world-games executable
bool exit_application()
{
    std::cout << "STARTING - Close application" << std::endl;
    std::string windows_terrinate_process_command = "taskkill /F /IM main.exe";
    std::string unix_terrinate_process_command = "pkill main";

    if (updateApp_OSversion == "Windows")
    {
        system(windows_terrinate_process_command.c_str());
    }
    else
    {
        system(unix_terrinate_process_command.c_str());
    }
    return true;
}

// Function to delete a directory and its contents using the rmdir command
bool delete_directory(const std::string &folderPath)
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

    if (updateApp_OSversion == "Windows")
    {
        std::string command = "rmdir /s /q \"" + folderPath + "\"";
        int result = system(command.c_str());

        if (result == 0)
        {
            std::cout << "Directory deleted: " << folderPath << std::endl;
            return true;
        }
        else
        {
            std::cerr << "Error deleting directory: " << folderPath << std::endl;
            return false;
        }
    }
    else
    {
        std::string command = "rm -r \"" + folderPath + "\"";
        int result = system(command.c_str());

        if (result == 0)
        {
            std::cout << "Directory deleted: " << folderPath << std::endl;
            return true;
        }
        else
        {
            std::cerr << "Error deleting directory: " << folderPath << std::endl;
            return false;
        }
    }
}

// Delete original application directory and its subdirectories
bool delete_original_application_directory_subdirectories()
{
    std::cout << "STARTING - delete original application directory - subdirectories" << std::endl;
    std::cout << "Existing application folder to be deleted is: " << UpdateApp_sourceDirectory << std::endl;

    // Call the recursive delete_directory function
    delete_directory(UpdateApp_sourceDirectory);
    return true;
}

// Delete original application directory
bool delete_original_application_folder()
{
    std::cout << "STARTING - delete original application directory" << std::endl;
    std::cout << "Existing application folder to be deleted is: " << UpdateApp_sourceDirectory << std::endl;

    if (updateApp_OSversion == "Windows")
    {
        try
        {
            std::filesystem::remove_all(UpdateApp_sourceDirectory); // Use remove_all to delete hidden folders as well
            std::cout << "Original application directory deleted." << std::endl;
        }
        catch (const std::filesystem::filesystem_error &exception)
        {
            std::cout << "Error deleting original application directory: " << exception.what() << std::endl;
        }
    }
    else if (updateApp_OSversion == "linux" || updateApp_OSversion == "Mac OS X")
    {
        std::cout << "delete original application directory Work in progress" << std::endl;
    }
    return true;
}

// Rename unzipped new updated application folder "world-games-master" to "world-games"
bool rename_extracted_folder()
{
    std::string newDirectory = get_unzipped_application_file_path();

    std::cout << "STARTING - rename unzipped folder to world-games" << std::endl;
    try
    {
        rename(newDirectory.c_str(), UpdateApp_sourceDirectory.c_str());
        std::cout << "Unzipped folder sucessfully renamed from 'world-games-master' to 'world-games'." << std::endl;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error renaming Unzipped folder from 'world-games-master' to 'world-games': " << e.what() << std::endl;
    }
    return true;
}

// FUTURE DEVELOPMENT - Run CMAKE, to copy shortcut to desktop
bool CMAKE_build()
{
    std::cout << "Running CMAKE build steps to copy shortcuts to desktop" << std::endl;
    return true;
}

// Open new application executable or binary to complete update application step
bool application_start()
{
    std::cout << "STARTING - Opening application executable or binary" << std::endl;
    std::string new_application_directory_path = UpdateApp_sourceDirectory;
    std::string start_command;

    if (updateApp_OSversion == "Windows")
    {
        start_command = "start \"\" \"" + new_application_directory_path + "\\world-games.exe\"";
        system(start_command.c_str());
    }
    else
    {
        start_command = "chmod +x \"" + new_application_directory_path + "/world-games.bin\"";
        system(start_command.c_str());
    }
    return true;
}

// If all functions return true, write to save-file, applicationupdated
void set_application_updated_variable()
{
    std::string updateApp_currentVersion = update_version_string_from_readme_file("README.md");

    std::ofstream savefile_object("world-games_save.txt");

    if (savefile_object.is_open())
    {
        savefile_object << "application successfully updated to version: " << updateApp_currentVersion;
        savefile_object.close();
    }
    else
    {
        std::cerr << "Error: Unable to open save file." << std::endl;
    }
}

// Call to start program after setting UpdateApp_sourceDirectory = "" && update_version_string_from_readme_file("");
void start_application_update(std::string urlPath, std::string downloadLink)
{
    start_curl(urlPath);
    if (updateApp_startUpdate)
    {
        if (set_parent_directory_file_path() &&
            set_zip_file_name(downloadLink) &&
            download_file(downloadLink) &&
            extract_zip() &&
            copy_save_to_extracted_folder() &&
            exit_application() &&
            delete_original_application_directory_subdirectories() &&
            rename_extracted_folder() &&
            CMAKE_build() &&
            application_start())
        {
            set_application_updated_variable();
        }
    }
}
