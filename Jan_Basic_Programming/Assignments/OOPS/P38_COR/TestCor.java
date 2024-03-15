package P38_COR;


interface Logger {
    void logMessage(LogLevel level, String message);
}


class ConsoleLogger implements Logger {
    private LogLevel level;

    public ConsoleLogger(LogLevel level) {
        this.level = level;
    }

    @Override
    public void logMessage(LogLevel messageLevel, String message) {
        if (messageLevel.compareTo(level) >= 0) {
            System.out.println("Console Logger: " + message);
        }
    }
}

class FileLogger implements Logger {
    private LogLevel level;
    private String logFilePath;

    public FileLogger(LogLevel level, String logFilePath) {
        this.level = level;
        this.logFilePath = logFilePath;
    }

    @Override
    public void logMessage(LogLevel messageLevel, String message) {
        if (messageLevel.compareTo(level) >= 0) {
            System.out.println("File Logger (" + logFilePath + "): " + message);
        }
    }
}


enum LogLevel {
    INFO,
    DEBUG,
    ERROR
}


class LoggerChain {
    private Logger firstLogger;

    public LoggerChain(Logger firstLogger) {
        this.firstLogger = firstLogger;
    }

    public void logMessage(LogLevel level, String message) {
        firstLogger.logMessage(level, message);
    }
}




public class TestCor {
    public static void main(String[] args) {

        Logger consoleLogger = new ConsoleLogger(LogLevel.INFO);
        Logger fileLogger = new FileLogger(LogLevel.DEBUG, "debug.log");
        Logger errorLogger = new ConsoleLogger(LogLevel.ERROR);


        LoggerChain loggerChain = new LoggerChain(consoleLogger);
        consoleLogger = new FileLogger(LogLevel.DEBUG, "debug.log");
        fileLogger = new FileLogger(LogLevel.ERROR, "error.log");


        loggerChain.logMessage(LogLevel.INFO, "This is an informational message");
        loggerChain.logMessage(LogLevel.DEBUG, "This is a debug message");
        loggerChain.logMessage(LogLevel.ERROR, "This is an error message");
    }
}
