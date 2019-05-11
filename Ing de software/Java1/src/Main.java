import java.util.Collection;
import java.util.Iterator;

class Curso{
    private int name;
    private Collection<Student> students;
    public int getName() {
        return name;
    }

    public void setName(int name) {
        this.name = name;
    }

    public Collection<Student> getStudents() {
        return students;
    }

    public void setStudents(Collection<Student> students) {
        this.students = students;
    }
    public void eraseStudent(Student s){
        Iterator<Student> it = students.iterator();
        while(it.hasNext())
        {
            Student i = it.next();
            if(i == s)
                it.remove();
            break;
            }
    }
}
class Student{
    private String name;
    private int age;
    Student(String name, int age){
        this.name=name;
        this.age=age;
    }
}
public class Main {
    public static void main(String[] args) {
        Curso curso = new Curso();
        System.out.println("Hello World!");
    }
}
