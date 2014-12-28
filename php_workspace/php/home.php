<html>
	<head>
	<title>session</title>
	</head>
	
	<body>
	
		<?php
			session_start();
			if($_SESSION['session']!=5)
			{
				echo header("Location: signin.php");	
			}
		?>
		
		<form method="post" action="event.php">
			
				Register for Robowars
				<br>
				<input type="submit" value="submit">
				<br>
			</form>
		<h1>successfully logged in</h1>
		
			
		
		
		<p><a href="logout.php">to logout click</a></p>
		
	</body>
	

</html>