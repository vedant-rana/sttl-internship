<?php
function changeFirstCharacterColor($string, $color = 'red') {
    
    $words = explode(' ', $string);

   
    foreach ($words as &$word) {
        $firstCharacter = mb_substr($word, 0, 1);
        $word = '<span style="color: ' . $color . ';">' . $firstCharacter . '</span>' . mb_substr($word, 1);
    }

   
    return implode(' ', $words);
}
$string = "This is a sample sentence";
echo changeFirstCharacterColor($string);
?>
