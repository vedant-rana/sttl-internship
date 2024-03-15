<!DOCTYPE html>
<html>
<head>
    <title>PHP Form Example</title>
</head>
<body>

<h2>Enter Your Name</h2>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    <label for="name">Name:</label>
    <input type="text" id="name" name="name">
    <input type="submit" value="Submit">
</form>

<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    echo "<h3>Hello, $name!</h3>";
}
?>

</body>
</html>
