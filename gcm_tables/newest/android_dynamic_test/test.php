 <?php

         $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("college_stat2", $con);
		   
		   
		   $q="select company_name from comp_company where s_no=4";
		   $r=mysql_query($q);
		   $row = mysql_fetch_array($r);
		   echo $row['company_name'];
		   
?>