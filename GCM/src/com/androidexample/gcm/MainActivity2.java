package com.androidexample.gcm;


import java.util.ArrayList;

import android.support.v4.app.Fragment;
import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.os.Build;

public class MainActivity2 extends Activity {


		
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main2);
		
		
		
		    
		    
		  
		   
		
		ImageView latest=(ImageView)findViewById(R.id.latest);
		latest.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				Intent i = new Intent(MainActivity2.this,Latest.class);
				startActivity(i);
			}
		});
		
		ImageView ptp=(ImageView)findViewById(R.id.ptp);
		ptp.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				Intent i = new Intent(MainActivity2.this,ptp.class);
				startActivity(i);
			}
		});

		ImageView events=(ImageView)findViewById(R.id.events_and_activities);
		events.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				Intent i = new Intent(MainActivity2.this,Events_and_activities.class);
				startActivity(i);
			}
		});
		
		
		ImageView directory=(ImageView)findViewById(R.id.directory);
		directory.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				Intent i = new Intent(MainActivity2.this,Directory.class);
				startActivity(i);
			}
		});
		
	}


	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment {

		public PlaceholderFragment() {
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			return rootView;
		}
	}

}


