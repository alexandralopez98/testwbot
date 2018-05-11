<?php
include_once 'header.php';
?>

<section class="main-container">
  <div class="main-wrapper">
    <?php
      if(isset($_SESSION['u_id']))
      {
        echo'<h2>Welcome to ULTIMATE HOMEWORK PLANNER</h2>
      </div>
      <div class="main-text">
        <p>Congratulations on saving yourself hours and hours of wasted time planning out your days!</p>
        <img src="https://scontent-ort2-1.xx.fbcdn.net/v/t1.0-9/31499471_10156044286572605_2936121535687032832_n.jpg?_nc_cat=0&oh=b172768f91e2502fce4e0d8cb66a932e&oe=5B4F1600" alt="Happy Student" height="400" width="400">
        <a href="UHH.zip" download="UHH">Download</a>
      </div>';
      } else {
        echo '<h2>It is time to get ULTIMATE HOMEWORK PLANNER</h2>
      </div>
      <div class="main-text">
        <p>Why are you wasting your time planning your homework like these nerds?!??!!</p>
        <img src="https://scontent-ort2-1.xx.fbcdn.net/v/t1.0-9/31934075_10156054130682605_8679616528502489088_o.jpg?_nc_cat=0&oh=3bfb652de03ae56645729397a718aa2b&oe=5B920D3E" alt="Sad Studnet" height="400" width="400">
        <a href="signup.php">Sign Up NOW!!</a>
      </div>';
      }
     ?>

</section>

<?php
include_once 'footer.php';
?>
