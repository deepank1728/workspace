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

public class PlacementList extends Activity{

	private List<PList> plist=new ArrayList<PList>();
	String name="",info="";
	 @Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.placementlist);
	        
	        addplist();
	        addplistview();	
	        registerClickCallback();
	 }
	 
	 private void addplist()
	 {
		/* plist.add(new PList(R.drawable.work,"Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		 plist.add(new PList(R.drawable.work,"Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		 plist.add(new PList(R.drawable.work,"Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		 plist.add(new PList(R.drawable.work,"Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		 plist.add(new PList(R.drawable.work,"Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		 plist.add(new PList(R.drawable.work,"Amazon","Amazon is Coming on 27 July, 2014","27 July, 2014",R.drawable.arrow));
		 */
		 
		 Database_functions df=new Database_functions(PlacementList.this);
		 df.open();
		 
		 Cursor dataCount = df.ourdatabase.rawQuery(" select company_name,placement_info,enddate,endmonth,endyear from comp_company union"+ 
				 									" select company_name,placement_info,enddate,endmonth,endyear from chem_company union"+
				 									" select company_name,placement_info,enddate,endmonth,endyear from civil_company union"+
				 									" select company_name,placement_info,enddate,endmonth,endyear from mech_company union"+
				 									" select company_name,placement_info,enddate,endmonth,endyear from tronics_company union"+
				 									" select company_name,placement_info,enddate,endmonth,endyear from electrical_company union"+
				 									" select company_name,placement_info,enddate,endmonth,endyear from meta_company order by endyear,endmonth,enddate", null);
		 
		 dataCount.moveToLast();
		 int count=0;
		 while(count!=9)
		 {
			 if(dataCount.getPosition()==-1)
				 break;
			 String name=dataCount.getString(0);
			 String info=dataCount.getString(1);
			
			 int date=dataCount.getInt(2);
			 int day=dataCount.getInt(3);
			 int year=dataCount.getInt(4);
			 dataCount.moveToPrevious();
			 if(info.equals(""))
				 continue;
			 plist.add(new PList(R.drawable.work,name,info,date+"/"+day+"/"+year,R.drawable.arrow));
			
			 count++;
			 
		 }
		 df.close();
	
		 
		 
	 }
	 
	 private void addplistview()
	 {
		 ArrayAdapter<PList> padapter=new MyListAdapter();
		 ListView list=(ListView)findViewById(R.id.list);
		 list.setAdapter(padapter);
	 }
	 
	 private class MyListAdapter extends ArrayAdapter<PList>	 {
		 
		 public MyListAdapter()
		 {
			 super(PlacementList.this,R.layout.list_view,plist);
			 
		 }
		 @Override
		 public View getView(int position,View convertview, ViewGroup parent)
		 {
			 View itemview=convertview;
			 if(itemview == null)
			 {
				 
				 itemview=getLayoutInflater().inflate(R.layout.list_view, parent,false);
			 }
				 
			 
			 PList currentlist=plist.get(position);
			 
			 ImageView imageview=(ImageView) itemview.findViewById(R.id.compicon);
			 imageview.setImageResource(currentlist.geticonid());
			 
			 TextView compname=(TextView)itemview.findViewById(R.id.compname);
			 compname.setText(""+currentlist.getcname());
			 
			 TextView compinfo=(TextView)itemview.findViewById(R.id.compinfo);
			 compinfo.setText(""+currentlist.getpinfo());
			 
			 TextView compdate=(TextView)itemview.findViewById(R.id.compdate);
			 compdate.setText(""+currentlist.getcompdate());
			 
			 ImageView imageview1=(ImageView) itemview.findViewById(R.id.arrow);
			 imageview1.setImageResource(currentlist.getarrow());
			 
			 return itemview;
		 }
		 
		
	 }
	 private void registerClickCallback()
	 {
		ListView list=(ListView)findViewById(R.id.list);
		list.setOnItemClickListener(new AdapterView.OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View viewclicked, int position,
					long id) {
				// TODO Auto-generated method stub
				//String message="Clicked";
				//Toast.makeText(PlacementList.this, message, Toast.LENGTH_SHORT).show();
				Intent i = new Intent(PlacementList.this,Compdetails.class);
				
				
				PList lisno=plist.get(position);
				Bundle localBundle = new Bundle();
				localBundle.putString("name", lisno.getcname() );
				localBundle.putString("Compinfo", lisno.getpinfo() );
				localBundle.putString("Compdate", lisno.getcname() );
				i.putExtras(localBundle);
				startActivity(i);
			}
			
		});
		 
	 }
}