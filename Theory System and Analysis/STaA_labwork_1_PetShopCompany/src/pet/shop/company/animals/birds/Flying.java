package pet.shop.company.animals.birds;

import pet.shop.company.animals.Animal;

public class Flying extends Animal implements BirdsInterface {
    public Flying(String name, String birth, String type, int price) {
        super(name, birth, type, price);
    }
}
