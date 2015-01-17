package com.androidexample.gcm;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.TextureView;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.ViewFlipper;
 
public class Event_details extends Activity {
 
	ViewFlipper viewFlipper;
	Button Next,Previous;
	TextView About_event,contect,date;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.eventdetails);
        
        Bundle gotbundle=getIntent().getExtras();
        
        
       About_event = (TextView)findViewById(R.id.textView1);
       About_event.setText(gotbundle.getString("info"));
       date =(TextView)findViewById(R.id.textView2);
       contect =(TextView)findViewById(R.id.textView3);
       date.setText(gotbundle.getString("date")+"\n"+gotbundle.getString("venue"));
       contect.setText(gotbundle.getString("organizers"));
        viewFlipper = (ViewFlipper) findViewById(R.id.ViewFlipper01);
        
        
        Next = (Button) findViewById(R.id.Next);
        Previous = (Button) findViewById(R.id.Previous);
        
        Next.setOnClickListener(new View.OnClickListener() {
			
		public void onClick(View v) {
			// TODO Auto-generated method stub
				
			viewFlipper.showNext();
		}
	});
        Previous.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				viewFlipper.showPrevious();
			}
		});
    }
}
