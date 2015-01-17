package com.androidexample.gcm;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.StrictMode;
import android.view.View;
import android.widget.ExpandableListView;
import android.widget.TextView;
import android.widget.ExpandableListView.OnChildClickListener;
import android.widget.ExpandableListView.OnGroupClickListener;
import android.widget.ExpandableListView.OnGroupCollapseListener;
import android.widget.ExpandableListView.OnGroupExpandListener;
import android.widget.Toast;
 
public class DirectoryTab1Activity extends Activity {
 
    DirectoryExpandableListAdapter listAdapter;
    ExpandableListView expListView;
    List<String> listDataHeader;
    HashMap<String, List<String>> listDataChild;
    String result;
    ArrayList<String> name;
    String table_names[];
    ArrayList<String> name2;
    ArrayList<String> info;
    ArrayList<String> type;
    
    StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
 
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.directorytab1activity);
        StrictMode.setThreadPolicy(policy);
        
        table_names=new String[7];
        table_names[0]="director";
        table_names[1]="dean";
        table_names[2]="section";
        table_names[3]="departments";
        table_names[4]="centers";
        table_names[5]="hostel";
        table_names[6]="others";
        
        String filename="deepank";
        int check=0;
		SharedPreferences sharedPref;
		sharedPref = this.getSharedPreferences(filename,0);
		try{
			RegisterActivity.temp=0;
			
			check=sharedPref.getInt("ptpupdate",0);
			if(check==0)
			{
				
					SharedPreferences.Editor editor = sharedPref.edit();
				    editor.putInt("ptpupdate",1);
				    editor.commit();
				    Database_functions df=new Database_functions(DirectoryTab1Activity.this);
				    df.open();
				for(int i=0;i<7;i++)
					df.update_databasedirectory(table_names[i]);
				df.close();
			}
			
		}
		catch(Exception e)
		{
			
			
		}
		
      
        // get the listview
        expListView = (ExpandableListView) findViewById(R.id.directorylvExp);
 
        // preparing list data
        prepareListData();
        
        setDataChild(0,table_names[0]);
        setDataChild(1,table_names[1]);
        setDataChild(2,table_names[2]);
        setDataChild(3,table_names[3]);
        setDataChild(4,table_names[4]);
        setDataChild(5,table_names[5]);
        setDataChild(6,table_names[6]);
  
 
        listAdapter = new DirectoryExpandableListAdapter(this, listDataHeader, listDataChild);
 
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
            	     
                
             	     Database_functions info1=new Database_functions(DirectoryTab1Activity.this);
         	        info1.open();
         	       
         	        ArrayList<String[]> a;
         		   	a=info1.getDatadirectory(table_names[groupPosition]);
         		       
         		       info=new ArrayList<String>();
         		       name2=new ArrayList<String>();
         		       
         		       int size=a.size();
         		       int i=0;
         		       while(!a.isEmpty() && size!=0)
         		       {
         		    	   
         		    	 //  name.add(a.get(size-i-1)[0]);
         		    	 //  Log.i("deepank",a.get(size-i-1)[0]);
         		    	   info.add(a.get(size-i-1)[2]);
         		    	   name2.add(a.get(size-i-1)[1]);
         		    	   a.remove(size-i-1);
         		    	   i++;
         		    	   
         		    	   
         		       }
         		          
         		       info1.close(); 
                
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
             
                Bundle b=new Bundle();   
                //  if(childPosition==0)
                  {
                 	   
                	  b.putString("name",name2.get(childPosition));
                        b.putString("type",type.get(childPosition));
                        b.putString("info",info.get(childPosition));
                         	
                  }
                
                Intent i = new Intent(DirectoryTab1Activity.this,DirectoryInfo.class);
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
        listDataHeader.add("Director");
        listDataHeader.add("Deans");
        listDataHeader.add("Sections");
        listDataHeader.add("Departments");
        listDataHeader.add("Centers");
        listDataHeader.add("Hostels");
        listDataHeader.add("Others");
 /*
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
       // listDataChild.put(listDataHeader.get(1), Deans);
        listDataChild.put(listDataHeader.get(2), Sections);
        listDataChild.put(listDataHeader.get(3), Departments);
        listDataChild.put(listDataHeader.get(4), Centers);
        listDataChild.put(listDataHeader.get(5), Hostels);
        listDataChild.put(listDataHeader.get(6), Others);
        */
        
    }
    
    private void setDataChild(int j,String table)
    {
    	 
	       Database_functions info22=new Database_functions(DirectoryTab1Activity.this);
	         info22.open();
	        
	    	ArrayList<String[]> a2=info22.getDatadirectory(table_names[j]);
	        
	        type=new ArrayList<String>();
	       // Previous_upcoming ob1=new Previous_upcoming();
	       int size=a2.size();
	        int i=0;
	        while(!a2.isEmpty())
	        {
	     	  // if(!ob1.checkdate(a2.get(size-1-i)[3],a2.get(size-1-i)[4],a2.get(size-1-i)[5]))
	     		   type.add(a2.get(size-i-1)[0]);
	     	  // Log.i("deepank",a2.get(size-i-1)[0]);
	     	   a2.remove(size-i-1);
	     	   i++;
	     	   
	     	   
	        }
	         //  Log.i("nmae2 name2",name2.get(0));
	           listDataChild.put(listDataHeader.get(j), type);
	          // Log.i("Datachild",listDataChild.toString());
	        info22.close();
	       // name2.clear();
         
    }
}