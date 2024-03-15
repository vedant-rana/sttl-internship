package P10_Singleton;

class Logger{
    private static Logger oneLog;
    private int num;
    private Logger(int num){
        this.num = num;
    }

    public static Logger getObject(int num){
        if(oneLog == null){
            oneLog = new Logger(num);
        }
        return oneLog;
    }

    public void logMessage(String message){
        System.out.println("object "+this.num+"'s log : "+message);
    }
}
public class TestSingleton {
    public static void main(String[] args) {
        Logger l1 = Logger.getObject(1);
        l1.logMessage("hello World !");

        Logger l2 = Logger.getObject(2);
        l2.logMessage("Hi there");
    }
}
