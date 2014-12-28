 <?php

         $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("college_stat2", $con);
		   
		   $v1=$_REQUEST['table'];
		   
		    if($v1==null)
            {

                $r["re"]="No news available!!!";
                 print(json_encode($r));
                die('Could not connect: ' . mysql_error());
          }
		  else
		  {
          
				$q="select * from $v1";
                $i=mysql_query($q,$con);
         
			   $k=0;
			    while($row = mysql_fetch_array($i))
				{
					  $r[sprintf("name%s",$k)]=$row['name'];
					  $r[sprintf("info%s",$k)]=$row['info'];
					  $r[sprintf("type%s",$k)]=$row['type'];
					  $k=$k+1;

				}
				
				$r["count"]=$k;
                print(json_encode($r));
                            
		 }
 mysql_close($con);
              
    ?> 