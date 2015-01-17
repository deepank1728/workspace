package com.androidexample.gcm;

import java.util.ArrayList;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Looper;
import android.util.Log;

import com.google.android.gcm.GCMBaseIntentService;

public class GCMIntentService extends GCMBaseIntentService {

	private static final String TAG = "GCMIntentService";
	
	private Controller aController = null;
	
	String table_names[];
    String table_names_directory[];
    ArrayList<String> name2;
	 SharedPreferences sharedPref;
		String filename="deepank";
	 private SQLiteDatabase ourdatabase;
    public GCMIntentService() {
    	// Call extended class Constructor GCMBaseIntentService
        super(Config.GOOGLE_SENDER_ID);
        table_names=new String[7];
        table_names[0]="comp_company";
        table_names[1]="chem_company";
        table_names[2]="civil_company";
        table_names[3]="mech_company";
        table_names[4]="tronics_company";
        table_names[5]="electrical_company";
        table_names[6]="meta_company";
        
        
        table_names_directory=new String[7];
	    table_names_directory[0]="director";
	    table_names_directory[1]="dean";
	    table_names_directory[2]="section";
	    table_names_directory[3]="departments";
	    table_names_directory[4]="centers";
	    table_names_directory[5]="hostel";
	    table_names_directory[6]="others";
    }

    /**
     * Method called on device registered
     **/
    @Override
    protected void onRegistered(Context context, String registrationId) {
    	
    	//Get Global Controller Class object (see application tag in AndroidManifest.xml)
    	Log.i("Registration id",registrationId);
    	if(aController == null)
           aController = (Controller) getApplicationContext();
    	 
    	 if( RegisterActivity.temp==1)
		    {
		    	
		    	
		    	Thread t1=new Thread(){
		    		
		    		public void run()
		    		{
		    			Looper.prepare();
		    			 Database_functions df=new Database_functions(GCMIntentService.this);
			 		    	df.open();
			 		    	
			 		    	for(int i=0;i<7;i++)
			 		    	{
			 		    			df.update_databaseptp(table_names[i]);
			 		    			try{
			 		    				//sleep(1000);
			 		    			}
			 		    			catch(Exception e)
			 		    			{}
			 		    	}
			 		    	df.close();
			 		    	
					 		    Looper.loop();
		    		}
		    		
		    		
		    	};
		    			
		 		   // t1.start();
		 		    
		 		   
		 		   Thread t2=new Thread(){
		 		    	
		 		    	public void run()
		 		    	{
		 		    		Looper.prepare();
		 		    		try
		 		    		{
		 		    			//sleep(1000);
		 		    		}
		 		    		catch (Exception e)
		 		    		{}
		 		    		 Database_functions df=new Database_functions(GCMIntentService.this);
				 		    	df.open();
		 		    		df.update_databaseextras("extras");
		 		    		
		 		    		Looper.loop();
		 		    	}
		 		    	
		 		    };
		 		    
		 		   // t2.start();
		 	
		 			Thread t3=new Thread(){
 		    			
 		    			public void run(){
 		    				
 		    				Looper.prepare();
 		    				Database_functions df=new Database_functions(GCMIntentService.this);
			 		    	df.open();
 		    				
 		    				for(int i=0;i<7;i++)
 					    	{
 								
 					    		df.update_databasedirectory(table_names_directory[i]);
 					    		try
			 		    		{
			 		    			//sleep(1000);
			 		    		}
			 		    		catch (Exception e)
			 		    		{}
 					    		
 					    	}
 		    				Looper.loop();
 		    			}
 		    		};
 		    		//t3.start();
				    	
				    
				    
				    	
		    		//	df.close();
			
		    	
		    }
		   
    	
   	 sharedPref = getSharedPreferences(filename,0);
		SharedPreferences.Editor editor = sharedPref.edit();
	    editor.putInt("flag", 40);
	    editor.commit();
	    
	    Log.i("shared pref is ",""+sharedPref.getInt("flag",0));
        Log.i(TAG, "Device registered: regId = " + registrationId);
        aController.displayMessageOnScreen(context, "Your device registred with GCM");
        Log.d("NAME", MainActivity.name);
        Log.i("deepank here","see its working");
        
        
	    editor.putInt("updateextras",0);
	    editor.commit();
	    
	    editor.putInt("updatedirectory",0);
	    editor.commit();
	    
	    editor.putInt("updateptp",0);
	    editor.commit();
       
        aController.register(context, MainActivity.name, MainActivity.email, registrationId);
    }

    /**
     * Method called on device unregistred
     * */
    @Override
    protected void onUnregistered(Context context, String registrationId) {
    	if(aController == null)
            aController = (Controller) getApplicationContext();
        Log.i(TAG, "Device unregistered");
        aController.displayMessageOnScreen(context, getString(R.string.gcm_unregistered));
        aController.unregister(context, registrationId);
    }

    /**
     * Method called on Receiving a new message from GCM server
     * */
    @Override
    protected void onMessage(Context context, Intent intent) {
    	
    	
    	if(aController == null)
            aController = (Controller) getApplicationContext();
    	
    	
        Log.i(TAG, "Received message");
        String message = intent.getExtras().getString("price");
        
	    
        try
        {
        
        Log.i("push notification",message);
        String table=intent.getExtras().getString("table");
        Database_functions info1=new Database_functions(GCMIntentService.this);
		info1.open();
        	if(table.equalsIgnoreCase("extras"))
        	{
        		
        		ourdatabase=info1.ourdatabase;
        		Cursor dataCount = ourdatabase.rawQuery("select s_no from " + table, null);
        		int count=dataCount.getCount();
        		
        		Server_database sd=new Server_database();
        		int server_count=sd.get_count(table);
        		
        		
        			sd.setArrayListsextras(count,table);
        			Log.i("name size",""+sd.name.size());
        	        int i=sd.server_database_count-(sd.server_database_count-count);
        			while(!sd.name.isEmpty())
        			{
        				info1.createEntryextras(i,sd.type.get(0),sd.name.get(0),sd.info.get(0),sd.venue.get(0) 
        						, Integer.parseInt(sd.date.get(0)),
        						Integer.parseInt(sd.month.get(0)), 
        						Integer.parseInt(sd.year.get(0)),sd.time.get(0),sd.organizers.get(0),table);
        				sd.name.remove(0); sd.type.remove(0);
        				sd.info.remove(0); sd.venue.remove(0);
        				sd.date.remove(0); sd.month.remove(0); sd.year.remove(0);
        				sd.time.remove(0); sd.organizers.remove(0);
        				i++;
        				
        			}
        		
        			
        	}	
        	else
        	{
        		
        		
        		 String company_name="";
        		//Log.i("company name is ",intent.getExtras().getString("company_name"));
        		company_name=intent.getExtras().getString("company_name");
    	        if(company_name!=null)
    	        {
    	        	Log.i("latest update ","inside23"+intent.getExtras().getString("enddate")+intent.getExtras().getString("endmonth"));
    	        	
    	        	//company_name=intent.getExtras().getString("company_name");
    	        	
    	            try
    	            {
    	            	int enddate=Integer.parseInt(intent.getExtras().getString("enddate"));
    	            	int endmonth=Integer.parseInt(intent.getExtras().getString("endmonth"));
    	            	int endyear=Integer.parseInt(intent.getExtras().getString("endyear"));
    	            	Log.i("latest update ","inside NO caught exception "+enddate+endmonth+endyear+table);
    	            	
    	            	ourdatabase=info1.ourdatabase;
    	            	Log.i("latest update ","inside NO caught exception "+enddate+endmonth+endyear);
                		 ourdatabase.execSQL("update " + table +" set placement_info =\""+message+
                				"\", enddate ="+enddate+",endmonth="+endmonth+",endyear="+endyear+"  where company_name=\""+company_name+"\" ");
                		
    	            }
    	            
    	            catch(Exception E)
    	            {
    	            	Log.i("latest update ","inside caught exception "+E.getMessage());
    	            }
    	        }
    	        else
    	        {
    	        	
    	        	ourdatabase=info1.ourdatabase;
            		Cursor dataCount = ourdatabase.rawQuery("select s_no from " + table, null);
            		int count=dataCount.getCount();
            		
            		Log.i("table table.....table",table);
            		
            		Server_database sd=new Server_database();
            		int server_count=sd.get_count(table);
            		
            		
            			sd.setArrayLists(count,table);
            			Log.i("name size",""+sd.name.size());
            	        int i=sd.server_database_count-(sd.server_database_count-count);
            	        
            			while(!sd.name.isEmpty())
            			{
            				Log.i("entry@@@@entry","entry created");
            				info1.createEntry(i,sd.name.get(0),sd.info.get(0),sd.message.get(0) 
            						, Integer.parseInt(sd.date.get(0)),
            						Integer.parseInt(sd.month.get(0)), 
            						Integer.parseInt(sd.year.get(0)),sd.placement_info.get(0),Integer.parseInt(sd.enddate.get(0))
            						,Integer.parseInt(sd.endmonth.get(0)),Integer.parseInt(sd.endyear.get(0)),table);
            				sd.name.remove(0);
            				sd.info.remove(0); sd.message.remove(0);
            				sd.date.remove(0); sd.month.remove(0); sd.year.remove(0);
            				sd.placement_info.remove(0);
            				sd.enddate.remove(0);sd.endmonth.remove(0);sd.endyear.remove(0);
            				i++;
            				
            			}
    	        }
        	}
        
        	
        	info1.close();
        }
        catch(Exception e)
        {
        	 String table=intent.getExtras().getString("table");
        	 Log.i("table name is ",table);
        	String company_name="";
    		//Log.i("company name is ",intent.getExtras().getString("company_name"));
    		//company_name=intent.getExtras().getString("company_name");
        	
        	Log.i("erererererer","generating errror");
        }
       
        aController.displayMessageOnScreen(context, message);
        // notifies user
        
        generateNotification(context, message);
    }

    /**
     * Method called on receiving a deleted message
     * */
    @Override
    protected void onDeletedMessages(Context context, int total) {
    	
    	if(aController == null)
            aController = (Controller) getApplicationContext();
    	
        Log.i(TAG, "Received deleted messages notification");
        String message = getString(R.string.gcm_deleted, total);
        aController.displayMessageOnScreen(context, message);
        // notifies user
        generateNotification(context, message);
    }

    /**
     * Method called on Error
     * */
    @Override
    public void onError(Context context, String errorId) {
    	
    	if(aController == null)
            aController = (Controller) getApplicationContext();
    	
        Log.i(TAG, "Received error: " + errorId);
        aController.displayMessageOnScreen(context, getString(R.string.gcm_error, errorId));
    }

    @Override
    protected boolean onRecoverableError(Context context, String errorId) {
    	
    	if(aController == null)
            aController = (Controller) getApplicationContext();
    	
        // log message
        Log.i(TAG, "Received recoverable error: " + errorId);
        aController.displayMessageOnScreen(context, getString(R.string.gcm_recoverable_error,
                errorId));
        return super.onRecoverableError(context, errorId);
    }

    /**
     * Create a notification to inform the user that server has sent a message.
     */
    private static void generateNotification(Context context, String message) {
        int icon = R.drawable.ic_launcher;
        long when = System.currentTimeMillis();
        NotificationManager notificationManager = (NotificationManager)
                context.getSystemService(Context.NOTIFICATION_SERVICE);
        Notification notification = new Notification(icon, message, when);
        
        String title = context.getString(R.string.app_name);
        //String title=message;
        Intent notificationIntent = new Intent(context, MainActivity2.class);
        // set intent so it does not start a new activity
        notificationIntent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP |
                Intent.FLAG_ACTIVITY_SINGLE_TOP);
        PendingIntent intent =
                PendingIntent.getActivity(context, 0, notificationIntent, 0);
        notification.setLatestEventInfo(context, title, message, intent);
        notification.flags |= Notification.FLAG_AUTO_CANCEL;
        
        // Play default notification sound
        notification.defaults |= Notification.DEFAULT_SOUND;
        
        //notification.sound = Uri.parse("android.resource://" + context.getPackageName() + "your_sound_file_name.mp3");
        
        // Vibrate if vibrate is enabled
        notification.defaults |= Notification.DEFAULT_VIBRATE;
        notificationManager.notify(0, notification);      

    }
    
   
}
