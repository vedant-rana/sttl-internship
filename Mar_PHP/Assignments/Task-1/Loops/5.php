<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Chess Board</title>
    <style>
        .chessboard {
            width: 320px;
            height: 320px;
            border: 2px solid #000;
            display: flex;
            flex-wrap: wrap;
        }
        .chessboard .cell {
            width: 40px; /* Total width is 320px, so each cell is 40px (320 / 8) */
            height: 40px;
            box-sizing: border-box;
        }
        .black {
            background-color: #000;
        }
        .white {
            background-color: #fff;
        }
    </style>
</head>
<body>

<div class="chessboard">
    <?php
    for ($row = 1; $row <= 8; $row++) {
        for ($col = 1; $col <= 8; $col++) {
            // Determine cell color by adding row and column numbers.
            // If the sum is even, the cell is white; if odd, it's black.
            $cellColor = ($row + $col) % 2 == 0 ? 'white' : 'black';
            echo "<div class='cell $cellColor'></div>";
        }
    }
    ?>
</div>

</body>
</html>
