<?php

// Check if the download request is sent
if (isset($_POST['download_pdf']) || isset($_GET['download'])) {
    // Specify the path to the PDF file
    $filePath = '../images/UserDetails.pdf';

    // Check if the file exists
    if (file_exists($filePath)) {
        // Set the appropriate headers
        header('Content-Description: File Transfer');
        header('Content-Type: application/pdf');
        header('Content-Disposition: attachment; filename="' . basename($filePath) . '"');
        header('Expires: 0');
        header('Cache-Control: must-revalidate');
        header('Pragma: public');
        header('Content-Length: ' . filesize($filePath));
        ob_clean(); // Clean (erase) the output buffer
        flush(); // Flush system output buffer
        readfile($filePath); // Send the file to the user
        exit;
    } else {
        echo 'File not found.';
    }
}

?>
