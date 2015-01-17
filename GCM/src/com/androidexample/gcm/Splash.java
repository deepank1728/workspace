package com.androidexample.gcm;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;

public class Splash extends Activity{

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.splash);
		
		
		Thread timer=new Thread(){
			public void run()
			{
				try{
					//sleep(3000);
					SharedPreferences sharedPref;
					String filename="deepank";
					
					try{
						sharedPref = getSharedPreferences(filename,0);
						int flag=sharedPref.getInt("flag",0);
						
						
						
						if(flag==40 || flag==41)
						{
							Intent i=new Intent("com.androidexample.gcm.MainActivity2");
							startActivity(i);
							finish();
						}
						else
						{
							Intent i=new Intent("com.androidexample.gcm.RegisterActivity");
							startActivity(i);
							finish();
							//Intent i=new Intent("com.androidexample.gcm.MainActivity2");
							//startActivity(i);
							//finish();
							
						}
						
						
						
						
					}
					catch (Exception E)
					{
						Log.i("Eceptin caught","exception caught");
						Intent i=new Intent("com.androidexample.gcm.RegisterActivity");
						
						sharedPref = getSharedPreferences(filename,0);
						SharedPreferences.Editor editor = sharedPref.edit();
					    editor.putInt("flag", 40);
						editor.commit();
						startActivity(i);
						finish();
					}
				}
				catch(Exception e)
				{
					
				}
			}
		};
		timer.start();
		
		
		
	}
	
}
