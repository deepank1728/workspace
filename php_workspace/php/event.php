<?php

	$connection=mysql_connect("localhost","root","") or die("unsucessful <br>");
	
	$db=mysql_select_db("deepank",$connection) or die("unsucessful <br>") ;
	
	session_start();
	$str1=sprintf("insert into robowars(name) values(\"%s\")",$_SESSION['username']);
	
	$result=mysql_query($str1) or die ("not registered<br>");

?>