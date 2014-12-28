import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class create
{
	String str[] = new String[5];
	public void creation(String j)
{
		
		str[0] = "monday";
		str[1] = "tuesday";
		str[2] = "wednesday";
		str[3] = "thursday";
		str[4] = "friday";
		String create = "( slot int primary key," +
				"s_id varchar(20) DEFAULT '0'," +
				"t_id int Default 0,"+
				"room_no int default 0 )";
		final String USER = "root";
		final String PASS = "";
		final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		Connection conn = null;
		Statement stmt5 = null;
		Statement stmt6 = null;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("Connecting to a database...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);
		    stmt5 = conn.createStatement();
		    stmt6 = conn.createStatement();
		    System.out.println("connected to the database");
		    
		    ResultSet r1;
		    r1= stmt6.executeQuery("select c_id from class where name='"+j+"'");
		    r1.next();
		    int i = r1.getInt("c_id");
	       
	        	for(int k=0;k<5;k++)
	        	{
		    		  input in1 = new input();
		    		  in1.insert("create table if not exists time_"+i+"_"+str[k]+create);
		    		  for(int l=0;l<9;l++)
		    		  {
		    			  in1.insert("insert into time_"+i+"_"+str[k]+"(slot) values("+l+")");
		    		  }
				    	  
				 }
			
		}
		  catch(SQLException se)
		   {
		      //Handle errors for JDBC
		      se.printStackTrace();
		   }
		   catch(Exception e)
		   {
		      //Handle errors for Class.forName
		      e.printStackTrace();
		   }
		   finally
		   {
		      //finally block used to close resources
			   try
			   {
				   if(stmt5!=null)
					   conn.close();
			   }
			   catch(SQLException se)
			   {
			   }// do nothing
			   try
			   {
				   if(conn!=null)
					   conn.close();
			   }
			   catch(SQLException se)
			   {
				   se.printStackTrace();
			   }//end finally try
			   
		   }
		
	}
	public void creation(int i)
	{
		
		str[0] = "monday";
		str[1] = "tuesday";
		str[2] = "wednesday";
		str[3] = "thursday";
		str[4] = "friday";
		String create = "( slot int primary key," +
				"s_id varchar(20) DEFAULT '0'," +
				"t_id int Default 0,"+
				"room_no int default 0 )";
		final String USER = "root";
		final String PASS = "";
		final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		Connection conn = null;
		Statement stmt5 = null;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("Connecting to a database...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);
		    stmt5 = conn.createStatement();
		    System.out.println("connected to the database");
		    
	       
	        	for(int j=0;j<5;j++)
	        	{
		    		  input in1 = new input();
		    		  in1.insert("create table if not exists time_"+i+"_"+str[j]+create);
		    		  for(int k=0;k<9;k++)
		    		  {
		    			  in1.insert("insert into time_"+i+"_"+str[j]+"(slot) values("+k+")");
		    		  }
				    	  
				 }
			
		}
		  catch(SQLException se)
		   {
		      //Handle errors for JDBC
		      se.printStackTrace();
		   }
		   catch(Exception e)
		   {
		      //Handle errors for Class.forName
		      e.printStackTrace();
		   }
		   finally
		   {
		      //finally block used to close resources
			   try
			   {
				   if(stmt5!=null)
					   conn.close();
			   }
			   catch(SQLException se)
			   {
			   }// do nothing
			   try
			   {
				   if(conn!=null)
					   conn.close();
			   }
			   catch(SQLException se)
			   {
				   se.printStackTrace();
			   }//end finally try
			   
		   }
		
	}
	public void precreation()
	{
		final String USER = "root";
		final String PASS = "";
		final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		Connection conn = null;
		Statement stmt5 = null;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("Connecting to a database...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);
		    stmt5 = conn.createStatement();
		    System.out.println("connected to the database");
		    ResultSet r2 = stmt5.executeQuery("select count(c_id) as count from class");
			   System.out.println("resultset");
		       r2.next();
		       int a = r2.getInt("count");
		       for(int k=1;k<=a;k++)
		       creation(k);
		}
		  catch(SQLException se)
		   {
		      //Handle errors for JDBC
		      se.printStackTrace();
		   }
		   catch(Exception e)
		   {
		      //Handle errors for Class.forName
		      e.printStackTrace();
		   }
		   finally
		   {
		      //finally block used to close resources
			   try
			   {
				   if(stmt5!=null)
					   conn.close();
			   }
			   catch(SQLException se)
			   {
			   }// do nothing
			   try
			   {
				   if(conn!=null)
					   conn.close();
			   }
			   catch(SQLException se)
			   {
				   se.printStackTrace();
			   }//end finally try
			   
		   }
	}
}

