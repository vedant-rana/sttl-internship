<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Extract Username from Email</title>
</head>
<body>
    <form method="post" action="">
        Enter your email address: <input type="email" name="email" required>
        <input type="submit" value="Extract Username">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the email input is set and not empty
        if (isset($_POST['email']) && $_POST['email'] !== '') {
            $email = $_POST['email'];
            
            // Extract the username
            $username = strstr($email, '@', true); // Get the substring before '@'

            echo "<p>The username extracted from the email address is: $username</p>";
        } else {
            echo "<p>Please enter an email address.</p>";
        }
    }
    ?>
</body>
</html>
