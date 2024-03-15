package P47;

import java.util.concurrent.CompletableFuture;

// Define states
enum State {
    INIT,
    STATE1,
    STATE2,
    FINAL
}

// Define events
enum Event {
    START,
    TRANSITION_TO_STATE1,
    ASYNC_OPERATION_COMPLETE,
    TRANSITION_TO_STATE2,
    ANOTHER_ASYNC_OPERATION_COMPLETE
}

// Finite State Machine
class StateMachine {
    private State currentState;

    public StateMachine() {
        this.currentState = State.INIT;
    }

    // Define state transition methods
    private CompletableFuture<Void> transitionToState1() {
        System.out.println("Transitioning to STATE1");
        currentState = State.STATE1;
        return CompletableFuture.completedFuture(null);
    }

    private CompletableFuture<Void> transitionToState2() {
        System.out.println("Transitioning to STATE2");
        currentState = State.STATE2;
        return CompletableFuture.completedFuture(null);
    }

    private CompletableFuture<Void> finalState() {
        System.out.println("Reached FINAL state");
        currentState = State.FINAL;
        return CompletableFuture.completedFuture(null);
    }

    // Define asynchronous operations
    private CompletableFuture<Void> asyncOperation() {
        System.out.println("Performing asynchronous operation...");
        // Simulate an asynchronous operation
        return CompletableFuture.runAsync(() -> {
            try {
                Thread.sleep(1000); // Simulating an asynchronous delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Asynchronous operation complete");
        });
    }

    private CompletableFuture<Void> anotherAsyncOperation() {
        System.out.println("Performing another asynchronous operation...");
        // Simulate another asynchronous operation
        return CompletableFuture.runAsync(() -> {
            try {
                Thread.sleep(1000); // Simulating an asynchronous delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Another asynchronous operation complete");
        });
    }

    // Execute the state machine
    public CompletableFuture<Void> execute(Event event) {
        switch (currentState) {
            case INIT:
                if (event == Event.START) {
                    return transitionToState1();
                }
                break;

            case STATE1:
                if (event == Event.TRANSITION_TO_STATE1) {
                    return asyncOperation().thenCompose(ignore -> transitionToState2());
                } else if (event == Event.ASYNC_OPERATION_COMPLETE) {
                    return transitionToState2();
                }
                break;

            case STATE2:
                if (event == Event.TRANSITION_TO_STATE2) {
                    return anotherAsyncOperation().thenCompose(ignore -> finalState());
                } else if (event == Event.ANOTHER_ASYNC_OPERATION_COMPLETE) {
                    return finalState();
                }
                break;

            case FINAL:
                // No further transitions from FINAL state
                break;
        }

        return CompletableFuture.completedFuture(null);
    }
}

public class TestFiniteState {
    public static void main(String[] args) {
        StateMachine stateMachine = new StateMachine();

        // Start the state machine
        stateMachine.execute(Event.START)
                .thenCompose(ignore -> stateMachine.execute(Event.TRANSITION_TO_STATE1))
                .thenCompose(ignore -> stateMachine.execute(Event.ASYNC_OPERATION_COMPLETE))
                .thenCompose(ignore -> stateMachine.execute(Event.TRANSITION_TO_STATE2))
                .thenCompose(ignore -> stateMachine.execute(Event.ANOTHER_ASYNC_OPERATION_COMPLETE))
                .join(); // Wait for completion
    }
}
