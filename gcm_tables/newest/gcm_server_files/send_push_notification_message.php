<?php

 require_once('loader.php');

	//$gcmRegID    = $_GET["regId"]; // GCM Registration ID got from device
	$pushMessage = $_GET["table"];
	
	
	if(strcmp($pushMessage,"extras")==0)
	{
			if (isset($pushMessage)) {
		
		
		//$registatoin_ids = array($gcmRegID);
		//$con = mysql_connect("sql200.byethost7.com","b7_15025964","212521");
		$con = mysql_connect("localhost","root","");
                
               //  if(isset($company_name["company_name"]))
                    $message = array("price" => $_GET["message"],"table"=>$pushMessage);
               // else
               // $message = array("price" => $_GET["message"],"table"=>$pushMessage);
	
		//$result = send_push_notification($registatoin_ids, $message);
	
		//mysql_select_db("b7_15025964_gcm", $con) or die('database not selected');
		mysql_select_db("gcm", $con) or die('database not selected');
		$query2="select count(id) as count from gcm_users";
		$result2=mysql_query($query2);
		
		$r=mysql_fetch_array($result2);
		$count=$r['count'];
		
		$k=1;
		while($k<=$count)
		{
			$query3=sprintf("select gcm_regid from gcm_users where id=%s",$k);
			$result3=mysql_query($query3);
			$r2=mysql_fetch_array($result3);
			echo $r2['gcm_regid'];
			 //$registatoin_ids=str_split( $r2['gcm_regid'] );
			$registatoin_ids= array($r2['gcm_regid']) ;
			//echo $registatoin_ids;
			//$registatoin_ids=json_encode($r2['gcm_regid']);
			send_push_notification($registatoin_ids, $message);
			$k=$k+1;
		}
	
		//echo $result;
	}
	
	}

	else
	{
		echo $pushMessage;
		echo "after this";
		
		
			
			$company_name=$_GET["company_name"];
			$enddate=$_GET["enddate"];
			$endmonth=$_GET["endmonth"];
			$endyear=$_GET["endyear"];

			echo $company_name;
			echo $enddate;
			echo $endmonth;
			echo $endyear;
		
		if (isset($pushMessage)) {
			
			
			//$registatoin_ids = array($gcmRegID);
			//$con = mysql_connect("sql200.byethost7.com","b7_15025964","212521");
			$con = mysql_connect("localhost","root","");
					
				   //  if(isset($company_name["company_name"]))
						$message = array("price" => $_GET["message"],"table"=>$pushMessage,"company_name"=>$company_name,"enddate"=>$enddate,"endmonth"=>$endmonth,"endyear"=>$endyear);
				   // else
				   // $message = array("price" => $_GET["message"],"table"=>$pushMessage);
		
			//$result = send_push_notification($registatoin_ids, $message);
		
			//mysql_select_db("b7_15025964_gcm", $con) or die('database not selected');
			mysql_select_db("gcm", $con) or die('database not selected');
			$query2="select count(id) as count from gcm_users";
			$result2=mysql_query($query2);
			
			$r=mysql_fetch_array($result2);
			$count=$r['count'];
			
			$k=1;
			while($k<=$count)
			{
				$query3=sprintf("select gcm_regid from gcm_users where id=%s",$k);
				$result3=mysql_query($query3);
				$r2=mysql_fetch_array($result3);
				echo $r2['gcm_regid'];
				 //$registatoin_ids=str_split( $r2['gcm_regid'] );
				$registatoin_ids= array($r2['gcm_regid']) ;
				//echo $registatoin_ids;
				//$registatoin_ids=json_encode($r2['gcm_regid']);
				send_push_notification($registatoin_ids, $message);
				$k=$k+1;
			}
		
			//echo $result;
		}
	}
?>
