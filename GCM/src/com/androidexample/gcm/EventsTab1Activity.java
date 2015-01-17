package com.androidexample.gcm;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.os.Bundle;
import android.os.StrictMode;
import android.util.Log;
import android.view.View;
import android.widget.ExpandableListView;
import android.widget.TextView;
import android.widget.ExpandableListView.OnChildClickListener;
import android.widget.ExpandableListView.OnGroupClickListener;
import android.widget.ExpandableListView.OnGroupCollapseListener;
import android.widget.ExpandableListView.OnGroupExpandListener;
import android.widget.Toast;
 
public class EventsTab1Activity extends Activity {
 
    EventsExpandableListAdapter listAdapter;
    ExpandableListView expListView;
    List<String> listDataHeader;
    HashMap<String, List<String>> listDataChild;
    ArrayList<String> technical;
    ArrayList<String> cultural;
    ArrayList<String> sports;
    ArrayList<String> others;
    String table_names[];
 
    StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.eventstab1activity);
        StrictMode.setThreadPolicy(policy);
        
        table_names=new String[4];
        table_names[0]="Technical";
        table_names[1]="Cultural";
        table_names[2]="Sports";
        table_names[3]="Others";
        
        int check=0;
		SharedPreferences sharedPref;
		String filename="deepank";
		sharedPref = this.getSharedPreferences(filename,0);
		try{
			RegisterActivity.temp=0;
			check=sharedPref.getInt("extrasupdate",0);
			if(check==0)
			{
				
					SharedPreferences.Editor editor = sharedPref.edit();
				    editor.putInt("extrasupdate",1);
				    editor.commit();
				    Database_functions df=new Database_functions(EventsTab1Activity.this);
				    df.open();
				
					df.update_databaseextras("extras");
				df.close();
			}
			
		}
		catch(Exception e)
		{
			
			
		}
		
     
        // get the listview
        expListView = (ExpandableListView) findViewById(R.id.eventslvExp);
        
 
        // preparing list data
        prepareListData();
        
        setDataChild(0,"extras");
        
 
        listAdapter = new EventsExpandableListAdapter(this, listDataHeader, listDataChild);
 
        // setting list adapter
        expListView.setAdapter(listAdapter);
 
        // Listview Group click listener
        expListView.setOnGroupClickListener(new OnGroupClickListener() {
 
            @Override
            public boolean onGroupClick(ExpandableListView parent, View v,
                    int groupPosition, long id) {
                // Toast.makeText(getApplicationContext(),
                // "Group Clicked " + listDataHeader.get(groupPosition),
                // Toast.LENGTH_SHORT).show();
            	
            	
            	
                return false;
            }
        });
 
        // Listview Group expanded listener
        expListView.setOnGroupExpandListener(new OnGroupExpandListener() {
 
            @Override
            public void onGroupExpand(int groupPosition) {
                
            	     Toast.makeText(getApplicationContext(),
                        listDataHeader.get(groupPosition) + " Expanded",
                        Toast.LENGTH_SHORT).show();
            	     
                
            }
        });
 
        // Listview Group collasped listener
        expListView.setOnGroupCollapseListener(new OnGroupCollapseListener() {
 
            @Override
            public void onGroupCollapse(int groupPosition) {
                Toast.makeText(getApplicationContext(),
                        listDataHeader.get(groupPosition) + " Collapsed",
                        Toast.LENGTH_SHORT).show();
 
            }
        });
 
        // Listview on child click listener
        expListView.setOnChildClickListener(new OnChildClickListener() {
 
            @Override
            public boolean onChildClick(ExpandableListView parent, View v,
                    int groupPosition, int childPosition, long id) {
                // TODO Auto-generated method stub
                Toast.makeText(
                        getApplicationContext(),
                        listDataHeader.get(groupPosition)
                                + " : "
                                + listDataChild.get(
                                        listDataHeader.get(groupPosition)).get(
                                        childPosition), Toast.LENGTH_SHORT)
                        .show();
             
                
                Database_functions info1=new Database_functions(EventsTab1Activity.this);
    	        info1.open();
    	    
    	        Cursor c = info1.ourdatabase.rawQuery("select * from extras where type=\"" + table_names[groupPosition]+"\"", null);
 		   	//a=info1.getDataptp(table_names[groupPosition]);
    	        
    	        Bundle b=new Bundle();
    	        int z=0;
    	        for(c.moveToFirst();!c.isAfterLast();c.moveToNext()){
    	        	
    	        	
    	        	if(z==childPosition)
    	        	{
    	        		b.putString("name",c.getString(c.getColumnIndex("name")));
    	        		b.putString("info",c.getString(c.getColumnIndex("info")));
    	        		b.putString("venue",c.getString(c.getColumnIndex("venue")));
    	        		b.putString("date",""+c.getString(c.getColumnIndex("date")));
    	        		b.putString("month",""+c.getString(c.getColumnIndex("month")));
    	        		b.putString("year",""+c.getString(c.getColumnIndex("year")));
    	        		b.putString("time",""+c.getString(c.getColumnIndex("time")));
    	        		b.putString("organizers",""+c.getString(c.getColumnIndex("organizers")));
    	        	}
    	        	z++;
    			/*	String s[]=new String[10] ;
    				s[0]=c.getString(0);
    				//Log.i("iname",s[0]);
    				s[1]=c.getString(1);
    				s[2]=c.getString(2);
    				s[3]=c.getString(3);
    				s[4]=c.getString(4);
    				s[5]=""+c.getInt(5);
    				s[6]=""+c.getInt(6);
    				s[7]=""+c.getInt(7);
    				s[8]=c.getString(8);
    				s[9]=c.getString(9);
    				result.add(s);
    				s=null;
    				*/
    			}
                
                Intent i = new Intent(EventsTab1Activity.this,Event_details.class);
                i.putExtras(b);
       	     startActivity(i);

                return false;
            }
        });
    }
 
    /*
     * Preparing the list data
     */
    private void prepareListData() {
        listDataHeader = new ArrayList<String>();
        listDataChild = new HashMap<String, List<String>>();
 
        // Adding child data
        listDataHeader.add("Technical");
        listDataHeader.add("Cultural");
        listDataHeader.add("Sports");
        listDataHeader.add("Others");
     
        
        /*  listDataHeader.add("Centers");
        listDataHeader.add("Hostels");
        listDataHeader.add("Others");
 
        // Adding child data
        List<String> Director = new ArrayList<String>();
        Director.add("Director");
      
        
        List<String> Deans = new ArrayList<String>();
        Deans.add("M.K. Shrimali ");
        Deans.add("R.C. Gupta");
        Deans.add("C.P. Sharma");
        Deans.add("Awadhesh Sharma");
        Deans.add("R.A. Gupta");
        Deans.add("Rohit Goyal");
 
        List<String> Sections = new ArrayList<String>();
        Sections.add("Academic Section");
        Sections.add("Account Section");
        Sections.add("Administration Section");
        Sections.add("Security Section");
        
        List<String> Departments = new ArrayList<String>();
        Departments.add("Academic Section");
        Departments.add("Account Section");
        Departments.add("Administration Section");
        Departments.add("Security Section");
        
        List<String> Centers = new ArrayList<String>();
        Centers.add("Computer Center");
        Centers.add("Alumni Section");
        Centers.add("Library Section");
        
        
        List<String> Hostels = new ArrayList<String>();
        Hostels.add("Hostel No. 1");
        Hostels.add("Hostel No. 2");
        Hostels.add("Hostel No. 3");
        Hostels.add("Hostel No. 4");
        Hostels.add("Hostel No. 5");
        Hostels.add("Hostel No. 6");
        Hostels.add("Hostel No. 7");
        Hostels.add("Hostel No. 8");
        Hostels.add("Aurobindo Hostel");
        Hostels.add("Gargi Hostel");
        Hostels.add("Girls Hostel");
        Hostels.add("P.G. Hostel");
        
        List<String> Others = new ArrayList<String>();
        Others.add("Library");
        Others.add("Hospital");
        Others.add("Sports");
        
        listDataChild.put(listDataHeader.get(0), Director); // Header, Child data
        listDataChild.put(listDataHeader.get(1), Deans);
        listDataChild.put(listDataHeader.get(2), Sections);
        listDataChild.put(listDataHeader.get(3), Departments);
        listDataChild.put(listDataHeader.get(4), Centers);
        listDataChild.put(listDataHeader.get(5), Hostels);
        listDataChild.put(listDataHeader.get(6), Others);
        */
    }
    
    private void setDataChild(int j,String table)
    {
    	 
	       Database_functions info22=new Database_functions(EventsTab1Activity.this);
	         info22.open();
	        
	    	ArrayList<String[]> a2=info22.getDataextras("extras");
	        
	        technical=new ArrayList<String>();
	        cultural=new ArrayList<String>();
	        sports=new ArrayList<String>();
	        others=new ArrayList<String>();
	        Previous_upcoming ob1=new Previous_upcoming();
	       int size=a2.size();
	        int i=0;
	        Log.i("before while","before while...");
	        while(!a2.isEmpty())
	        {
	        //	Log.i("type type",a2.get(size-1-i)[1]);
	     	   if(!ob1.checkdate(a2.get(size-1-i)[5],a2.get(size-1-i)[6],a2.get(size-1-i)[7]))
	     	   {
	     		   if(a2.get(size-1-i)[1].equalsIgnoreCase("technical"))
	     			   technical.add(a2.get(size-i-1)[2]);
	     		   if(a2.get(size-1-i)[1].equalsIgnoreCase("cultural"))
	     			   cultural.add(a2.get(size-i-1)[2]);
	     		  if(a2.get(size-1-i)[1].equalsIgnoreCase("sports"))
	     			   sports.add(a2.get(size-i-1)[2]);
	     		 if(a2.get(size-1-i)[1].equalsIgnoreCase("others"))
	     			   others.add(a2.get(size-i-1)[2]);
	     		   
	     	   }
	     	  // Log.i("deepank",a2.get(size-i-1)[0]);
	     	   a2.remove(size-i-1);
	     	   i++;
	     	   
	     	   
	        }
	       // Log.i("After while",technical.get(0));
	         //  Log.i("nmae2 name2",name2.get(0));
	        
	           listDataChild.put(listDataHeader.get(0), technical);
	           listDataChild.put(listDataHeader.get(1), cultural);
	           listDataChild.put(listDataHeader.get(2), sports);
	           listDataChild.put(listDataHeader.get(3), others);
	           
	          // Log.i("Datachild",listDataChild.toString());
	        info22.close();
	       // name2.clear();
         
    }
}