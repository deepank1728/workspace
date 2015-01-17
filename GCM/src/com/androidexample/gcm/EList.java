package com.androidexample.gcm;

	public class EList {

		private String ename;
		private String eifo;
		private String edate;
		private int arrow;
		public EList(String ename, String einfo,String edate,int arrow)
		{
			super();
			
			this.ename=ename;
			this.eifo=einfo;	
			this.edate=edate;
			this.arrow=arrow;
		}
		
		
		
		
		public String getename()
		{
			return ename;
		}
		public String geteinfo()
		{	
			return eifo; 
		}
		
		public String getedate()
		{	
			return edate; 
		}
		
		public int getarrow()
		{	
			return arrow; 
		}
		
	}


