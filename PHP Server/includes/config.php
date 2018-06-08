<?php
/**
 * Created by: Digital Logic
 * Date: 5/31/2018
 */
$servername="localhost";
$username="root";
$password="";
$database="ufr";
$conn=new mysqli($servername,$username,$password,$database);

if ($conn->connect_error) {
    die("Connection failed: " .$conn_>connect_error);
}
?>