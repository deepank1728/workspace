  <?php

         $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("b7_15025964_college_stat", $con);
		   
		  // $v1=$_REQUEST['table'];
                     $v1="extras";
		   
		    if($v1==null)
            {

                $r["re"]="No news available!!!";
                 print(json_encode($r));
                die('Could not connect: ' . mysql_error());
          }
		  else
		  {
          
				$q="select * from extras";
                $i=mysql_query($q,$con);
         
			   $k=0;
			    while($row = mysql_fetch_array($i))
				{
					$r[sprintf("type%s",$k)]=$row['type'];
					$r[sprintf("name%s",$k)]=$row['name'];
					$r[sprintf("info%s",$k)]=$row['info'];
					$r[sprintf("venue%s",$k)]=$row['venue'];
					$r[sprintf("date%s",$k)]=$row['date'];
					$r[sprintf("month%s",$k)]=$row['month'];
					$r[sprintf("year%s",$k)]=$row['year'];
					$r[sprintf("time%s",$k)]=$row['time'];
					$r[sprintf("organizers%s",$k)]=$row['organizers'];
					  
					  $k=$k+1;

				}
				
				$r["count"]=$k;
                print(json_encode($r));
                            
		 }
 mysql_close($con);
              
    ?> 