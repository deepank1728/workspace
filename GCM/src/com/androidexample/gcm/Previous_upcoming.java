package com.androidexample.gcm;

import java.util.Calendar;

import android.util.Log;

public class Previous_upcoming {
	
	public boolean checkdate(String date,String month,String year)
	{
		final Calendar c = Calendar.getInstance();
		int actual_date=c.get(Calendar.DATE);
		int actual_month=c.get(Calendar.MONTH);
		int actual_year=c.get(Calendar.YEAR);
		
		Log.i("Actual Date is ...",""+actual_date);
		Log.i("Actual month is ...",""+actual_month);
		Log.i("Actual year is ...",""+actual_year);
		
		if(actual_year>Integer.parseInt(year))
			return false;
		else if(actual_year<Integer.parseInt(year))
			return true;
		else
		{
			if(actual_month>Integer.parseInt(month))
				return false;
			else if(actual_month<Integer.parseInt(month))
				return true;
			else
			{
				if(actual_date<Integer.parseInt(year))
					return false;
				else
					return true;
			}
			
		}
		
	}

}
