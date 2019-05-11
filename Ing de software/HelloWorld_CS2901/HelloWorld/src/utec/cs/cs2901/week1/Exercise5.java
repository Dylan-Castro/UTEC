public class Exercise5 {

    public static int countLetterS(String input) {
        int count = 0;
        for(int i = 0; i <= input.length() -1; i++) {
            
            if(input.substring(i,i+1).equals("s")) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int letters = countLetterS("sFind tshe bugs :)");
        System.out.println(letters);
    }
}
