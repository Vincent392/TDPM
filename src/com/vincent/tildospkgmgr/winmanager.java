package com.vincent.tildospkgmgr;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class winmanager {

    public static void main(String[] args) {
        System.out.println("Til Dos package manager");
        System.out.println("Version 0.1.0");
        System.out.println("=======================");
        System.out.println("What do you want to do?");
        System.out.println("1. Install package");
        System.out.println("2. List installed packages");

        // TODO Auto-generated method stub
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("> "); // Print a prompt
            String input = scanner.nextLine(); // Read user input

            // Check for exit command
            if (input.equalsIgnoreCase("exit")) {
                System.out.println("Exiting the package manager...");
                break; // Exit the loop
            }

            // Process the input command
            processCommand(input);
        }

        scanner.close();
    }

    private static void processCommand(String command) {
        // Split the command into tokens
        String[] tokens = command.split("\\s+");

        // Perform different actions based on the command
        switch (tokens[0]) {
            default:
                System.out.println("Command invalid, this is a package manager, not the command line.");
                break;
            case "1":
                installpkg();
                break;
            case "2":
                System.out.println("Listing installed packages...");
                pkglistall();
                break;
        }
    }

    private static void installpkg() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("What package would you like to install?");
        String packageName = null;
        try {
            packageName = reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }

        ProcessBuilder pb = new ProcessBuilder("choco", "install", packageName, "-y");
        pb.inheritIO();
        try {
            Process process = pb.start();
            int exitCode = process.waitFor();
            if (exitCode == 0) {
            	System.out.println("----------------------------------------");
                System.out.println("Package was installed successfully from Chocolatey.");
                System.exit(0);
            } else {
            	System.out.println("----------------------------------------");
                System.out.println("Package didn't install from Chocolatey, trying scoop.");
            }
        } catch (Exception e) {
      	  System.exit(1);
        }
            
       ProcessBuilder pb2 = new ProcessBuilder("scoop install", packageName);
       pb2.inheritIO();
        
       try {
           Process process2 = pb2.start();
           int exitCode2 = process2.waitFor();
           if (exitCode2 == 0) {
           	System.out.println("----------------------------------------");
               System.out.println("Package was installed successfully from Scoop.");
               System.exit(0);
           } else {
           	System.out.println("----------------------------------------");
               System.out.println("Package didn't install from Scoop, trying winget.");
           }
       } catch (Exception e)
       {
    	  System.exit(1);
       }
       
       ProcessBuilder pb3 = new ProcessBuilder("scoop install", packageName);
       pb3.inheritIO();
        
       try {
           Process process3 = pb3.start();
           int exitCode3 = process3.waitFor();
           if (exitCode3 == 0) {
           	System.out.println("----------------------------------------");
               System.out.println("Package was installed successfully from Winget.");
               System.exit(0);
           } else {
           	System.out.println("----------------------------------------");
               System.out.println("Package didn't install from Winget.");
               System.out.println("No packages were installed");
           }
       } catch (Exception e)
       {
    	  System.exit(1);
       }
    }
    
    private static void pkglistall() {
    	System.out.println("Packages installed from Chocolatey.");
    	System.out.println("-----------------------------------");
        ProcessBuilder pb1 = new ProcessBuilder("choco list");
        try {
            Process process1 = pb1.start();
            int exitCode1 = process1.waitFor();
            if (exitCode1 == 0) {
            
            } else {
            	System.out.println("what.");
            }
        } catch (Exception e) {
        	
        }
        ProcessBuilder pb21 = new ProcessBuilder("scoop list");       
        System.out.println("Packages installed from scoop");
        try {
            Process process21 = pb21.start();
            int exitCode21 = process21.waitFor();
            if (exitCode21 == 0) {
            
            } else {
            	System.out.println("what.");
            }
        } catch (Exception e) {
        	
        }
        ProcessBuilder pb31 = new ProcessBuilder("winget list");       
        System.out.println("Packages installed from winget");
        try {
            Process process31 = pb31.start();
            int exitCode31 = process31.waitFor();
            if (exitCode31 == 0) {
            
            } else {
            	System.out.println("what.");
            }
        } catch (Exception e) {
        	
        }
    }
}
