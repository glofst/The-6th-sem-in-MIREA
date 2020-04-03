package pet.shop.company.animals.birds;

import pet.shop.company.animals.Animal;

public class Flightless extends Animal implements BirdsInterface {
    public Flightless(String name, String birth, String type, int price) {
        super(name, birth, type, price);
    }
}
