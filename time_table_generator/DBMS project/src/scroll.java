import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.sql.*;

class scroll extends JFrame	implements  ItemListener
{
	
	final String USER = "root";
    final String PASS = "";
    final String DB_URL = "jdbc:mysql://localhost/deenbandhu";
    Connection conn = null;
    Statement stmt = null;		   
    Statement stmt1 = null;
    Statement stmt2 = null;
    Statement stmt3 = null;
    String str[] = new String[5];
	{
		str[0] = "monday";
		str[1] = "tuesday";
		str[2] = "wednesday";
		str[3] = "thursday";
		str[4] = "friday";
	}
	
	String a[];
	public JComboBox combo = new JComboBox();
	public int id;
	public JLabel[][] label = new JLabel[5][9];
	public JLabel[] label1 = new JLabel[5];
	public JLabel[] label2 = new JLabel[5];
	public JLabel[] label3 = new JLabel[5];
	public JLabel[][] roomlabel=new JLabel[5][9];
	public JLabel[][] teacherlabel=new JLabel[5][9];
	public JLabel test;
	public JPanel topPanel= new JPanel();	
	public scroll()
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
				label1[i].setSize(150,15);
				label1[i].setLocation((150+(120*i)),50);
				label1[1].setVisible(true);
				topPanel.add(label1[i]);
			}			
			for(int i=0;i<4;i++)
			{
				label2[i].setText((i+1)+":00-"+(i+1)+":55");
				label2[i].setSize(150,15);
				label2[i].setLocation((750+(120*i)),50);
				label2[i].setVisible(true);
				topPanel.add(label2[i]);
			}
			
			for(int i=0;i<5;i++)
			{
				label3[i].setText(str[i]);
				label3[i].setSize(140,15);
				label3[i].setLocation(10,(100+(120*i)));
				label3[i].setVisible(true);
				topPanel.add(label3[i]);
			}		
		for(int i=0;i<5;i++)	
		{
		  for(int j=0;j<9;j++)
			{
			  label[i][j] = new JLabel("null");
			  roomlabel[i][j]=new JLabel("null");
			  teacherlabel[i][j]=new JLabel("null");
			}
		}
		
		
			setTitle( "ComboBox Application" );
		setBackground( Color.gray );
		getContentPane().setLayout(new BorderLayout());

		topPanel.setLayout( null );
		getContentPane().add(topPanel, BorderLayout.CENTER );
		
			for(int i=0;i<5;i++)	
			{
			  for(int j=0;j<9;j++)
				{
					label[i][j].setText("");
					roomlabel[i][j].setText("");
					teacherlabel[i][j].setText("");
					label[i][j].setSize(150,15);
					roomlabel[i][j].setSize(150,15);
					teacherlabel[i][j].setSize(150,15);
					label[i][j].setLocation((150+(120*j)),100+(120*i));
					teacherlabel[i][j].setLocation(150+(120*j),115+(120*i));
					roomlabel[i][j].setLocation((150+(120*j)),130+(120*i));
					topPanel.add(label[i][j]);
					topPanel.add(roomlabel[i][j]);
					topPanel.add(teacherlabel[i][j]);
					label[i][j].setVisible(true);
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
        // Create a combobox
		combo.setBounds( 20, 10, 260, 20 );
		topPanel.add( combo );	
		// Populate the combobox list
		ResultSet r1=stmt1.executeQuery("select name from class");
		
		 while(r1.next())
	      {
	    	  combo.addItem(r1.getString("name"));
	      }

        // Allow edits
        combo.setEditable( false );

        // Watch for changes
        combo.addItemListener( this );
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
	public void itemStateChanged( ItemEvent event )
	{
		if( event.getStateChange() == ItemEvent.SELECTED )
		{
			System.out.println( "Change:"+ event.getItem() );
			try
			{
				
			  Class.forName("com.mysql.jdbc.Driver");
		      System.out.println("Connecting to a database...");
		      conn = DriverManager.getConnection(DB_URL, USER, PASS);
		      stmt1 = conn.createStatement();
		      stmt2 = conn.createStatement();
		      stmt3 = conn.createStatement();
		      
		   
			ResultSet r2=stmt2.executeQuery("select c_id from class where name='"+event.getItem()+"'");
			r2.next();		
			id=r2.getInt("c_id");	
			   System.out.println(event.getItem());
			   ResultSet r3;
			   ResultSet r1;
			   
			   for(int i=0;i<5;i++)
			   {
				   for(int j=0;j<9;j++)
				   {
					   label[i][j].setText("");
					   roomlabel[i][j].setText("");
					   teacherlabel[i][j].setText("");
				   }
			   }
			for(int i=0;i<5;i++)
			{	
				for(int j=0;j<9;j++)
				{	
					 r3=stmt3.executeQuery("select name from subject where s_id = ( select s_id from time_"+id+"_"+str[i]+" where slot ="+j+")");
					 r2=stmt2.executeQuery("select room_name from room where room_no=(select room_no from time_"+id+"_"+str[i]+" where slot ="+j+")");
					 r1=stmt1.executeQuery("select name from teacher where t_id=(select t_id from time_"+id+"_"+str[i]+" where slot="+j+")");
					if(r3.next())
					{
							label[i][j].setText(r3.getString("name"));
					}
					
					if(r2.next())
					{
						roomlabel[i][j].setText(r2.getString("room_name"));
					}
					
					if(r1.next())
					{
						teacherlabel[i][j].setText(r1.getString("name"));
					}
				}
			}
		}	
			catch(NullPointerException s)
			{
				System.out.println("happy bday..");
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

