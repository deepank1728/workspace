 <?php

         $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("b7_15025964_college_stat", $con);
		   
		   $v1=$_GET['table'];
		   
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
					  $r[sprintf("name%s",$k)]=$row['s_no'];
					 
					  $k=$k+1;

				}
				
				$r["count"]=$k;
                print(json_encode($r));
                            
		 }
 mysql_close($con);
              
    ?> 