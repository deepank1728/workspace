<html>
	<head>
		<title> registration </title>
	</head>
	
	<body>
		<?php
			$connection=mysql_connect("localhost","root","");
			
			mysql_select_db("deepank",$connection);
			
			$query=sprintf("insert into users(username,password) values(\"%s\",\"%s\")",$_REQUEST['username2'],$_REQUEST['password2']);
			
			$result=mysql_query($query) or die ("not registered<br>");
			
			
		?>
		<h1>Registered successfully</h1>
		<p>to go to login page <a href="signin.php">click here</a></p>
	</body>
</html>