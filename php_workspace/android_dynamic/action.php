 <?php

         $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

           mysql_select_db("news", $con);
           $v1=$_REQUEST['s_no'];
		   //echo $v1
		  // $v1=1;
          if($v1==-1)
            {

                $r["re"]="No news available!!!";
                 print(json_encode($r));
                die('Could not connect: ' . mysql_error());
          }

          else

            {

				$q="select message from news_detail where s_no=$v1";
                $i=mysql_query($q,$con);
               $check='';
               $row = mysql_fetch_array($i);
                {
                  $r["message"]=$row['message'];
                //  $check=$row['s_no'];
                 }
                 

                     {
						$j=mysql_query("select count(s_no) as count_s_no from news_detail");
						$row2=mysql_fetch_array($j);
						//$k=""+$row2['count_s_no'];
                         $r["re"]="success";
						 $r["count"]=$row2['count_s_no'];
                            print(json_encode($r));
                             
                       }



			}

 mysql_close($con);
              
    ?> 