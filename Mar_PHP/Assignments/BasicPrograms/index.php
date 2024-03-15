<!-- links.php -->
<?php
$files = array();
for ($i = 1; $i <= 66; $i++) {
    if ($i < 12) {
        $filename = 'Pattern-' . $i . '.php';
        $files[$filename] = 'Pattern ' . $i;
    } else {
        $filename = $i - 11 . '.php';
        $files[$filename] = 'Program ' . $i-11;
    }
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>Links to PHP Files</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            font-family: Arial, sans-serif;
        }

        .container {
            display: flex;
            height: 100vh;
        }

        .links {
            flex: 1;
            position: fixed;
            overflow-y: auto;
            height: 100%;
            background-color: #f4f4f4;
            padding: 20px;
            width: 10vw;
        }

        .links ul {
            list-style-type: none;
            padding: 0;
            margin: 0;
        }

        .links li {
            margin-bottom: 10px;
        }

        .links a {
            text-decoration: none;
            color: #333;
            padding: 5px 10px;
            display: block;
            transition: background-color 0.2s ease;
        }

        .links a:hover {
            background-color: #ddd;
        }

        .files {
            flex: 3;
            padding-left: 200px;
            overflow-y: auto;
            padding: 20px;
        }

        .files iframe {
            width: 100%;
            height: 100%;
            border: none;
            overflow-y: auto;
            margin-left: 12vw;
        }
    </style>
</head>

<body>
    <div class="container">
        <div class="links">
            <ul>
                <?php foreach ($files as $file => $name) : ?>
                    <li><a href="#<?php echo $file; ?>"><?php echo $name; ?></a></li>
                <?php endforeach; ?>
            </ul>
        </div>
        <div class="files">
            <?php foreach ($files as $file => $name) : ?>
                <iframe src="<?php echo $file; ?>" id="<?php echo $file; ?>" style="display: none;"></iframe>
            <?php endforeach; ?>
        </div>
    </div>
    <script>
        // JavaScript to toggle iframe visibility based on link clicks
        document.addEventListener('DOMContentLoaded', function() {
            var links = document.querySelectorAll('.links a');
            links.forEach(function(link) {
                link.addEventListener('click', function(e) {
                    e.preventDefault();
                    var fileId = this.getAttribute('href').substring(1);
                    var iframes = document.querySelectorAll('.files iframe');
                    iframes.forEach(function(iframe) {
                        iframe.style.display = 'none';
                    });
                    document.getElementById(fileId).style.display = 'block';
                });
            });
        });
    </script>
</body>

</html>