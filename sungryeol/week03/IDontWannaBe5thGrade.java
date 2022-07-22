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
/**
 * 마친 학기 수: N
 * 이수한 전공학점: A
 * 이수한 총 학점: B
 * 개설될 전공과목 수: X
 * 개설될 비전공과목 수: Y
 *
 * 한 학기에 전공 수업과 비전공 수업을 포함하여 최대 6과목을 수강할 수 있음
 * 과목당 학점은 3점으로 동일
 *
 * N, A, B를 입력받은 뒤 각 변수에 저장한다.
 * 8 - N 만큼 반복한다.
 * 수강 가능한 강의 수 = 6;
 * if(A < 66 && B < 130)이고, if(수강 가능한 강의 수 > 0 && 수강 가능한 강의 수 > X) 이면, A += X * 3, 수강 가능한 강의 수 - X, B += 수강 가능한 강의 수 * 3
 * else 이면, "Nice"
 */