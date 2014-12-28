<?php

	$connection=mysql_connect("localhost","root","");
			
	mysql_select_db("news",$connection) or die("db not connected");
	
	$query1="select count(s_no) as count from news_detail";
	
	$result1=mysql_query($query1);
	$r=mysql_fetch_array($result1);
	
	$count_s_no=$r['count'] + 1;
	
	
	$query=sprintf("insert into news_detail(s_no,message) values(\"%s\",\"%s\")",$count_s_no,$_REQUEST['message']);
	$result=mysql_query($query) or die ("message not saved<br>");
	echo "successful ";
			

?>