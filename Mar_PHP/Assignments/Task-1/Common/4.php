<?php
$user_agent = $_SERVER['HTTP_USER_AGENT'];
$browsers = array(
    'Firefox' => 'Firefox',
    'Chrome' => 'Chrome',
    'Safari' => 'Safari',
    'Opera' => 'Opera',
    'Edge' => 'Edge',
    'IE' => 'MSIE', 
);

$detected_browser = 'Unknown';
foreach ($browsers as $browser => $browser_string) {
    if (strpos($user_agent, $browser_string) !== false) {
        $detected_browser = $browser;
        break;
    }
}

echo "Your browser is: $detected_browser";
?>
