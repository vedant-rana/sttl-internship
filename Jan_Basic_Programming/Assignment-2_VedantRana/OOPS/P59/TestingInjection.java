package P59;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;

// Dependency Injection Container
class DIContainer {
    private final Map<Class<?>, Object> instances = new HashMap<>();

    // Register a singleton instance
    public <T> void registerSingleton(Class<T> clazz, T instance) {
        instances.put(clazz, instance);
    }

    // Resolve and create an instance with dependencies
    public <T> T resolve(Class<T> clazz) {
        if (instances.containsKey(clazz)) {
            // Return singleton instance if available
            return clazz.cast(instances.get(clazz));
        }

        try {
            // Create a new instance using reflection
            Constructor<T> constructor = clazz.getDeclaredConstructor();
            T instance = constructor.newInstance();

            // Store the created instance as a singleton
            instances.put(clazz, instance);

            // Inject dependencies into fields
            for (Field field : clazz.getDeclaredFields()) {
                if (field.isAnnotationPresent(Inject.class)) {
                    Class<?> dependencyType = field.getType();
                    Object dependencyInstance = resolve(dependencyType);
                    field.setAccessible(true);
                    field.set(instance, dependencyInstance);
                }
            }

            return instance;
        } catch (InstantiationException | IllegalAccessException | NoSuchMethodException
                 | InvocationTargetException e) {
            throw new RuntimeException("Failed to resolve dependency for " + clazz.getName(), e);
        }
    }
}

// Annotation for marking injectable fields
@interface Inject {
}

// Example classes to demonstrate dependency injection
class Logger {
    public void log(String message) {
        System.out.println("Logging: " + message);
    }
}

class Service {
    @Inject
    private Logger logger;

    public void doSomething() {
        logger.log("Service is doing something");
    }
}

public class TestingInjection {
    public static void main(String[] args) {
        DIContainer diContainer = new DIContainer();

        // Register singleton instances
        Logger loggerInstance = new Logger();
        diContainer.registerSingleton(Logger.class, loggerInstance);

        // Resolve and create instances with dependencies
        Service serviceInstance = diContainer.resolve(Service.class);

        // Use the instances
        serviceInstance.doSomething();
    }
}
