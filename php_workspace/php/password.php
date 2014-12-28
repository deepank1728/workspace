<?php
	$connection=mysql_connect("localhost","root","") or die("unsucessful <br>");
	
	$db=mysql_select_db("deepank",$connection) or die("unsucessful <br>") ;
	
	$str1=sprintf("select * from users where username=\"%s\"",$_REQUEST["username"]);
	
	if(mysql_query($str1))
	{
		$str2=sprintf("select password from users where username=\"%s\"",$_REQUEST["username"]);
		$p=mysql_query($str2);
		$pass=mysql_fetch_array($p);

		if(($pass['password']==$_REQUEST['password']))
		{
			echo "hello everyone";
			echo $pass['password'];
			echo "<br>";
			echo $_REQUEST['password'];
			echo header("Location: home.php");
			session_start();
			$_SESSION['session']=5;
			$_SESSION['username']=$_REQUEST['username'];
			$_SESSION['password']=$_REQUEST['password'];
			
			
		}
		else
		{
			echo header("Location: signin.php");
		}
		
	}
	else
	echo "username does not exist<br>";
	
	
	
?>