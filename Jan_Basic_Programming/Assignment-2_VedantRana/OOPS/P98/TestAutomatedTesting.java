package P98;

import java.util.ArrayList;
import java.util.List;

class TestCase {
    private String testName;

    public TestCase(String testName) {
        this.testName = testName;
    }

    public void run() {
        System.out.println("Running Test: " + testName);
    }
}

class TestSuite {
    private List<TestCase> testCases;

    public TestSuite() {
        this.testCases = new ArrayList<>();
    }

    public void addTestCase(TestCase testCase) {
        testCases.add(testCase);
    }

    public void run() {
        for (TestCase testCase : testCases) {
            testCase.run();
        }
    }
}


public class TestAutomatedTesting {
    public static void main(String[] args) {

        // automated test runner class

        TestCase test1 = new TestCase("Test Case 1");
        TestCase test2 = new TestCase("Test Case 2");
        TestCase test3 = new TestCase("Test Case 3");


        TestSuite testSuite = new TestSuite();
        testSuite.addTestCase(test1);
        testSuite.addTestCase(test2);
        testSuite.addTestCase(test3);


        testSuite.run();
    }
}
