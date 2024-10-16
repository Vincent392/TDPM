/*
 * tdpm_main.cpp
 * Purpose: Main entry to TDPM
 * Author(s): Vincent392
 */

// Includes
#include <SDL2/SDL.h>
#include <stdio.h>
#include <cstring>
#include <iostream>

// Constants
const char* pkgFile = nullptr;

// Library Extension on platforms
#if defined(_WIN32) || defined(_WIN64)
    #define LIBRARY_EXTENSION "dll"
#elif defined(__APPLE__)
    #define LIBRARY_EXTENSION "dylib"
#else
    #define LIBRARY_EXTENSION "so"
#endif

void showHelp() {
    std::cout << "TDPM - Til Dos Package Manager\n";
    std::cout << "Usage:\n";
    std::cout << "  install <package>   Install a package\n";
    std::cout << "  uninstall <package> Uninstall a package\n";
    std::cout << "  help                Show this help message\n"
    std::cout << "  ver                 Show the TDPM version\n"
}

void installPackage(const char* pkgFile) {
    // Load the tdpm-pkg library
    std::string libraryPath = std::string("tdpm-pkg.") + LIBRARY_EXTENSION;

    if (SDL_Init(0) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return;
    }

    void* handle = SDL_LoadObject(libraryPath.c_str());
    if (!handle) {
        SDL_Log("Failed to load tdpm-pkg library: %s", SDL_GetError());
        SDL_Quit();
        return;
    }

    // Load the 'install_package' function from tdpm-pkg library
    typedef void (*InstallPackageFunc)(const char*);
    InstallPackageFunc installFunc = (InstallPackageFunc)SDL_LoadFunction(handle, "install_package");
    if (!installFunc) {
        SDL_Log("Failed to load 'install_package' function: %s", SDL_GetError());
        SDL_UnloadObject(handle);
        SDL_Quit();
        return;
    }

    // Call the install_package function to install the package
    installFunc(pkgFile);

    // Unload the library and quit SDL
    SDL_UnloadObject(handle);
    SDL_Quit();
}

int main(int argc, char* args[]) {
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(args[i], "help") == 0) {
            showHelp();
            return 0;
        } else if (std::strcmp(args[i], "install") == 0) {
            if (i + 1 < argc) {
                pkgFile = args[i + 1];
                installPackage(pkgFile);
                i++;
            } else {
                std::cerr << "Error: No package selected for installation\n";
                return 1;
            }
        } else if (std::strcmp(args[i], "uninstall") == 0) {
            if (i + 1 < argc) {
                pkgFile = args[i + 1];
                std::cout << "Uninstalling package: " << pkgFile << std::endl;
                // Implement uninstall logic, later.
                i++;
            } else {
                std::cerr << "Error: No package selected for uninstallation\n";
                return 1;
            }
        } else {
            std::cerr << "Error -01: No command-line argument specified\n";
            std::cerr << "Type \"help\" to view available commands.\n";
            return -1;
        }
    }

    return 0;
}