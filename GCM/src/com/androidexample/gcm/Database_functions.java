package com.androidexample.gcm;

import java.util.ArrayList;

import android.app.Activity;
import android.content.ContentValues;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Looper;
import android.util.Log;

public class Database_functions extends Activity{
	
	public static final String KEY_S_NO="s_no";
	public static final String KEY_COMPANY_NAME="company_name";
	public static final String KEY_INFO="company_info";
	public static final String KEY_MESSAGE="message";
	public static final String KEY_DATE="date";
	public static final String KEY_MONTH="month";
	public static final String KEY_YEAR="year";
	
	private static final String DATABASE_NAME="test4";
	private static final String DATABASE_TABLE="comp_company";
	private static final int DATABASE_VERSION=1;
	
	private  dbhelper ourhelper;
	private  Context ourcontext;
	public SQLiteDatabase ourdatabase;
	String filename="deepank";
	String table_names[];
    String table_names_directory[];
	
	
	
	public Database_functions(Context c){
		
		ourcontext=c;
	}
	 
	
	private static class dbhelper extends SQLiteOpenHelper{
		public dbhelper(Context context){
			
			super(context,DATABASE_NAME,null,DATABASE_VERSION);
		}

		@Override
		public void onCreate(SQLiteDatabase db) {
			// TODO Auto-generated method stub
			
			
			
			db.execSQL("CREATE TABLE " + DATABASE_TABLE + "(" +
			KEY_S_NO + " INT, "+
			KEY_COMPANY_NAME + " TEXT NOT NULL, "+
			KEY_INFO + " TEXT NOT NULL," + KEY_MESSAGE + " TEXT NOT NULL,date INT,month INT,year INT,placement_info TEXT,enddate INT,endmonth INT,endyear INT); "
			);
			
			db.execSQL("CREATE TABLE chem_company (" +
					KEY_S_NO + " INT, "+
					KEY_COMPANY_NAME + " TEXT NOT NULL, "+
					KEY_INFO + " TEXT NOT NULL," + KEY_MESSAGE + " TEXT NOT NULL,date INT,month INT,year INT,placement_info TEXT,enddate INT,endmonth INT,endyear INT); "
					);
			
			db.execSQL("CREATE TABLE  civil_company (" +
					KEY_S_NO + " INT, "+
					KEY_COMPANY_NAME + " TEXT NOT NULL, "+
					KEY_INFO + " TEXT NOT NULL," + KEY_MESSAGE + " TEXT NOT NULL,date INT,month INT,year INT,placement_info TEXT,enddate INT,endmonth INT,endyear INT); "
					);
			
			db.execSQL("CREATE TABLE mech_company (" +
					KEY_S_NO + " INT, "+
					KEY_COMPANY_NAME + " TEXT NOT NULL, "+
					KEY_INFO + " TEXT NOT NULL," + KEY_MESSAGE + " TEXT NOT NULL,date INT,month INT,year INT,placement_info TEXT,enddate INT,endmonth INT,endyear INT); "
					);
			
			db.execSQL("CREATE TABLE tronics_company (" +
					KEY_S_NO + " INT, "+
					KEY_COMPANY_NAME + " TEXT NOT NULL, "+
					KEY_INFO + " TEXT NOT NULL," + KEY_MESSAGE + " TEXT NOT NULL,date INT,month INT,year INT,placement_info TEXT,enddate INT,endmonth INT,endyear INT); "
					);
			
			db.execSQL("CREATE TABLE electrical_company (" +
					KEY_S_NO + " INT, "+
					KEY_COMPANY_NAME + " TEXT NOT NULL, "+
					KEY_INFO + " TEXT NOT NULL," + KEY_MESSAGE + " TEXT NOT NULL,date INT,month INT,year INT,placement_info TEXT,enddate INT,endmonth INT,endyear INT); "
					);
			
			db.execSQL("CREATE TABLE meta_company (" +
					KEY_S_NO + " INT, "+
					KEY_COMPANY_NAME + " TEXT NOT NULL, "+
					KEY_INFO + " TEXT NOT NULL," + KEY_MESSAGE + " TEXT NOT NULL,date INT,month INT,year INT,placement_info TEXT,enddate INT,endmonth INT,endyear INT); "
					);
			
			db.execSQL("CREATE TABLE extras (s_no int ,type text ,name text,info text,venue text,date int,month int,year int,time text,organizers text);");
			
			db.execSQL("CREATE TABLE centers(s_no int,type text,name text,info text);");
			db.execSQL("CREATE TABLE dean(s_no int,type text,name text ,info text);");
			db.execSQL("CREATE TABLE director(s_no int,type text,name text, info text);");
			db.execSQL("CREATE TABLE departments(s_no int,type text ,name text, info text);");
			db.execSQL("CREATE TABLE hostel(s_no int,type text,name text ,info text);");
			db.execSQL("CREATE TABLE others(s_no int,type text,name text ,info text);");
			db.execSQL("CREATE TABLE section(s_no int,type text,name text ,info text);");
			
			//db.execSQL("CREATE TABLE timestampvalue(value int)");
			
			
			
			
		}
		

		@Override
		public void onUpgrade(SQLiteDatabase db, int arg1, int arg2) {
			
		
			// TODO Auto-generated method stub
			//db.execSQL("DROP TABLE IF EXISTS " +DATABASE_TABLE);
			//onCreate(db);
			
		}
		
		
	}
	
	public Database_functions open() throws SQLException{
		
		ourhelper=new dbhelper(ourcontext);
		ourdatabase=ourhelper.getWritableDatabase();
		return this;
	}
	
	public void close(){
		ourhelper.close();
		
	}

	public long createEntry(int s_no,String name, String info ,String message,int date,int month,int year,String placement_info,int enddate,int endmonth,int endyear,String table) {
		// TODO Auto-generated method stub
		ContentValues cv=new ContentValues();
		cv.put(KEY_S_NO, s_no);
		cv.put(KEY_COMPANY_NAME, name);
		cv.put(KEY_INFO, info);
		cv.put(KEY_MESSAGE, message);
		cv.put(KEY_DATE, date);
		cv.put(KEY_MONTH, month);
		cv.put(KEY_YEAR, year);
		cv.put("placement_info", placement_info);
		cv.put("enddate",enddate);
		cv.put("endmonth",endmonth);
		cv.put("endyear",endyear);
		//Log.i("create entreteerer...","dddddddddd");
		return ourdatabase.insert(table, null, cv);
	}
	
	public long createEntryextras(int s_no,String type, String name ,String info,String venue,int date,int month,int year,String time,String organizers,String table) {
		// TODO Auto-generated method stub
		ContentValues cv=new ContentValues();
		cv.put(KEY_S_NO, s_no);
		cv.put("type", type);
		cv.put("name",name);
		cv.put("info", info);
		cv.put("venue",venue);
		cv.put(KEY_DATE, date);
		cv.put(KEY_MONTH, month);
		cv.put(KEY_YEAR, year);
		cv.put("time", time);
		cv.put("organizers", organizers);
		//Log.i("create entreteerer...","dddddddddd");
		return ourdatabase.insert(table, null, cv);
	}
	
	
	public long createEntrydirectory(int s_no,String type,String name,String info,String table) {
		// TODO Auto-generated method stub
		ContentValues cv=new ContentValues();
		cv.put("s_no", s_no);
		cv.put("type", type);
		cv.put("name", name);
		cv.put("info", info);
		
		//Log.i("create entreteerer...","dddddddddd");
		return ourdatabase.insert(table, null, cv);
	}

	public ArrayList<String[]> getDataptp(String table) {
		// TODO Auto-generated method stub
		String[] columns=new String[]{KEY_S_NO,KEY_COMPANY_NAME,KEY_INFO,KEY_MESSAGE,KEY_DATE,KEY_MONTH,KEY_YEAR,"placement_info"};
		
		  table_names=new String[7];
	        table_names[0]="comp_company";
	        table_names[1]="chem_company";
	        table_names[2]="civil_company";
	        table_names[3]="mech_company";
	        table_names[4]="tronics_company";
	        table_names[5]="electrical_company";
	        table_names[6]="meta_company";
	        
	        
	        
		int flag=0;
		 
			Cursor c=ourdatabase.query(table, columns, null, null, null,null,null);
			
			
			ArrayList<String[]> result=new ArrayList<String[]>();
			
			int iS_no=c.getColumnIndex(KEY_S_NO);
			int iName=c.getColumnIndex(KEY_COMPANY_NAME);
			int iInfo=c.getColumnIndex(KEY_INFO);
			int iMessage=c.getColumnIndex(KEY_MESSAGE);
			int iDate=c.getColumnIndex(KEY_DATE);
			int iMonth=c.getColumnIndex(KEY_MONTH);
			int iYear=c.getColumnIndex(KEY_YEAR);
			int iPinfo=c.getColumnIndex("placement_info");
			
			
			for(c.moveToFirst();!c.isAfterLast();c.moveToNext()){
				String s[]=new String[7] ;
				s[0]=c.getString(iName);
				//Log.i("iname",s[0]);
				s[1]=c.getString(iInfo);
				s[2]=c.getString(iMessage);
				s[3]=""+c.getInt(iDate);
				s[4]=""+c.getInt(iMonth);
				s[5]=""+c.getInt(iYear);
				s[6]=c.getString(iPinfo);
				result.add(s);
				s=null;
				
			}
			
			return result;
		
	}
	
	
	public ArrayList<String[]> getDatadirectory(String table) {
		// TODO Auto-generated method stub
		
		 table_names_directory=new String[7];
		    table_names_directory[0]="director";
		    table_names_directory[1]="dean";
		    table_names_directory[2]="section";
		    table_names_directory[3]="departments";
		    table_names_directory[4]="centers";
		    table_names_directory[5]="hostel";
		    table_names_directory[6]="others";
		   
			
		
		String[] columns=new String[]{"s_no","type","name","info"};
			
			Cursor c=ourdatabase.query(table, columns, null, null, null,null,null);
			
			Log.i("cursor position in directory",""+c.getPosition());
			ArrayList<String[]> result=new ArrayList<String[]>();
			
			int iS_no=c.getColumnIndex("s_no");
			int iType=c.getColumnIndex("type");
			int iName=c.getColumnIndex("name");
			int iInfo=c.getColumnIndex("info");
			
			
			for(c.moveToFirst();!c.isAfterLast();c.moveToNext()){
				String s[]=new String[3] ;
				s[0]=c.getString(iType);
				s[1]=c.getString(iName);
				s[2]=c.getString(iInfo);	
				result.add(s);
				s=null;
				
			}
			
			return result;	
		
	}

	public ArrayList<String[]> getDataextras(String table) {
		// TODO Auto-generated method stub
		String[] columns=new String[]{"s_no","type","name","info","venue","date","month","year","time","organizers"};
		
			
				Cursor c=ourdatabase.rawQuery("select * from extras",null);
			
			
			ArrayList<String[]> result=new ArrayList<String[]>();
			
			int iS_no=c.getColumnIndex(KEY_S_NO);
			int iType=c.getColumnIndex("type");
			int iName=c.getColumnIndex("name");
			int iInfo=c.getColumnIndex("info");
			int iVenue=c.getColumnIndex("venue");
			int iDate=c.getColumnIndex(KEY_DATE);
			int iMonth=c.getColumnIndex(KEY_MONTH);
			int iYear=c.getColumnIndex(KEY_YEAR);
			int iTime=c.getColumnIndex("time");
			int iOrganizers=c.getColumnIndex("organizers");
			//Log.i("deepank dekh ye  ",""+c.getPosition());
			//Log.i("deepank ye bhi dekh",""+c.getCount());
			
			
			for(c.moveToFirst();!c.isAfterLast();c.moveToNext()){
				String s[]=new String[10] ;
				s[0]=""+c.getInt(iS_no);
				//Log.i("iname",s[0]);
				s[1]=c.getString(iType);
				s[2]=c.getString(iName);
				s[3]=c.getString(iInfo);
				s[4]=c.getString(iVenue);
				s[5]=""+c.getInt(iDate);
				s[6]=""+c.getInt(iMonth);
				s[7]=""+c.getInt(iYear);
				s[8]=c.getString(iTime);
				s[9]=c.getString(iOrganizers);
				result.add(s);
				s=null;
				
			}
			//Log.i("checking s string...",result.get(0)[0]);
			
			return result;
		
		
	}
	
	void update_databaseextras(String table)
	{
		//if(RegisterActivity.temp==1)
		{
			
			
			Cursor dataCount = ourdatabase.rawQuery("select s_no from " + table, null);
			int count=dataCount.getCount();
			
			Server_database sd=new Server_database();
			int server_count=sd.get_count(table);
			
			Log.i("count count",""+count);
			Log.i("server count",""+server_count);
			if(server_count!=count)
			{
				Log.i("server count in if",""+server_count);
				sd.setArrayListsextras(count,table);
				 Log.i("before setarraylists ","hello...");
				Database_functions info1=new Database_functions(ourcontext);
		        info1.open();
		        int i=sd.server_database_count-(sd.server_database_count-count);
		        int j=0;
		        try{
		         j=sd.name.size();
		        }
		        
		        catch(Exception e){}
		        Log.i("j is ",""+j);
				for(int k=0;k<j;k++)
				{
					long l=info1.createEntryextras(i,sd.type.get(k),sd.name.get(k),sd.info.get(k),
							sd.venue.get(k) ,Integer.parseInt(sd.date.get(k))
							,Integer.parseInt(sd.month.get(k)),
							Integer.parseInt(sd.year.get(k)),
							sd.time.get(k),sd.organizers.get(k),"extras");
					Log.i("create entry status",""+l+" is status");
					i++;
					
				}
				info1.close();
				Cursor dataCount2 = ourdatabase.rawQuery("select name from " + table, null);
				//String x=dataCount2.getString(0);
				int count2=dataCount2.getCount();
				//Log.i("after local count",x);
				Log.i("after server count",""+server_count);
				
			
			}
			try{
				SharedPreferences sharedPref;
				sharedPref = getSharedPreferences(filename,0);
				
		        SharedPreferences.Editor editor = sharedPref.edit();
			    editor.putInt("flag", 41);
				editor.commit();
				Log.i("no exception","no exception.........");
				
				}
				catch(Exception e)
				{
					Log.i("ecpt exception","no exception.........");
				}
		}      
		
	//	Log.i("flag",""+flag);
	}
	
	void update_databaseptp(String table){
		

				//if(RegisterActivity.temp==1)
				{
					
					
					Database_functions info1=new Database_functions(ourcontext);
			        info1.open();
					
					Cursor dataCount = ourdatabase.rawQuery("select s_no from " + table, null);
					int count=dataCount.getCount();
					
					Server_database sd=new Server_database();
					
					int server_count=sd.get_count(table);
					
					Log.i("count count",""+count);
					Log.i("server count",""+server_count);
					
					if(server_count!=count)
					{
						Log.i("server count in if",""+server_count);
			
						sd.setArrayLists(count,table);
						 Log.i("before setarraylists ","hello...");
						
				        int i=sd.server_database_count-(sd.server_database_count-count);
				        int j=sd.name.size();
				        Log.i("j is ",""+j);
						for(int k=0;k<j;k++)
						{
							info1.createEntry(i,sd.name.get(k),sd.info.get(k),
									sd.message.get(k) ,Integer.parseInt(sd.date.get(k))
									,Integer.parseInt(sd.month.get(k)),
									Integer.parseInt(sd.year.get(k)),sd.placement_info.get(k),
									Integer.parseInt(sd.enddate.get(k)),Integer.parseInt(sd.endmonth.get(k)),
									Integer.parseInt(sd.endyear.get(k)),table);
							i++;
							
						}
						info1.close();
						
						Log.i("after server count",""+server_count);
						
					}
					try{
						SharedPreferences sharedPref;
						sharedPref = getSharedPreferences(filename,0);
				        SharedPreferences.Editor editor = sharedPref.edit();
					    editor.putInt("flag", 41);
						editor.commit();
						Log.i("no exception","no exception.........");
						
						}
						catch(Exception e)
						{
							Log.i("ecpt exception","no exception.........");
						}
				} 
				
		
	}
	
	void update_databasedirectory(String table){
			
		
				//if(RegisterActivity.temp==1)
				{
					
					
					Cursor dataCount = ourdatabase.rawQuery("select s_no from " + table, null);
					int count=dataCount.getCount();
					
					Server_database sd=new Server_database();
					int server_count=sd.get_count(table);
					
					Log.i("table start",table);
					Log.i("count count",""+count);
					Log.i("server count",""+server_count);
					if(server_count!=count)
					{
						Log.i("server count in if",""+server_count);
						sd.setArrayListsdirectory(count,table);
						 Log.i("before setarraylists ","hello...");
						Database_functions info1=new Database_functions(ourcontext);
				        info1.open();
				        int i=sd.server_database_count-(sd.server_database_count-count);
				        int j=0;
				        try{
				        j=sd.name.size();
				        }
				        catch(Exception e){}
				        Log.i("j is ",""+j);
						for(int k=0;k<j;k++)
						{
							info1.createEntrydirectory(i,sd.type.get(k),sd.name.get(k),sd.info.get(k),table);
							i++;
							
						}
						info1.close();
						Log.i("after server count",""+server_count);
						Log.i("table ends",table);
						
					}
					try{
						SharedPreferences sharedPref;
						sharedPref = getSharedPreferences(filename,0);
				        SharedPreferences.Editor editor = sharedPref.edit();
					    editor.putInt("flag", 41);
						editor.commit();
						Log.i("no exception","no exception.........");
						
						}
						catch(Exception e)
						{
							Log.i("ecpt exception","no exception.........");
						}
				}      
			
		
				
		}
		
		
	
	/*
	 
	 <ImageView
        android:id="@+id/ImageView01"
        android:layout_width="match_parent"
        android:layout_height="70dp"
        android:layout_marginLeft="40dp"
        android:layout_marginRight="40dp"
        android:layout_marginTop="10dp"
        android:src="@drawable/locations" />

    <ImageView
        android:id="@+id/ImageView02"
        android:layout_width="match_parent"
        android:layout_height="70dp"
        android:layout_marginLeft="40dp"
        android:layout_marginRight="40dp"
        android:layout_marginTop="10dp"
        android:src="@drawable/settings" />
	 
	 
	 */
	
}
