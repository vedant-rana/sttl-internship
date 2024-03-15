//package P15;
//
//import java.util.HashMap;
//import java.util.Map;
//
//// Command Handler
//class CommandHandler {
//    private final Map<String, String> dataStore = new HashMap<>();
//
//    public void handle(CreateCommand command) {
//        String entityId = command.getEntityId();
//        String entityData = command.getEntityData();
//        dataStore.put(entityId, entityData);
//        System.out.println("Entity created: " + entityId);
//    }
//
//    public void handle(UpdateCommand command) {
//        String entityId = command.getEntityId();
//        String newEntityData = command.getNewEntityData();
//        if (dataStore.containsKey(entityId)) {
//            dataStore.put(entityId, newEntityData);
//            System.out.println("Entity updated: " + entityId);
//        } else {
//            System.out.println("Entity not found for update: " + entityId);
//        }
//    }
//}
//
//// Query Handler
//class QueryHandler {
//    private final Map<String, String> dataStore;
//
//    public QueryHandler(Map<String, String> dataStore) {
//        this.dataStore = dataStore;
//    }
//
//    public String handle(GetQuery query) {
//        String entityId = query.getEntityId();
//        return dataStore.get(entityId);
//    }
//}
//
//// Commands
//class CreateCommand {
//    private final String entityId;
//    private final String entityData;
//
//    public CreateCommand(String entityId, String entityData) {
//        this.entityId = entityId;
//        this.entityData = entityData;
//    }
//
//    public String getEntityId() {
//        return entityId;
//    }
//
//    public String getEntityData() {
//        return entityData;
//    }
//}
//
//class UpdateCommand {
//    private final String entityId;
//    private final String newEntityData;
//
//    public UpdateCommand(String entityId, String newEntityData) {
//        this.entityId = entityId;
//        this.newEntityData = newEntityData;
//    }
//
//    public String getEntityId() {
//        return entityId;
//    }
//
//    public String getNewEntityData() {
//        return newEntityData;
//    }
//}
//
//// Queries
//class GetQuery {
//    private final String entityId;
//
//    public GetQuery(String entityId) {
//        this.entityId = entityId;
//    }
//
//    public String getEntityId() {
//        return entityId;
//    }
//}
//
//public class TestCQRS {
//    public static void main(String[] args) {
//        CommandHandler commandHandler = new CommandHandler();
//        QueryHandler queryHandler = new QueryHandler(commandHandler.getDataStore());
//
//        // Command: Create entity
//        CreateCommand createCommand = new CreateCommand("1", "EntityData1");
//        commandHandler.handle(createCommand);
//
//        // Query: Get entity data
//        GetQuery getQuery = new GetQuery("1");
//        String entityData = queryHandler.handle(getQuery);
//        System.out.println("Retrieved Entity Data: " + entityData);
//
//        // Command: Update entity
//        UpdateCommand updateCommand = new UpdateCommand("1", "NewEntityData1");
//        commandHandler.handle(updateCommand);
//
//        // Query: Get updated entity data
//        entityData = queryHandler.handle(getQuery);
//        System.out.println("Updated Entity Data: " + entityData);
//    }
//}
