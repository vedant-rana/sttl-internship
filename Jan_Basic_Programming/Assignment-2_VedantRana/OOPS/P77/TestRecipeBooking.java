package P77;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Ingredient {
    private String name;

    public Ingredient(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

class Recipe {
    private String name;
    private List<Ingredient> ingredients;
    private String category;

    public Recipe(String name, String category) {
        this.name = name;
        this.ingredients = new ArrayList<>();
        this.category = category;
    }

    public String getName() {
        return name;
    }

    public List<Ingredient> getIngredients() {
        return ingredients;
    }

    public void addIngredient(Ingredient ingredient) {
        ingredients.add(ingredient);
    }

    public String getCategory() {
        return category;
    }
}

class Cookbook {
    private Map<String, List<Recipe>> recipesByCategory;

    public Cookbook() {
        this.recipesByCategory = new HashMap<>();
    }

    public void addRecipe(Recipe recipe) {
        String category = recipe.getCategory();
        recipesByCategory.putIfAbsent(category, new ArrayList<>());
        recipesByCategory.get(category).add(recipe);
    }

    public List<Recipe> searchRecipesByIngredient(Ingredient ingredient) {
        List<Recipe> matchingRecipes = new ArrayList<>();
        for (List<Recipe> recipes : recipesByCategory.values()) {
            for (Recipe recipe : recipes) {
                if (recipe.getIngredients().contains(ingredient)) {
                    matchingRecipes.add(recipe);
                }
            }
        }
        return matchingRecipes;
    }

    public List<Recipe> getRecipesByCategory(String category) {
        return recipesByCategory.getOrDefault(category, new ArrayList<>());
    }
}


public class TestRecipeBooking {
    public static void main(String[] args) {
        Ingredient chicken = new Ingredient("Chicken");
        Ingredient rice = new Ingredient("Rice");
        Ingredient tomato = new Ingredient("Tomato");

        Recipe chickenRiceBowl = new Recipe("Chicken Rice Bowl", "Main Dish");
        chickenRiceBowl.addIngredient(chicken);
        chickenRiceBowl.addIngredient(rice);

        Recipe tomatoSalad = new Recipe("Tomato Salad", "Salad");
        tomatoSalad.addIngredient(tomato);

        Cookbook cookbook = new Cookbook();
        cookbook.addRecipe(chickenRiceBowl);
        cookbook.addRecipe(tomatoSalad);

        Ingredient searchIngredient = new Ingredient("Rice");
        List<Recipe> recipesWithIngredient = cookbook.searchRecipesByIngredient(searchIngredient);

        System.out.println("Recipes with " + searchIngredient.getName() + ":");
        for (Recipe recipe : recipesWithIngredient) {
            System.out.println("- " + recipe.getName() + " (" + recipe.getCategory() + ")");
        }

        String categoryToSearch = "Salad";
        List<Recipe> recipesInCategory = cookbook.getRecipesByCategory(categoryToSearch);

        System.out.println("Recipes in " + categoryToSearch + ":");
        for (Recipe recipe : recipesInCategory) {
            System.out.println("- " + recipe.getName());
        }
    }
}
