<!DOCTYPE html>
<html>
<head>
    <title>Email Validation</title>
</head>
<body>

<h2>Email Validation</h2>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    <label for="email">Email:</label>
    <input type="text" id="email" name="email">
    <input type="submit" value="Check">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $email = $_POST['email'];

    if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "<p>$email is a valid email address.</p>";
    } else {
        echo "<p>$email is not a valid email address.</p>";
    }
}
?>

</body>
</html>
