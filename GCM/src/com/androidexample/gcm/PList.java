package com.androidexample.gcm;

public class PList {

	private int iconid;
	private String cname;
	private String pifo;
	private String compdate;
	private int arrow;
	public PList(int iconid,String cname, String pinfo,String compdate,int arrow)
	{
		super();
		this.iconid=iconid;
		this.cname=cname;
		this.pifo=pinfo;	
		this.compdate=compdate;
		this.arrow=arrow;
	}
	
	
	public int geticonid()
	{
		return iconid;	
	}
	
	public String getcname()
	{
		return cname;
	}
	public String getpinfo()
	{	
		return pifo; 
	}
	
	public String getcompdate()
	{	
		return compdate; 
	}
	
	public int getarrow()
	{	
		return arrow; 
	}
	
}
