/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++11
    Purpose: Declaration/Definition file combined
    License: MIT License
    Description: read the attached help.txt file
*/

#pragma once

#include <iostream>
// #include <curl.h>     // for downloading latest game from Github
#include "../src/curl/include/curl/curl.h"
#include <cstdio>
#include <cstring>
#include <cstdlib> // multiplatform e.g. std::system("pkill") to run system commands e.g terminate app,
#ifdef _WIN32
#include <winsock2.h> // For curling on Windows
#endif

// FUNCTION PROTOTYPE
void download_file();

// GLOBAL VARIABLES
extern std::string currentVersion;
extern std::string osVersion;
extern std::string zipFilePath;
double download_progress = 0.0;
bool show_progress = false;
double currentVersionDouble;
double remoteVersionDouble;

// This function reads the README.md to find the current version, to compare with online repo latest version
std::string update_version_string_from_readme_file()
{
    std::fstream readme_object;
    std::string version = "";
    readme_object.open("README.md", std::ios::in);
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
        std::cerr << "Error: Unable to open README.md file to find version." << std::endl;
    }
    return currentVersion;
}

// Set curl executable or bin path by OS
std::string set_curl_executable_or_bin_path()
{
    std::string filepath_separator = "";
    std::string curl_path = "";
    const char *home_directory = nullptr;

    if (osVersion == "Windows")
    {
        filepath_separator = '\\';
        home_directory = getenv("USERPROFILE"); // Windows uses USERPROFILE for the home directory
        curl_path = std::string(home_directory) + filepath_separator + "Documents" + filepath_separator + "world-games" + filepath_separator + "src" + filepath_separator + "curl" + filepath_separator + "bin" + filepath_separator + "curl.exe";
    }
    else if (osVersion == "linux" || osVersion == "Mac OS X")
    {
        filepath_separator = '/';
        home_directory = getenv("HOME"); // linux and macOS use HOME for the home directory
        // curl_path = std::string(home_directory) + filepath_separator + "world-games" + filepath_separator + "curl" + filepath_separator + "bin" + filepath_separator + "curl";
    }
    else
    {
        std::cout << "Error: Host OS Home directory folder cannot be found" << std::endl;
    }
    std::cout << "Curl binary/executable path set to: " << curl_path << std::endl;
    return curl_path;
}

// Set path to download game updates to
std::string save_path_for_zip()
{
    std::string filepath_separator = "";
    const char *home_directory = nullptr;

    if (osVersion == "Windows")
    {
        filepath_separator = '\\';
        home_directory = getenv("USERPROFILE"); // Windows uses USERPROFILE for the home directory
        zipFilePath = std::string(home_directory) + filepath_separator + "world-games_updates.zip";
    }
    else if (osVersion == "linux" || osVersion == "Mac OS X")
    {
        filepath_separator = '/';
        home_directory = getenv("HOME"); // linux and macOS use HOME for the home directory
        zipFilePath = std::string(home_directory) + filepath_separator + "world-games_updates.zip";
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
void start_curl()
{
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl)
    {
        std::cout << "Success: Curl initialised." << std::endl;
        curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/SumeetSinghJi/world-games");

        // Step 1 - Configure curl with curl.exe path
        std::string curl_path = set_curl_executable_or_bin_path(); // Get the curl executable path
        if (!curl_path.empty())
        {
            curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, 1L); // Set this to avoid converting slashes
            curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, curl_path.c_str());
        }

        /*
        Important: To prevent man in the middle attacks.
        To enable libcurl to verify remote server SSL certificate you must point
        curl to a existing .crt that contains a bunch of trusted famous CA's.

        Curl provides one such certificate bundled within the ./bin folder e.g. here: src\curl\bin\curl-ca-bundle.crt
        curl must be set to use this CA.

        Note this can be bypassed for testing purpose only by replacing the below commands with only these 2 commands
        which will bypass curl verifying remote server certificate
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // Disable SSL certificate verification
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); // Disable hostname verification
        */
        curl_easy_setopt(curl, CURLOPT_CAINFO, "./src/curl/bin/curl-ca-bundle.crt");

        // Store the response in a string
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cout_curl_response_to_terminal);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        std::cout << "Status: Now starting to curl https://github.com/SumeetSinghJi/world-games" << std::endl;

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
            "Ensure no bullet point in front of word in online page. e.g. Version: 1.0" << std::endl;
            
            if (version_pos != std::string::npos)
            {
                version_pos += version_tag.length(); // Move past the "Version: " string

                // Find the position of the first non-numeric character in the version number
                size_t non_numeric_pos = response.find_first_not_of("0123456789.", version_pos);

                // Keep only the numeric part of the version number
                std::string versionNumber = response.substr(version_pos, non_numeric_pos - version_pos);

                // Convert version strings to double
                currentVersionDouble = stod(currentVersion);
                remoteVersionDouble = stod(versionNumber);

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
                        show_progress = true; // Enable progress display
                        download_file();
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
            std::cout << "Manually download latest game version from here: https://github.com/SumeetSinghJi/world-games" << std::endl;
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
void download_file()
{
    std::cout << "Attempting to download updates for world-games." << std::endl;

    CURL *curl;
    CURLcode res;
    std::string download_link = "https://github.com/SumeetSinghJi/world-games/archive/refs/heads/master.zip";
    std::string save_path = save_path_for_zip();
    std::string curl_path = set_curl_executable_or_bin_path(); // Get the curl executable path
    FILE *file = fopen(save_path.c_str(), "wb");

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
    // Step 1 - set curl to use the custom curl path for portability (if not macOS)
    if (!curl_path.empty() && osVersion != "Mac OS X")
    {
        curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, 1L); // Set this to avoid converting slashes
        curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, curl_path.c_str());
    }

    /*
        Important: To prevent man in the middle attacks.
        To enable libcurl to verify remote server SSL certificate you must point
        curl to a existing .crt that contains a bunch of trusted famous CA's.

        Curl provides one such certificate bundled within the ./bin folder e.g. here: src\curl\bin\curl-ca-bundle.crt
        curl must be set to use this CA.

        Note this can be bypassed for testing purpose only by replacing the below commands with only these 2 commands
        which will bypass curl verifying remote server certificate
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // Disable SSL certificate verification
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); // Disable hostname verification
        */
    curl_easy_setopt(curl, CURLOPT_CAINFO, "./src/curl/bin/curl-ca-bundle.crt");

    curl_easy_setopt(curl, CURLOPT_URL, download_link.c_str());

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
