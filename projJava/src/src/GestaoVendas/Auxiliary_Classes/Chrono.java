package GestaoVendas.Auxiliary_Classes;

import static java.lang.System.nanoTime;

/*Classe fornecida pela equipa docente*/

public class Chrono {

    private static long inicio = 0L;
    private static long fim = 0L;

    public static void start() {
        fim = 0L; inicio = nanoTime();
    }

    public static double stop() {
        fim = nanoTime();
        long elapsedTime = fim - inicio;
        // segundos
        return elapsedTime / 1.0E09;
    }

    public static String getTime() {
        return "" + stop();
    }


    public static String getTImeString() {
        return "Elapsed Time: " +getTime() + " s";
    }
}