import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;





public class input
{
	
	public void insert(String sql)
	{
		final String USER = "root";
	    final String PASS = "";
	    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
	    Connection conn = null;
	    Statement stmt = null;
	    try
	    {
	      //STEP 2: Register JDBC driver
	      Class.forName("com.mysql.jdbc.Driver");
	      //STEP 3: Open a connection
	      conn = DriverManager.getConnection(DB_URL, USER, PASS);
	      //STEP 4: Execute a query
	      stmt = conn.createStatement();
	      stmt.executeUpdate(sql);
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
	         if(stmt!=null)
	            conn.close();
	      }
	      catch(SQLException se)
	      {
	      }// do nothing
	      try{
	         if(conn!=null)
	            conn.close();
	      }
	      catch(SQLException se)
	      {
	         se.printStackTrace();
	      }//end finally try
	   }
	}
	public void teacher(String i,String x)
	{
		insert("INSERT INTO teacher " +
	                   "VALUES ("+i+",'"+x+"')");
	}
	public void clas(String x)
	{
		int count = count();
		count++;
		
		insert("INSERT INTO class (c_id ,name)" +
	                   "VALUES ("+count+ " ,'"+x+"')");
	}
	public void subject(String i,String x,String a,String b,String d,String c)
	{
		insert("INSERT INTO subject " +
	                   "VALUES ("+i+",'"+x+"',"+a+","+b+",'"+d+"',"+c+")");
	}
	public void room(String i,String x)
	{
		insert("INSERT INTO room " +
	                   "VALUES ("+i+",'"+x+"')");
	}
	public void combination(String i,String x,String a, String c)
	{
		
			int z = comb2(x);
			
			insert("INSERT INTO combination(t_id,c_id,s_id,course) " +
                "VALUES ("+i+","+z+","+a+","+c+")");
			
	}
	
	public int count()
	{
		Statement stmt3 = null;
		 Connection conn = null;
		 final String USER = "root";
		    final String PASS = "";
		    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		    try
		    {    
		    	Class.forName("com.mysql.jdbc.Driver");
		    	System.out.println("Connecting to a database...");
		    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
		       
		      stmt3 = conn.createStatement();
		      ResultSet r3= stmt3.executeQuery("select count(*) as count from class");
		      r3.next();
		      return r3.getInt("count");
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
			         if(stmt3!=null)
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
	

	public int comb2(String m)
	{
		 Statement stmt3 = null;
		 Connection conn = null;
		 final String USER = "root";
		    final String PASS = "";
		    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		    try
		    {    
		    	Class.forName("com.mysql.jdbc.Driver");
		    	System.out.println("Connecting to a database...");
		    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
		       
		      stmt3 = conn.createStatement();
		      ResultSet r3= stmt3.executeQuery("select c_id from class where name ='"+m+"'");
		      r3.next();
		      return r3.getInt("c_id");
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
			         if(stmt3!=null)
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
