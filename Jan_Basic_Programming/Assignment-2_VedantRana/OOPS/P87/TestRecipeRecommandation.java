package P87;
import java.util.ArrayList;
import java.util.List;

// Ingredient class representing ingredients used in recipes
class Ingredient {
    private String name;

    public Ingredient(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

// Recipe class representing a recipe with ingredients and instructions
class Recipe {
    private String name;
    private List<Ingredient> ingredients;
    private String instructions;

    public Recipe(String name, List<Ingredient> ingredients, String instructions) {
        this.name = name;
        this.ingredients = ingredients;
        this.instructions = instructions;
    }

    public String getName() {
        return name;
    }

    public List<Ingredient> getIngredients() {
        return ingredients;
    }

    public String getInstructions() {
        return instructions;
    }
}

// User class representing a user with preferences, dietary restrictions, and ingredient availability
class User {
    private List<Ingredient> preferredIngredients;
    private List<String> dietaryRestrictions;
    private List<Recipe> favoriteRecipes;

    public User(List<Ingredient> preferredIngredients, List<String> dietaryRestrictions) {
        this.preferredIngredients = preferredIngredients;
        this.dietaryRestrictions = dietaryRestrictions;
        this.favoriteRecipes = new ArrayList<>();
    }

    public List<Ingredient> getPreferredIngredients() {
        return preferredIngredients;
    }

    public List<String> getDietaryRestrictions() {
        return dietaryRestrictions;
    }

    public List<Recipe> getFavoriteRecipes() {
        return favoriteRecipes;
    }

    public void addFavoriteRecipe(Recipe recipe) {
        favoriteRecipes.add(recipe);
    }
}

// RecipeRecommendationSystem class for recommending recipes to users
class RecipeRecommendationSystem {
    private List<Recipe> allRecipes;

    public RecipeRecommendationSystem(List<Recipe> allRecipes) {
        this.allRecipes = allRecipes;
    }

    public List<Recipe> recommendRecipes(User user) {
        List<Recipe> recommendedRecipes = new ArrayList<>();

        for (Recipe recipe : allRecipes) {
            if (isRecipeSuitable(recipe, user)) {
                recommendedRecipes.add(recipe);
            }
        }

        return recommendedRecipes;
    }

    private boolean isRecipeSuitable(Recipe recipe, User user) {
        // Check if the recipe contains preferred ingredients
        for (Ingredient preferredIngredient : user.getPreferredIngredients()) {
            if (!recipe.getIngredients().contains(preferredIngredient)) {
                return false;
            }
        }

        // Check if the recipe satisfies dietary restrictions
        for (String restriction : user.getDietaryRestrictions()) {
            if (recipe.getIngredients().stream().anyMatch(ingredient -> ingredient.getName().contains(restriction))) {
                return false;
            }
        }

        return true;
    }
}

public class TestRecipeRecommandation {
    public static void main(String[] args) {
        // Create ingredients
        Ingredient tomato = new Ingredient("Tomato");
        Ingredient onion = new Ingredient("Onion");
        Ingredient chicken = new Ingredient("Chicken");

        // Create recipes
        List<Ingredient> recipeIngredients1 = List.of(tomato, onion, chicken);
        Recipe recipe1 = new Recipe("Chicken Curry", recipeIngredients1, "Instructions for Chicken Curry");

        List<Ingredient> recipeIngredients2 = List.of(tomato, onion);
        Recipe recipe2 = new Recipe("Tomato Onion Salad", recipeIngredients2, "Instructions for Tomato Onion Salad");

        // Create a user
        List<Ingredient> preferredIngredients = List.of(tomato, chicken);
        List<String> dietaryRestrictions = List.of("Peanut");
        User user = new User(preferredIngredients, dietaryRestrictions);

        // Add favorite recipe for the user
        user.addFavoriteRecipe(recipe1);

        // Create a recipe recommendation system
        List<Recipe> allRecipes = List.of(recipe1, recipe2);
        RecipeRecommendationSystem recommendationSystem = new RecipeRecommendationSystem(allRecipes);

        // Recommend recipes for the user
        List<Recipe> recommendedRecipes = recommendationSystem.recommendRecipes(user);

        // Display recommended recipes
        System.out.println("Recommended Recipes:");
        for (Recipe recommendedRecipe : recommendedRecipes) {
            System.out.println(recommendedRecipe.getName());
        }
    }
}
