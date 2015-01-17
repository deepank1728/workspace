package com.androidexample.gcm;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONException;
import org.json.JSONObject;






import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
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
 
public class Tab1Activity extends Activity {
 
	
    ExpandableListAdapter listAdapter;
    ExpandableListView expListView;
    List<String> listDataHeader;
    HashMap<String, List<String>> listDataChild;
    InputStream is;
    String result;
    int count;
    ArrayList<String> name;
    ArrayList<String> info;
    ArrayList<String> message;
    ArrayList<String> naming;
    String table_names[];
    ArrayList<String> name2;
    ArrayList<String> placement_info;
    
    private SQLiteDatabase ourdatabase;
	 SharedPreferences sharedPref;
		String filename="deepank";
		

    StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
 
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.tab1activity);
        StrictMode.setThreadPolicy(policy);
        
        table_names=new String[7];
        table_names[0]="comp_company";
        table_names[1]="chem_company";
        table_names[2]="civil_company";
        table_names[3]="mech_company";
        table_names[4]="tronics_company";
        table_names[5]="electrical_company";
        table_names[6]="meta_company";
        //table_names[0]="comp_company";
    
        
        int check=0;
		SharedPreferences sharedPref;
		sharedPref = this.getSharedPreferences(filename,0);
		try{
			RegisterActivity.temp=0;
			String filename="deepank";
			check=sharedPref.getInt("directoryupdate",0);
			if(check==0)
			{
				
					SharedPreferences.Editor editor = sharedPref.edit();
				    editor.putInt("directoryupdate",1);
				    editor.commit();
				    Database_functions df=new Database_functions(Tab1Activity.this);
				    df.open();
				for(int i=0;i<7;i++)
					df.update_databaseptp(table_names[i]);
				df.close();
			}
			
		}
		catch(Exception e)
		{
			
			
		}
		
        
    //....................................................localdatabse.................................................
        prepareListData();
        
       
       
        
        setDataChild(0,table_names[0]);
        setDataChild(1,table_names[1]);
        setDataChild(2,table_names[2]);
        setDataChild(3,table_names[3]);
        setDataChild(4,table_names[4]);
        setDataChild(5,table_names[5]);
        setDataChild(6,table_names[6]);
        RegisterActivity.temp=0;
        
    //.............................................localdatabse ends................................................
        
	        
	        
        // get the listview
        expListView = (ExpandableListView) findViewById(R.id.lvExp);
 
        // preparing list data
        
 
        listAdapter = new ExpandableListAdapter(this, listDataHeader, listDataChild);
        
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
               
            	     Database_functions info1=new Database_functions(Tab1Activity.this);
            	        info1.open();
            	        
            	        Previous_upcoming ob1=new Previous_upcoming();
            	       
            	        ArrayList<String[]> a;
            		   	a=info1.getDataptp(table_names[groupPosition]);
            		       
            		       info=new ArrayList<String>();
            		       message=new ArrayList<String>();
            		       placement_info=new ArrayList<String>();
            		      
            		       
            		       
            		       int size=a.size();
            		       int i=0;
            		       while(!a.isEmpty() && size!=0 )
            		       {
            		    	   
            		    	   if(ob1.checkdate(a.get(size-1-i)[3],a.get(size-1-i)[4],a.get(size-1-i)[5]))
            		    	   {
            		    		   a.remove(size-i-1);
            		    		   i++;
            		    		   continue;
            		    	   }
            		    	 //  name.add(a.get(size-i-1)[0]);
            		    	 //  Log.i("deepank",a.get(size-i-1)[0]);
            		    	   info.add(a.get(size-i-1)[0]);
            		    	   message.add(a.get(size-i-1)[2]);
            		    	   placement_info.add(a.get(size-i-1)[6]);
            		    	   a.remove(size-i-1);
            		    	   i++;
            		    	   
            		    	   
            		       }
            		          
            		       info1.close(); 
            		      // listDataChild.put(listDataHeader.get(0), name);
            		       
            	     
                
            }
        });
 
        // Listview Group collasped listener
        expListView.setOnGroupCollapseListener(new OnGroupCollapseListener() {
 
            @Override
            public void onGroupCollapse(int groupPosition) {
                
 
            }
        });
 
        // Listview on child click listener
        expListView.setOnChildClickListener(new OnChildClickListener() {
 
            @Override
            public boolean onChildClick(ExpandableListView parent, View v,
                    int groupPosition, int childPosition, long id) {
                // TODO Auto-generated method stub
               
            	 naming=new ArrayList<String>();
            	 
             naming=(ArrayList<String>)listDataChild.get(listDataHeader.get(groupPosition));
                Bundle b=new Bundle();   
           //  if(childPosition==0)
             {
            	   
            	 	b.putString("name", naming.get(childPosition));
                   b.putString("message",message.get(childPosition)+"\n\n"+placement_info.get(childPosition));
                   b.putString("info",info.get(childPosition));
                    	
             }
             
           /*  if(childPosition==1)
             {
            	   
                   b.putString("message",message2.get(childPosition));
                   b.putString("info",info2.get(childPosition));
                    	
             }
               */
                Intent i = new Intent(Tab1Activity.this,Compdetails.class);
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
        listDataHeader.add("Computer");
        listDataHeader.add("Chemical");
        listDataHeader.add("Civil");
        listDataHeader.add("Mechanical");
        listDataHeader.add("Electronics");
        listDataHeader.add("Electrical");
        listDataHeader.add("Metallurgy");
        
 
        // Adding child data
       
      //  listDataChild.put(listDataHeader.get(2), comingSoon);
    }
    
    private void setDataChild(int j,String table)
    {
    	 
	       Database_functions info22=new Database_functions(Tab1Activity.this);
	         info22.open();
	        
	    	ArrayList<String[]> a2=info22.getDataptp(table_names[j]);
	    	name2=new ArrayList<String>();
	        
	        Previous_upcoming ob1=new Previous_upcoming();
	       int size=a2.size();
	        int i=0;
	        while(!a2.isEmpty())
	        {
	     	   if(!ob1.checkdate(a2.get(size-1-i)[3],a2.get(size-1-i)[4],a2.get(size-1-i)[5]))
	     		   name2.add(a2.get(size-i-1)[0]);
	     	  // Log.i("deepank",a2.get(size-i-1)[0]);
	     	   a2.remove(size-i-1);
	     	   i++;
	     	   
	     	   
	        }
	         //  Log.i("nmae2 name2",name2.get(0));
	           listDataChild.put(listDataHeader.get(j), name2);
	          // Log.i("Datachild",listDataChild.toString());
	        info22.close();
	       // name2.clear();
         
    }
   
}