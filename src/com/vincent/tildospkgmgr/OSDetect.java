package com.vincent.tildospkgmgr;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import com.vincent.tildospkgmgr.*;

public class OSDetect {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	  /**
	  * Authors: Vincent392
	  * Purpose: Detect the Operating System before running anything.
	  */
		
	  String[] blkargs = null;
	  String osName = System.getProperty("os.name").toLowerCase();
	  String osVersion = System.getProperty("os.version").toLowerCase();
		    
	  if (osName.contains("Windows")) {
		  if(osVersion.contains("5.1")) {
			  System.out.println("SECURTY RISK: YOUR OS IS WINDOWS XP, THIS APP MIGHT NOT WORK BUT YOU CAN TRY ANYWAY\nPress any key to continue...");
			  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			  try {
				br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.exit(1);
			}
		  if(osVersion.contains("6.0")) {
			  System.out.println("SECURTY RISK: YOUR OS IS WINDOWS VISTA, THIS APP MIGHT NOT WORK BUT YOU CAN TRY ANYWAY\nPress any key to continue...");
			  BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
			  try {
				br1.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.exit(1);
			}
			
			System.out.println("Windows Kernel version:" + osVersion);
			 
			 winmanager.main(blkargs);
		  }
		  
		  }
	  } else if(osName.contains("mac")) {
		  System.out.println("Warning: due to how apple breaks userspace (seemingly) every 5 minutes, this might not work");
	  } else if(osName.contains("linux")) {
		  System.out.println("OS: Linux Name" + osName + "Kernel:" + osVersion + "There's a chance this is running under distrobox\nBut anyway, we're gonna run ALOT of package managers.");
	      
	  }
	  else if (osName.contains("steamos")) {
		  System.out.println("Nope, were relaunching under an Arch distrobox instance");
		  //borrowed code from https://github.com/K-Launcher/K-L/blob/c351a6cc519f80e19f11d6207cd3a3626a270ec7/Source-1.1(dev-reset)/src/K/Launcher/WindowsTM.java#L112
	        try {
	            Runtime runTime = Runtime.getRuntime();
	            
	            String executablePath;
	            executablePath = "distobox";
	            
	            runTime.exec(executablePath);
	        } catch (IOException o) {
	        	System.out.println("Well, it's broken. or the user doesn't have distrobox installed.");
				  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				  try {
	        	br.readLine();
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						System.exit(1);
					}
	        }
	  }
	}

}
