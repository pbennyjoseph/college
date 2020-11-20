<?php

if(isset($_GET['rlno'])){
    $con = mysqli_connect("localhost","root","","mydb");

    // Check connection
    if (mysqli_connect_errno()) {
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
        exit();
    }
    $rlno = $_GET['rlno'];
    $sql_query = "SELECT * FROM students where rlno='$rlno';";
    if($result = mysqli_query($con, $sql_query)){
        while ($row = mysqli_fetch_array($result)) {
            printf ("<b> Roll Number </b>: %s<br/>", $row[1]);
            printf ("<b> Name </b>: %s<br/>", $row[2]);
            printf ("<b> Fathers Name </b>: %s<br/>", $row[3]);
            printf ("<b> Mothers Name </b>: %s<br/>", $row[4]);
            printf ("<b> Semester </b>: %s<br/>", $row[5]);
        }
        mysqli_free_result($result);
        $mark_query = "SELECT * FROM memorecords where rlno='$rlno';";
        if($result = mysqli_query($con, $mark_query)){
            printf("::<b> Subject Marks </b>::<br/>");
            $scored = 0;
            $total = 0;
            while($row = mysqli_fetch_array($result)){
                printf ( "<b> %s </b>: %d/%d <br/>", $row[2], $row[3], $row[4]);
                $total += $row[4];
                $scored += $row[3];
            }
            printf("<b> Total Score </b>: %d/%d",$scored,$total);
            if($scored/$total > 0.70) printf(" <b> DISTINCTION </b>");
            printf("<br/>");
        }
        mysqli_close($con);
    } else {
        echo "No such student found<br>";
        mysqli_close($con);
        exit(0);
    }

} else {
    echo "Pass rlno as a Query parameter";
}

?>