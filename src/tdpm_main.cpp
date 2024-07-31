/*
 * tdpm_main.cpp
 * Purpose: Main entry to TDPM
 * Author(s): Vincent392
 */


//Includes
#include <stdio.h>
#include <cstring>
#include <iostream>
//consts
const char* pkgFile = nullptr;
//Library + Arch
#if defined(_WIN32) || defined(_WIN64)
    #define LIBRARY_EXTENSION "dll"
#elif defined(__APPLE__)
    #define LIBRARY_EXTENSION "dylib"
#else
    #define LIBRARY_EXTENSION "so"
#endif
#if defined(__x86_64__) || defined(_M_X64)
    return "x86_64";
#elif defined(__i386) || defined(_M_IX86)
    return "x86";
#elif defined(__arm__) || defined(_M_ARM)
    return "arm";
#elif defined(__aarch64__)
    return "aarch64";
#else
    return "unknown";
#endif


int main(int argc, char* args[]) {
    void* handle = popen("tdpm-pkg" + ARCHITECTURE + "." + LIBRARY_EXTENSION, RTLD_LAZY);
        if (!handle) {
           printf(stderr, "Error: %s\n", perror());
           return 1;
}        
//Command Line Arguments, we need these
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(args[i], "help") == 0) {
           //showhelp()
        } else if (std::strcmp(args[i], "install") == 0) {
            if (i + 1 < argc) {
                pkgFile = args[i + 1];
                i++;
            } else {
                printf("Error\nno package selected for installation\n");
            }
        } else if (std::strcmp(args[i], "uninstall") == 0) {
            if (i + 1 < argc) {
                pkgFile = args[i + 1];
                i++;
            } else {
                printf("Error\nno package selected for uninstallation\n");
            }
        } else {
         printf("Error -01");
         printf("No command line argument specified\n");
         printf("Type \"Help\" to view them all.\n");
         return -01;
        }
    }
}

//void showhelp() {

//}
