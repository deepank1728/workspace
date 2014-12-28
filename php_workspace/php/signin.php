<html>

		<head>
		
			<title> Password Login </title>
			
		</head>
		
		<body>
		
		<?php
			session_start();
			if(isset($_SESSION['session']))
			{
				if($_SESSION['session']==5)
				echo header("location: home.php");
			}
		?>
			<h1>Password Login</h1>
			
			<form method="post" action="password.php">
			
				Enter your username.
				<br>
				<input type="text" name="username">
				Enter your password.
				<br>
				<input type="password" name="password">
					
				<input type="submit" value="submit">
			</form>
			
			
			<h2>register here if not registered</h2>
			
			
			<form method="post" action="register.php">
				
				Enter your username.
				<br>
				<input type="text" name="username2">
				Enter your password.
				<br>
				<input type="password" name="password2">
				
				<input type="submit" value="submit2">
			</form>
		
		
		</body>

	</html>

