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
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONException;
import org.json.JSONObject;

import android.os.AsyncTask;
import android.util.Log;

public class setListptp extends AsyncTask<String,Void,Void>{

	InputStream is;
	String result2;
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
	    int local_database_count;
	    int server_database_count;
	ArrayList<NameValuePair> nameValuePairs = new ArrayList<NameValuePair>();
	@Override
	protected Void doInBackground(String... urls) {
		// TODO Auto-generated method stub
		try
		{
			local_database_count=Integer.parseInt(urls[2]);
			nameValuePairs.clear();
			 nameValuePairs.add(new BasicNameValuePair("table",urls[1]));
				
	        HttpClient httpclient = new DefaultHttpClient();
	        HttpPost httppost = new HttpPost(urls[0]);
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
		return null;
	}
	@Override
	protected void onPostExecute(Void result) {
		// TODO Auto-generated method stub
		super.onPostExecute(result);
		
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

	        result2=sb.toString();
	        Log.i("StringBuilder...", result2);
		}
		catch(Exception e)
		{
	       Log.e("log_tag", "Error converting result "+e.toString());
	      
	   // Toast.makeText(null, " Input reading fail", Toast.LENGTH_SHORT).show();

		}
		
		
		try{
			
		      
	          JSONObject object = new JSONObject(result2);
	          
	           
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
	
	

	
	

}
