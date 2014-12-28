import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class delete_gui extends JFrame{
	   //  Database credentials
	public int c=0;   
	public JButton rb1;
	public JButton rb2;
	public JButton rb3;
	public JButton rb4;
	public JButton rb5;
	
	
	public JTextField tf1;
	public JTextField tf2;
	public JTextField tf3;
	
	public JLabel jl1;
	public JLabel jl2;
	public JLabel jl3;
	
	public String s;
	
	public delete_gui()
	{
		super("ENTER KEY TO DELETE FROM DATABASE");
		
		
		
		setLayout(null);
		setBackground( Color.BLACK );	
		rb1=new JButton("teacher");
		rb1.setLocation(60,100);
		rb1.setSize(150,30);
		add(rb1);
		
		rb2=new JButton("subject");
		add(rb2);
		rb2.setLocation(250,100);
		rb2.setSize(150,30);
		
		rb3=new JButton("batch");
		add(rb3);
		rb3.setLocation(450,100);
		rb3.setSize(150,30);
		
		rb4=new JButton("GO");
		add(rb4);
		rb4.setLocation(450,400);
		rb4.setSize(150,30);
		
		rb5=new JButton("DONE");
		add(rb5);
		rb5.setLocation(450,450);
		rb5.setSize(150,30);
		
		
		tf1=new JTextField("",10);
		add(tf1);
		tf1.setLocation(60,150);
		tf1.setSize(150,30);
		
		tf2=new JTextField("",10);
		add(tf2);
		tf2.setLocation(250,150);
		tf2.setSize(150,30);
		
		
		tf3=new JTextField("",10);
		add(tf3);
		tf3.setSize(150,30);
		tf3.setLocation(450,150);
		
		
		tf1.setVisible(false);
		
		tf2.setVisible(false);
		
		tf3.setVisible(false);
		
		
		validate();
		
		
		jl1=new JLabel("t_Id");
		add(jl1);
		jl1.setLocation(10,150);
		jl1.setSize(150,30);
		
		jl2=new JLabel("subj_id");
		add(jl2);
		jl2.setLocation(100,150);
		jl2.setSize(150,30);
		
		jl3=new JLabel("batch_name");
		add(jl3);
		jl3.setLocation(300,150);
		jl3.setSize(150,30);
		
		
		jl1.setVisible(false);
		jl2.setVisible(false); 
		jl3.setVisible(false);
		
		
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
		
	}
	
		public class HandlerClass implements ActionListener
		{	
			public void actionPerformed(ActionEvent event)
			{
				c=1;
				tf2.setVisible(false);
			    jl2.setVisible(false);
			    tf1.setVisible(true);
			    jl1.setVisible(true);
			    tf3.setVisible(false);
			    jl3.setVisible(false);
			}
		}
		
		public class HandlerClass2 implements ActionListener
		{	
			public void actionPerformed(ActionEvent event)
			{
				c=2;
				tf1.setVisible(false);
			    jl1.setVisible(false);
			    tf2.setVisible(true);
			    jl2.setVisible(true);
			    tf3.setVisible(false);
			    jl3.setVisible(false);
			}
		}
		
		public class HandlerClass3 implements ActionListener
		{	
			public void actionPerformed(ActionEvent event)
			{
				c=3;
				tf3.setVisible(true);
			    jl3.setVisible(true);
			    tf1.setVisible(false);
			    jl1.setVisible(false);
			    tf2.setVisible(false);
			    jl2.setVisible(false);
			}
		}
		
		public class HandlerClass4 implements ActionListener
		{	
			public void actionPerformed(ActionEvent event)
			{
				input in = new input();
				if(c==1)
				{
					s = tf1.getText();
					tf1.setText("");
					System.out.println("...."+s);
					in.insert("delete from combination where t_id="+s);
					in.insert("delete from teacher where t_id="+s);
					System.out.println("...."+s);
				}
				
				if(c==2)
				{
					s = tf2.getText();
					tf2.setText("");
					in.insert("delete from combination where s_id="+s);
					in.insert("delete from subject where s_id="+s);
				}
				
				if(c==3)
				{
					s = tf3.getText();
					tf3.setText("");
					in.insert("delete from combination where c_id= (select c_id from class where name =)"+s);
					in.insert("delete from class where name ="+s);
				}
			}
		}
		
		public class HandlerClass5 implements ActionListener
		{	
			public void actionPerformed(ActionEvent event)
			{
				System.exit(0);
			}
		}
	
}