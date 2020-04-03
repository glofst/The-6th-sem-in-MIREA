package pet.shop.company.animals.mammals;

import pet.shop.company.animals.Animal;

public class Pet extends Animal implements MammalsInterface {
    public Pet(String name, String birth, String type, int price) {
        super(name, birth, type, price);
    }
}
