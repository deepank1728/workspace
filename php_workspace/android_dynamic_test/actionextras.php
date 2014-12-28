 <?php

        $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("college_stat2", $con);
		   
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
				
					$temp_s_date=0;
					$temp_s_month=0;
					$temp_s_year=0;
					
					$z=0;
					while($row["start_date"][$z]!="-")
					{
						$temp_s_date=(10*$temp_s_date)+$row["start_date"][$z];
						$z=$z+1;
					}
					$z=$z+1;
					while($row["start_date"][$z]!="-")
					{
						$temp_s_month=(10*$temp_s_month)+$row["start_date"][$z];
						$z=$z+1;
					}
					$z=$z+1;
					while($z!=strlen($row["start_date"]))
					{
						$temp_s_year=(10*$temp_s_year)+$row["start_date"][$z];
						$z=$z+1;
					}
					
					
					$r[sprintf("type%s",$k)]=$row['type'];
					$r[sprintf("name%s",$k)]=$row['name'];
					$r[sprintf("info%s",$k)]=$row['info'];
					$r[sprintf("venue%s",$k)]=$row['venue'];
					$r[sprintf("date%s",$k)]=$temp_s_date;
					$r[sprintf("month%s",$k)]=$temp_s_month;
					$r[sprintf("year%s",$k)]=$temp_s_year;
					$r[sprintf("time%s",$k)]=$row['time'];
					$r[sprintf("organizers%s",$k)]=$row['organizers'];
					  
					  $k=$k+1;

				}
				
				$r["count"]=$k;
                print(json_encode($r));
                            
		 }
 mysql_close($con);
              
    ?> 