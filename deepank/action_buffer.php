<?php
    if (isset($_POST)){
        
        		echo "hello";
           
            $file = fopen("temp.txt","a+");
            echo "heeo";
            while(!feof($file)){
                $old = $old . fgets($file). "<br />";
                echo $old;
            }
           	echo $old;
            $text = $_POST["area"];
             echo $text;
            file_put_contents( "temp.txt", $old . $text);
            fclose($file);
        

    }
    ?>
