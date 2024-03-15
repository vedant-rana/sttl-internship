<?php
function multiplyLists($list1, $list2) {
    $result = array();
    if (count($list1) != count($list2)) {
        return "Lists must have the same length.";
    }
    for ($i = 0; $i < count($list1); $i++) {
        $result[] = $list1[$i] * $list2[$i];
    }
    return $result;
}

$list1 = array(1, 2, 3, 4, 5);
$list2 = array(2, 3, 4, 5, 6);
$result = multiplyLists($list1, $list2);

echo "Result of multiplying corresponding elements of lists:<br>";
echo implode(', ', $list1) . "<br>";
echo "x<br>";
echo implode(', ', $list2) . "<br>";
echo "=<br>";
echo implode(', ', $result);
?>
