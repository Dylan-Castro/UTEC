
public class Exercise3 {
    public static void main(String[] args) {
        String[] arr = {"The", "quick", "brown", "fox", "jumped", "over", "the", null};
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] != null) {
                System.out.println(arr[i].toLowerCase());
            }
        }
    }
}
