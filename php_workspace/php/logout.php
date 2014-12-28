<html>
	<head>
	
		<title>logut</title>
	</head>
	
	<body>
	<title>successfully logedout </title>
	<?php
		session_start();
		$_SESSION['session']=0;
		$_SESSION['username']=null;
		$_SESSION['password']=null;
		
	?>
		
		<p>to go to signin page <a href="signin.php">click here</a><p>
	</body>
</html>
