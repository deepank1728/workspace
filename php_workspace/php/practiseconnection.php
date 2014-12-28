
<html>
	<head>
		<title>Use of Ajax with database connection</title>
		
		<script language="javascript">
		
			var deepank=false;
			
			if(window.XMLHttpRequest)
			deepank=new XMLHttpRequest();
			else if(window.ActiveXObjecet)
			deepank=new ActiveXObject("Microsoft.XMLHTTP");
			
			function getdata(divid,dataForm)
			{
				if(deepank)
				{
					var obj=document.getElementById(divid);
					deepank.open("GET","sql.php?data="+ document.getElementById("textarea").value);
					
					
					deepank.onreadystatechange=function()
					{
						if(deepank.readyState==4 && deepank.status==200)
						{
							obj.innerHTML=deepank.responseText;
						}
					}
					
					deepank.send(null);
				}
			}
		</script>
		
	</had>
	
	<body>
		<h1>database php and ajax</h1>
		<form name="dataform">
		
			<input type="button" name="button" value="button" onclick="getdata('targetdiv','dataform')">
			<textarea name="message" id="textarea"  cols="50" rows="5"></textarea>
			
		</form>
		
		<div id="targetdiv">
		<p>it is the place for your answer<br></p>
		</div>
	
	</body>
</html>