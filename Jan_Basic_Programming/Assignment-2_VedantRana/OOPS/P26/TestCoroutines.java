package P26;


import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;


public class TestCoroutines {
    private static CompletableFuture<String> downloadResource(String url) {
        return CompletableFuture.supplyAsync(() -> {
            // Simulate some asynchronous download logic
            try {
                Thread.sleep(2000); // Simulating download delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            // Return the downloaded resource
            return "Content from " + url;
        });
    }

    public static void main(String[] args) {
        String url1 = "https://example.com/resource1";
        String url2 = "https://example.com/resource2";
        String url3 = "https://example.com/resource3";

        // Download resources asynchronously
        CompletableFuture<String> download1 = downloadResource(url1);
        CompletableFuture<String> download2 = downloadResource(url2);
        CompletableFuture<String> download3 = downloadResource(url3);

        // Combine results when all downloads complete
        CompletableFuture<Void> allDownloads = CompletableFuture.allOf(download1, download2, download3);

        // Handle the result or perform additional operations when all downloads are complete
        allDownloads.thenRun(() -> {
            try {
                String content1 = download1.get();
                String content2 = download2.get();
                String content3 = download3.get();

                System.out.println("Downloaded content 1: " + content1);
                System.out.println("Downloaded content 2: " + content2);
                System.out.println("Downloaded content 3: " + content3);
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        });

        // Simulate other work while downloads are in progress
        System.out.println("Performing other work...");

        // Wait for all downloads to complete before exiting
        allDownloads.join();
    }
}
