import javax.swing.*;
import java.math.BigInteger;
import java.util.Random;

import java.awt.*;

import javax.swing.JOptionPane;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;


class gui extends JFrame{
	public Button b1;
	public Button b2;
	private Button b3;
	private Label l5;
	public Label l1;
	public Label l2;
	public Label l3;
	public Label l4;
	private Label l6;
	public TextField t1;
	public TextField t2;
	public TextField t3;
	public TextField t4;
	private TextField t5;
	private TextField t6;
	String k1;
	Random rn;
	int random_number;
	
	public gui(){
			super("		encrypt and decrypt");
			setLayout(null);
			l1 = new Label("plain text");
			l1.setSize(100,40);
			l1.setLocation(30,50);
			add(l1);
			
			l2 = new Label("encrypted text");
			l2.setSize(100,40);
			l2.setLocation(30,160);
			add(l2);
			
			l3 = new Label("encrypted text");
			l3.setSize(100,40);
			l3.setLocation(330,50);
			add(l3);
			
			l4 = new Label("plain text");
			l4.setSize(100,40);
			l4.setLocation(330,160);
			add(l4);
			
			l5 = new Label("key");
			l5.setSize(100,30);
			l5.setLocation(230,330);
			add(l5);
			
			b1 = new Button("convert");
			b1.setSize(100,30);
			b1.setLocation(30,250);
			add(b1);
			
			b2 = new Button("convert");
			b2.setSize(100,30);
			b2.setLocation(330,250);
			add(b2);
			
			b3 = new Button("enter");
			b3.setSize(100,30);
			b3.setLocation(200,410);
			add(b3);
			
			t1 = new TextField();
			t1.setSize(200,30);
			t1.setLocation(10,90);
			t1.setEditable(true);
			add(t1);
			
			t2 = new TextField();
			t2.setSize(200,30);
			t2.setLocation(10,200);
			t2.setEditable(false);
			add(t2);
			
			t3 = new TextField();
			t3.setSize(200,30);
			t3.setLocation(310,90);
			t3.setEditable(true);
			add(t3);
			
			t4 = new TextField();
			t4.setSize(200,30);
			t4.setLocation(310,200);
			t4.setEditable(false);
			add(t4);
			
			t5=new TextField();
			t5.setSize(200,30);
			t5.setLocation(150,370);
			t5.setEditable(true);
			add(t5);
			
			l6 = new Label("hamming distace");
			l6.setSize(100,30);
			l6.setLocation(30,300);
			add(l6);
			
			t6 = new TextField("");
			t6.setSize(100,30);
			t6.setLocation(150,300);
			add(t6);
			
			k1="1a25s8fe5dsg65az";
			
			handlerclass1 hand1 = new handlerclass1();
			b1.addActionListener(hand1);
			
			handlerclass2 hand2 = new handlerclass2();
			b2.addActionListener(hand2);
			
			handlerclass3 hand3=new handlerclass3();
			b3.addActionListener(hand3);
			
			
			
	}
	public class handlerclass1 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			String s1 = t1.getText();
			if(s1.length() != 16){
				JOptionPane.showMessageDialog(null,"sorry!! string must of exact 16 characters, refill it");
				t2.setText("");
				t1.setText("");
			}
			else{
				try{
					
					String k = "1a25s8fe5dsg65ad";
					k=k1;
					byte[] inputebytearray=s1.getBytes();
					
					rn = new Random();
					random_number=rn.nextInt(44);
					
					
					byte[] enc = AES.encrypt(s1,s1.getBytes("UTF-8"), k.getBytes("UTF-8"),random_number);
					
					StringBuilder input = new StringBuilder(inputebytearray.length * 8);
				    for( int i = 0; i < 8 * inputebytearray.length; i++ )
				        input.append((inputebytearray[i / 8] << i % 8 & 0x80) == 0 ? '0' : '1');
					
					StringBuilder sb = new StringBuilder(enc.length * 8);
				    for( int i = 0; i < 8 * enc.length; i++ )
				        sb.append((enc[i / 8] << i % 8 & 0x80) == 0 ? '0' : '1');
				    System.out.println(sb);
				    
				    int result=hammingdistance(input,sb);
				    System.out.println("hamming distance is "+result);
				    
				    t6.setText(""+result);
					t2.setText(sb.toString());
					
				}catch(Exception e){
					e.printStackTrace();
				}
			}
		}
	}
			
	public class handlerclass2 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			String str = t3.getText();
			//byte[] s2 = new BigInteger(str, 2).toByteArray();
			//byte [] s2=str.getBytes();
			//System.out.println(s2);
			byte []s2=new byte[16];
			String temp2="";
			int j=0;
			int temp3=0;
			for(int i=0;i<128;i++)
			{
				temp2+=str.charAt(i);
				if(i%8==7)
				{
					
					s2[j++]=(byte)Integer.parseInt(temp2,2);
					System.out.println(temp2);
					temp2="";
				}
				
			
				
			}
			
			StringBuilder sb = new StringBuilder(s2.length * 8);
		    for( int i = 0; i < 8 * s2.length; i++ )
		        sb.append((s2[i / 8] << i % 8 & 0x80) == 0 ? '0' : '1');
		    System.out.println(sb);
			System.out.println(s2.length);
			if(s2.length == 1){
				JOptionPane.showMessageDialog(null,"sorry!! string must of exact 16 characters, refill it");
				t3.setText("");
				t4.setText("");
			}
			else{
				try{
				
					String k = "1a25s8fe5dsg65ad";
					k=k1;
					byte[] dec = AES.decrypt(s2, k.getBytes(),random_number);
					System.out.println(dec.length);
					t4.setText(new String(dec));
					
				   }catch(Exception e){
					   	e.printStackTrace();
				}
			}
		}
		
		
		
	}
	
	private class handlerclass3 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			if(t5.getText().length()==16)
			k1=t5.getText();
			else
			{
				JOptionPane.showMessageDialog(null,"sorry!! string must of exact 16 characters, refill it");
				t5.setText("");
			}
				
		}
	}

	private int hammingdistance(StringBuilder input,StringBuilder enc)
	{
		int result=0;
		for(int i=0;i<input.length();i++)
		{
			if(input.charAt(i)!=enc.charAt(i))
			{
				result++;
			}
		}
		
		return result;
	}
}
