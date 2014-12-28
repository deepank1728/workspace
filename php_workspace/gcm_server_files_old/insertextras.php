<?php

	 $con = mysql_connect("sql200.byethost7.com","b7_15025964","212521");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("b7_15025964_college_stat", $con) or die('database not selected');
		
		$query1=sprintf("insert into extras (s_no,type,name,info,venue,date,month,year,time,organizers) values (%s,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",$_REQUEST['s_no'],$_REQUEST['name'],$_REQUEST['info'],$_REQUEST['venue'],$_REQUEST['date'],$_REQUEST['month'],$_REQUEST['year'],$_REQUEST['time'],$_REQUEST['organizers']);
		$result1=mysql_query($query1);
		echo $query1;
		if($result1==1)
			echo "sucess";
		else echo "failure";
		
		
		echo header(sprintf("Location:send_push_notification_message.php?table=%s&message=%s","extras",$_REQUEST['name']+" : "+$_REQUEST['date']+" : "+$_REQUEST['month']+" : "+$_REQUEST['year']));
?>