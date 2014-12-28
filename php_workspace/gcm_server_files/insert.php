<?php

	 $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("college_stat2", $con) or die('database not selected');
		
		$query=sprintf("select max(s_no) from %s",$_REQUEST[['table']]);
		$result=mysql_query($query);
		$s_no=$result+1;
		
		$query1=sprintf("insert into %s (s_no,company_name,company_info,message,start_date) values (%s,\"%s\",\"%s\",\"%s\",\"%s\")",$_REQUEST['table'],$s_no,$_REQUEST['name'],$_REQUEST['info'],$_REQUEST['message'],$_REQUEST['start_date']);
		$result1=mysql_query($query1);
		echo $query1;
		if($result1==1)
			echo "sucess";
		else echo "failure";
		
                echo "message is  :  ";
		echo $_REQUEST['message'];
		
				$temp_date=0;
			$temp_month=0;
			$temp_year=0;
			$i=0;
			while($_REQUEST["start_date"][$i]!="-")
			{
				$temp_date=(10*$temp_date)+$_REQUEST["start"][$i];
				$i=$i+1;
			}
			$i=$i+1;
			while($_REQUEST["start_date"][$i]!="-")
			{
				$temp_month=(10*$temp_month)+$_REQUEST["start"][$i];
				$i=$i+1;
			}
			$i=$i+1;
			while($i!=strlen($_REQUEST["start_date"]))
			{
				$temp_year=(10*$temp_year)+$_REQUEST["start"][$i];
				$i=$i+1;
			}

		echo header(sprintf("Location:send_push_notification_message.php?table=%s & message=%s",$_REQUEST['table'],sprintf("%s : %s",$_REQUEST['name'],$_REQUEST['message'])));
?>