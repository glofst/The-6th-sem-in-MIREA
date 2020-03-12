package pet.shop.company;

import pet.shop.company.animals.Animal;
import pet.shop.company.animals.birds.Flightless;
import pet.shop.company.animals.birds.Flying;
import pet.shop.company.animals.mammals.Pet;
import pet.shop.company.animals.mammals.Wild;
import pet.shop.company.animals.reptiles.WaterReptile;

import java.util.ArrayList;
import java.util.List;

public class PetShop {

    public static void main(String[] args) {
        List<Animal> animals = new ArrayList<>();
        animals.add(new WaterReptile("Tortilla", "05.07.1906", "Sea Turtle", 2000));
        animals.add(new Flightless("Petuh", "15.06.1992", "Ostrich", 3000));
        animals.add(new Pet("Barsik", "15.04.2000", "Cat", 100));
        animals.add(new Pet("Sharik", "17.07.2000", "Dog", 100));
        animals.add(new Pet("Barboss", "17.07.2020", "Dog", 150));
        animals.add(new Flying("Kesha", "12.12.2012", "Parrot", 500));
        animals.add(new Wild("Gray", "13.04.2015", "Wolf", 300));
        animals.add(new Wild("Redhead", "17.08.2003", "Fox", 400));

        String type = "Dog";
        System.out.println("Animal prices by type " + type + ":");
        for(Animal animal : getAnimalPricesBySpecialType(animals, type)) {
            String output = "\t" + animal.getName() + " " + animal.getPrice() + "$";
            System.out.println(output);
        }
    }

    private static List<Animal> getAnimalPricesBySpecialType(List<Animal> animals, String type) {
        List<Animal> result = new ArrayList<>();
        for (Animal animal : animals) {
            if (animal.getType().equals(type))
                result.add(animal);
        }
        return result;
    }
}
