/*
 * tdpm_main.cpp
 * Purpose: Main entry to TDPM
 * Author(s): Vincent392
 */


//Includes
#include <stdio.h>
#include <cstring>
#include <iostream>

int main(int argc, char* args[]) {
//Command Line Arguments, we need these
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(args[i], "help") == 0) {
           showhelp()
        } else if (std::strcmp(args[i], "install") == 0) {

        } else if (std::strcmp(args[i], "uninstall") == 0) {

        } else {
         printf("Error 01");
         printf("No command line argument specified\n");
         printf("Type \"Help\" to view them all.\n");
         return E01;
        }
}

void showhelp() {

}