import javax.swing.JFrame;
import javax.swing.JOptionPane;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;

import java.io.UTFDataFormatException;
import java.nio.charset.Charset;

public class main {

	private static final Charset UTF8_CHARSET = Charset.forName("UTF-8");

	public static void main(String[] args) {
		
		gui object = new gui();
		object.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		object.setSize(550,500);
		object.setVisible(true);
		
		
	}

}
