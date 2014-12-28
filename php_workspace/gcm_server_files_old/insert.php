<?php

	 $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("college_stat", $con) or die('database not selected');
		
		$query1=sprintf("insert into %s (s_no,company_name,company_info,message,date,day,year) values (%s,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",$_REQUEST['table'],$_REQUEST['s_no'],$_REQUEST['name'],$_REQUEST['info'],$_REQUEST['message'],$_REQUEST['date'],$_REQUEST['month'],$_REQUEST['year']);
		$result1=mysql_query($query1);
		echo $query1;
		if($result1==1)
			echo "sucess";
		else echo "failure";
		
		
		echo header(sprintf("Location:send_push_notification_message.php?table=%s&message=%s",$_REQUEST['table'],$_REQUEST['name']+" : "+$_REQUEST['message']));
?>