package com.androidexample.gcm;



import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.TextureView;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.ViewFlipper;
 
public class DirectoryInfo extends Activity {
 
	TextView type,info;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.directoryinfo);
        
        type = (TextView)findViewById(R.id.type);
        info = (TextView)findViewById(R.id.info);
        
        Bundle gotbundle=getIntent().getExtras();
        
        String s1="",s2="";
		s1=gotbundle.getString("type");
		s2=gotbundle.getString("info");
        
       
        //s1="Student Welfare";
        //s2="R. C. Gupta	\nProfessor	\nStudent Welfare	\n+91-141-2713364";
        type.setText(s1);
        info.setText(s2);
   }
}
        