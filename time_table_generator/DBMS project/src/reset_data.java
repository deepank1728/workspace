import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.*;




public class reset_data {

	String str[] = new String[5];
	{ 
	str[0] = "monday";
	str[1] = "tuesday";
	str[2] = "wednesday";
	str[3] = "thursday";
	str[4] = "friday";
	}

	public void delete()
	{
	   input in1 = new input();
	   final String USER = "root";
	    final String PASS = "";
	    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
	    Connection conn = null;
	    Statement stmt = null;	
	    try
	    {
	    Class.forName("com.mysql.jdbc.Driver");
    	System.out.println("Connecting to a database...");
    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
    	stmt = conn.createStatement();
    	
        ResultSet r3; 
        
        r3 = stmt.executeQuery("select count(c_id) as count from  class");
        r3.next();
        
	    
	   int m= r3.getInt("count");
	   System.out.println("dffgiohjopo...........................................");
	   for(int i=1;i<m+2;i++ )
	   {
		   for(int j=0;j<5;j++)
		   {
			   in1.insert("drop table time_"+i+"_"+str[j]);
			  
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
		    	  System.out.println("dffgiohjopo...........................................");
		         if(stmt!=null)
		            conn.close();
		      }
		      catch(SQLException se)
		      {
		      }// do nothing
		      try
		      {
		    	  System.out.println("dffgiohjopo...........................................");
		         if(conn!=null)
		            conn.close();
		      }
		      catch(SQLException se)
		      {
		         se.printStackTrace();
		      }//end finally try
		   }

	
	   
	   in1.insert("truncate table combination");
	   in1.insert("truncate table class");
	   in1.insert("truncate table teacher");
	   in1.insert("truncate table subject");
	   in1.insert("truncate table room");
	   in1.insert("truncate table t_hour");
	   
	}
}
