package week03;

import java.util.Scanner;

public class IDontWannaBe5thGrade {
    public static void main(String[] args) {
        String msg = "Nae ga wae";
        Scanner scanner = new Scanner(System.in);

        String current = scanner.nextLine();
        String[] currentList = current.split(" ");
        int N = Integer.parseInt(currentList[0]);
        int A = Integer.parseInt(currentList[1]);
        int B = Integer.parseInt(currentList[2]);

        for(int i=0; i< 8-N; i++) {
            int lectureCnt = 6;

            String line = scanner.nextLine();
            String[] lineList = line.split(" ");
            int X = Integer.parseInt(lineList[0]);
            int Y = Integer.parseInt(lineList[1]);

            if(lectureCnt > 0 && lectureCnt >= X) {
                A += X * 3;
                B += X * 3;
                lectureCnt -= X;
            }
            if(lectureCnt > 0) {
                if(lectureCnt >= Y) {
                    B += Y * 3;
                } else {
                    B += lectureCnt * 3;
                }
            }
        }
        if(A >= 66 && B >= 130) msg = "Nice";

        System.out.println(msg);
    }
}