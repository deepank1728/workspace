import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class fix_subj extends JFrame{
	   //  Database credentials
	public int c;  
	String str[] = new String[5];
	public JButton rb1;
	public JButton rb2;
	public JButton rb3;
	public JTextField tf1;
	public JTextField tf2;
	public JTextField tf3;
	public JTextField tf4;
	public JTextField tf5;
	public JLabel jl1;
	public JLabel jl2;
	public JLabel jl3;
	public JLabel jl4;
	public JLabel jl5;
	{	
	str[0] = "monday";
	str[1] = "tuesday";
	str[2] = "wednesday";
	str[3] = "thursday";
	str[4] = "friday";
	}
	public fix_subj()
	{
		
		super("                                    GIVE DETAILS FOR OPEN ELECTIVE!!!");
		setLayout(null);
	    c = 1;	
		
		
		rb1=new JButton("GO");
		rb1.setLocation(600,450);
		rb1.setSize(150,30);
		add(rb1);
		
		rb2=new JButton("DONE");
		add(rb2);
		rb2.setLocation(600,500);
		rb2.setSize(150,30);
		
		
		
		
		tf1=new JTextField("",10);
		add(tf1);
		tf1.setLocation(10,250);
		tf1.setSize(150,30);
		
		tf2=new JTextField("",10);
		add(tf2);
		tf2.setLocation(160,250);
		tf2.setSize(150,30);
		
		
		tf3=new JTextField("",10);
		add(tf3);
		tf3.setLocation(310,250);
		tf3.setSize(150,30);
		
		tf4=new JTextField("",10);
		add(tf4);
		tf4.setLocation(460,250);
		tf4.setSize(150,30);
		
		tf5=new JTextField("",10);
		add(tf5);
		tf5.setLocation(610,250);
		tf5.setSize(150,30);
		
		
		
        tf1.setVisible(true);
		
		tf2.setVisible(true);
		
		tf3.setVisible(true);
		
		tf4.setVisible(true);
		
		tf5.setVisible(true);
		validate();
		
		
		
		jl1=new JLabel("class_id");
		add(jl1);
		jl1.setLocation(50,150);
		jl1.setSize(150,30);
		
		jl2=new JLabel("subject_Id");
		add(jl2);
		jl2.setLocation(200,150);
		jl2.setSize(150,30);
		
		jl3=new JLabel("room_no");
		add(jl3);
		jl3.setLocation(350,150);
		jl3.setSize(150,30);
		
		jl4=new JLabel("slot");
		add(jl4);
		jl4.setLocation(500,150);
		jl4.setSize(150,30);
		
		jl5=new JLabel("day");
		add(jl5);
		jl5.setLocation(650,150);
		jl5.setSize(150,30);
		
		
		jl1.setVisible(true);
		jl2.setVisible(true);
		jl3.setVisible(true);
		jl4.setVisible(true);
		jl5.setVisible(true);
		
		
		HandlerClass10 handler10=new HandlerClass10();
		rb1.addActionListener(handler10);
		
		HandlerClass11 handler11=new HandlerClass11();
		rb2.addActionListener(handler11);
		
	}
		
		
		public class HandlerClass10 implements ActionListener
		{
			public void actionPerformed(ActionEvent event)
			{
				String i = tf1.getText();
				String j = tf2.getText();
				String k = tf3.getText();
				String l = tf4.getText();
				String m = tf5.getText();
				
				 input in2 = new input();
				 
				 in2.insert("update time_"+i+"_"+m+" set s_id='"+j+"',room_no="+k+" where slot="+l);
				 tf1.setText("");
				 tf2.setText("");
				 tf3.setText("");
				 tf4.setText("");
				 tf5.setText("");
				 System.out.println("akki...............................");
				
				
				
			}
				
			
	         
		}
		
		public class HandlerClass11 implements ActionListener
		{
			
			public void actionPerformed(ActionEvent event)
			{					
				generate gi = new generate();
				gi.labassign();
				gi.lecture_assign();		
				tabbedpanel go = new tabbedpanel();
				go.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				go.setVisible(true);

			}
				
			
	         
		}
}