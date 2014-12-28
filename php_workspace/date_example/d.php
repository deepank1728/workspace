<?php

         $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("date", $con);
		   
		   	
			$temp_date=0;
			$temp_month=0;
			$temp_year=0;
			$i=0;
			while($_REQUEST["start"][$i]!="-")
			{
				$temp_date=(10*$temp_date)+$_REQUEST["start"][$i];
				$i=$i+1;
			}
			$i=$i+1;
			while($_REQUEST["start"][$i]!="-")
			{
				$temp_month=(10*$temp_month)+$_REQUEST["start"][$i];
				$i=$i+1;
			}
			$i=$i+1;
			while($i!=strlen($_REQUEST["start"]))
			{
				$temp_year=(10*$temp_year)+$_REQUEST["start"][$i];
				$i=$i+1;
			}
			echo $temp_date;
			echo $temp_month;
			echo $temp_year;
	/*	$query1=sprintf("insert into %s (s_no,company_name,company_info,message,date,day,year) values (%s,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",$_REQUEST['table'],$_REQUEST['s_no'],$_REQUEST['name'],$_REQUEST['info'],$_REQUEST['message'],$_REQUEST['date'],$_REQUEST['month'],$_REQUEST['year']);
		$result1=mysql_query($query1);
		echo $query1;
		if($result1==1)
			echo "sucess";
		else echo "failure";
		
		
		echo header(sprintf("Location:send_push_notification_message.php?table=%s&message=%s",$_REQUEST['table'],$_REQUEST['name']+" : "+$_REQUEST['message']));
		
		*/
		   
?>