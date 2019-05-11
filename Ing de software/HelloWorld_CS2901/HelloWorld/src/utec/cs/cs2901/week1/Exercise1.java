
import java.lang.Math.*;

public class Exercise1 {
    private static double volume(String solidom, double alturam, double areaBasem, double raiom) {
        double vol;
        if (solidom.equalsIgnoreCase("esfera") ){
            vol = (4.0 / 3) * Math.PI * Math.pow(raiom, 3);
        }
    else{
            if (solidom.equalsIgnoreCase("cilindro") ){
                vol = Math.PI * Math.pow(raiom, 2) * alturam;
            }
      else{
                vol = (1.0 / 3) * Math.PI * Math.pow(raiom, 2) * alturam;
            }
        }
        return vol;
    }

    public static void main(String[] args) {
        volume("esfera", 3.1, 2.3, 1.3);
    }
}