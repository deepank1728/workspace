package com.androidexample.gcm;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterViewFlipper;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class EventsList extends Activity{

	private List<EList> elist=new ArrayList<EList>();
	 @Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.eventslist);
	        
	        addelist();
	        addelistview();	
	        registerClickCallback();
	 }
	 
	 private void addelist()
	 {
		// elist.add(new EList("Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		// elist.add(new EList("Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		// elist.add(new EList("Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		// elist.add(new EList("Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		// elist.add(new EList("Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		// elist.add(new EList("Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		 
		 Database_functions df=new Database_functions(EventsList.this);
		 df.open();
		 
		 Cursor dataCount = df.ourdatabase.rawQuery(" select name,venue,date,month,year "
		 		+ "from extras order by year desc,month desc,date desc",null);
		
		 
		 dataCount.moveToLast();
		 
		 for(int i=0;i<9;i++)
		 {
			 if(dataCount.getPosition()==-1)
				 break;
			 String name=dataCount.getString(0);
			 String venue=dataCount.getString(1);
			 int date=dataCount.getInt(2);
			 int day=dataCount.getInt(3);
			 int year=dataCount.getInt(4);
			 elist.add(new EList(name,venue,date+"/"+day+"/"+year,R.drawable.arrow));
			 dataCount.moveToPrevious();
			 
		 }
		 df.close();
	 }
	 
	 private void addelistview()
	 {
		 ArrayAdapter<EList> eadapter=new MyListAdapter();
		 ListView list=(ListView)findViewById(R.id.elist);
		 list.setAdapter(eadapter);
	 }
	 
	 private class MyListAdapter extends ArrayAdapter<EList>	 {
		 
		 public MyListAdapter()
		 {
			 super(EventsList.this,R.layout.eventslist_view,elist);
			 
		 }
		 @Override
		 public View getView(int position,View convertview, ViewGroup parent)
		 {
			 View itemview=convertview;
			 if(itemview == null)
			 {
				 
				 itemview=getLayoutInflater().inflate(R.layout.eventslist_view, parent,false);
			 }
				 
			 
			 EList currentlist=elist.get(position);
			 
			 
			 TextView ename=(TextView)itemview.findViewById(R.id.ename);
			 ename.setText(""+currentlist.getename());
			 
			 TextView einfo=(TextView)itemview.findViewById(R.id.einfo);
			 einfo.setText(""+currentlist.geteinfo());
			 
			 TextView edate=(TextView)itemview.findViewById(R.id.edate);
			 edate.setText(""+currentlist.getedate());
			 
			 ImageView imageview1=(ImageView) itemview.findViewById(R.id.arrow);
			 imageview1.setImageResource(currentlist.getarrow());
			 
			 return itemview;
		 }
		 
		
	 }
	 private void registerClickCallback()
	 {
		ListView list=(ListView)findViewById(R.id.elist);
		list.setOnItemClickListener(new AdapterView.OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View viewclicked, int position,
					long id) {
				// TODO Auto-generated method stub
				//String message="Clicked";
				//Toast.makeText(PlacementList.this, message, Toast.LENGTH_SHORT).show();
				Intent i = new Intent(EventsList.this,Compdetails.class);
				
				
				EList lisno=elist.get(position);
				Bundle localBundle = new Bundle();
				localBundle.putString("Eventname", lisno.getename() );
				localBundle.putString("Eventinfo", lisno.geteinfo() );
				localBundle.putString("Eventdate", lisno.getename() );
				i.putExtras(localBundle);
				startActivity(i);
			}
			
		});
		 
	 }
}