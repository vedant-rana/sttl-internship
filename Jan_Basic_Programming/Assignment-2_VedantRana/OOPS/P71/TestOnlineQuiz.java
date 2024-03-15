package P71;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Quiz {
    private List<Question> questions;

    public Quiz(List<Question> questions) {
        this.questions = questions;
    }

    public List<Question> getQuestions() {
        return questions;
    }
}

class Question {
    private String questionText;
    private String[] options;
    private int correctOption;

    public Question(String questionText, String[] options, int correctOption) {
        this.questionText = questionText;
        this.options = options;
        this.correctOption = correctOption;
    }

    public boolean isCorrect(int selectedOption) {
        return selectedOption == correctOption;
    }

    public String[] getOptions() {
        return options;
    }
}

class Student {
    private String studentName;
    private int score;

    public Student(String studentName) {
        this.studentName = studentName;
        this.score = 0;
    }

    public void takeQuiz(Quiz quiz) {
        List<Question> questions = quiz.getQuestions();
        Random random = new Random();

        for (Question question : questions) {
            int selectedOption = random.nextInt(question.getOptions().length) + 1;

            if (question.isCorrect(selectedOption)) {
                score++;
            }
        }
    }

    public int getScore() {
        return score;
    }
}

public class TestOnlineQuiz {
    public static void main(String[] args) {
        Question question1 = new Question("What is the capital of France?",
                new String[]{"Berlin", "Paris", "Madrid", "Rome"}, 2);

        Question question2 = new Question("Which planet is known as the Red Planet?",
                new String[]{"Earth", "Mars", "Venus", "Jupiter"}, 2);

        List<Question> quizQuestions = new ArrayList<>();
        quizQuestions.add(question1);
        quizQuestions.add(question2);

        Quiz quiz = new Quiz(quizQuestions);

        Student student = new Student("John Doe");
        student.takeQuiz(quiz);

        System.out.println(student.getScore());
    }
}
