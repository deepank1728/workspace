<?php

         $con = mysql_connect("localhost","root","");
         if (!$con)
           {
             die('Could not connect: ' . mysql_error());
           }

               mysql_select_db("ex1", $con);


                  $v1=$_REQUEST['f1'];


                 if($v1==NULL)
                {


                          $r["re"]="Enter the number!!!";
                          print(json_encode($r));
                         die('Could not connect: ' . mysql_error());

                     }



                    else

                   {
                           $i=mysql_query("select * from t1 where f1=$v1",$con);
                           $check='';

                        while($row = mysql_fetch_array($i))
                         {
 
                             $check=$row['f1'];

                           }

          
                             if($check==NULL)
                             {

                                   $r["re"]="Record is not found.. Enter valid number";
                                   print(json_encode($r));
                              }            
                           else
                          {
                                    $q="delete from t1 where f1='$v1'";
                                     $s= mysql_query($q,$con);
                                     if(!$s)
                                    {
                                            $r["re"]="Record deletion problem in batabase";
                 
                                             print(json_encode($r));
                                     }
                                     else
                                          {
                                             $r["re"]="Record Deleted successfully";
                                              print(json_encode($r));
                                            }

                                 }


                    }

 mysql_close($con);
              
    ?> 