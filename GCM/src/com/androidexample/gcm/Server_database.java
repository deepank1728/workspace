package com.androidexample.gcm;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.utils.URLEncodedUtils;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONException;
import org.json.JSONObject;

import android.os.AsyncTask;
import android.util.Log;
import android.widget.Toast;

public class Server_database {
	InputStream is;
	 String result;
	 int count;
	 ArrayList<String>  type;
	 ArrayList<String> name;
	    ArrayList<String> info;
	    ArrayList<String> message;
	    ArrayList<String> date;
	    ArrayList<String> month;
	    ArrayList<String> year;
	    ArrayList<String>  time;
	    ArrayList<String>  organizers;
	    ArrayList<String>  venue;
	    ArrayList<String> placement_info;
	    ArrayList<String> enddate;
	    ArrayList<String> endmonth;
	    ArrayList<String> endyear;
	    
	    int server_database_count;

	ArrayList<NameValuePair> nameValuePairs = new ArrayList<NameValuePair>();
	
	public void setArrayLists(int local_database_count,String table){
		
		nameValuePairs.clear();
		 nameValuePairs.add(new BasicNameValuePair("table",table));
			
		 	String url="http://"+Config.Address+"/android_dynamic_test/action.php";
			/*setListptp lsptp=new setListptp();
			lsptp.execute(url,table,""+local_database_count);
			
			 name=lsptp.name;
	          info=lsptp.info;
	          message=lsptp.message;
	          date=lsptp.date;
	          month=lsptp.month;
	          year=lsptp.year;
	          placement_info=lsptp.placement_info;
	          enddate=lsptp.enddate;
	          endmonth=lsptp.endmonth;
	          endyear=lsptp.endyear;	
	       */   
	          try
	  		{
	  			//local_database_count=Integer.parseInt(urls[2]);
	  			nameValuePairs.clear();
	  			 nameValuePairs.add(new BasicNameValuePair("table",table));
	  				
	  	        HttpClient httpclient = new DefaultHttpClient();
	  	        HttpPost httppost = new HttpPost(url);
	  	        httppost.setEntity(new UrlEncodedFormEntity(nameValuePairs));
	  	        HttpResponse response = httpclient.execute(httppost); 
	  	        HttpEntity entity = response.getEntity();
	  	        is = entity.getContent();
	  			/*
	  			 String url="http://"+Config.Address+"/android_dynamic_test/action.php";
	  			DefaultHttpClient httpClient = new DefaultHttpClient();
	              String paramString = URLEncodedUtils.format(nameValuePairs, "utf-8");
	              url += "?" + paramString;
	              HttpGet httpGet = new HttpGet(url);

	              HttpResponse httpResponse = httpClient.execute(httpGet);
	              HttpEntity httpEntity = httpResponse.getEntity();

	              is = httpEntity.getContent();
	              */
	  		}
	  	catch(Exception e)
	  		{
	  	        Log.e("log_tag", "Error in http connection "+e.toString());
	  	       // Toast.makeText(null, text, duration)
	  	      //  Toast.makeText(null, "Connection fail", Toast.LENGTH_SHORT).show();

	  		}
	          
	          try{
	  			//"iso-8859-1"
	  	        BufferedReader reader = new BufferedReader(new InputStreamReader(is,"iso-8859-1"),8);
	  	        StringBuilder sb = new StringBuilder();
	  	        String line = null;
	  	        while ((line = reader.readLine()) != null) 
	  	        {
	  	                sb.append(line + "\n");
	  	               // Toast.makeText(getApplicationContext(), "Input Reading pass", Toast.LENGTH_SHORT).show();
	  	        }
	  	        is.close();

	  	        result=sb.toString();
	  	        Log.i("StringBuilder...", result);
	  		}
	  		catch(Exception e)
	  		{
	  	       Log.e("log_tag", "Error converting result "+e.toString());
	  	      
	  	   // Toast.makeText(null, " Input reading fail", Toast.LENGTH_SHORT).show();

	  		}
	  		
	  		
	  		try{
	  			
	  		      
	  	          JSONObject object = new JSONObject(result);
	  	          
	  	           
	  	          name=new ArrayList<String>();
	  	          info=new ArrayList<String>();
	  	          message=new ArrayList<String>();
	  	          date=new ArrayList<String>();
	  	          month=new ArrayList<String>();
	  	          year=new ArrayList<String>();
	  	          placement_info=new ArrayList<String>();
	  	          enddate=new ArrayList<String>();
	  	          endmonth=new ArrayList<String>();
	  	          endyear=new ArrayList<String>();
	  	           
	  	           for(int i=server_database_count-(server_database_count-local_database_count);i<server_database_count;i++)
	  	           {
	  	        	   name.add(object.getString("name"+i));
	  	        	   info.add(object.getString("info"+i));
	  	        	   message.add(object.getString("message"+i));
	  	        	   date.add(object.getString("date"+i));
	  	        	   month.add(object.getString("month"+i));
	  	        	   year.add(object.getString("year"+i));  
	  	        	   placement_info.add(object.getString("placement_info"+i));
	  	        	   enddate.add(object.getString("enddate"+i));
	  	        	   endmonth.add(object.getString("endmonth"+i));
	  	        	   endyear.add(object.getString("endyear"+i));
	  	        	   
	  	           }
	  	           
	  	         
	  	          // name.add(object.getString("name1"));
	  	          
	  		
	  		}
	  		catch(JSONException e)
	  		{
	  		        Log.e("log_tag", "Error parsing data "+e.toString());
	  		       // Toast.makeText(null, "JsonArray fail", Toast.LENGTH_SHORT).show();
	  		}
		
	}
	
	int get_count(String table)
	{
		nameValuePairs.add(new BasicNameValuePair("table",table));
		try
		{

			String url="http://"+Config.Address+"/android_dynamic_test/actioncount.php";
	        HttpClient httpclient = new DefaultHttpClient();
	        HttpPost httppost = new HttpPost("http://"+Config.Address+"/android_dynamic_test/actioncount.php");
	        httppost.setEntity(new UrlEncodedFormEntity(nameValuePairs));
	        HttpResponse response = httpclient.execute(httppost); 
	        HttpEntity entity = response.getEntity();
	        is = entity.getContent();
		/*
			
			DefaultHttpClient httpClient = new DefaultHttpClient();
            String paramString = URLEncodedUtils.format(nameValuePairs, "utf-8");
            url += "?" + paramString;
            HttpGet httpGet = new HttpGet(url);

            HttpResponse httpResponse = httpClient.execute(httpGet);
            HttpEntity httpEntity = httpResponse.getEntity();

            is = httpEntity.getContent();
           */
		}
	catch(Exception e)
		{
	        Log.e("log_tag", "Error in http connection "+e.toString());
	       // Toast.makeText(null, text, duration)
	       // Toast.makeText(null, "Connection fail", Toast.LENGTH_SHORT).show();

		}
		
		try{
			//"iso-8859-1"
	        BufferedReader reader = new BufferedReader(new InputStreamReader(is,"iso-8859-1"),8);
	        StringBuilder sb = new StringBuilder();
	        String line = null;
	        while ((line = reader.readLine()) != null) 
	        {
	                sb.append(line + "\n");
	             //  Toast.makeText(null, "Input Reading pass", Toast.LENGTH_SHORT).show();
	        }
	        is.close();

	        result=sb.toString();
	       // Log.i("StringBuilder...", result);
	        Log.i("kk","ok");
		}
		catch(Exception e)
		{
	       Log.e("log_tag", "Error converting result "+e.toString());
	      
	   // Toast.makeText(null, " Input reading fail", Toast.LENGTH_SHORT).show();

		}
		
		
		try{
			
		      
	          JSONObject object = new JSONObject(result);
	           
	          String ch=object.getString("count");
	           count=Integer.parseInt(ch);
	           server_database_count=count;
	           
		}
		catch(JSONException e)
		{
		        Log.e("log_tag", "Error parsing data "+e.toString());
		       // Toast.makeText(getApplicationContext(), "JsonArray fail", Toast.LENGTH_SHORT).show();
		}
		return count;
	}
	
	
public void setArrayListsextras(int local_database_count,String table){
		
		nameValuePairs.clear();
		 nameValuePairs.add(new BasicNameValuePair("table",table));
			
			try
			{
				String url="http://"+Config.Address+"/android_dynamic_test/actionextras.php";
		        HttpClient httpclient = new DefaultHttpClient();
		        HttpPost httppost = new HttpPost("http://"+Config.Address+"/android_dynamic_test/actionextras.php");
		        httppost.setEntity(new UrlEncodedFormEntity(nameValuePairs));
		        HttpResponse response = httpclient.execute(httppost); 
		        HttpEntity entity = response.getEntity();
		        is = entity.getContent();
			/*
				DefaultHttpClient httpClient = new DefaultHttpClient();
                String paramString = URLEncodedUtils.format(nameValuePairs, "utf-8");
                url += "?" + paramString;
                HttpGet httpGet = new HttpGet(url);

                HttpResponse httpResponse = httpClient.execute(httpGet);
                HttpEntity httpEntity = httpResponse.getEntity();

                is = httpEntity.getContent();
              */
			}
		catch(Exception e)
			{
		        Log.e("log_tag", "Error in http connection "+e.toString());
		       // Toast.makeText(null, text, duration)
		        Toast.makeText(null, "Connection fail", Toast.LENGTH_SHORT).show();

			}
			
			try{
				//"iso-8859-1"
		        BufferedReader reader = new BufferedReader(new InputStreamReader(is,"iso-8859-1"),8);
		        StringBuilder sb = new StringBuilder();
		        String line = null;
		        while ((line = reader.readLine()) != null) 
		        {
		                sb.append(line + "\n");
		               // Toast.makeText(getApplicationContext(), "Input Reading pass", Toast.LENGTH_SHORT).show();
		        }
		        is.close();

		        result=sb.toString();
		        Log.i("StringBuilder...", result);
			}
			catch(Exception e)
			{
		       Log.e("log_tag", "Error converting result "+e.toString());
		      
		   // Toast.makeText(getApplicationContext(), " Input reading fail", Toast.LENGTH_SHORT).show();

			}
			
			
			try{
				
			      
		          JSONObject object = new JSONObject(result);
		          
		          type=new ArrayList<String>();
		          name=new ArrayList<String>();
		          info=new ArrayList<String>();
		          venue=new ArrayList<String>();
		          date=new ArrayList<String>();
		          month=new ArrayList<String>();
		          year=new ArrayList<String>();
		          time=new ArrayList<String>();
		          organizers=new ArrayList<String>();
		           
		           for(int i=server_database_count-(server_database_count-local_database_count);i<server_database_count;i++)
		           {
		        	   type.add(object.getString("type"+i));
		        	   name.add(object.getString("name"+i));
		        	   info.add(object.getString("info"+i));
		        	   venue.add(object.getString("venue"+i));
		        	   date.add(object.getString("date"+i));
		        	   month.add(object.getString("month"+i));
		        	   year.add(object.getString("year"+i));
		        	   time.add(object.getString("time"+i));
		        	   organizers.add(object.getString("organizers"+i));
		           }
		           
		           Log.i("server database log",type.get(0)+type.get(1)+name.get(0)+name.get(1));
		         
		          // name.add(object.getString("name1"));
		          
			
			}
			catch(JSONException e)
			{
			        Log.e("log_tag", "Error parsing data "+e.toString());
			       // Toast.makeText(getApplicationContext(), "JsonArray fail", Toast.LENGTH_SHORT).show();
			}
	}

public void setArrayListsdirectory(int local_database_count,String table){
		
		nameValuePairs.clear();
		 nameValuePairs.add(new BasicNameValuePair("table",table));
			
			try
			{
				String url="http://"+Config.Address+"/android_dynamic_test/actiondirectory.php";
		        HttpClient httpclient = new DefaultHttpClient();
		        HttpPost httppost = new HttpPost("http://"+Config.Address+"/android_dynamic_test/actiondirectory.php");
		        httppost.setEntity(new UrlEncodedFormEntity(nameValuePairs));
		        HttpResponse response = httpclient.execute(httppost); 
		        HttpEntity entity = response.getEntity();
		        is = entity.getContent();
				
				/*
				DefaultHttpClient httpClient = new DefaultHttpClient();
                String paramString = URLEncodedUtils.format(nameValuePairs, "utf-8");
                url += "?" + paramString;
                HttpGet httpGet = new HttpGet(url);

                HttpResponse httpResponse = httpClient.execute(httpGet);
                HttpEntity httpEntity = httpResponse.getEntity();

                is = httpEntity.getContent();
                
                */
				
			}
		catch(Exception e)
			{
		        Log.e("log_tag", "Error in http connection "+e.toString());
		       // Toast.makeText(null, text, duration)
		        Toast.makeText(null, "Connection fail", Toast.LENGTH_SHORT).show();

			}
			
			try{
				//"iso-8859-1"
		        BufferedReader reader = new BufferedReader(new InputStreamReader(is,"iso-8859-1"),8);
		        StringBuilder sb = new StringBuilder();
		        String line = null;
		        while ((line = reader.readLine()) != null) 
		        {
		                sb.append(line + "\n");
		               // Toast.makeText(getApplicationContext(), "Input Reading pass", Toast.LENGTH_SHORT).show();
		        }
		        is.close();

		        result=sb.toString();
		        Log.i("StringBuilder...", result);
			}
			catch(Exception e)
			{
		       Log.e("log_tag", "Error converting result "+e.toString());
		      
		   // Toast.makeText(getApplicationContext(), " Input reading fail", Toast.LENGTH_SHORT).show();

			}
			
			
			try{
				
			      
		          JSONObject object = new JSONObject(result);
		          
		           
		          name=new ArrayList<String>();
		          info=new ArrayList<String>();
		          type=new ArrayList<String>();
		         
		           
		           for(int i=server_database_count-(server_database_count-local_database_count);i<server_database_count;i++)
		           {
		        	   name.add(object.getString("name"+i));
		        	   info.add(object.getString("info"+i));
		        	   type.add(object.getString("type"+i));
		        	  
		           }
		         
		          // name.add(object.getString("name1"));
		          
			
			}
			catch(JSONException e)
			{
			        Log.e("log_tag", "Error parsing data "+e.toString());
			       // Toast.makeText(getApplicationContext(), "JsonArray fail", Toast.LENGTH_SHORT).show();
			}
	}
	
	
	  	
}
