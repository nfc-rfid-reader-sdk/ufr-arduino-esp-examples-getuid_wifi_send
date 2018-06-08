<?php
/**
 * Created by: Digital Logic
 * Date: 5/31/2018
 */
include("config.php");
define("GRANT", "1,2");
define("DENY", "2,3");

function addLog($SN, $UID, $CTRLINFO)
{
    global $conn;
    $stmt = $conn->prepare("INSERT INTO log (SN, UID, CTRLINFO) VALUES (?,?,?)");
    $stmt->bind_param("ssi",$SN, $UID, $CTRLINFO);

    if ($stmt->execute()) {
        return 1;
    } else {
        return 0;
    }

    $stmt->close();
    $conn->close();
}

function checkUID($UID)
{
    global $conn;
    $stmt = $conn->prepare("SELECT * FROM whitelist WHERE UID=?");
    $stmt->bind_param("s",$UID);
    $stmt->execute();
    $stmt->store_result();


    if ($stmt->num_rows()==1) {
        return 1;
    } else {
        return 0;
    }
    $stmt->close();
    $conn->close();
}