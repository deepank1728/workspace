<?php

	
	$connection=mysql_connect("localhost","root","")
	or die("unsuccessful");
	
	$db=mysql_select_db("danielle_youtube",$connection)
	or die("unsuccessful 2");
	
	$query=sprintf("select name from customers where id=%d",$_REQUEST["data"]);
	
	echo"<br>";
	
	$result=mysql_query($query)
	or die("unsuccessful 3");
	$row=mysql_fetch_array($result)
	or die("unsuccessful 4");
	echo($row['name']);

?>