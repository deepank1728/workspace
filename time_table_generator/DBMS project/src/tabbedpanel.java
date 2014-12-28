import java.awt.*;
import java.awt.event.*;
import java.sql.*;

import javax.swing.*;

public class tabbedpanel extends JFrame
{
		public tabbedpanel()
		{
			setTitle( "TIME TABLE" );
			setBackground( Color.gray );
			setSize(1600,1600);
			JPanel topPanel = new JPanel();
			topPanel.setLayout( new BorderLayout() );
			getContentPane().add( topPanel );
			
			
			
			JTabbedPane jtp=new JTabbedPane();
			jtp.addTab( "batchwise", new scroll().topPanel );
			jtp.addTab( "teacherwise", new teacherwise().topPanel );
			jtp.addTab( "roomwise", new subjectwise().topPanel );
			topPanel.add(jtp,BorderLayout.CENTER);
		}
}
