<html>
	<head>
		<title>
		your email was sent
		</title>
	</head>
	
	<body>
	<h1>your emaill was sent</h1>
	thanks for your email
	<br><br>
	
	<?php
		echo $_REQUEST["message"];
		mail("deepank1728.com","web mail",$_REQUEST["message"]);
	?>
	
	</body>
</html>