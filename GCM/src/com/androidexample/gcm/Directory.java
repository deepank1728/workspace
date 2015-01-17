package com.androidexample.gcm;

import android.app.TabActivity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.widget.TabHost;

public class Directory extends TabActivity{
	
private TabHost tabhost;
			
	
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.directory);
		 
		tabhost = getTabHost();
		TabHost.TabSpec spc ;
		Intent intent ;
		Resources res = getResources();
		
		intent = new Intent(this,DirectoryTab1Activity.class);
		spc = tabhost.newTabSpec("Administration").setIndicator("Administration",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		
		
		/*
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Deans").setIndicator("Deans",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
			
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Sections").setIndicator("Sections",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Departments").setIndicator("Departments",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Centers").setIndicator("Centers",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Hostels").setIndicator("Hostels",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Others").setIndicator("Others",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		*/
		
		
	}


}
