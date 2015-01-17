package com.androidexample.gcm;

import android.app.Activity;
import android.app.TabActivity;
import android.content.Intent;
import android.content.res.Resources;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TabHost;
import android.widget.TabHost.OnTabChangeListener;
import android.widget.TabHost.TabSpec;
import android.widget.TextView;

public class ptp extends TabActivity{

	private TabHost tabhost;
			
	
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.ptp);
		 
		tabhost = getTabHost();
		TabHost.TabSpec spc ;
		Intent intent ;
		Resources res = getResources();
		
		intent = new Intent(this,Tab1Activity.class);
		spc = tabhost.newTabSpec("Previous").setIndicator("Previous",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		
		intent = new Intent(this,Tab2Activity.class);
		spc = tabhost.newTabSpec("Upcoming").setIndicator("Upcomig",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
			
		
		
	}


}
