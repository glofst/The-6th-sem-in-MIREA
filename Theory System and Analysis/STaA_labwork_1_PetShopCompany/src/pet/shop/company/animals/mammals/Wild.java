package pet.shop.company.animals.mammals;

import pet.shop.company.animals.Animal;

public class Wild extends Animal implements MammalsInterface {
    public Wild(String name, String birth, String type, int price) {
        super(name, birth, type, price);
    }
}
