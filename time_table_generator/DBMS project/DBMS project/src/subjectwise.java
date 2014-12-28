

import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.*;
import java.sql.*;


public class subjectwise extends JFrame	

{
	
	final String USER = "root";
    final String PASS = "";
    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
    Connection conn = null;
    Statement stmt = null;		   
    Statement stmt1 = null;
    Statement stmt2 = null;
    Statement stmt3 = null;
    Statement stmt4 = null;
    Statement stmt5 = null;
    Statement stmt6 = null;
    String str[] = new String[5];
   	{
   		str[0] = "monday";
   		str[1] = "tuesday";
   		str[2] = "wednesday";
   		str[3] = "thursday";
   		str[4] = "friday";
   	}
   	
   	public JComboBox combo = new JComboBox();
    public JPanel topPanel=new JPanel();
    {topPanel.setLayout( null );
	getContentPane().add( topPanel );}
    public JLabel[][] teacherlabel = new JLabel[5][9];
    public JLabel[][] roomlabel=new JLabel[5][9];
	public JLabel[][] classlabel=new JLabel[5][9];
	public JLabel[] label1 = new JLabel[5];
	public JLabel[] label2 = new JLabel[5];
	public JLabel[] label3 = new JLabel[5];
    
	public subjectwise()
	{
		for(int i=0;i<5;i++)
		{
			label1[i]=new JLabel("null");
		}
		
		for(int i=0;i<4;i++)
		{
			label2[i]=new JLabel("null");
		}
		for(int i=0;i<5;i++)
		{
			label3[i]=new JLabel("null");
		}	
		
		for(int i=0;i<5;i++)
		{
			label1[i].setText((i+8)+":00-"+(i+8)+":55");
			label1[i].setSize(150,20);
			label1[i].setLocation((150+(120*i)),50);
			label1[1].setVisible(true);
			topPanel.add(label1[i]);
		}			
		for(int i=0;i<4;i++)
		{
			label2[i].setText((i+1)+":00-"+(i+1)+":55");
			label2[i].setSize(150,20);
			label2[i].setLocation((750+(120*i)),50);
			label2[i].setVisible(true);
			topPanel.add(label2[i]);
		}
		
		for(int i=0;i<5;i++)
		{
			label3[i].setText(str[i]);
			label3[i].setSize(140,20);
			label3[i].setLocation(10,(100+(120*i)));
			label3[i].setVisible(true);
			topPanel.add(label3[i]);
		}		
		
		for(int i=0;i<5;i++)	
		{
		  for(int j=0;j<9;j++)
			{
			  classlabel[i][j] = new JLabel("null");
			  roomlabel[i][j]=new JLabel("null");
			  teacherlabel[i][j]=new JLabel("null");
			}
		}
		for(int i=0;i<5;i++)	
		{
		  for(int j=0;j<9;j++)
			{
				classlabel[i][j].setText("");
				roomlabel[i][j].setText("");
				teacherlabel[i][j].setText("");
				classlabel[i][j].setSize(150,20);
				roomlabel[i][j].setSize(150,20);
				teacherlabel[i][j].setSize(150,20);
				classlabel[i][j].setLocation((150+(120*j)),100+(120*i));
				teacherlabel[i][j].setLocation(150+(120*j),115+(120*i));
				roomlabel[i][j].setLocation((150+(120*j)),130+(120*i));
				topPanel.add(classlabel[i][j]);
				topPanel.add(roomlabel[i][j]);
				topPanel.add(teacherlabel[i][j]);
				
			}
		}
		
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
	    	System.out.println("Connecting to a database...");
	    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
			stmt1 = conn.createStatement();
		      stmt2 = conn.createStatement();
		      stmt3 = conn.createStatement();
		      stmt4 = conn.createStatement();
		      
		      combo.setBounds( 20, 10, 260, 20 );
				topPanel.add( combo );	
			ResultSet r3=stmt3.executeQuery("select room_name from room");
			 while(r3.next())
		      {
		    	  combo.addItem(r3.getString("room_name"));
		      }
			
			
			 combo.setEditable( false );
			 combo.setVisible(true);
			 

		        // Watch for changes
			 HandlerClass1 handler1=new HandlerClass1();
				combo.addItemListener(handler1);
			
					
					
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
	
	public class HandlerClass1 implements ItemListener
	{
		public void itemStateChanged(ItemEvent event)
		{
			if( event.getStateChange() == ItemEvent.SELECTED )
			{
				
				try
				{
					
					Class.forName("com.mysql.jdbc.Driver");
			    	System.out.println("Connecting to a database...");
			    	conn = DriverManager.getConnection(DB_URL, USER, PASS);
					stmt1 = conn.createStatement();
				      stmt2 = conn.createStatement();
				      stmt3 = conn.createStatement();
				      stmt4 = conn.createStatement();
				      stmt5 = conn.createStatement();
				      stmt6 = conn.createStatement();
					if( event.getStateChange() == ItemEvent.SELECTED )
					{
						String rname=""+event.getItem();
						
						//ResultSet r2=stmt2.executeQuery("select room_no from room where name="+rno);
						//r2.next();
						
						//int sid=r2.getInt("s_id");
						System.out.println("toto desasterrr...");
						ResultSet r1=stmt1.executeQuery("select count(c_id) as count from class");
						r1.next();
						//System.out.println(sid);
						
						int cid=r1.getInt("count");
						cid=cid;
						for(int i=0;i<5;i++)
						   {
							   for(int j=0;j<9;j++)
							   {
								   roomlabel[i][j].setText("");
								   teacherlabel[i][j].setText("");
								   classlabel[i][j].setText("");
								   
							   }
						   }
						
				ResultSet r6=stmt6.executeQuery("select room_no from room where room_name='"+rname+"'");
				r6.next();
				String rno=r6.getString("room_no");
						for(cid=cid; cid>0;cid--)
						{
							
							for (int i=0;i<5;i++)
							{
								for(int j=0;j<9;j++)
								{
									
									ResultSet r2=stmt2.executeQuery("select t_id,s_id from time_"+cid+"_"+str[i]+"  where room_no="+rno+" and slot="+j);
				
									
									if(r2.next())
										
									{
										
									ResultSet r4=stmt4.executeQuery("select name from teacher where t_id="+r2.getInt("t_id"));
									r4.next();
									
									
										System.out.println("deepa///vdavdsv");
										String tname=r4.getString("name");
										
										r4=stmt4.executeQuery("select name from subject where s_id="+r2.getInt("s_id"));
										r4.next();
										
									teacherlabel[i][j].setText(tname);
									
									roomlabel[i][j].setText(r4.getString("name"));
									
								/*	r4=stmt4.executeQuery("select name from class where c_id="+cid);
									r4.next();
									String cname=r4.getString("name");
									classlabel[i][j].setText(cname);*/
									
									}
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
	}
}
