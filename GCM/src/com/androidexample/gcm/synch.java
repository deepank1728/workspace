package com.androidexample.gcm;

import java.util.ArrayList;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.util.Log;

public class synch extends AsyncTask{

	String table_names[];
    String table_names_directory[];
    ArrayList<String> name2;
	 SharedPreferences sharedPref;
		String filename="deepank";
	Context c;
	public synch(Context context)
	{
		
		c=context;
		 table_names=new String[7];
	        table_names[0]="comp_company";
	        table_names[1]="chem_company";
	        table_names[2]="civil_company";
	        table_names[3]="mech_company";
	        table_names[4]="tronics_company";
	        table_names[5]="electrical_company";
	        table_names[6]="meta_company";
	        
	        
	        table_names_directory=new String[7];
		    table_names_directory[0]="director";
		    table_names_directory[1]="dean";
		    table_names_directory[2]="section";
		    table_names_directory[3]="departments";
		    table_names_directory[4]="centers";
		    table_names_directory[5]="hostel";
		    table_names_directory[6]="others";
	}
	@Override
	protected Object doInBackground(Object... params) {
		// TODO Auto-generated method stub
		
		Log.i("do in background","it works........");
		 if( RegisterActivity.temp==1)
		    {
		    	
		    	
		    	
		    			 Database_functions df=new Database_functions(c);
		 		    	df.open();
		 		    	
		 		    	for(int i=0;i<7;i++)
		 		    	{
		 		    			df.update_databaseptp(table_names[i]);
		 		    	}
		 		    
		 		    	
		 		  	
				    	df.update_databaseextras("extras");
				    
				    	for(int i=0;i<7;i++)
				    	{
							

				    		df.update_databasedirectory(table_names_directory[i]);
				    		
				    	}
				    	
		    			df.close();
			
		    	
		    }
		 return null;
 	
	}

	

	
}
