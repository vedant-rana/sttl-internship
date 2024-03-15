package P35;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexExample {

    // Define a regular expression pattern as a constant
    private static final String EMAIL_REGEX = "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}";

    // Precompile the pattern during class initialization
    private static final Pattern EMAIL_PATTERN = Pattern.compile(EMAIL_REGEX);

    // Method to check if a string matches the email pattern
    public static boolean isEmailValid(String email) {
        Matcher matcher = EMAIL_PATTERN.matcher(email);
        return matcher.matches();
    }

    public static void main(String[] args) {
        String validEmail = "example@example.com";
        String invalidEmail = "invalid_email";

        // Test email validation
        System.out.println("Is '" + validEmail + "' a valid email? " + isEmailValid(validEmail));
        System.out.println("Is '" + invalidEmail + "' a valid email? " + isEmailValid(invalidEmail));
    }
}

