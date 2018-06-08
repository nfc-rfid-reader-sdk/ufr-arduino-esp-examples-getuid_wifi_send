<?php
/**
 * Created by: Digital Logic
 * Date: 5/31/2018
 */
include("includes/functions.php");

if(isset($_POST))
{
    $SN = $_POST["SN"];               // Reader Serial Number, i.e. "WR654321"
    $UID = $_POST["UID"];             // Card UID, in hexadecimal representation delimited with colon, i.e. "52:DA:D9:95"
    $CTRLINFO = $_POST["CTRLINFO"];   // control number - an (auto-increment) integer between 0 and 255

    if(addLog($SN, $UID, $CTRLINFO))
    {
        if(checkUID($UID))
        {
            echo GRANT;
        }
        else
        {
            echo DENY;
        }
    }
}
?>