/*
 * tdpm_main.cpp
 * Purpose: Main entry to TDPM
 * Author(s): Vincent392
 */


//Includes
#include <stdio.h>
#include <iostream>

int main() {
//Command Line Arguments, we need these
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(args[i], "help") == 0) {
           showhelp()
        } else if (std::strcmp(args[i], "install") == 0) {

        } else if (std::strcmp(args[i], "uninstall") == 0) {

        } else {
         Printf("Error 01");
         Printf("No command line argument specified\n");
         Printf("Type \"Help\" to view them all.\n");
         return E01;
        }
}

void showhelp() {

}