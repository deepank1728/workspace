package com.androidexample.gcm;

import android.app.TabActivity;
import android.content.Intent;
import android.content.res.Resources;
import android.graphics.Typeface;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TabHost;
import android.widget.TextView;

public class Latest extends TabActivity{
	
private TabHost tabHost;
			
	
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.latest);
		 
/*
		tabhost = getTabHost();
		TabHost.TabSpec spc ;
		Intent intent ;
		Resources res = getResources();
		
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Placements").setIndicator("Placements",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		
		tabhost.addTab(spc);
		
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Events & Activities").setIndicator("Events & Activities",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
			
		intent = new Intent(this,EventsTab2Activity.class);
		spc = tabhost.newTabSpec("Other Circulars").setIndicator("",res.getDrawable(R.drawable.tab_icon)).setContent(intent);
		tabhost.addTab(spc);
		//tabhost.getTabWidget().getChildAt(0).getLayoutParams().width =25;
		//tabhost.getTabWidget().getChildAt(0).getLayoutParams().width =5;
	
		*/ 
		 
	
	
	
		
		    //TabHost tabHost;
		    
		    // Button logout;
		   
		  

		        
		      
		        tabHost = getTabHost();
		        Resources res = getResources();
		        TabHost.TabSpec placements = tabHost.newTabSpec("tid1");
		        TabHost.TabSpec Events_activities = tabHost.newTabSpec("tid2");
		        TabHost.TabSpec circulars = tabHost.newTabSpec("tid3");
		        
		        View tabIndicator1 = LayoutInflater.from(this).inflate(
		                R.layout.tab_indicator, tabHost.getTabWidget(), false);
		        TextView title1 = (TextView) tabIndicator1.findViewById(R.id.titlebox);
		        
		        View tabIndicator2 = LayoutInflater.from(this).inflate(
		                R.layout.tab_indicator, tabHost.getTabWidget(), false);
		        TextView title2 = (TextView) tabIndicator2.findViewById(R.id.titlebox);
		        
		        
		        final View tabIndicator3 = LayoutInflater.from(this).inflate(
		                R.layout.tab_indicator, tabHost.getTabWidget(), false);
		        final TextView title3 = (TextView) tabIndicator3.findViewById(R.id.titlebox);
		        
		       
		        Intent placement = new Intent(this, PlacementList.class);

		        title1.setText("PLACEMENTS");
		        
		        title1.setTextSize(16);
		        title1.setTypeface(null, Typeface.NORMAL);
		        
		        
		        placements.setIndicator(tabIndicator1).setContent(placement);
		        

		         Intent events = new Intent(this, EventsList.class);

		        //commentPage.putExtra("g0", stopmModel);
		        title2.setText("EVENTS & ACTIVITIES");
		        title2.setTextSize(16);
		        title2.setTypeface(null, Typeface.NORMAL);
		        Events_activities.setIndicator(tabIndicator2).setContent(events);
		        events.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
		         
		        
		        final Intent notice = new Intent(this, EventsTab2Activity.class); 
		        title3.setText("OTHER CIRCULARS AND NOTICES");
		    title3.setTextSize(16);
		    title3.setTypeface(null, Typeface.NORMAL);
		        circulars.setIndicator(tabIndicator3).setContent(notice);
		    

		       // tabHost.getTabWidget().setDividerDrawable(R.drawable.divider);


		       		       
		        
		        tabHost.addTab(placements);
		        tabHost.addTab(Events_activities);
		        tabHost.addTab(circulars);
		        
		       
		      //  tabHost.getTabWidget().getChildAt(0).getLayoutParams().width = 70;
		       // tabHost.getTabWidget().getChildAt(0).getLayoutParams().height = 25;
		       
		        
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}


	
	
	
	
	
}
