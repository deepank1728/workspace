import java.sql.*;
import java.math.*;

//x teaacher id
//s str[i]..
public class generate 
{
	String str[] = new String[5];
		public void labassign()
		{
			int alt =0;
			str[0] = "monday";
			str[1] = "tuesday";
			str[2] = "wednesday";
			str[3] = "thursday";
			str[4] = "friday";
			final String USER = "root";
		    final String PASS = "";
		    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		    Connection conn = null;
		    Statement stmt = null;		   
		    Statement stmt1 = null;
		 
		    try
		    {
		    	Class.forName("com.mysql.jdbc.Driver");
		    	System.out.println("Connecting to a database...");
		    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
		        stmt = conn.createStatement();
		        stmt1 = conn.createStatement();
		      System.out.println("connected to the database");
		      ResultSet	r2;
		      System.out.println("resultset");
		      teacherfree t1 = new teacherfree();
		      clas cl1 = new clas();
		      room r0 = new room();
		     	r2 = stmt.executeQuery("select count(c_id) as count from class");
			   System.out.println("resultset");
		       r2.next();
		       int a = r2.getInt("count");
		   
		      System.out.println(".......the programme is in lab assign is ..."+a);
		      ResultSet r1 = stmt1.executeQuery("select subject.s_id,combination.c_id from combination,subject where no_of_labs > 0 and subject.s_id=combination.s_id");
		    
		
		      while(r1.next())
		      {
		    	  alt =0;
		    	  r2 = stmt.executeQuery("select assigned from combination where s_id = "+r1.getInt("s_id")+" and c_id = "+r1.getInt("c_id"));
		    	  r2.next();
		    	  int assigned = r2.getInt("assigned"); 
		    	  if(assigned >= 1)
		          continue;
		    	  String w = r1.getString("c_id");
		    	  int z =0;
		    	  String id = r1.getString("s_id");		    	
		    	  r2 = stmt.executeQuery("select t_id from combination group by s_id having s_id= "+id);  //
		    	  r2.next();
		    	  int x =r2.getInt("t_id");
		    	  int f = 0;
		    	  for(int i=0;i<5;i++)
		    	  {
		    		
		    		  for(int j=0;j<7;j++)
		    		  {
		    			  if(j==0||j==1||j==5||j==6)
		    			  {
		    				  
		    				  
		    				  f = 0;
			    			  f = t1.free(j, i, str[i], x, a);  // teacher free...
			    			  
			    			  if(f==0)  // teacher working hours....
			    			  {		  
			    				 f = t1.workinghours(x, str[i]);  // working hours...
			    				 if(f==1)
			    				 break;
			    			  }
			    			  if(f==0) // class free.....
			    			  {
			    				 f = cl1.free(j, r1.getInt("c_id"), str[i]);	 	 
			    			  }
			    			  if(f==0&&alt==0) //  no_of_labs_of_class.....
			    			  { 
			    				  if(i==0)
			    				  {
			    					  f = cl1.no_of_labs(r1.getInt("c_id"), str[i]);
			    					  if(f==0)
			    					  f = cl1.no_of_labs(r1.getInt("c_id"), str[i+1]);
			    				  }	
			    				  else if(i==1||i==2||i==3)
			    				  {
			    					  f = cl1.no_of_labs(r1.getInt("c_id"), str[i-1]);
			    					  if(f==0)
			    					  f = cl1.no_of_labs(r1.getInt("c_id"), str[i]);
			    					  if(f==0)
			    					  f = cl1.no_of_labs(r1.getInt("c_id"), str[i+1]);			    					  
			    				  }	
			    				  else if(i==4)
			    				  {
			    					  f = cl1.no_of_labs(r1.getInt("c_id"), str[i-1]);
			    					  if(f==0)
			    					  f = cl1.no_of_labs(r1.getInt("c_id"), str[i]);
			    					  if(f==1)
			    					  {
			    						  i = -1;
			    						  alt =1;
			    					  }
			    				  }	
			    				  if(f==1)
			    				  break;
			    			  }
			    			  if(f==0&&alt==1)
			    			  {
			    				  f=0;
			    				  f = cl1.no_of_labs(r1.getInt("c_id"), str[i]);
			    			  }
			    				
			    			  if(f==0)  // room free...
			    			  {
			    				  z = r0.free(id, j, str[i], a);
			    				  if(z==0)
			    				  f =1;
			    			  } 
			    			  if(f==0)
			    			  {
			    				 
			    				  input in1 = new input();
			    				  in1.insert("update time_"+w+"_"+str[i]+" set room_no ="+z+" ,s_id ="+id+" ,t_id ="+x+" where slot ="+j);
			    				  int v =j+1;
			    				  in1.insert("update time_"+w+"_"+str[i]+" set room_no ="+z+" ,s_id ="+id+" ,t_id ="+x+" where slot ="+v);
			    				  v++;
			    				  in1.insert("update time_"+w+"_"+str[i]+" set room_no ="+z+" ,s_id ="+id+" ,t_id ="+x+" where slot ="+v);
			    				  in1.insert("update t_hour set hour = hour+3 where t_id ="+x+" and day ='"+str[i]+"'");
			    				  in1.insert("update combination set assigned = 1 where s_id = "+r1.getInt("s_id")+" and c_id = "+r1.getInt("c_id"));
			    				  break;
			    			  }
			    		  }
		    		  }
		    		  if(f==0)
		    		 break;
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
		         if(stmt!=null)
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
		public void lecture_assign()
		{
			
			str[0] = "monday";
			str[1] = "tuesday";
			str[2] = "wednesday";
			str[3] = "thursday";
			str[4] = "friday";
			final String USER = "root";
		    final String PASS = "";
		    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		    Connection conn = null;
		    Statement stmt = null;		   
		    Statement stmt1 = null;
		    Statement stmt3 = null;
		    try
		    {
		    	
			      teacherfree t1 = new teacherfree();
			      clas cl1 = new clas();
			      room r0 = new room();

		    	Class.forName("com.mysql.jdbc.Driver");
		    	System.out.println("Connecting to a database...");
		    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
		        stmt = conn.createStatement();
		        stmt1 = conn.createStatement();
		      stmt3 = conn.createStatement();
		      System.out.println("connected to the database");
		      ResultSet r1 = stmt1.executeQuery("select subject.s_id,combination.c_id from combination,subject where no_of_lectures > 0 and subject.s_id=combination.s_id");
		      ResultSet r2;
		     
		      	r2 = stmt.executeQuery("select count(c_id) as count from class");
		      System.out.println("resultset");
		      r2.next();
		      int a = r2.getInt("count");
		      while(r1.next())
		      {
		    	  int xy = r1.getInt("c_id");
		    	  r2 = stmt.executeQuery("select no_of_lectures from subject where s_id = "+r1.getInt("s_id"));
		    	  r2.next();
		    	  int count1 = r2.getInt("no_of_lectures");
		    	  r2 = stmt.executeQuery("select assigned from combination where s_id = "+r1.getInt("s_id")+" and c_id = "+r1.getInt("c_id"));
		    	  r2.next();
		    	  int assigned = r2.getInt("assigned");
		    	  r2 = stmt.executeQuery("select (no_of_labs+no_of_lectures) as number from subject where s_id ="+r1.getInt("s_id"));
		    	  r2.next();
		    	  System.out.println("........."+r2.getInt("number"));
		    	  if(assigned >= r2.getInt("number"))  
		          continue;
			    	  
			    	
			    	  int z =0;
			    	  String id = r1.getString("s_id");		    	
			    	  r2 = stmt.executeQuery("select t_id from combination group by s_id having s_id= "+id);  //
			    	  r2.next();
			    	  int x =r2.getInt("t_id");
			    	  int f = 0;
			    	  for(;;)
			    	  {
			    		  double rans = Math.random()*5;
				    		int i = (int)rans;
			    		  for(int j=0;j<9;j++)
			    		  {
			    			  	  if(j==4)			// lunch break
			    			  	  continue;
			    				  f = 0;
			    				  f = t1.freelec(j, i, str[i], x, a);   // teacher free..
				    			  if(f==0)  // teacher working hours....
				    			  {		  
				    				  f = t1.workinghourslec(x, str[i]);
				    				  if(f==1)
				    				  break;
				    				  
				    			  }
				    			  if(f==0) // class free.....
				    			  {
				    					 f = cl1.freelec(j, str[i], id);
				    				  	  	  
				    			  }
				    			  if(f==0)  // room free...
				    			  {
				    				 z = r0.freelec(id, j, str[i], a); 
				    				 if(z==0)
				    				 f=1;
				    				 
				    			  }
				    			  if(f==0)
				    			  {
				    				  f = cl1.no_of_lec(id, str[i], xy);
				    			  }
				    			  if(f==0)
				    			  {
				    				  count1--;
				    				  input in1 = new input();				    				   
				    				  ResultSet r4 = stmt3.executeQuery("select c_id from combination where s_id ="+r1.getInt("s_id"));
				    				  while(r4.next())
				    				  {
					    				  
					    				  System.out.println("......"+r1.getInt("s_id")+"...deenbandhu");
					    				  in1.insert("update time_"+r4.getInt("c_id")+"_"+str[i]+" set room_no ="+z+" ,s_id ="+id+" ,t_id ="+x+" where slot ="+j);    				  
					    				  in1.insert("update combination set assigned = assigned+1 where s_id = "+r1.getInt("s_id")+" and c_id = "+r4.getInt("c_id"));	    				  
				    				  }
				    				  in1.insert("update t_hour set hour = hour+1 where t_id ="+x+" and day ='"+str[i]+"'");
				    				  break;
				    			  }
			    		  }
			    		  if(count1==0)
			    		 break;
			    	  }  // i ends....
		    
		      }// while end.....
		      
		    }// try end..
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
		
		public void tut_assign()
		{
			
			str[0] = "monday";
			str[1] = "tuesday";
			str[2] = "wednesday";
			str[3] = "thursday";
			str[4] = "friday";
			final String USER = "root";
		    final String PASS = "";
		    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		    Connection conn = null;
		    Statement stmt = null;		   
		    Statement stmt1 = null;
		   
		    try
		    {
		    	
			      teacherfree t1 = new teacherfree();
			      clas cl1 = new clas();
			      room r0 = new room();

		    	Class.forName("com.mysql.jdbc.Driver");
		    	System.out.println("Connecting to a database...");
		    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
		        stmt = conn.createStatement();
		        stmt1 = conn.createStatement();
		     
		      System.out.println("connected to the database");
		      ResultSet r1 = stmt1.executeQuery("select subject.s_id,combination.c_id from combination,subject where no_of_tut > 0 and subject.s_id=combination.s_id");
		      ResultSet r2;
		     
		     
		      	r2 = stmt.executeQuery("select count(c_id) as count from class");
		      System.out.println("resultset");
		      r2.next();
		      int a = r2.getInt("count");
		      while(r1.next())
		      {
		    	 
		    	  int count1 =1;
		    	  r2 = stmt.executeQuery("select assigned from combination where s_id = "+r1.getInt("s_id")+" and c_id = "+r1.getInt("c_id"));
		    	  r2.next();
		    	  int assigned = r2.getInt("assigned");
		    	  r2 = stmt.executeQuery("select (no_of_labs+no_of_lectures+no_of_tut) as number from subject where s_id ="+r1.getInt("s_id"));
		    	  r2.next();
		    	  System.out.println("........."+r2.getInt("number"));
		    	  if(assigned >= r2.getInt("number"))  
		          continue;
			    	  
			    	
			    	  int z =0;
			    	  String id = r1.getString("s_id");		    	
			    	  r2 = stmt.executeQuery("select t_id from combination group by s_id having s_id= "+id);  //
			    	  r2.next();
			    	  int x =r2.getInt("t_id");
			    	  int f = 0;
			    	  for(int i=0;i<5;i++)
			    	  {
			    		  for(int j=0;j<9;j++)
			    		  {
			    			  	  if(j==4)			// lunch break
			    			  	  continue;
			    				  f = 0;
			    				  f = t1.freelec(j, i, str[i], x, a);   // teacher free..
				    			  if(f==0)  // teacher working hours....
				    			  {		  
				    				  f = t1.workinghourslec(x, str[i]);
				    				  if(f==1)
				    				  break;
				    				  
				    			  }
				    			  if(f==0) // class free.....
				    			  {
				    					 f = cl1.freetut(j, str[i], id);
				    				  	  	  
				    			  }
				    			  if(f==0)  // room free...
				    			  {
				    				 z = r0.freetut(id, j, str[i], a); 
				    				 if(z==0)
				    				 f=1;
				    				 
				    			  }
				    			  if(f==0)
				    			  {
				    				  count1--;
				    				  input in1 = new input();				    				   
				    				 
					    				  
					    				  System.out.println("......"+r1.getInt("s_id")+"...deenbandhu");
					    				  in1.insert("update time_"+r1.getInt("c_id")+"_"+str[i]+" set room_no ="+z+" ,s_id ="+id+" ,t_id ="+x+" where slot ="+j);    				  
					    				  in1.insert("update combination set assigned = assigned+1 where s_id = "+r1.getInt("s_id")+" and c_id = "+r1.getInt("c_id"));	    				  
				    				  
				    				  in1.insert("update t_hour set hour = hour+1 where t_id ="+x+" and day ='"+str[i]+"'");
				    				  break;
				    			  }
			    		  }
			    		  if(count1==0)
			    		 break;
			    	  }  // i ends....
		    
		      }// while end.....
		      
		    }// try end..
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
