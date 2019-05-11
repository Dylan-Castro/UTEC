package cs2901.oop.dependencies.sample2;

public class Email {
    private Subject subject;

    public Email(Subject subject) {
        this.subject = subject;
    }

    public Subject getSubject() {
        return subject;
    }

    public void setSubject(Subject subject) {
        this.subject = subject;
    }
}
