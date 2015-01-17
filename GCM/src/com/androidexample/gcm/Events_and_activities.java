package com.androidexample.gcm;

import android.app.TabActivity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.widget.TabHost;

public class Events_and_activities extends TabActivity{
	
private TabHost tabhost;
			
	
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.events_and_activities);
		 
		tabhost = getTabHost();
		TabHost.TabSpec spc ;
		Intent intent ;
		Resources res = getResources();
		
		intent = new Intent(this,EventsTab1Activity.class);
		spc = tabhost.newTabSpec("Previous").setIndicator("Previous",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Upcoming").setIndicator("Upcoming",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
			
		intent = new Intent(this,CalendarView.class);
		spc = tabhost.newTabSpec("Dates").setIndicator("Dates",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		//tabhost.addTab(spc);
		
		
		
	}


}
