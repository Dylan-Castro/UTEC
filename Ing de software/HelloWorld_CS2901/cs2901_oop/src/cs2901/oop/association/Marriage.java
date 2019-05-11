package cs2901.oop.association;

import java.util.Date;

public class Marriage {
    private Man man;
    private Woman woman;
    Date date;

    public Marriage(Man man, Woman woman, Date date) {
        this.man = man;
        this.woman = woman;
        this.date = date;
    }
}
