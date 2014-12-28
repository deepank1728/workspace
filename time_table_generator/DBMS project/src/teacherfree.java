import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class teacherfree
{
	public int free(int j, int i, String s, int x, int a)
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
		    for(int k=1;k<=a;k++)   // teacher free......
		    {
			  m = j;
			  r3 = stmt5.executeQuery("select t_id from time_"+k+"_"+s+" where slot= "+m);
			  r3.next();  
			  int y = r3.getInt("t_id");
			  if(x==y)
			  {
				  return 1;
			  }
		  
			  else 
			  {
				  m++;		 
				  r3 = stmt5.executeQuery("select t_id from time_"+k+"_"+s+" where slot = "+m);
				  r3.next();
				  if(x==r3.getInt("t_id"))
				  {
					  return 1;
				  }
				  else 
				  {
					  m++;
					  r3 = stmt5.executeQuery("select t_id from time_"+k+"_"+s+" where slot = "+m);
		    		  r3.next();
					  if(x==r3.getInt("t_id"))
					  {
						  return 1;
					  }				    				  			    					  
				  }		    				  
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
	public int workinghours(int x, String s)
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
		    input in1 = new input();
			  in1.insert("insert into t_hour(t_id,day) values("+x+",'"+s+"')");
			  r3 = stmt5.executeQuery("select hour from t_hour where t_id ="+x+" and day ='"+s+"'"); 	
			  r3.next();
			  if(r3.getInt("hour")>2)
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
	public int freelec(int j, int i, String s, int x, int a)
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
		    for(int k=1;k<=a;k++)   // teacher free......
		    {
			  m = j;
			  r3 = stmt5.executeQuery("select t_id from time_"+k+"_"+s+" where slot= "+m);
			  r3.next();  
			  int y = r3.getInt("t_id");
			  if(x==y)
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
	public int workinghourslec(int x, String s)
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
		    input in1 = new input();
			  in1.insert("insert into t_hour(t_id,day) values("+x+",'"+s+"')");
			  r3 = stmt5.executeQuery("select hour from t_hour where t_id ="+x+" and day ='"+s+"'"); 	
			  r3.next();
			  if(r3.getInt("hour")>4)
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
