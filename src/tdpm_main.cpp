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
//bools
bool arch = "";
if defined(_WIN32) || defined (_WIN64)
bool libext = "dll";
else if defined(__APPLE__)
bool libext = "dylib";
else if
bool libext = "so";
endif


int main(int argc, char* args[]) {
    void* handle = dlopen("tdpm-pkg." + libext, RTLD_LAZY);
        if (!handle) {
           fprintf(stderr, "Error: %s\n", dlerror());
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
