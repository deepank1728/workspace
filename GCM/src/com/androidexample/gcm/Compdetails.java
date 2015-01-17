package com.androidexample.gcm;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout.LayoutParams;
import android.widget.TextView;

public class Compdetails extends Activity{
	
	TextView name,message,info;
	String info_string,message_string,name_string;
	@Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.compdetails);
	        
	        getWindow().setLayout(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT);
	        
	        name = (TextView)findViewById(R.id.name1);
	        message=(TextView)findViewById(R.id.message);
	        info=(TextView)findViewById(R.id.info);
			
			 
	        Bundle gotbundle=getIntent().getExtras();
	        
			info_string=gotbundle.getString("info");
			message_string=gotbundle.getString("message");
			name_string=gotbundle.getString("name");
			
			name.setText(name_string);
			info.setText(info_string);
			message.setText(message_string);
	        String s1="",s2="",s3="";
	        s1="Microsoft India ";
	        s2="The computer pipeline is divided in stages. ";
	        s3="The computer pipeline is divided in stages.";
	       // name.setText(s1);
	        
	        
	        
}
}