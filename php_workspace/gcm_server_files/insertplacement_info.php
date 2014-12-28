<?php

	 $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("college_stat_2", $con);
		   
		   
		   
					$temp_e_date=0;
					$temp_e_month=0;
					$temp_e_year=0;
					$z=0;
					while($row["end_date"][$z]!="-")
					{
						$temp_e_date=(10*$temp_e_date)+$row["end_date"][$z];
						$z=$z+1;
					}
					$z=$z+1;
					while($row["end_date"][$z]!="-")
					{
						$temp_e_month=(10*$temp_e_month)+$row["end_date"][$z];
						$z=$z+1;
					}
					$z=$z+1;
					while($z!=strlen($row["end_date"]))
					{
						$temp_e_year=(10*$temp_e_year)+$row["end_date"][$z];
						$z=$z+1;
					}
		
		$query1=sprintf("update %s set placement_info= \"%s\",enddate=%s,endmonth=%s,endyear=%s where company_name= \"%s\"",$_REQUEST['table'],$_REQUEST['placement_info'],$_REQUEST['enddate'],$_REQUEST['endmonth'],$_REQUEST['endyear'],$_REQUEST['name']);
		$result1=mysql_query($query1);
		echo $query1;
		if($result1==1)
			echo "sucess";
		else echo "failure";
		
      

		echo header(sprintf("Location:send_push_notification_message.php?table=%s& message=%s& company_name=%s& enddate=%s& endmonth=%s& endyear=%s",$_REQUEST['table'],sprintf("%s : %s",$_REQUEST[name],$_REQUEST['placement_info']),$_REQUEST['name'],$temp_e_date,$temp_e_month,$temp_e_year));
?>