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
				
				
					  	
					$temp_s_date=0;
					$temp_s_month=0;
					$temp_s_year=0;
					$temp_e_date=0;
					$temp_e_month=0;
					$temp_e_year=0;
					$z=0;
					while($row["start_date"][$z]!="-")
					{
						$temp_s_date=(10*$temp_s_date)+$row["start_date"][$z];
						
						if($row["end_date"]!="")
						$temp_e_date=(10*$temp_e_date)+($row["end_date"][$z]);
						$z=$z+1;
					}
					$z=$z+1;
					while($row["start_date"][$z]!="-")
					{
						$temp_s_month=(10*$temp_s_month)+$row["start_date"][$z];
						if($row["end_date"]!="")
						$temp_e_month=(10*$temp_e_month)+$row["end_date"][$z];
						$z=$z+1;
					}
					$z=$z+1;
					while($z!=strlen($row["start_date"]))
					{
						$temp_s_year=(10*$temp_s_year)+$row["start_date"][$z];
						if($row["end_date"]!="")
						$temp_e_year=(10*$temp_e_year)+$row["end_date"][$z];
						$z=$z+1;
					}
					
					  $r[sprintf("name%s",$k)]=$row['company_name'];
					  $r[sprintf("info%s",$k)]=$row['company_info'];
					  $r[sprintf("message%s",$k)]=$row['message'];
					  $r[sprintf("date%s",$k)]=$temp_s_date;
					  $r[sprintf("month%s",$k)]=$temp_s_month;
					  $r[sprintf("year%s",$k)]=$temp_s_year;
                                          $r[sprintf("placement_info%s",$k)]=$row['placement_info'];
                                          $r[sprintf("enddate%s",$k)]=$temp_e_date;
                                          $r[sprintf("endmonth%s",$k)]=$temp_e_month;
                                          $r[sprintf("endyear%s",$k)]=$temp_e_year;
					  $k=$k+1;

				}
				
				$r["count"]=$k;
                print(json_encode($r));
                            
		 }
 mysql_close($con);
              
    ?> 