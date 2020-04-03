package pet.shop.company.animals.reptiles;

import pet.shop.company.animals.Animal;

public class Amphibian extends Animal implements ReptilesInterface {
    public Amphibian(String name, String birth, String type, int price) {
        super(name, birth, type, price);
    }
}
