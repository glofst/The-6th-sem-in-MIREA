package pet.shop.company.animals.reptiles;

import pet.shop.company.animals.Animal;

public class LandReptile extends Animal implements ReptilesInterface {
    public LandReptile(String name, String birth, String type, int price) {
        super(name, birth, type, price);
    }
}
