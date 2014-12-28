<?php

 require_once('loader.php');

	//$gcmRegID    = $_GET["regId"]; // GCM Registration ID got from device
	$pushMessage = $_GET["table"];
	echo $pushMessage;
	echo "after this";
	
	if (isset($pushMessage)) {
		
		
		//$registatoin_ids = array($gcmRegID);
		$con = mysql_connect("localhost","root","");
		$message = array("price" => $_GET["message"],"table"=>$pushMessage);
	
		//$result = send_push_notification($registatoin_ids, $message);
	
		mysql_select_db("gcm", $con) or die('database not selected');
		$query2="select count(id) as count from gcm_users";
		$result2=mysql_query($query2);
		
		$r=mysql_fetch_array($result2);
		$count=$r['count'];
		
		$k=2;
		while($k<=$count+1)
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
?>
