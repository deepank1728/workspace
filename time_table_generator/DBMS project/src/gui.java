import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.sql.*;

public class gui extends JFrame
{
	   //  Database credentials
	public int c;   
	public JButton rb1;
	public JButton rb2;
	public JButton rb3;
	public JButton rb4;
	public JButton rb5;
	public JButton rb6;
	public JButton rb7;
	public JButton rb8;
	public JButton rb9;
	
	public JTextField tf1;
	public JTextField tf2;
	public JTextField tf3;
	public JTextField tf4;
	public JTextField tf5;
	public JTextField tf6;
	
	public JComboBox combination1;
	public JComboBox combination2;
	public JComboBox combination3;
	public JComboBox combination4;
	final String USER = "root";
    final String PASS = "";
    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
    Connection conn = null;
    Statement stmt = null;		   
    Statement stmt1 = null;
    Statement stmt2 = null;
    Statement stmt3 = null;

	
	public JLabel jl1;
	public JLabel jl2;
	public JLabel jl3;
	public JLabel jl4;
	public JLabel jl5;
	public JLabel jl6;
	
	public JLabel jl8;
	public JLabel jl9;
	public JLabel j20;
	public JLabel j21;
	public JLabel j22;
	public JLabel j23;
	public JLabel j24;
	public JLabel j25;
	public JLabel j26;
	public JLabel j27;
	public JLabel j29;
	
	public String x;
	public String combination1s;
	public String combination2s;
	public String combination3s;
	public String combination4s;
	public String combination5s;

	

	public gui()
	{
		super("                        TIME-TABLE-GENERATOR using database management");
		create c2 = new create();
		c2.precreation();
		setLayout(null);
		setBackground( Color.BLACK );	
		rb1=new JButton("teacher");
		rb1.setLocation(10,100);
		rb1.setSize(150,30);
		add(rb1);
		
		rb2=new JButton("subject");
		add(rb2);
		rb2.setLocation(200,100);
		rb2.setSize(150,30);
		
		rb3=new JButton("batch");
		add(rb3);
		rb3.setLocation(400,100);
		rb3.setSize(150,30);
		
		rb6=new JButton("room");
		add(rb6);
		rb6.setLocation(200,50);
		rb6.setSize(150,30);
		
		rb7=new JButton("combination");
		add(rb7);
		rb7.setLocation(400,50);
		rb7.setSize(150,30);
		
		tf1=new JTextField("",10);
		add(tf1);
		tf1.setLocation(200,150);
		tf1.setSize(150,30);
		
		tf2=new JTextField("",10);
		add(tf2);
		tf2.setLocation(200,200);
		tf2.setSize(150,30);
		
		
		tf3=new JTextField("",10);
		add(tf3);
		tf3.setSize(150,30);
		tf3.setLocation(200,250);
		
		tf4=new JTextField("",10);
		add(tf4);
		tf4.setLocation(200,300);
		tf4.setSize(150,30);
		
		tf5=new JTextField("",10);
		add(tf5);
		tf5.setLocation(200,350);
		tf5.setSize(150,30);
		
		tf6=new JTextField("",10);
		add(tf6);
		tf6.setLocation(200,400);
		tf6.setSize(150,30);
		
		rb4=new JButton("Submit");
		add(rb4);
		rb4.setLocation(350,500);
		rb4.setSize(150,30);
		rb4.setVisible(false);
		
		rb5 = new JButton("generate");
		add(rb5);
		rb5.setLocation(400,400);
		rb5.setSize(150,30);
		rb5.setVisible(false);
		
		rb8=new JButton("delete data");
		add(rb8);
		rb8.setLocation(200,500);
		rb8.setSize(150,30);
		rb8.setVisible(true);
		
		rb9=new JButton("reset data");
		add(rb9);
		rb9.setLocation(50,500);
		rb9.setSize(150,30);
		rb9.setVisible(true);
		
		tf1.setVisible(false);
		
		tf2.setVisible(false);
		
		tf3.setVisible(false);
		
		tf4.setVisible(false);
		
		tf5.setVisible(false);
		
		tf6.setVisible(false);
		
		validate();
		
		jl9=new JLabel("Time Table Generator Using Database Management");
		add(jl9);
		jl9.setLocation(150,20);
		jl9.setSize(300,20);
		
		jl1=new JLabel("Teacher Id");
		add(jl1);
		jl1.setLocation(10,150);
		jl1.setSize(150,30);
		
		jl2=new JLabel("Name");
		add(jl2);
		jl2.setLocation(10,200);
		jl2.setSize(150,30);
		
		jl3=new JLabel("Subject Id");
		add(jl3);
		jl3.setLocation(10,150);
		jl3.setSize(150,30);
		
		jl4=new JLabel("Name");
		add(jl4);
		jl4.setLocation(10,200);
		jl4.setSize(150,30);
		
		jl5=new JLabel("No.of lectures");
		add(jl5);
		jl5.setLocation(10,250);
		jl5.setSize(150,30);
		
		
		jl6=new JLabel("No. of labs");
		add(jl6);
		jl6.setLocation(10,300);
		jl6.setSize(150,30);
		
		
		
		j20=new JLabel("no_of_tut");
		add(j20);
		j20.setLocation(10,350);
		j20.setSize(150,30);
		
		j21=new JLabel("lab_rm_tp");
		add(j21);
		j21.setLocation(10,400);
		j21.setSize(150,30);
		
		
		
		jl8=new JLabel("Name");
		add(jl8);
		jl8.setLocation(10,150);
		jl8.setSize(150,30);
		
		j22=new JLabel("room_no.");
		add(j22);
		j22.setLocation(10,150);
		j22.setSize(150,30);
		
		j23=new JLabel("Type");
		add(j23);
		j23.setLocation(10,200);
		j23.setSize(150,30);
		
		j24=new JLabel("subject ID");
		add(j24);
		j24.setLocation(50,170);
		j24.setSize(150,30);
		
		j25=new JLabel("teacher ID");
		add(j25);
		j25.setLocation(210,170);
		j25.setSize(150,30);
		
		j26=new JLabel("class name");
		add(j26);
		j26.setLocation(370,170);
		j26.setSize(150,30);
		
		j27=new JLabel("course");
		add(j27);
		j27.setLocation(220,240);
		j27.setSize(150,30);
		
		j29=new JLabel("Select 0 for M.Tech and 1 for B.Tech in courses");
		add(j29);
		j29.setLocation(50,310);
		j29.setSize(350,30);
		
		add(j29);
		j29.setVisible(false);
		
		combination1=new JComboBox();
		combination2=new JComboBox();
		combination3=new JComboBox();
		combination4=new JComboBox();
		
		combination1.setVisible(false);
		combination2.setVisible(false);
		combination3.setVisible(false);
		combination4.setVisible(false);
		
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
	    	System.out.println("Connecting to a database...");
	    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
	        stmt1 = conn.createStatement();
	      stmt2 = conn.createStatement();
	      stmt3 = conn.createStatement();
	      
	      ResultSet r1=stmt1.executeQuery("select s_id from subject");
	      ResultSet r2=stmt2.executeQuery("select t_id from teacher");
	      ResultSet r3=stmt3.executeQuery("select name from class");
	      
	      while(r1.next())
	      {
	    	  combination1.addItem(r1.getInt("s_id"));
	      }
	      
	      while(r2.next())
	      {
	    	  combination2.addItem(r2.getInt("t_id"));
	      }
	      
	      while(r3.next())
	      {
	    	  combination3.addItem(r3.getString("name"));
	      }
	     combination4.addItem("0");
	     combination4.addItem("1");
	      
	      add(combination1);
	      add(combination2);
	      add(combination3);
	      add(combination4);
	      combination1.setBounds(50,200,150,30);
	      combination2.setBounds(210,200,150,30);
	      combination3.setBounds(370,200,150,30);
	      combination4.setBounds(210,270,150,30);
	     
	      combination1.setEditable(false);
	      combination2.setEditable(false);
	      combination3.setEditable(false);
	      combination4.setEditable(false);
	      
	    
	      
	      
	      HandlerClass10 handler10 = new HandlerClass10();
	  	combination1.addItemListener(handler10);
	  	
	  	HandlerClass11 handler11 = new HandlerClass11();
	  	combination2.addItemListener(handler11);
	  	
	  	HandlerClass12 handler12 = new HandlerClass12();
	  	combination3.addItemListener(handler12);
	  	
	  	HandlerClass13 handler13 = new HandlerClass13();
	  	combination4.addItemListener(handler13);
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
		
		
		jl1.setVisible(false);
		jl2.setVisible(false); 
		jl3.setVisible(false);
		jl4.setVisible(false);
		jl5.setVisible(false);
		jl6.setVisible(false);
		
		jl8.setVisible(false);
		j20.setVisible(false);
		j21.setVisible(false);
		j22.setVisible(false);
		j23.setVisible(false);
		j24.setVisible(false);
		j25.setVisible(false);
		j26.setVisible(false);
		j27.setVisible(false);
		
		

	HandlerClass handler=new HandlerClass();
	rb1.addActionListener(handler);
	
	HandlerClass2 handler2=new HandlerClass2();
	rb2.addActionListener(handler2);
	
	HandlerClass3 handler3=new HandlerClass3();
	rb3.addActionListener(handler3);
	
	HandlerClass4 handler4 = new HandlerClass4();
	rb4.addActionListener(handler4);
	
	HandlerClass5 handler5 = new HandlerClass5();
	rb5.addActionListener(handler5);
	
	HandlerClass6 handler6 = new HandlerClass6();
	rb6.addActionListener(handler6);
	
	HandlerClass7 handler7 = new HandlerClass7();
	rb7.addActionListener(handler7);
	
	HandlerClass8 handler8 = new HandlerClass8();
	rb8.addActionListener(handler8);
	
	HandlerClass9 handler9 = new HandlerClass9();
	rb9.addActionListener(handler9);

	
	}
 	
	public class HandlerClass8 implements ActionListener
	{	
		public void actionPerformed(ActionEvent event)
		{
			delete_gui go=new delete_gui();
			go.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			go.setSize(700,600);
			go.setVisible(true);
		}
	}	
	
	
	public class HandlerClass9 implements ActionListener
	{	
		public void actionPerformed(ActionEvent event)
		{
			reset_data r = new reset_data();
			r.delete();
		}
	}	
	
	
	public class HandlerClass implements ActionListener
	{	
		public void actionPerformed(ActionEvent event)
		{	
			c = 1;
			tf1.setVisible(true);
			tf2.setVisible(true);
			tf1.setText("");
			tf2.setText("");
			tf3.setVisible(false);
			tf4.setVisible(false);
			tf5.setVisible(false);
			tf6.setVisible(false);
			jl1.setVisible(true);
			jl2.setVisible(true);
			jl3.setVisible(false);
			jl4.setVisible(false);
			jl5.setVisible(false);
			jl6.setVisible(false);
			
			jl8.setVisible(false);
			rb4.setVisible(true);
			rb5.setVisible(true);
			j20.setVisible(false);
			j21.setVisible(false);
			j22.setVisible(false);
			j23.setVisible(false);
			j24.setVisible(false);
			j25.setVisible(false);
			j26.setVisible(false);
			j27.setVisible(false);
			j29.setVisible(false);
			combination1.setVisible(false);
			combination2.setVisible(false);
			combination3.setVisible(false);
			combination4.setVisible(false);

			validate();	
		}
	}
	public class HandlerClass2 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			c = 2;
			tf1.setVisible(true);
			tf2.setVisible(true);
			tf3.setVisible(true);
			tf4.setVisible(true);
			tf5.setVisible(true);
			tf6.setVisible(true);
			tf1.setText("");
			tf2.setText("");
			tf3.setText("");
			tf4.setText("");
			tf5.setText("");
			tf6.setText("");
			jl1.setVisible(false);
			jl2.setVisible(false);
			jl3.setVisible(true);
			jl4.setVisible(true);
			jl5.setVisible(true);
			jl6.setVisible(true);
			
			jl8.setVisible(false);
			rb4.setVisible(true);
			rb5.setVisible(true);
			j20.setVisible(true);
			j21.setVisible(true);
			j22.setVisible(false);
			j23.setVisible(false);
			j24.setVisible(false);
			j25.setVisible(false);
			j26.setVisible(false);
			j27.setVisible(false);
			j29.setVisible(false);
			combination1.setVisible(false);
			combination2.setVisible(false);
			combination3.setVisible(false);
			combination4.setVisible(false);
			validate();	
		}
	}		
	public class HandlerClass3 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			c = 3;
			tf1.setVisible(true);
			tf1.setText("");
			tf2.setVisible(false);
			tf3.setVisible(false);
			tf4.setVisible(false);
			tf5.setVisible(false);
			tf6.setVisible(false);
			jl1.setVisible(false);
			jl2.setVisible(false);
			jl3.setVisible(false);
			jl4.setVisible(false);
			jl5.setVisible(false);
			jl6.setVisible(false);
			
			jl8.setVisible(true);
			rb4.setVisible(true);
			rb5.setVisible(true);
			j20.setVisible(false);
			j21.setVisible(false);
			j22.setVisible(false);
			j23.setVisible(false);
			j24.setVisible(false);
			j25.setVisible(false);
			j26.setVisible(false);
			j27.setVisible(false);
			combination1.setVisible(false);
			combination2.setVisible(false);
			combination3.setVisible(false);
			combination4.setVisible(false);
			j29.setVisible(false);
			validate();	
		}
		
	}
	public class HandlerClass10 implements ItemListener
	{
		public void itemStateChanged(ItemEvent event)
		{
			if( event.getStateChange() == ItemEvent.SELECTED )
			{
				combination1s="" + event.getItem();
			}
		}
	}
	
	public class HandlerClass11 implements ItemListener
	{
		public void itemStateChanged(ItemEvent event)
		{
			if( event.getStateChange() == ItemEvent.SELECTED )
			{
				combination2s="" + event.getItem();
			}
		}
	}
	
	public class HandlerClass12 implements ItemListener
	{
		public void itemStateChanged(ItemEvent event)
		{
			if( event.getStateChange() == ItemEvent.SELECTED )
			{
				combination3s="" + event.getItem();
			}
		}
	}
	
	public class HandlerClass13 implements ItemListener
	{
		public void itemStateChanged(ItemEvent event)
		{
			if( event.getStateChange() == ItemEvent.SELECTED )
			{
				combination4s= ""+event.getItem();
					
			}
		}
	}

	public class HandlerClass6 implements ActionListener
	{
		public void actionPerformed(ActionEvent event) 
		{
			c = 4;
			tf1.setVisible(true);
			tf2.setVisible(true);
			tf1.setText("");
			tf2.setText("");
			tf3.setVisible(false);
			tf4.setVisible(false);
			tf5.setVisible(false);
			tf6.setVisible(false);
			jl1.setVisible(false);
			jl2.setVisible(false);
			jl3.setVisible(false);
			jl4.setVisible(false);
			jl5.setVisible(false);
			jl6.setVisible(false);
			
			jl8.setVisible(false);
			j20.setVisible(false);
			j21.setVisible(false);
			rb4.setVisible(true);
			rb5.setVisible(true);
			j22.setVisible(true);
			j23.setVisible(true);
			j24.setVisible(false);
			j25.setVisible(false);
			j26.setVisible(false);
			j27.setVisible(false);
			j29.setVisible(false);
			combination1.setVisible(false);
			combination2.setVisible(false);
			combination3.setVisible(false);
			combination4.setVisible(false);
			validate();	
		}
	}		
	
	public class HandlerClass7 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			c = 5;
			tf1.setVisible(false);
			tf2.setVisible(false);
			tf3.setVisible(false);
			tf4.setVisible(false);
			tf1.setText("");
			tf2.setText("");
			tf3.setText("");
			tf4.setText("");
			tf5.setVisible(false);
			tf6.setVisible(false);
			jl1.setVisible(false);
			jl2.setVisible(false);
			jl3.setVisible(false);
			jl4.setVisible(false);
			jl5.setVisible(false);
			jl6.setVisible(false);
			
			jl8.setVisible(false);
			j20.setVisible(false);
			j21.setVisible(false);
			rb4.setVisible(true);
			rb5.setVisible(true);
			j22.setVisible(false);
			j23.setVisible(false);
			j24.setVisible(true);
			j25.setVisible(true);
			j26.setVisible(true);
			j27.setVisible(true);
			combination1.setVisible(true);
			combination2.setVisible(true);
			combination3.setVisible(true);
			combination4.setVisible(true);
			j29.setVisible(true);
			validate();	
		}
	}
	
	public class HandlerClass5 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			fix_subj fi = new fix_subj();
			fi.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			fi.setSize(800,600);
			fi.setVisible(true);
		
		}
	}
	public class HandlerClass4 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			input in = new input();
			if(c==1)
			{
				String i = tf1.getText();
				String x = tf2.getText();
				tf1.setText("");
				tf2.setText("");
				combination2.addItem(i);
				in.teacher(i,x);
			}
			if(c==2)
			{
				String i = tf1.getText();
				String x = tf2.getText();
				String a = tf3.getText();
				String b = tf4.getText();
				String c = tf5.getText();
				String d = tf6.getText();
				tf1.setText("");
				tf2.setText("");
				tf3.setText("");
				tf4.setText("");
				tf5.setText("");
				tf6.setText("");
				combination1.addItem(x);
				in.subject(i,x,a,b,d,c);
		
			}
			if(c==3)
			{
				String i = tf1.getText();
				
				in.clas(i);
				tf1.setText("");
				combination3.addItem(i);
				create c1 = new create();
				c1.creation(i);
				
			}
			if(c==4)
			{
				String i = tf1.getText();
				String x = tf2.getText();
				in.room(i,x);
				tf1.setText("");
				tf2.setText("");
				
			}
		/*		try
			{
				Class.forName("com.mysql.jdbc.Driver");
		    	System.out.println("Connecting to a database...");
		    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
		        stmt1 = conn.createStatement();
		      stmt2 = conn.createStatement();
		      stmt3 = conn.createStatement();
		      
		      ResultSet r1=stmt1.executeQuery("select s_id from subject");
		      ResultSet r2=stmt2.executeQuery("select t_id from teacher");
		      ResultSet r3=stmt3.executeQuery("select c_id from class");
		      
		      while(r1.next())
		      {
		    	  combination1.addItem(r1.getInt("s_id"));
		      }
		      
		      while(r2.next())
		      {
		    	  combination2.addItem(r2.getInt("t_id"));
		      }
		      
		      while(r3.next())
		      {
		    	  combination3.addItem(r3.getInt("c_id"));
		      }
		      add(combination1);
		      add(combination2);
		      add(combination3);
		      combination1.setBounds(50,200,150,30);
		      combination2.setBounds(210,200,150,30);
		      combination3.setBounds(370,200,150,30);
		     
		      combination1.setEditable(false);
		      combination2.setEditable(false);
		      combination3.setEditable(false);
		      
		    
		      */
		      
		      HandlerClass10 handler10 = new HandlerClass10();
		  	combination1.addItemListener(handler10);
		  	
		  	HandlerClass11 handler11 = new HandlerClass11();
		  	combination2.addItemListener(handler11);
		  	
		  	HandlerClass12 handler12 = new HandlerClass12();
		  	combination3.addItemListener(handler12);
			
			HandlerClass13 handler13 = new HandlerClass13();
		  	combination4.addItemListener(handler13);
			
			/*
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
			   }*/

			
			if(c==5)
			{
				/*String i = tf2.getText();
				String x = tf3.getText();
				String a = tf1.getText();
				String c = tf4.getText();
				in.combination(i,x,a,c);
				tf1.setText("");
				tf2.setText("");
				tf3.setText("");
				tf4.setText("");*/
			
				in.combination(combination2s,combination3s,combination1s,combination4s);// i=teacher_id,x=class_id,a=subject_id
			}
			
			
		
				
		}
	}
/*		public void dataentery(JTextField tf1)
		{
			
			final String USER = "root";
		    final String PASS = "";
		// final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
		 final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
		x = tf1.getText();
		System.out.print(x);
		Connection conn = null;
		   Statement stmt = null;
		   try{
		      //STEP 2: Register JDBC driver
		      Class.forName("com.mysql.jdbc.Driver");

			      //STEP 3: Open a connection
			      System.out.println("Connecting to a selected database...");
			      conn = DriverManager.getConnection(DB_URL, USER, PASS);
			      System.out.println("Connected database successfully...");

			      //STEP 4: Execute a query
			      System.out.println("Inserting records into the table...");
			      stmt = conn.createStatement();

			      String sql = "INSERT INTO xyz " +
			                   "VALUES ('"+x+"',18)";
			      stmt.executeUpdate(sql);
			      sql = "INSERT INTO xyz " +
			                   "VALUES ( 'Maete', 25)";
			      stmt.executeUpdate(sql);
			      sql = "INSERT INTO xyz " +
			                   "VALUES ('hefbhf', 30)";
			      stmt.executeUpdate(sql);
			      sql = "INSERT INTO xyz " +
			                   "VALUES( 'gate', 28)";
			      stmt.executeUpdate(sql);
			      System.out.println("Inserted records into the table...");

			   }catch(SQLException se){
			      //Handle errors for JDBC
			      se.printStackTrace();
			   }catch(Exception e){
			      //Handle errors for Class.forName
			      e.printStackTrace();
			   }finally{
			      //finally block used to close resources
			      try{
			         if(stmt!=null)
			            conn.close();
			      }catch(SQLException se){
			      }// do nothing
			      try{
			         if(conn!=null)
			            conn.close();
			      }catch(SQLException se){
			         se.printStackTrace();
			      }//end finally try
			   }
				
			}*/
}