package pet.shop.company.animals;

public abstract class Animal {
    private String name;
    private String birth;
    private String type;
    private int price;

    public Animal(String name, String birth, String type, int price) {
        this.name = name;
        this.birth = birth;
        this.type = type;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public int getPrice() {
        return price;
    }
}
