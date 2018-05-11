<?php

if(isset($_POST['submit'])){

  include_once 'dbh-inc.php';

  $first = $_POST['first'];
  $last = $_POST['last'];
  $email = $_POST['email'];
  $uid = $_POST['uid'];
  $pwd = $_POST['pwd'];

  //handlers

  if(empty($first) || empty($last) || empty($email) || empty($pwd) || empty($uid)){

    header("Location: ../signup.php?signup=empty");
    exit();
  } else {
    if(!preg_match("/^[a-zA-Z]*$/",$first) || !preg_match("/^[a-zA-Z]*$/",$last)){
      header("Location: ../signup.php?signup=invalid");
      exit();
    } else {
      if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
        header("Location: ../signup.php?signup=invalidemail");
        exit();
      } else {
        $sql = "SELECT * FROM users WHERE user_uid='$uid'";
        $RESULT = mysqli_query($conn, $sql);
        $RESULTCHECK = mysqli_num_rows($RESULT);
        if($RESULTCHECK > 0){
          header("Location: ../signup.php?signup=invalidusername");
          exit();
        } else {
          $HASHED = password_hash($pwd, PASSWORD_DEFAULT);
          $SQL = "INSERT INTO users (user_first, user_last, user_email, user_uid, user_pwd) VALUES (?,?,?,?,?);";
          $stmt = mysqli_stmt_init($conn);
          if(!mysqli_stmt_prepare($stmt,$SQL)){
            header("Location: ../signup.php?signup=failed");
            exit();
          } else {
            mysqli_stmt_bind_param($stmt,"sssss", $first, $last, $email, $uid, $HASHED);
            mysqli_stmt_execute($stmt);
            $RESULT = mysqli_query($conn, $SQL);
            header("Location: ../signup.php?signup=success");
            exit();
          }
          $RESULT = mysqli_query($conn, $SQL);
          header("Location: ../signup.php?signup=success");
          exit();
        }
      }
    }
  }

} else {
  header("Location: ../signup.php");
  exit();
}
