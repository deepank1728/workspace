import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class room 
{
	public int free(String id,int j,String s,int a)
	{
		final String USER = "root";
		final String PASS = "";
		final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		Connection conn = null;
		Statement stmt5 = null;
		Statement stmt6 = null;
		int z = 0;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("Connecting to a database...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);
		    stmt5 = conn.createStatement();
		    stmt6 = conn.createStatement();
		    System.out.println("connected to the database");
		    ResultSet r3; 
		    r3 = stmt5.executeQuery("select lab_room_type from subject where s_id = "+id);
			  r3.next();
			  String t = r3.getString("lab_room_type");
			  r3 = stmt5.executeQuery("select room_no from room where type = '"+t+"'");
			  while(r3.next())
			  {
				  int f = 0;
				  for(int k=1;k<=a;k++)
				  {
					  for(int l=j;l<j+3;l++)
					  {  
						  ResultSet r4 = stmt6.executeQuery("select room_no from time_"+k+"_"+s+" where slot = "+l);
						  r4.next();
						   z = r4.getInt("room_no");
						  if(z==r3.getInt("room_no"))
						  {
							  f=1;
							  break;
						  }
					  }
					  if(f==1)
					  break ;  
				  }
				  if(f==0)
				  {
					  z = r3.getInt("room_no");
					  return z;
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
	public int freelec(String id,int j,String s,int a)
	{
		final String USER = "root";
		final String PASS = "";
		final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		Connection conn = null;
		Statement stmt5 = null;
		Statement stmt6 = null;
		Statement stmt7 = null;
		int z = 0;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("Connecting to a database...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);
		    stmt5 = conn.createStatement();
		    stmt6 = conn.createStatement();
		    stmt7 = conn.createStatement();
		    System.out.println("connected to the database");
		    ResultSet r3;
		    ResultSet r5;
		    r5= stmt7.executeQuery("select course from combination where s_id="+id);
		    r5.next();
		    int b= r5.getInt("course");
		    if(b==1)
		    {
			  r3 = stmt5.executeQuery("select room_no from room where type = 'LT'");
			  while(r3.next())
			  {
				  int f = 0;
				  for(int k=1;k<=a;k++)
				  {
					 
						  ResultSet r4 = stmt6.executeQuery("select room_no from time_"+k+"_"+s+" where slot = "+j);
						  r4.next();
						   z = r4.getInt("room_no");
						  if(z==r3.getInt("room_no"))
						  {
							  f=1;
							  break;
						  }
					  
					  if(f==1)
					  break ;  
				  }
				  if(f==0)
				  {
					  z = r3.getInt("room_no");
					  return z;
				  }
			  } 
		    }
		    
		    
		    if(b==0)
		    {
		    	 r3 = stmt5.executeQuery("select room_no from room where type = 'TR'");
				  while(r3.next())
				  {
					  int f = 0;
					  for(int k=1;k<=a;k++)
					  {
						 
							  ResultSet r4 = stmt6.executeQuery("select room_no from time_"+k+"_"+s+" where slot = "+j);
							  r4.next();
							   z = r4.getInt("room_no");
							  if(z==r3.getInt("room_no"))
							  {
								  f=1;
								  break;
							  }
						  
						  if(f==1)
						  break ;  
					  }
					  if(f==0)
					  {
						  z = r3.getInt("room_no");
						  return z;
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
	
	
	
	public int freetut(String id,int j,String s,int a)
	{
		final String USER = "root";
		final String PASS = "";
		final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		Connection conn = null;
		Statement stmt5 = null;
		Statement stmt6 = null;
		int z = 0;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("Connecting to a database...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);
		    stmt5 = conn.createStatement();
		    stmt6 = conn.createStatement();
		    System.out.println("connected to the database");
		    ResultSet r3; 
			  r3 = stmt5.executeQuery("select room_no from room where type = 'TR'");
			  while(r3.next())
			  {
				  int f = 0;
				  for(int k=1;k<=a;k++)
				  {
					 
						  ResultSet r4 = stmt6.executeQuery("select room_no from time_"+k+"_"+s+" where slot = "+j);
						  r4.next();
						   z = r4.getInt("room_no");
						  if(z==r3.getInt("room_no"))
						  {
							  f=1;
							  break;
						  }
					  
					  if(f==1)
					  break ;  
				  }
				  if(f==0)
				  {
					  z = r3.getInt("room_no");
					  return z;
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
}
