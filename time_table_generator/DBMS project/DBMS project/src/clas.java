import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class clas
{
	public int freelec(int j, String s, String id)
	{
		final String USER = "root";
		final String PASS = "";
		final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		Connection conn = null;
		Statement stmt6 = null;
		Statement stmt5 = null;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("Connecting to a database...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);
		    stmt5 = conn.createStatement();
		    stmt6 = conn.createStatement();
		    System.out.println("connected to the database");
		    ResultSet r3; 
		    ResultSet r4 = stmt6.executeQuery("select c_id from combination where s_id ="+id);
			  while(r4.next())
			  {
				  int xy = r4.getInt("c_id");
				  System.out.println(".......c-id"+xy+"....."+s);
				  r3 = stmt5.executeQuery("select s_id from time_"+xy+"_"+s+" where slot ="+j);
				  r3.next();
				  if(r3.getInt("s_id")!=0)
				  {
					  System.out.print("......"+r3.getString("s_id"));			  
					 return 1;
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
	return 0;
	}
	public int free(int j,int xy,String s)
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
		    ResultSet r3; 
		    for(int k=j;k<j+3;k++)
			  {
				  System.out.println(".......c-id"+xy+"....."+s);
				  r3 = stmt5.executeQuery("select s_id from time_"+xy+"_"+s+" where slot ="+k);
				  r3.next();
				  if(r3.getInt("s_id")!=0)
				  {
					  System.out.print("......"+r3.getString("s_id"));
					  return 1;
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
	return 0;
	}
	public int no_of_lec(String id ,String s,int xy)
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
		    ResultSet r3;
		    for(int j=0;j<9;j++)
		    {
		    	r3 = stmt5.executeQuery("select s_id from time_"+xy+"_"+s+" where s_id ='"+id+"'");
		    	if(r3.next())
		    	return 1;
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
		return 0;
	}
	public int no_of_labs(int xy, String s)
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
		    ResultSet r3; 
		    int m;
			  for(int k=0;k<7;k++)
			  {
				  m = k;
				  r3 = stmt5.executeQuery("select s_id from time_"+xy+"_"+s+" where slot= "+m);
				  r3.next();  
				  int y = r3.getInt("s_id");
				  m++;		 
				  r3 = stmt5.executeQuery("select s_id from time_"+xy+"_"+s+" where slot = "+m);
	    		  r3.next();
				  if((y == r3.getInt("s_id"))&& y!=0)
				  {
					return 1; 
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
		return 0;
	}
	
	public int freetut(int j,String s,String xy)
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
		    ResultSet r3; 
		   r3= stmt5.executeQuery("select s_id from  time_"+xy+"_"+s+" where slot = "+j);
		   if(r3.getInt("s_id")!=0)
		   {
			   return 1;
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
	return 0;
	}
}	
