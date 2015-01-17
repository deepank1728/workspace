package com.androidexample.gcm;

public interface Config {

	
	// CONSTANTS
	 //static final String Address="player1728.byethost7.com";
	static final String Address="androidproject.byethost18.com";
	//static final String Address="10.0.2.2";
	static final String YOUR_SERVER_URL =  "http://"+Config.Address+"/gcm_server_files/register.php";
	// YOUR_SERVER_URL : Server url where you have placed your server files
    // Google project id
    static final String GOOGLE_SENDER_ID = "728733539161";  // Place here your Google project id
    
    /**
     * Tag used on log messages.
     */
    static final String TAG = "College Stats";

    static final String DISPLAY_MESSAGE_ACTION =
            "com.androidexample.gcm.DISPLAY_MESSAGE";

    static final String EXTRA_MESSAGE = "message";
    
 		
	
}
