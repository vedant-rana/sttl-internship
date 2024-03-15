<?php
function removeDuplicates($sortedList) {
    $uniqueList = array();

    foreach ($sortedList as $element) {
        if (empty($uniqueList) || $element !== end($uniqueList)) {
            $uniqueList[] = $element;
        }
    }

    return $uniqueList;
}

$sortedList = array(1, 2, 2, 3, 3, 4, 5, 5, 6);

$uniqueList = removeDuplicates($sortedList);

echo "Original list: " . implode(', ', $sortedList) . "<br>";
echo "List with duplicates removed: " . implode(', ', $uniqueList);
?>
