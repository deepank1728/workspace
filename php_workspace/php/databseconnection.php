<?php

$connection=mysql_connect("localhost","root","")
or die("<i>unsucessful<\i>");
echo"hello <br>";
echo"<i>unsucessful i am not";

$db=mysql_select_db("deenbandhu",$connection)
or die("<i>unsucessful<\i>");

$query="select * from class";

echo $query;

$result=mysql_query($query)
or die("unsucessful</i>");

echo "<table border ='1'>";
echo"<tr>";
echo "<th>c_id</th><th>name</th>";
echo"</tr>";
while($row=mysql_fetch_array($result))
{
	echo "<tr>";
	echo "<td>";
	echo $row['c_id'];
	echo "</td>";
	echo "<td>";
	echo $row['name'];
	echo "</td>";
	echo "</tr>";
}
echo"</table>";
if(mysql_close($connection));
echo"<br>successfully closed<br>";
?>